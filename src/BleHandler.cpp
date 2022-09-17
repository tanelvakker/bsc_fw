// Copyright (c) 2022 tobias
// 
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT


#include "BleHandler.h"

void scanEndedCB(NimBLEScanResults results);
bool bleNeeyBalancerConnect(uint8_t deviceNr);

static bleDevice bleDevices[BT_DEVICES_COUNT];
NimBLEScan* pBLEScan;
NimBLEAdvertisedDevice* advDevice;

WebSettings webSettings;

static boolean doStartBtScan   = false; 
static boolean btScanIsRunning = false; 

NimBLEUUID NeyyBalancer4A_serviceUUID("0000ffe0-0000-1000-8000-00805f9b34fb");
NimBLEUUID NeyyBalancer4A_charUUID   ("0000ffe1-0000-1000-8000-00805f9b34fb");

byte NeeyBalancer_getInfo[20] PROGMEM = {0xaa, 0x55, 0x11, 0x01, 0x02, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf9, 0xff}; 

std::string notifyMacAdr;


class ClientCallbacks : public NimBLEClientCallbacks
{
  void onConnect(NimBLEClient* pClient)
  {
    Serial.println("Connected");
    /** After connection we should change the parameters if we don't need fast response times.
     *  These settings are 150ms interval, 0 latency, 450ms timout.
     *  Timeout should be a multiple of the interval, minimum is 100ms.
     *  I find a multiple of 3-5 * the interval works best for quick response/reconnect.
     *  Min interval: 120 * 1.25ms = 150, Max interval: 120 * 1.25ms = 150, 0 latency, 60 * 10ms = 600ms timeout
     */
    pClient->updateConnParams(120,120,0,100);

    String devMacAdr = pClient->getPeerAddress().toString().c_str();
    Serial.println(devMacAdr);

    for(uint8_t i=0;i<BT_DEVICES_COUNT;i++)
    {
      if(bleDevices[i].macAdr.equals(devMacAdr))
      {
        bleDevices[i].isConnect = true;
        bleDevices[i].doConnect = btDoConnectionIdle; 
        setBmsLastDataMillis(i,millis());
      }
    }
  };

  void onDisconnect(NimBLEClient* pClient)
  {
    Serial.println(" Disconnected");

    String devMacAdr = pClient->getPeerAddress().toString().c_str();
    Serial.println(devMacAdr);

    for(uint8_t i=0;i<BT_DEVICES_COUNT;i++)
    {
      if(bleDevices[i].macAdr.equals(devMacAdr))
      {
        bleDevices[i].isConnect = false;
        bleDevices[i].doConnect = btDoConnectionIdle; 
        bleDevices[i].deviceTyp = "";
        bleDevices[i].macAdr = "";
      }
    }
  }

  /** Called when the peripheral requests a change to the connection parameters.
   *  Return true to accept and apply them or false to reject and keep
   *  the currently used parameters. Default will return true.
   */
  bool onConnParamsUpdateRequest(NimBLEClient* pClient, const ble_gap_upd_params* params)
  {
    Serial.println("onConnParamsUpdateRequest()");
    if(params->itvl_min < 24) { /** 1.25ms units */
      return false;
    } else if(params->itvl_max > 40) { /** 1.25ms units */
      return false;
    } else if(params->latency > 2) { /** Number of intervals allowed to skip */
      return false;
    } else if(params->supervision_timeout > 100) { /** 10ms units */
      return false;
    }

    return true;
  };
};


class MyAdvertisedDeviceCallbacks: public NimBLEAdvertisedDeviceCallbacks 
{
  std::string devMacAdr;

