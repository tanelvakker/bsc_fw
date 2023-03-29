// Copyright (c) 2022 tobias
// 
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#include "Arduino.h"
#include "defines.h"
#include "WebSettings.h"

/* ***********************************************************************************
 * Wichtiger Hinweis!
 * params.h nicht manuell bearbeiten! Änderungen immer in der params_py.h vornehmen!
 * Die params.h wird beim Build automatisch erstellt!
 * ***********************************************************************************/


//PY_VAR_ANF
const String comboAlarms PROGMEM = ""
  "{'v':'1','l':'Trigger 1','d':122683392},"
  "{'v':'2','l':'Trigger 2','d':122683393}," 
  "{'v':'3','l':'Trigger 3','d':122683394}," 
  "{'v':'4','l':'Trigger 4','d':122683395},"
  "{'v':'5','l':'Trigger 5','d':122683396},"
  "{'v':'6','l':'Trigger 6','d':122683397},"
  "{'v':'7','l':'Trigger 7','d':122683398},"
  "{'v':'8','l':'Trigger 8','d':122683399},"
  "{'v':'9','l':'Trigger 9','d':122683400},"
  "{'v':'10','l':'Trigger 10','d':122683401}";
//PY_VAR_END

const String paramSystem = "["
  "{"
    "'label':'Master/Slave',"
    "'type':"+String(HTML_SEPARATION)+","
  "},"
  "{"
    "'name':"+String(ID_PARAM_MASTER_SLAVE_TYP)+","
    "'label':'Master/Slave',"
    "'type':"+String(HTML_INPUTSELECT)+","
    "'options':["
      "{'v':'"+String(ID_I2C_MASTER)+"','l':'Master'},"
      "{'v':'"+String(I2C_DEV_ADDR_SLAVE1)+"','l':'Slave 0'},"
      "{'v':'"+String(I2C_DEV_ADDR_SLAVE2)+"','l':'Slave 1'}"
    "],"
    "'default':'0'"
  "},"

  "{"
    "'label':'WLAN',"
    "'type':"+String(HTML_SEPARATION)+","
  "},"
  "{"
  "'name':"+String(ID_PARAM_WLAN_SSID)+","
  "'label':'WLAN SSID',"
  "'type':"+String(HTML_INPUTTEXT)+","
  "'default':''"
  "},"
  "{"
  "'name':"+String(ID_PARAM_WLAN_PWD)+","
  "'label':'WLAN Passwort',"
  "'type':"+String(HTML_INPUTPASSWORD)+","
  "'default':''"
  "},"
  "{"
  "'name':"+String(ID_PARAM_WLAN_CONNECT_TIMEOUT)+","
  "'label':'WLAN connect Timeout',"
  "'type':"+String(HTML_INPUTNUMBER)+","
  "'unit':'s',"
  "'default':30,"
  "'min':0,"
  "'max':3600,"
  "'help':'Der Timeout gibt an, nach welcher Zeit ein Verbindungsversuch abgebrochen wird und ein Accesspoint erstellt wird.\n"
    "0 deaktiviert den Timeout.'"
  "},"
  "{"
  "'label':'MQTT',"
  "'type':"+String(HTML_SEPARATION)+""
  "},"
  "{"
  "'name':"+String(ID_PARAM_MQTT_SERVER_ENABLE)+","
  "'label':'MQTT enable',"
  "'type':"+String(HTML_INPUTCHECKBOX)+","
  "'default':0"
  "},"
  "{"
  "'name':"+String(ID_PARAM_MQTT_SERVER_IP)+","
  "'label':'MQTT Server IP',"
  "'type':"+String(HTML_INPUTTEXT)+","
  "'default':''"
  "},"
  "{"
  "'name':"+String(ID_PARAM_MQTT_SERVER_PORT)+","
  "'label':'MQTT Server Port',"
  "'type':"+String(HTML_INPUTNUMBER)+","
  "'default':1883,"
  "'min':1,"
  "'max':10000"
  "},"
  "{"
  "'name':"+String(ID_PARAM_MQTT_USERNAME)+","
  "'label':'Username',"
  "'type':"+String(HTML_INPUTTEXT)+","
  "'default':''"
  "},"
  "{"
  "'name':"+String(ID_PARAM_MQTT_PWD)+","
  "'label':'Passwort',"
  "'type':"+String(HTML_INPUTPASSWORD)+","
  "'default':''"
  "},"
  "{"
  "'name':"+String(ID_PARAM_MQTT_DEVICE_NAME)+","
  "'label':'MQTT Device Name',"
  "'type':"+String(HTML_INPUTTEXT)+","
  "'default':'bsc'"
  "},"

  "{"
    "'label':'Triggername',"
    "'type':"+String(HTML_SEPARATION)+","
  "},"
  "{"
  "'name':"+String(ID_PARAM_TRIGGER_NAMES)+","
  "'label':'Trigger',"
  "'type':"+String(HTML_INPUTTEXT)+","
  "'size':"+String(CNT_ALARMS)+","
  "'default':'',"
  "'flash':'1',"
  "'dt':"+String(PARAM_DT_ST)+""
  "}"

  "]";


