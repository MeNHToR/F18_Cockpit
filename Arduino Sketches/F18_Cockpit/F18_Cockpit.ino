/*
  Tell DCS-BIOS to use a serial connection and use interrupt-driven
  communication. The main program will be interrupted to prioritize
  processing incoming data.
  
  This should work on any Arduino that has an ATMega328 controller
  (Uno, Pro Mini, many others).
 */
#define DCSBIOS_IRQ_SERIAL

#include "DcsBios.h"
#include "Arduino.h"
#include "PCF8575.h"



// Set i2c address
PCF8575 pcf8575_1(0x20);
PCF8575 pcf8575_2(0x22);
unsigned long timeElapsed;

/* paste code snippets from the reference documentation here */

//DcsBios::RotaryEncoder comIlsChannelSw("COM_ILS_CHANNEL_SW", "DEC", "INC", 6, 7);

void setup() {
  DcsBios::setup();

  //Serial.begin(115200);
  //Serial.begin(9600);

  pcf8575_1.pinMode(P0, INPUT);
  pcf8575_1.pinMode(P1, INPUT);
  pcf8575_1.pinMode(P2, INPUT);
  pcf8575_1.pinMode(P3, INPUT);
  pcf8575_1.pinMode(P4, INPUT);
  pcf8575_1.pinMode(P5, INPUT);
  pcf8575_1.pinMode(P6, INPUT);
  pcf8575_1.pinMode(P7, INPUT);
  pcf8575_1.pinMode(P8, INPUT);
  pcf8575_1.pinMode(P9, INPUT);
  pcf8575_1.pinMode(P10, INPUT);
  pcf8575_1.pinMode(P11, INPUT);
  pcf8575_1.pinMode(P12, INPUT);
  pcf8575_1.pinMode(P13, INPUT);
  pcf8575_1.pinMode(P14, INPUT);
  pcf8575_1.pinMode(P15, INPUT);

  pcf8575_2.pinMode(P0, INPUT);
  pcf8575_2.pinMode(P1, INPUT);
  pcf8575_2.pinMode(P2, INPUT);
  pcf8575_2.pinMode(P3, INPUT);
  pcf8575_2.pinMode(P4, INPUT);
  pcf8575_2.pinMode(P5, INPUT);
  pcf8575_2.pinMode(P6, INPUT);
  pcf8575_2.pinMode(P7, INPUT);
  pcf8575_2.pinMode(P8, INPUT);
  pcf8575_2.pinMode(P9, INPUT);
  pcf8575_2.pinMode(P10, INPUT);
  pcf8575_2.pinMode(P11, INPUT);
  pcf8575_2.pinMode(P12, INPUT);
  pcf8575_2.pinMode(P13, INPUT);
  pcf8575_2.pinMode(P14, INPUT);
  pcf8575_2.pinMode(P15, INPUT);

  pcf8575_1.begin();
  pcf8575_2.begin();
}