  void onResult(NimBLEAdvertisedDevice* advertisedDevice)
  {
    Serial.printf("BT device found()\n");

    //Device gefunden
    devMacAdr = advertisedDevice->getAddress().toString();

    for(uint8_t i=0; i<BT_DEVICES_COUNT; i++)
    {    
      if(!webSettings.getString(ID_PARAM_SS_BTDEVMAC,0,i,0).equals(""))
      {
        if (webSettings.getString(ID_PARAM_SS_BTDEVMAC,0,i,0).equals(devMacAdr.c_str()) && webSettings.getString(ID_PARAM_SS_BTDEV,0,i,0).equals(String(ID_BT_DEVICE_NB))==false)
        {
          Serial.print("Gesuchtes Device gefunden: ");
          Serial.println(webSettings.getString(ID_PARAM_SS_BTDEVMAC,0,i,0));
          
          Serial.println("Scan stop");
          NimBLEDevice::getScan()->stop();
        
          advDevice = advertisedDevice;   
          bleDevices[i].deviceTyp = webSettings.getString(ID_PARAM_SS_BTDEV,0,i,0);
          bleDevices[i].macAdr = webSettings.getString(ID_PARAM_SS_BTDEVMAC,0,i,0);
          bleDevices[i].doConnect = btDoConnect;
     
          btScanIsRunning = false; //Scan beendet
        }
      }
    }
  }
};


/** Notification / Indication receiving handler callback */
void notifyCB(NimBLERemoteCharacteristic* pRemoteCharacteristic, uint8_t* pData, size_t length, bool isNotify)
{
  notifyMacAdr = pRemoteCharacteristic->getRemoteService()->getClient()->getPeerAddress().toString();

  for(uint8_t i=0;i<BT_DEVICES_COUNT;i++)
  {
    if(bleDevices[i].macAdr.equals(notifyMacAdr.c_str()))
    {
      setBmsLastDataMillis(i,millis());

      if(bleDevices[i].deviceTyp.equals(String(ID_BT_DEVICE_NEEY4A)))
      {
        //Daten kopieren
        NeeyBalancer::neeyBalancerCopyData(i, pData, length);
      }
    }
  }

  /*Serial.print(": len=");
  Serial.println(length);
  Serial.print("data=");
  //Serial.println((char*)pData);
  for(uint16_t i=0; i<length; i++)
  {
    Serial.print(pData[i], HEX);
    Serial.print(" ");
  }
  Serial.println("");*/
}


/**
 * Callback invoked when scanning has completed.
 */
void scanCompleteCB(NimBLEScanResults scanResults) {
	//Serial.printf("Scan complete! %i Devices found\n",scanResults.getCount());
} 


/** Create a single global instance of the callback class to be used by all clients */
static ClientCallbacks clientCB;