const String paramBluetooth PROGMEM = "["
  "{"
    "'name':"+String(ID_PARAM_SS_BT)+","
    "'label':'Bluetooth',"
    "'label_entry':'BT Device',"
    "'groupsize':7,"
    "'type':"+String(HTML_OPTIONGROUP)+","
    "'group':["
    "{"
      "'name':"+String(ID_PARAM_SS_BTDEV)+","
      "'label':'Bluetooth',"
      "'type':"+String(HTML_INPUTSELECT)+","
      "'options':["
        "{'v':'"+String(ID_BT_DEVICE_NB)+"','l':'nicht belegt'},"
        "{'v':'"+String(ID_BT_DEVICE_NEEY4A)+"','l':'NEEY Balancer 4A'},"
        "{'v':'"+String(ID_BT_DEVICE_JKBMS_JK02)+"','l':'JK-BMS [Test]'},"
        "{'v':'"+String(ID_BT_DEVICE_JKBMS_JK02_32S)+"','l':'JK-BMS (32S) [Test]'}],"
        
      "'default':'0'"
    "},"
    "{"
      "'name':"+String(ID_PARAM_SS_BTDEVMAC)+","
      "'label':'MAC-Adresse',"
      "'type':"+String(HTML_INPUTTEXT)+","
      "'default':''"
    "}]"
  "}"
  "]";
  
 
const String paramSerial PROGMEM = "["
  "{"
    "'label':'Serielle Schnitstellen',"
    "'label_entry':'Serial',"
    "'groupsize':3,"
    "'type':"+String(HTML_OPTIONGROUP)+","
    "'group':["
      "{"
        "'name':"+String(ID_PARAM_SERIAL_CONNECT_DEVICE)+","
        "'label':'Serial',"
        "'type':"+String(HTML_INPUTSELECT)+","
        "'options':["
          "{'v':'"+String(ID_SERIAL_DEVICE_NB)+"','l':'nicht belegt'},"
          "{'v':'"+String(ID_SERIAL_DEVICE_JBDBMS)+"','l':'JBD BMS'},"
          "{'v':'"+String(ID_SERIAL_DEVICE_JKBMS)+"','l':'JK-BMS'},"
          "{'v':'"+String(ID_SERIAL_DEVICE_SEPLOSBMS)+"','l':'Seplos-BMS'}],"
        "'default':'"+String(ID_SERIAL_DEVICE_NB)+"'"
      "}"
    "]"
  "},"
  "{"
    "'label':'Seplos BMS',"
    "'type':"+String(HTML_SEPARATION)+","
  "},"
  "{"
    "'name':"+String(ID_PARAM_SERIAL_SEPLOS_CONNECT_TO_ID)+","
    "'label':'Abfrage IDs',"
    "'help':'Abgefragt werden alles Seplos von ID 0 bis zur hier eingestellten ID.\n"
      "Die Einstellung betrifft nur das Seplos BMS an der Serial 2.',"
    "'type':"+String(HTML_INPUTNUMBER)+","
    "'default':0,"
    "'min':0,"
    "'max':2"
  "}"
"]";


const String paramAlarmBms PROGMEM = "["
  "{"
    "'name':"+String(ID_PARAM_ALARM_BT)+","
    "'label':'BMS Alarmregeln',"
    "'label_entry':'Alarmregel',"
    "'groupsize':"+String(CNT_BT_ALARMS_RULES)+","
    "'type':"+String(HTML_OPTIONGROUP)+","
    "'group':["
      "{"
      "'name':"+String(ID_PARAM_ALARM_BTDEV_BMS_SELECT)+","
      "'label':'Zu &uuml;berwachendes BMS',"
      "'type':"+String(HTML_INPUTSELECT)+","
      "'options':["
        "{'v':'0','l':'Aus'},"
        "{'v':'1','l':'Bluetooth 0'},"
        "{'v':'2','l':'Bluetooth 1'},"
        "{'v':'3','l':'Bluetooth 2'},"
        "{'v':'4','l':'Bluetooth 3'},"
        "{'v':'5','l':'Bluetooth 4'},"
        "{'v':'6','l':'Bluetooth 5'},"
        "{'v':'7','l':'Bluetooth 6'},"
        "{'v':'8','l':'Serial 0'},"
        "{'v':'9','l':'Serial 1'},"
        "{'v':'10','l':'Serial 2'}"
        "],"
      "'default':0"
      "},"
      "{"
        "'label':'Keine Daten vom BMS',"
        "'type':"+String(HTML_SEPARATION)+","
      "},"
      "{"
      "'name':"+String(ID_PARAM_ALARM_BTDEV_ALARM_AKTION)+","
      "'label':'Aktion bei Trigger',"
      "'type':"+String(HTML_INPUTSELECT)+","
      "'options':["
        "{'v':'0','l':'Aus'},"
        +comboAlarms+
        "],"
      "'default':'0'"
      "},"
      "{"
        "'name':"+String(ID_PARAM_ALARM_BTDEV_ALARM_TIME_OUT)+","
        "'label':'Trigger keine Daten',"
        "'unit':'s',"
        "'type':"+String(HTML_INPUTNUMBER)+","
        "'default':15,"
        "'min':1,"
        "'max':255"
      "},"
      "{"
        "'label':'Spannungs&uuml;berwachung Zelle Min/Max',"
        "'type':"+String(HTML_SEPARATION)+","
      "},"
      "{"
      "'name':"+String(ID_PARAM_ALARM_BT_CELL_SPG_ALARM_AKTION)+","
      "'label':'Aktion bei Trigger',"
      "'type':"+String(HTML_INPUTSELECT)+","
      "'options':["
        "{'v':'0','l':'Aus'},"
        +comboAlarms+
        "],"
      "'default':'0'"
      "},"
      "{"
        "'name':"+String(ID_PARAM_ALARM_BT_CNT_CELL_CTRL)+","
        "'label':'Anzahl Zellen Monitoring',"
        "'type':"+String(HTML_INPUTNUMBER)+","
        "'default':16,"
        "'min':1,"
        "'max':24"
      "},"
      "{"
        "'name':"+String(ID_PARAM_ALARM_BT_CELL_SPG_MIN)+","
        "'label':'Zellspannung Min',"
        "'unit':'mV',"
        "'type':"+String(HTML_INPUTNUMBER)+","
        "'default':2500,"
        "'min':2000,"
        "'max':5000"
      "},"
      "{"
        "'name':"+String(ID_PARAM_ALARM_BT_CELL_SPG_MAX)+","
        "'label':'Zellspannung Max',"
        "'unit':'mV',"
        "'type':"+String(HTML_INPUTNUMBER)+","
        "'default':3650,"
        "'min':2000,"
        "'max':5000"
      "},"
      /*"{"
        "'name':"+String(ID_PARAM_ALARM_BT_CELL_SPG_MAX_HYSTERESE)+","
        "'label':'Hysterese',"
        "'unit':'mV',"
        "'type':"+String(HTML_INPUTNUMBER)+","
        "'default':20,"
        "'min':0,"
        "'max':255"
      "},"*/
      "{"
        "'label':'Spannungs&uuml;berwachung Gesamt Min/Max',"
        "'type':"+String(HTML_SEPARATION)+","
      "},"
      "{"
      "'name':"+String(ID_PARAM_ALARM_BT_GESAMT_SPG_ALARM_AKTION)+","
      "'label':'Aktion bei Trigger',"
      "'type':"+String(HTML_INPUTSELECT)+","
      "'options':["
        "{'v':'0','l':'Aus'},"
        +comboAlarms+
        "],"
      "'default':'0'"
      "},"
      "{"
        "'name':"+String(ID_PARAM_ALARM_BT_GESAMT_SPG_MIN)+","
        "'label':'Spannung Min',"
        "'unit':'V',"
        "'type':"+String(HTML_INPUTFLOAT)+","
        "'default':48.0,"
        "'min':0,"
        "'max':60"
      "},"
      "{"
        "'name':"+String(ID_PARAM_ALARM_BT_GESAMT_SPG_MAX)+","
        "'label':'Spannung Max',"
        "'unit':'V',"
        "'type':"+String(HTML_INPUTFLOAT)+","
        "'default':54.0,"
        "'min':0,"
        "'max':60"
      "}"
    "]"
  "}"