void loop() {
  DcsBios::loop();


  //sendDcsBiosMessage("PORT_RAD_FLAP","0");

  uint8_t comCommRelaySw_Cipher = pcf8575_1.digitalRead(P0);
  //if (comCommRelaySw_Cipher==HIGH) Serial.println("Comm Relay Switch, CIPHER");
  if (comCommRelaySw_Cipher==HIGH) sendDcsBiosMessage("COM_COMM_RELAY_SW","0");
  

  // uint8_t comCommRelaySw_Plain = pcf8575_1.digitalRead(P1);
  // if (comCommRelaySw_Plain==HIGH) Serial.println("Comm Relay Switch, PLAIN");
  
  // uint8_t comm1AntSelectSw_Upper = pcf8575_1.digitalRead(P2);
  // if (comm1AntSelectSw_Upper==HIGH) Serial.println("COMM 1 Antenna Selector Switch, UPPER");
  
  // uint8_t comm1AntSelectSw_Lower = pcf8575_1.digitalRead(P3);
  // if (comm1AntSelectSw_Lower==HIGH) Serial.println("COMM 1 Antenna Selector Switch, LOWER");

  // uint8_t hydIsolateOverrideSw_Oride = pcf8575_1.digitalRead(P4);
  // if (hydIsolateOverrideSw_Oride==HIGH) Serial.println("Hydraulic Isolate Override Switch, NORM");

  // uint8_t obogsSw_On = pcf8575_1.digitalRead(P5);
  // if (obogsSw_On==HIGH) Serial.println("OBOGS Control Switch, ON");

  // uint8_t mcSw_2off = pcf8575_1.digitalRead(P6);
  // if (mcSw_2off==HIGH) Serial.println("MC Switch, 2 OFF");

  // uint8_t mcSw_1off = pcf8575_1.digitalRead(P7);
  // if (mcSw_1off==HIGH) Serial.println("MC Switch, 1 OFF");

  // uint8_t comCryptoSw_Hold = pcf8575_1.digitalRead(P8);
  // if (comCryptoSw_Hold==HIGH) Serial.println("CRYPTO Switch, HOLD");

  // uint8_t comCryptoSw_Zero = pcf8575_1.digitalRead(P9);
  // if (comCryptoSw_Zero==HIGH) Serial.println("CRYPTO Switch, ZERO");

  // uint8_t comIffMode4Sw_DisAud = pcf8575_1.digitalRead(P10);
  // if (comIffMode4Sw_DisAud==HIGH) Serial.println("IFF Mode 4 Switch, DIS/AUD");

  // uint8_t comIffMode4Sw_Off = pcf8575_1.digitalRead(P11);
  // if (comIffMode4Sw_Off==HIGH) Serial.println("IFF Mode 4 Switch, Off");

  // uint8_t comIffMasterSw_Emer = pcf8575_1.digitalRead(P12);
  // if (comIffMasterSw_Emer==HIGH) Serial.println("IFF Master Switch, EMER");

  // uint8_t comIlsUfcManSw_Ufc = pcf8575_1.digitalRead(P13);
  // if (comIlsUfcManSw_Ufc==HIGH) Serial.println("ILS UFC/MAN Switch, UFC");

  // uint8_t comCommGXmtSw_Comm2 = pcf8575_1.digitalRead(P14);
  // if (comCommGXmtSw_Comm2==HIGH) Serial.println("COMM G XMT Switch, COMM 2");

  // uint8_t comCommGXmtSw_Comm1 = pcf8575_1.digitalRead(P15);
  // if (comCommGXmtSw_Comm1==HIGH) Serial.println("COMM G XMT Switch, COMM 1");
  




  // uint8_t probeSw_EmergExtd = pcf8575_2.digitalRead(P0);
  // if (probeSw_EmergExtd==HIGH) Serial.println("Probe Control Switch, EMERG EXTD");
  
  // uint8_t probeSw_Extend = pcf8575_2.digitalRead(P1);
  // if (probeSw_Extend==HIGH) Serial.println("Probe Control Switch, EXTEND");

  // uint8_t toTrimBtn_On = pcf8575_2.digitalRead(P2);
  // if (toTrimBtn_On==HIGH) Serial.println("T/O TRIM Button");
  
  // uint8_t apuControlSw_On = pcf8575_2.digitalRead(P3);
  // if (apuControlSw_On==HIGH) Serial.println("APU Control Switch, ON");

  // uint8_t engineCrankSw_Right = pcf8575_2.digitalRead(P4);
  // if (engineCrankSw_Right==HIGH) Serial.println("Engine Crank Switch, RIGHT");

  // uint8_t engineCrankSw_Left = pcf8575_2.digitalRead(P5);
  // if (engineCrankSw_Left==HIGH) Serial.println("Engine Crank Switch, LEFT");

  // uint8_t iffAntSelectSw_Lower = pcf8575_2.digitalRead(P6);
  // if (iffAntSelectSw_Lower==HIGH) Serial.println("IFF Antenna Selector Switch, LOWER"); //falla

  // uint8_t iffAntSelectSw_Upper = pcf8575_2.digitalRead(P7);
  // if (iffAntSelectSw_Upper==HIGH) Serial.println("IFF Antenna Selector Switch, UPPER");

  // uint8_t gainSwitch_On = pcf8575_2.digitalRead(P8);
  // if (gainSwitch_On==HIGH) Serial.println("GAIN Switch");

  // uint8_t gainSwitchCover_On = pcf8575_2.digitalRead(P9);
  // if (gainSwitchCover_On==HIGH) Serial.println("GAIN Switch Cover");

  // uint8_t fcsResetBtn_On = pcf8575_2.digitalRead(P10);
  // if (fcsResetBtn_On==HIGH) Serial.println("FCS RESET Button");

  // uint8_t fuelDumpSw_Off = pcf8575_2.digitalRead(P11);
  // if (fuelDumpSw_Off==HIGH) Serial.println("Fuel Dump Switch, OFF");

  // uint8_t extCntTankSw_Oride = pcf8575_2.digitalRead(P12);
  // if (extCntTankSw_Oride==HIGH) Serial.println("External Centerline Tanks Fuel Control Switch, ORIDE");

  // uint8_t extCntTankSw_Stop = pcf8575_2.digitalRead(P13);
  // if (extCntTankSw_Stop==HIGH) Serial.println("External Centerline Tanks Fuel Control Switch, STOP");

  // uint8_t extWngTankSw_Oride = pcf8575_2.digitalRead(P14);
  // if (extWngTankSw_Oride==HIGH) Serial.println("External Wing Tanks Fuel Control Switch, ORIDE");

  // uint8_t extWngTankSw_Stop = pcf8575_2.digitalRead(P15);
  // if (extWngTankSw_Stop==HIGH) Serial.println("External Wing Tanks Fuel Control Switch, STOP");







}