bool bleNeeyBalancerConnect(uint8_t devNr)
{
  Serial.printf("bleNeeyBalancerConnect()\n");

  NimBLEClient* pClient = nullptr;

  /** Check if we have a client we should reuse first **/
  if(NimBLEDevice::getClientListSize())
  {
    /** Special case when we already know this device, we send false as the
     *  second argument in connect() to prevent refreshing the service database.
     *  This saves considerable time and power.
     */
    pClient = NimBLEDevice::getClientByPeerAddress(advDevice->getAddress());
    if(pClient)
    {
      //if(!pClient->connect(bleDevices[devNr].advDevice, false))
      if(!pClient->connect(advDevice, false))
      {
        Serial.println("Reconnect failed");
        return false;
      }
      Serial.println("Reconnected client");
    }
    /** We don't already have a client that knows this device,
     *  we will check for a client that is disconnected that we can use.
     */
    else
    {
      pClient = NimBLEDevice::getDisconnectedClient();
    }
  }

  /** No client to reuse? Create a new one. */
  if(!pClient)
  {
    if(NimBLEDevice::getClientListSize() >= NIMBLE_MAX_CONNECTIONS)
    {
      Serial.println("Max clients reached - no more connections available");
      return false;
    }

    pClient = NimBLEDevice::createClient();
    Serial.println("New client created");
    pClient->setClientCallbacks(&clientCB, false);
    /** Set initial connection parameters: These settings are 15ms interval, 0 latency, 120ms timout.
     *  These settings are safe for 3 clients to connect reliably, can go faster if you have less
     *  connections. Timeout should be a multiple of the interval, minimum is 100ms.
     *  Min interval: 12 * 1.25ms = 15, Max interval: 12 * 1.25ms = 15, 0 latency, 51 * 10ms = 510ms timeout
     */
    //pClient->setConnectionParams(12,12,0,51);
    pClient->setConnectionParams(12,12,0,100);
    /** Set how long we are willing to wait for the connection to complete (seconds), default is 30. */
    pClient->setConnectTimeout(5);


    //if (!pClient->connect(bleDevices[devNr].advDevice))
    if (!pClient->connect(advDevice))
    {
      /** Created a client but failed to connect, don't need to keep it as it has no data */
      NimBLEDevice::deleteClient(pClient);
      Serial.println("Failed to connect, deleted client");
      return false;
    }
  }

  if(!pClient->isConnected()) {
    //if (!pClient->connect(bleDevices[devNr].advDevice))
    if (!pClient->connect(advDevice))
    {
      Serial.println("Failed to connect");
      return false;
    }
  }

  Serial.print("Connected to: ");
  Serial.println(pClient->getPeerAddress().toString().c_str());
  Serial.print("RSSI: ");
  Serial.println(pClient->getRssi());

  /** Now we can read/write/subscribe the charateristics of the services we are interested in */
  NimBLERemoteService* pSvc = nullptr;
  //NimBLERemoteCharacteristic* pChr = nullptr;
  bleDevices[devNr].pChr = nullptr;
  NimBLERemoteDescriptor* pDsc = nullptr;

  pSvc = pClient->getService(NeyyBalancer4A_serviceUUID);
  if(pSvc)  /** make sure it's not null */
  {     
    bleDevices[devNr].pChr = pSvc->getCharacteristic(NeyyBalancer4A_charUUID);

    if(bleDevices[devNr].pChr)
    {     /** make sure it's not null */
      if(bleDevices[devNr].pChr->canRead())
      {
          Serial.print(bleDevices[devNr].pChr->getUUID().toString().c_str());
          Serial.print(" Value: ");
          Serial.println(bleDevices[devNr].pChr->readValue().c_str());
      }

      if(bleDevices[devNr].pChr->canWrite())
      {
        Serial.println("canWrite ok");
          /*if(pChr->writeValue("Tasty"))
          {
            Serial.print("Wrote new value to: ");
            Serial.println(pChr->getUUID().toString().c_str());
          }
          else
          {
            // Disconnect if write failed 
            pClient->disconnect();
            return false;
          }

          if(pChr->canRead())
          {
            Serial.print("The value of: ");
            Serial.print(pChr->getUUID().toString().c_str());
            Serial.print(" is now: ");
            Serial.println(pChr->readValue().c_str());
          }*/
      }

      /** registerForNotify() has been deprecated and replaced with subscribe() / unsubscribe().
       *  Subscribe parameter defaults are: notifications=true, notifyCallback=nullptr, response=false.
       *  Unsubscribe parameter defaults are: response=false.
       */
      if(bleDevices[devNr].pChr->canNotify())
      {
        //if(!pChr->registerForNotify(notifyCB))
        if(!bleDevices[devNr].pChr->subscribe(true, notifyCB))
        {
          /** Disconnect if subscribe failed */
          pClient->disconnect();
          return false;
        }
      }
      else if(bleDevices[devNr].pChr->canIndicate())
      {
        /** Send false as first argument to subscribe to indications instead of notifications */
        //if(!pChr->registerForNotify(notifyCB, false))
        if(!bleDevices[devNr].pChr->subscribe(false, notifyCB))
        {
          /** Disconnect if subscribe failed */
          pClient->disconnect();
          return false;
        }
      }
    }
  }
  else
  {
    Serial.println("Service not found.");
  }

  Serial.println("Done with this device!");
  return true;
}








/**
 * Class BleHandler
 */
BleHandler::BleHandler() {

};