"]";


const String paramAlarmTemp PROGMEM = "["
  //Alarm bei Sensorfehler
  "{"
    "'label':'Alarm bei Sensorfehler',"
    "'type':"+String(HTML_SEPARATION)+","
  "},"
  "{"
    "'name':"+String(ID_PARAM_TEMP_SENSOR_TIMEOUT_TRIGGER)+","
    "'label':'Trigger',"
    "'type':"+String(HTML_INPUTSELECT)+","
    "'options':["
    "{'v':'0','l':'Aus'},"
    +comboAlarms+
    "],"
    "'default':'0'"
  "},"
  "{"
    "'name':"+String(ID_PARAM_TEMP_SENSOR_TIMEOUT_TIME)+","
    "'label':'Timeout',"
    "'unit':'s',"
    "'type':"+String(HTML_INPUTNUMBER)+","
    "'default':'5',"
    "'min':5,"
    "'max':240"
  "},"

  "{"
    "'label':'Temperatur &#220;berwachung',"
    "'type':"+String(HTML_SEPARATION)+","
  "},"
  "{"
    "'name':"+String(ID_PARAM_TEMP_ALARM)+","
    "'label':'Temperatur &#220;berwachung',"
    "'label_entry':'&#220;berwachung',"
    "'groupsize':"+String(COUNT_TEMP_RULES)+","
    "'type':"+String(HTML_OPTIONGROUP)+","
    "'group':["
      "{"
        "'name':"+String(ID_PARAM_TEMP_ALARM_SENSOR_VON)+","
        "'label':'Sensornummer von',"
        "'type':"+String(HTML_INPUTNUMBER)+","
        "'default':'',"
        "'min':0,"
        "'max':255"
      "},"
      "{"
        "'name':"+String(ID_PARAM_TEMP_ALARM_SENSOR_BIS)+","
        "'label':'Sensornummer bis',"
        "'type':"+String(HTML_INPUTNUMBER)+","
        "'default':'',"
        "'min':0,"
        "'max':255"
      "},"
      "{"
        "'name':"+String(ID_PARAM_TEMP_ALARM_UEBERWACH_FUNKTION)+","
        "'label':'&Uuml;berwachung',"
        "'type':"+String(HTML_INPUTSELECT)+","
        "'options':["
          "{'v':'"+String(ID_TEMP_ALARM_FUNKTION_NB)+"','l':'nicht belegt'},"
          "{'v':'"+String(ID_TEMP_ALARM_FUNKTION_MAXWERT)+"','l':'Maximalwert-&Uuml;berschreitung'},"
          "{'v':'"+String(ID_TEMP_ALARM_FUNKTION_MAXWERT_REFERENZ)+"','l':'Maximalwert-&Uuml;berschreitung (Referenz)'},"
          "{'v':'"+String(ID_TEMP_ALARM_FUNKTION_DIFFERENZ)+"','l':'Differenzwert-&Uuml;berwachung'}],"
        "'default':'"+String(ID_TEMP_ALARM_FUNKTION_NB)+"',"
        "'help':'Maximalwert-&Uuml;berschreitung: Wert1=Maximale Temperatur\n"
          "Maximalwert-&Uuml;berschreitung (Referenz): Wert1=Temperatur Offset'\n"
          "Differenzwert-&Uuml;berwachung: Wert1=Maximal erlaubte Differenz'"
      "},"
      "{"
        "'name':"+String(ID_PARAM_TEMP_ALARM_SENSOR_VERGLEICH)+","
        "'label':'Referenzsensor',"
        "'type':"+String(HTML_INPUTNUMBER)+","
        "'default':'',"
        "'min':0,"
        "'max':255"
      "},"
      "{"
        "'name':"+String(ID_PARAM_TEMP_ALARM_WERT1)+","
        "'label':'Wert 1',"
        "'type':"+String(HTML_INPUTFLOAT)+","
        "'default':'',"
        "'min':0,"
        "'max':70"
      "},"
      "{"
        "'name':"+String(ID_PARAM_TEMP_ALARM_WERT2)+","
        "'label':'Wert 2',"
        "'type':"+String(HTML_INPUTFLOAT)+","
        "'default':'',"
        "'min':0,"
        "'max':70"
      "},"
      "{"
      "'name':"+String(ID_PARAM_TEMP_ALARM_AKTION)+","
      "'label':'Ausl&ouml;sung',"
      "'type':"+String(HTML_INPUTSELECT)+","
      "'options':["
        "{'v':'0','l':'Aus'},"
        +comboAlarms+
        "],"
      "'default':'0'"
      "}"
    "]"
  "}"
