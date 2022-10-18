// Copyright (c) 2022 tobias
// 
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#include "defines.h"

/*
   utf8     Html
ä: &#228;   &auml;
Ä: &#196;   &Auml;
ö: &#246;   
Ö: &#214;   
ü: &#252;   
Ü: &#220;   
*/

const String comboAlarms PROGMEM = ""
  "{'v':'1','l':'Alarm 1'},"
  "{'v':'2','l':'Alarm 2'},"
  "{'v':'3','l':'Alarm 3'},"
  "{'v':'4','l':'Alarm 4'},"
  "{'v':'5','l':'Alarm 5'},"
  "{'v':'6','l':'Alarm 6'},"
  "{'v':'7','l':'Alarm 7'},"
  "{'v':'8','l':'Alarm 8'},"
  "{'v':'9','l':'Alarm 9'},"
  "{'v':'10','l':'Alarm 10'}";


const String paramSystem PROGMEM = "["
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
  "'name':"+String(ID_PARAM_MQTT_SERVER_ENABLE)+","
  "'label':'MQTT enable',"
  "'type':"+String(HTML_INPUTCHECKBOX)+","
  "'default':'0'"
  "},"
  "{"
  "'name':"+String(ID_PARAM_MQTT_DEVICE_NAME)+","
  "'label':'MQTT Device Name',"
  "'type':"+String(HTML_INPUTTEXT)+","
  "'default':'bsc'"
  "}"
  "]";


const String paramBluetooth PROGMEM = "["
  "{"
    "'name':"+String(ID_PARAM_SS_BT)+","
    "'label':'Bluetooth',"
    "'label_entry':'BT Device',"
    "'groupsize':5,"
    "'type':"+String(HTML_OPTIONGROUP)+","
    "'group':["
    "{"
      "'name':"+String(ID_PARAM_SS_BTDEV)+","
      "'label':'Bluetooth',"
      "'type':"+String(HTML_INPUTSELECT)+","
      "'options':["
        "{'v':'"+String(ID_BT_DEVICE_NB)+"','l':'nicht belegt'},"
        "{'v':'"+String(ID_BT_DEVICE_NEEY4A)+"','l':'NEEY Balancer 4A'}],"
      "'default':'nb'"
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
          "{'v':'"+String(ID_SERIAL_DEVICE_JBDBMS)+"','l':'JBD BMS (IN)'}],"
        "'default':'"+String(ID_SERIAL_DEVICE_NB)+"'"
      "}"
    "]"
  "}"
"]";


const String paramAlarmBms PROGMEM = "["
  "{"
    "'name':"+String(ID_PARAM_ALARM_BT)+","
    "'label':'Bluetooth und serielle Devices',"
    "'label_entry':'BMS',"
    "'groupsize':8,"
    "'type':"+String(HTML_OPTIONGROUP)+","
    "'group':["
      "{"
        "'label':'Keine Daten vom BMS',"
        "'type':"+String(HTML_SEPARATION)+","
      "},"
      "{"
        "'name':"+String(ID_PARAM_ALARM_BTDEV_ALARM_ON)+","
        "'label':'Alarm keine Daten',"
        "'type':"+String(HTML_INPUTCHECKBOX)+","
        "'default':'0'"
      "},"
      "{"
      "'name':"+String(ID_PARAM_ALARM_BTDEV_ALARM_AKTION)+","
      "'label':'Aktion bei Alarm',"
      "'type':"+String(HTML_INPUTSELECT)+","
      "'options':["
        +comboAlarms+
        "],"
      "'default':'0'"
      "},"
      "{"
        "'name':"+String(ID_PARAM_ALARM_BTDEV_ALARM_TIME_OUT)+","
        "'label':'Alarm keine Daten',"
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
        "'name':"+String(ID_PARAM_ALARM_BT_CELL_SPG_ALARM_ON)+","
        "'label':'Spg.-&#220;berwachung',"
        "'type':"+String(HTML_INPUTCHECKBOX)+","
        "'default':'0'"
      "},"
      "{"
      "'name':"+String(ID_PARAM_ALARM_BT_CELL_SPG_ALARM_AKTION)+","
      "'label':'Aktion bei Alarm',"
      "'type':"+String(HTML_INPUTSELECT)+","
      "'options':["
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
      "'label':'Aktion bei Alarm',"
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
  "{"
    "'name':"+String(ID_PARAM_TEMP_ALARM)+","
    "'label':'Temperatur &#220;berwachung,"
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
        +comboAlarms+
        "],"
      "'default':'0'"
      "}"
    "]"
  "}"
"]";


//Digitalausgang 1..7
const String paramDigitalOut PROGMEM = "["
  "{"
    "'label':'Digitalausg&#228;nge',"
    "'label_entry':'Digitalausgang',"
    "'groupsize':7,"
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
      "{'v':'"+String(ID_CAN_DEVICE_SOLISRHI)+"','l':'Solis RHI'}],"
    "'default':'nb'"
  "},"
  "{"
  "'name':"+String(ID_PARAM_BMS_CAN_DATASOURCE)+","
  "'label':'Datenquelle',"
  "'type':"+String(HTML_INPUTSELECT)+","
  "'options':["
    "{'v':'0','l':'Bluetooth Device 1'},"
    "{'v':'1','l':'Bluetooth Device 2'},"
    "{'v':'2','l':'Bluetooth Device 3'},"
    "{'v':'3','l':'Bluetooth Device 4'},"
    "{'v':'4','l':'Bluetooth Device 5'},"
    "{'v':'5','l':'Serial Device 1'},"
    "{'v':'6','l':'Serial Device 2'},"
    "{'v':'7','l':'Serial Device 3'}],"
  "'default':'0'"
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