void BleHandler::init() {
  Serial.println("BleHandler::init()");
  timer_startScan=0;
  startManualScan=false;

  for(uint8_t i=0;i<BT_DEVICES_COUNT;i++)
  {
    bleDevices[i].doConnect = btDoConnectionIdle;
    bleDevices[i].doDisconnect = false;
    bleDevices[i].isConnect = false;
    bleDevices[i].macAdr = "";
    bleDevices[i].deviceTyp = "";
    setBmsLastDataMillis(i,0);

    for(uint8_t n=0;n<24;n++)
    {
      bmsCellVoltage[i][n] = 0;
    }
    
  }

  NimBLEDevice::init("");
  //NimBLEDevice::setPower(ESP_PWR_LVL_P9); /** +9db */

  pBLEScan = NimBLEDevice::getScan();
  pBLEScan->setAdvertisedDeviceCallbacks(new MyAdvertisedDeviceCallbacks());
  pBLEScan->setInterval(45);
  pBLEScan->setWindow(15);
  pBLEScan->setActiveScan(true);
  pBLEScan->setMaxResults(5);

  pBLEScan->clearResults();
  //pBLEScan->start(1);   
  Serial.println("BleHandler::init() end");
};

void BleHandler::startScan()
{
  startManualScan=true;
}

bool BleHandler::isScanFinish()
{
  if(btScanIsRunning)
  {
    return false;
  }
  else
  {
    return true;
  }
}


void BleHandler::run() {
  static uint8_t i;

  //BT Devices verbinden 
  for(i=0;i<BT_DEVICES_COUNT;i++)
  {
    //Nur wenn nicht nach BT Devices gesucht wird
    if(!btScanIsRunning) 
    {
      //Überprüfen ob BT-Devices gesucht werden müssen; ggf. suche starten
      if(webSettings.getString(ID_PARAM_SS_BTDEV,0,i,0).equals(String(ID_BT_DEVICE_NB))==false) //Wenn ein Device parametriert ist
      {
        if(bleDevices[i].isConnect==false && bleDevices[i].doConnect==btDoConnectionIdle) //Wenn es nicht verbunden ist
        {
          //Suche starten
          doStartBtScan = true;
        }
      }

      if(bleDevices[i].doConnect == btDoConnect)
      {
        if(bleDevices[i].deviceTyp.equals(String(ID_BT_DEVICE_NEEY4A))) //Wenn ein NEEY Balancer 4A konfiguriert ist
        {
          bleDevices[i].doConnect = btConnectionSetup; //Verbdinung wird hergestellt

          if(bleNeeyBalancerConnect(i))
          {
            bleDevices[i].pChr->writeValue(NeeyBalancer_getInfo, 20);
          }
          else //Wenn Verbingungsversuch fehgeschlagen
          {
            bleDevices[i].doConnect = btDoConnectionIdle; 
          }
        }
      }
    }
  }
  
  //Manuellen scan starten
  if(startManualScan)
  {
    startManualScan=false;
    if(!btScanIsRunning) doStartBtScan=true;
  }

  //Wenn angefordert, dann starte neuen BT scan
  if(doStartBtScan && !btScanIsRunning)
  {
    Serial.println("Starte BT Scan");
    doStartBtScan = false;
    btScanIsRunning = true;
    if(pBLEScan->isScanning())
    {
      Serial.println("scan läuft noch");
    }
    else
    {
      NimBLEDevice::getScan()->clearResults();
      NimBLEDevice::getScan()->start(0,scanCompleteCB);
    }
  }
} 


std::string BleHandler::getBtScanResult()
{
  std::string btDevScanResult = "<table>";

  NimBLEScanResults results = NimBLEDevice::getScan()->getResults();

  for (int i = 0; i < results.getCount(); i++)
  {
    NimBLEAdvertisedDevice device = results.getDevice(i);
    
    btDevScanResult += "<tr>";

    btDevScanResult += "<td>";
    btDevScanResult += device.getAddress().toString();
    btDevScanResult += "</td>";

    btDevScanResult += "<td>";
    btDevScanResult += device.getName();
    btDevScanResult += "</td>";

    btDevScanResult += "<td>";
    btDevScanResult += device.getServiceUUID();
    btDevScanResult += "</td>";
    
    btDevScanResult += "<td>";
    btDevScanResult += device.getServiceDataUUID();
    btDevScanResult += "</td>";
        
    btDevScanResult += "</tr>";
  }
  
  btDevScanResult += "<table>";

  return btDevScanResult;
}


bool BleHandler::bmsIsConnect(uint8_t devNr)
{
  return bleDevices[devNr].isConnect;
}