"]";


//Digitalausgang 1..6
const String paramDigitalOut PROGMEM = "["
  "{"
    "'label':'Digitalausg&#228;nge',"
    "'label_entry':'Digitalausgang',"
    "'groupsize':6,"
    "'type':"+String(HTML_OPTIONGROUP)+","
    "'group':["
      "{"
      "'name':"+String(ID_PARAM_DO_AUSLOESEVERHALTEN)+","
      "'label':'Ausl&#246;severhalten',"
      "'type':"+String(HTML_INPUTSELECT)+","
      "'options':["
        "{'v':'0','l':'Permanent'},"
        "{'v':'1','l':'Impuls'}],"
      "'default':'0'"
      "},"
      "{"
        "'name':"+String(ID_PARAM_DO_IMPULSDAUER)+","
        "'label':'Impulsdauer',"
        "'unit':'ms',"
        "'type':"+String(HTML_INPUTNUMBER)+","
        "'default':500,"
        "'min':100,"
        "'max':10000"
      "},"
      "{"
        "'name':"+String(ID_PARAM_DO_VERZOEGERUNG)+","
        "'label':'Verz&ouml;gerung',"
        "'unit':'s',"
        "'type':"+String(HTML_INPUTNUMBER)+","
        "'default':0,"
        "'min':0,"
        "'max':254"
      "},"
      "{"
      "'name':"+String(ID_PARAM_DO_AUSLOESUNG_BEI)+","
      "'label':'Ausl&#246;sung bei',"
      "'type':"+String(HTML_INPUTSELECT)+","
      "'options':["
        "{'v':'0','l':'Aus'},"
        +comboAlarms+
        "],"
      "'default':'0'"
      "}"
    "]"
  "}"
"]";


//Digitaleingänge 1..4
const String paramDigitalIn PROGMEM = "["
  "{"
    "'label':'Digitaleing&#228;nge',"
    "'label_entry':'Digitaleingang',"
    "'groupsize':4,"
    "'type':"+String(HTML_OPTIONGROUP)+","
    "'group':["
      "{"
      "'name':"+String(ID_PARAM_DI_INVERTIERT)+","
      "'label':'Eingang invertieren',"
      "'type':"+String(HTML_INPUTCHECKBOX)+","
      "'default':'0'"
      "},"
      "{"
      "'name':"+String(ID_PARAM_DI_ALARM_NR)+","
      "'label':'Weiterleiten an',"
      "'type':"+String(HTML_INPUTSELECT)+","
      "'options':["
        "{'v':'0','l':'Aus'},"
        +comboAlarms+
        "],"
      "'default':'0'"
      "}"
    "]"
  "}"
"]";


const String paramOnewireAdr PROGMEM = "["
  "{"
  "'name':"+String(ID_PARAM_ONWIRE_ENABLE)+","
  "'label':'Onewire enable',"
  "'type':"+String(HTML_INPUTCHECKBOX)+","
  "'default':'0'"
  "},"
  "{"
  "'name':"+String(ID_PARAM_ONEWIRE_ADR)+","
  "'label':'OW Adr.',"
  "'type':"+String(HTML_INPUTTEXT)+","
  "'size':"+String(MAX_ANZAHL_OW_SENSOREN)+","
  "'default':''"
  "}"
  "]";


const String paramOnewire2 PROGMEM = "["
  "{"
    "'label':'Onewire Sensoren',"
    "'label_entry':'Sensor',"
    "'groupsize':"+String(MAX_ANZAHL_OW_SENSOREN)+","
    "'type':"+String(HTML_OPTIONGROUP)+","
    "'group':["
      "{"
        "'name':"+String(ID_PARAM_ONWIRE_TEMP_OFFSET)+","
        "'label':'Offset',"
        "'unit':'&deg;C',"
        "'type':"+String(HTML_INPUTFLOAT)+","
        "'default':0,"
        "'min':-10,"
        "'max':10"
      "}"
    "]"
  "}"
"]";


//BMS to Inverter
const String paramBmsToInverter PROGMEM = "["
  "{"
    "'name':"+String(ID_PARAM_BMS_CAN_ENABLE)+","
    "'label':'BMS Canbus enable',"
    "'type':"+String(HTML_INPUTCHECKBOX)+","
    "'default':'0'"
  "},"
  "{"
    "'name':"+String(ID_PARAM_SS_CAN)+","
    "'label':'Canbus',"
    "'type':"+String(HTML_INPUTSELECT)+","
    "'options':["
      "{'v':'"+String(ID_CAN_DEVICE_NB)+"','l':'nicht belegt'},"
      "{'v':'"+String(ID_CAN_DEVICE_SOLISRHI)+"','l':'Solis RHI'},"
      "{'v':'"+String(ID_CAN_DEVICE_DEYE)+"','l':'DEYE'},"
      "{'v':'"+String(ID_CAN_DEVICE_VICTRON)+"','l':'VICTRON'}],"
    "'default':'nb'"
  "},"
  "{"
  "'name':"+String(ID_PARAM_BMS_CAN_DATASOURCE)+","
  "'label':'Datenquelle (Master)',"
  "'type':"+String(HTML_INPUTSELECT)+","
  "'options':["
    "{'v':'0','l':'Bluetooth Device 0'},"
    "{'v':'1','l':'Bluetooth Device 1'},"
    "{'v':'2','l':'Bluetooth Device 2'},"
    "{'v':'3','l':'Bluetooth Device 3'},"
    "{'v':'4','l':'Bluetooth Device 4'},"
    "{'v':'5','l':'Bluetooth Device 5'},"
    "{'v':'6','l':'Bluetooth Device 6'},"
    "{'v':'7','l':'Serial Device 0'},"
    "{'v':'8','l':'Serial Device 1'},"
    "{'v':'9','l':'Serial Device 2'}],"
  "'default':'0'"
  "},"
  "{"
    "'name':"+String(ID_PARAM_BMS_CAN_DATASOURCE_SS1)+","
    "'label':'\+ Datenquelle Serial 0',"
    "'type':"+String(HTML_INPUTCHECKBOX)+","
    "'default':'0'"
  "},"
  "{"
    "'name':"+String(ID_PARAM_BMS_CAN_DATASOURCE_SS2)+","
    "'label':'\+ Datenquelle Serial 1',"
    "'type':"+String(HTML_INPUTCHECKBOX)+","
    "'default':'0'"
  "},"
  "{"
    "'name':"+String(ID_PARAM_BMS_CAN_DATASOURCE_SS3)+","
    "'label':'\+ Datenquelle Serial 2',"
    "'type':"+String(HTML_INPUTCHECKBOX)+","
    "'default':'0'"
  "},"

  //Multi-BMS Settings
  "{"
    "'label':'Valuehandling Multi-BMS',"
    "'type':"+String(HTML_SEPARATION)+","
  "},"
  "{"
    "'name':"+String(ID_PARAM_INVERTER_MULTI_BMS_VALUE_SOC)+","
    "'label':'SoC',"
    "'type':"+String(HTML_INPUTSELECT)+","
    "'options':["
      "{'v':'0','l':'AUS'},"
      "{'v':"+String(OPTION_MULTI_BMS_SOC_AVG)+",'l':'SoC Mittelwert'},"
      "{'v':"+String(OPTION_MULTI_BMS_SOC_MAX)+",'l':'SoC Maximalwert'}],"
    "'default':'0'"
  "},"
  /*",{"
  "'name':"+String(ID_PARAM_INVERTER_MULTI_BMS_VALUE_HANDLING)+","
  "'label':'Valuehandling Multi-BMS',"
  "'type':"+String(HTML_INPUTMULTICHECK)+","
  "'options':["
  "{'v':'0','l':'SoC Mittelwert'},"
  "{'v':'1','l':'Test2'},"
  "{'v':'2','l':'Test3'}],"
  "'default':0"
  "}"*/

  "{"
    "'label':'Basisdaten',"
    "'type':"+String(HTML_SEPARATION)+","
  "},"
  "{"
    "'name':"+String(ID_PARAM_BMS_MAX_CHARGE_SPG)+","
    "'label':'Max. Ladespannung',"
    "'unit':'V',"
    "'type':"+String(HTML_INPUTFLOAT)+","
    "'default':'54.4',"
    "'min':40.0,"
    "'max':58.4"
  "},"
  "{"
    "'name':"+String(ID_PARAM_BMS_MAX_CHARGE_CURRENT)+","
    "'label':'Max. Ladestrom',"
    "'unit':'A',"
    "'type':"+String(HTML_INPUTNUMBER)+","
    "'default':'100',"
    "'min':0,"
    "'max':200"
  "},"
  "{"
    "'name':"+String(ID_PARAM_BMS_MAX_DISCHARGE_CURRENT)+","
    "'label':'Max. Entladestrom',"
    "'unit':'A',"
    "'type':"+String(HTML_INPUTNUMBER)+","
    "'default':'100',"
    "'min':0,"
    "'max':200"
  "},"
  "{"
    "'name':"+String(ID_PARAM_BMS_LADELEISTUNG_AUF_NULL)+","
    "'label':'Ladeleistung auf 0 bei:',"
    "'type':"+String(HTML_INPUTSELECT)+","
    "'options':["
      "{'v':'0','l':'AUS'},"
      +comboAlarms+
      "],"
    "'default':'0'"
  "},"
  "{"
    "'name':"+String(ID_PARAM_BMS_ENTLADELEISTUNG_AUF_NULL)+","
    "'label':'Entladeleistung auf 0 bei:',"
    "'type':"+String(HTML_INPUTSELECT)+","
    "'options':["
      "{'v':'0','l':'AUS'},"
      +comboAlarms+
      "],"
    "'default':'0'"
  "},"
  "{"
    "'name':"+String(ID_PARAM_BMS_SOC_AUF_FULL)+","
    "'label':'SOC auf 100 bei:',"
    "'type':"+String(HTML_INPUTSELECT)+","
    "'options':["
      "{'v':'0','l':'AUS'},"
      +comboAlarms+
      "],"
    "'default':'0'"
  "},"

//Alarm über Trigger
  "{"
    "'label':'Alarme (Inverter)',"
    "'type':"+String(HTML_SEPARATION)+","
  "},"
  "{"
    "'name':"+String(ID_PARAM_BMS_ALARM_HIGH_BAT_VOLTAGE)+","
    "'label':'High battery voltage',"
    "'type':"+String(HTML_INPUTSELECT)+","
    "'options':["
      "{'v':'0','l':'AUS'},"
      +comboAlarms+
      "],"
    "'default':'0'"
  "},"
  "{"
    "'name':"+String(ID_PARAM_BMS_ALARM_LOW_BAT_VOLTAGE)+","
    "'label':'Low battery voltage',"
    "'type':"+String(HTML_INPUTSELECT)+","
    "'options':["
      "{'v':'0','l':'AUS'},"
      +comboAlarms+
      "],"
    "'default':'0'"
  "},"
  "{"
    "'name':"+String(ID_PARAM_BMS_ALARM_HIGH_TEMPERATURE)+","
    "'label':'High Temperature',"
    "'type':"+String(HTML_INPUTSELECT)+","
    "'options':["
      "{'v':'0','l':'AUS'},"
      +comboAlarms+
      "],"
    "'default':'0'"
  "},"
  "{"
    "'name':"+String(ID_PARAM_BMS_ALARM_LOWTEMPERATURE)+","
    "'label':'Low Temperature',"
    "'type':"+String(HTML_INPUTSELECT)+","
    "'options':["
      "{'v':'0','l':'AUS'},"
      +comboAlarms+
      "],"
    "'default':'0'"
  "},"

  "{"
    "'label':'Batterietemperatur',"
    "'type':"+String(HTML_SEPARATION)+","
  "},"
  "{"
    "'name':"+String(ID_PARAM_INVERTER_BATT_TEMP_QUELLE)+","
    "'label':'Quelle',"
    "'type':"+String(HTML_INPUTSELECT)+","
    "'options':["
      "{'v':'1','l':'BMS'},"
      "{'v':'2','l':'Onewire'}"
      "],"
    "'default':'1'"
  "},"
  "{"
    "'name':"+String(ID_PARAM_INVERTER_BATT_TEMP_SENSOR)+","
    "'label':'Sensornummer',"
    "'type':"+String(HTML_INPUTNUMBER)+","
    "'default':'0',"
    "'min':0,"
    "'max':64,"
    "'help':'Mögliche Wert:\nBMS:0-2\nOnewire:0-63'"
  "},"

  "{"
    "'label':'Zell-Spannungsabhängige Drosselung',"
    "'type':"+String(HTML_SEPARATION)+","
  "},"
  "{"
    "'name':"+String(ID_PARAM_INVERTER_LADESTROM_REDUZIEREN_ZELLSPG_EN)+","
    "'label':'Ein/Aus',"
    "'type':"+String(HTML_INPUTCHECKBOX)+","
    "'default':'0'"
  "},"
  "{"
    "'name':"+String(ID_PARAM_INVERTER_LADESTROM_REDUZIEREN_ZELLSPG_STARTSPG)+","
    "'label':'Starten bei Zellspg. gr&ouml;ßer',"
    "'unit':'mV',"
    "'type':"+String(HTML_INPUTNUMBER)+","
    "'default':'3325',"
    "'min':2500,"
    "'max':5000"
  "},"
  "{"
    "'name':"+String(ID_PARAM_INVERTER_LADESTROM_REDUZIEREN_ZELLSPG_ENDSPG)+","
    "'label':'Maximale Zellspannung',"
    "'unit':'mV',"
    "'type':"+String(HTML_INPUTNUMBER)+","
    "'default':'3300',"
    "'min':2500,"
    "'max':5000"
  "},"
  "{"
    "'name':"+String(ID_PARAM_INVERTER_LADESTROM_REDUZIEREN_ZELLSPG_MINDEST_STROM)+","
    "'label':'Mindest Ladestrom',"
    "'unit':'A',"
    "'type':"+String(HTML_INPUTNUMBER)+","
    "'default':'5',"
    "'min':0,"
    "'max':200"
  "},"
  "{"
    "'label':'Ladestrom reduzieren bei Zelldrift',"
    "'type':"+String(HTML_SEPARATION)+","
  "},"
  "{"
    "'name':"+String(ID_PARAM_INVERTER_LADESTROM_REDUZIEREN_ZELLDRIFT_EN)+","
    "'label':'Ein/Aus',"
    "'type':"+String(HTML_INPUTCHECKBOX)+","
    "'default':'0'"
  "},"
  "{"
    "'name':"+String(ID_PARAM_INVERTER_LADESTROM_REDUZIEREN_STARTSPG_ZELLE)+","
    "'label':'Starten bei Zellspg. gr&ouml;ßer',"
    "'unit':'mV',"
    "'type':"+String(HTML_INPUTNUMBER)+","
    "'default':'3400',"
    "'min':2500,"
    "'max':5000"
  "},"
  "{"
    "'name':"+String(ID_PARAM_INVERTER_LADESTROM_REDUZIEREN_STARTABWEICHUNG)+","
    "'label':'Starten bei Drift gr&ouml;ßer',"
    "'unit':'mV',"
    "'type':"+String(HTML_INPUTNUMBER)+","
    "'default':'10',"
    "'min':1,"
    "'max':200"
  "},"
  "{"
    "'name':"+String(ID_PARAM_INVERTER_LADESTROM_REDUZIEREN_A_PRO_MV)+","
    "'label':'Reduzierung pro mV Abweichung',"
    "'unit':'A',"
    "'type':"+String(HTML_INPUTNUMBER)+","
    "'default':'1',"
    "'min':1,"
    "'max':200"
  "},"

  //Ladestrom reduzieren ab bestimmten SoC
  "{"
    "'label':'Ladesstrom reduzieren - SoC',"
    "'type':"+String(HTML_SEPARATION)+","
  "},"
  "{"
    "'name':"+String(ID_PARAM_INVERTER_LADESTROM_REDUZIEREN_SOC_EN)+","
    "'label':'Ein/Aus',"
    "'type':"+String(HTML_INPUTCHECKBOX)+","
    "'default':'0'"
  "},"
  "{"
    "'name':"+String(ID_PARAM_INVERTER_LADESTROM_REDUZIEREN_AB_SOC)+","
    "'label':'Reduzierung ab SoC',"
    "'unit':'%',"
    "'type':"+String(HTML_INPUTNUMBER)+","
    "'default':'98',"
    "'min':1,"
    "'max':99"
  "},"
  "{"
    "'name':"+String(ID_PARAM_INVERTER_LADESTROM_REDUZIEREN_A_PRO_PERCENT_SOC)+","
    "'label':'Pro 1% um x A reduzieren',"
    "'unit':'A',"
    "'type':"+String(HTML_INPUTNUMBER)+","
    "'default':'48',"
    "'min':1,"
    "'max':100"
  "},"  

  //Bei unterschreiten von Zellspannung melde SoC x% 
  "{"
    "'label':'SoC beim Unterschreiten der Zellspannung',"
    "'type':"+String(HTML_SEPARATION)+","
    "'help':'Wenn die eingestellte Zellspannung für den Ladebeginn unterschritten wird, dann kann durch das senden eines beliebigen SoC an den Wechselrichter ein Nachladen veranlasst werden.\n"
      "Es wird so lange nachgeladen, bis die Zellspannung Ladeende überschritten wird.'"
  "},"
  "{"
    "'name':"+String(ID_PARAM_INVERTER_SOC_BELOW_ZELLSPANNUNG_EN)+","
    "'label':'Ein/Aus',"
    "'type':"+String(HTML_INPUTCHECKBOX)+","
    "'default':'0'"
  "},"
  "{"
    "'name':"+String(ID_PARAM_INVERTER_SOC_BELOW_ZELLSPANNUNG_SPG)+","
    "'label':'Zellspannung Ladebeginn',"
    "'unit':'mV',"
    "'type':"+String(HTML_INPUTNUMBER)+","
    "'default':'3000',"
    "'min':2500,"
    "'max':4000"
  "},"
  "{"
    "'name':"+String(ID_PARAM_INVERTER_SOC_BELOW_ZELLSPANNUNG_SPG_END)+","
    "'label':'Zellspannung Ladeende',"
    "'unit':'mV',"
    "'type':"+String(HTML_INPUTNUMBER)+","
    "'default':'0',"
    "'min':0,"
    "'max':4000,"
    "'help':'Wenn Zellspannung Ladeende 0, dann wird geladen, bis die Zellspannung Ladebeginn wieder überschritten wird.'"
  "},"
  "{"
    "'name':"+String(ID_PARAM_INVERTER_SOC_BELOW_ZELLSPANNUNG_SOC)+","
    "'label':'SoC',"
    "'unit':'%',"
    "'type':"+String(HTML_INPUTNUMBER)+","
    "'default':'9',"
    "'min':1,"
    "'max':100"
  "},"  
  "{"
    "'name':"+String(ID_PARAM_INVERTER_SOC_BELOW_ZELLSPANNUNG_TIME)+","
    "'label':'Sperrzeit zwischen zwei Nachladungen',"
    "'unit':'s',"
    "'type':"+String(HTML_INPUTNUMBER)+","
    "'default':'600',"
    "'min':0,"
    "'max':3600"
  "}," 

  /* Wenn eine Zelle z.B. >3.4V ist und das Delta zwischen größter und kleinster größer als z.B. 5mV ist, 
  dann Ladespannung reduzieren. */
  "{"
    "'label':'Dynamische Ladespannungsbegrenzung (Beta!)',"
    "'type':"+String(HTML_SEPARATION)+","
    "'help':'Sobald die Spannung einer Zelle und das Delta zwischen der niedrigsten und der höchsten Zellenspannung größer als eingestellt werden, "
      "wird die Ladespannung dynamisch angepasst, um die maximale Ladeleistung zu erreichen, ohne dass die Zellen weiter auseinander driften.'"
  "},"
  "{"
    "'name':"+String(ID_PARAM_INVERTER_CHARGE_VOLTAGE_DYNAMIC_REDUCE_EN)+","
    "'label':'Ein/Aus',"
    "'type':"+String(HTML_INPUTCHECKBOX)+","
    "'default':'0'"
  "},"
  "{"
    "'name':"+String(ID_PARAM_INVERTER_CHARGE_VOLTAGE_DYNAMIC_REDUCE_ZELLSPG)+","
    "'label':'Start-Zellspannung',"
    "'unit':'mV',"
    "'type':"+String(HTML_INPUTNUMBER)+","
    "'default':'3400',"
    "'min':2000,"
    "'max':4000"
  "},"
  "{"
    "'name':"+String(ID_PARAM_INVERTER_CHARGE_VOLTAGE_DYNAMIC_REDUCE_DELTA)+","
    "'label':'Spg.-Delta Min/Max',"
    "'unit':'mV',"
    "'type':"+String(HTML_INPUTNUMBER)+","
    "'default':'5',"
    "'min':1,"
    "'max':100"
  "},"

//Sperrzeit einstellbar
  "{"
    "'label':'Sonstiges',"
    "'type':"+String(HTML_SEPARATION)+","
  "},"
  "{"
    "'name':"+String(ID_PARAM_INVERTER_LADESTROM_SPERRZEIT)+","
    "'label':'Sperrzeit wenn Ladestrom 0',"
    "'unit':'s',"
    "'type':"+String(HTML_INPUTNUMBER)+","
    "'default':'1800',"
    "'min':0,"
    "'max':65000"
  "}"
  "]";


const String paramDeviceNeeyBalancer PROGMEM = "["
  "{"
    "'label':'NEEY Active Balancer',"
    "'label_entry':'NEEY',"
    "'groupsize':7,"
    "'type':"+String(HTML_OPTIONGROUP)+","
    "'group':["
    "{"
      "'name':"+String(ID_PARAM_NEEY_CELLS)+","
      "'label':'Cells',"
      "'type':"+String(HTML_INPUTNUMBER)+","
      "'default':16,"
      "'min':4,"
      "'max':24,"
      "'flash':'1',"
      "'dt':"+String(PARAM_DT_U8)+""
    "},"
    "{"
      "'name':"+String(ID_PARAM_NEEY_START_VOLTAGE)+","
      "'label':'Start Voltage',"
      "'type':"+String(HTML_INPUTFLOAT)+","
      "'default':0.005,"
      "'min':0,"
      "'max':1,"
      "'unit':'V',"
      "'step':'0.001',"
      "'flash':'1',"
      "'dt':"+String(PARAM_DT_FL)+""
    "},"
    "{"
      "'name':"+String(ID_PARAM_NEEY_MAX_BALANCE_CURRENT)+","
      "'label':'Max. Balance Current',"
      "'type':"+String(HTML_INPUTFLOAT)+","
      "'default':4.0,"
      "'min':0.1,"
      "'max':4,"
      "'unit':'A',"
      "'step':'0.01',"
      "'flash':'1',"
      "'dt':"+String(PARAM_DT_FL)+""
    "},"
    "{"
      "'name':"+String(ID_PARAM_NEEY_SLEEP_VOLTAGE)+","
      "'label':'Sleep Voltage',"
      "'type':"+String(HTML_INPUTFLOAT)+","
      "'default':3.30,"
      "'min':1,"
      "'max':5,"
      "'unit':'V',"
      "'step':'0.001',"
      "'flash':'1',"
      "'dt':"+String(PARAM_DT_FL)+""
    "},"
    "{"
      "'name':"+String(ID_PARAM_NEEY_EQUALIZATION_VOLTAGE)+","
      "'label':'Equalization Voltage',"
      "'type':"+String(HTML_INPUTFLOAT)+","
      "'default':3.31,"
      "'min':1,"
      "'max':5,"
      "'unit':'V',"
      "'step':'0.001',"
      "'flash':'1',"
      "'dt':"+String(PARAM_DT_FL)+""
    "},"
    "{"
      "'name':"+String(ID_PARAM_NEEY_BAT_CAPACITY)+","
      "'label':'Bat. Capacity',"
      "'type':"+String(HTML_INPUTNUMBER)+","
      "'default':200,"
      "'min':1,"
      "'max':500,"
      "'unit':'Ah',"
      "'flash':'1',"
      "'dt':"+String(PARAM_DT_U16)+""
    "},"
    "{"
      "'name':"+String(ID_PARAM_NEEY_BAT_TYPE)+","
      "'label':'BatType',"
      "'type':"+String(HTML_INPUTSELECT)+","
      "'options':["
        "{'v':'1','l':'NCM'},"
        "{'v':'2','l':'LFP'},"
        "{'v':'3','l':'LTO'},"
        "{'v':'4','l':'PbAc'}],"
      "'default':'2',"
      "'flash':'1',"
      "'dt':"+String(PARAM_DT_U8)+""
    "},"
    //Buzzer mode (Shut)
    
    "{"
      "'name':"+String(ID_PARAM_NEEY_BALANCER_ON)+","
      "'label':'Balancer On',"
      "'type':"+String(HTML_INPUTSELECT)+","
      "'options':["
        "{'v':'0','l':'Aus'},"
        "{'v':'110','l':'Ein'},"
        +comboAlarms+
        "],"
      "'default':'0',"
      "'flash':'1',"
      "'dt':"+String(PARAM_DT_U8)+""
    "}"
    "]"
  "}"
  "]";
  
