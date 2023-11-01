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

uint8_t comCommRelaySw;
uint8_t comm1AntSelectSw; 
uint8_t hydIsolateOverrideSw;
uint8_t obogsSw;
uint8_t mcSw;
uint8_t comCryptoSw;
uint8_t comIffMode4Sw;
uint8_t comIffMasterSw;
uint8_t comIlsUfcManSw;
uint8_t comCommGXmtSw;

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
  //sendDcsBiosMessage("COM_COMM_RELAY_SW","0");
  
  //+++++++++++++++++++++++++++++++++++++++++++++
  //+ Señales de la Expansion 1, direccion 0x20 +
  //+++++++++++++++++++++++++++++++++++++++++++++

  //Comm Relay Switch, CIPHER/OFF/PLAIN
  uint8_t comCommRelaySw_Cipher = pcf8575_1.digitalRead(P0);        //Comm Relay Switch, CIPHER
  uint8_t comCommRelaySw_Plain = pcf8575_1.digitalRead(P1);         //Comm Relay Switch, PLAIN

  if (comCommRelaySw_Plain==HIGH && comCommRelaySw!=0 ) {
    sendDcsBiosMessage("COM_COMM_RELAY_SW","0");
    comCommRelaySw = 0;   
  }
  if (comCommRelaySw_Cipher==HIGH && comCommRelaySw!=2) { 
    sendDcsBiosMessage("COM_COMM_RELAY_SW","2");
    comCommRelaySw = 2; 
  }
  if (comCommRelaySw_Cipher!=HIGH && comCommRelaySw_Plain!=HIGH && comCommRelaySw!=1){ 
    sendDcsBiosMessage("COM_COMM_RELAY_SW","1");
    comCommRelaySw = 1;
  }
  delay(50);

  
  // //COMM 1 Antenna Selector Switch, UPPER/AUTO/LOWER
  // uint8_t comm1AntSelectSw_Upper = pcf8575_1.digitalRead(P2);       //COMM 1 Antenna Selector Switch, UPPER
  // uint8_t comm1AntSelectSw_Lower = pcf8575_1.digitalRead(P3);       //COMM 1 Antenna Selector Switch, LOWER

  // if (comm1AntSelectSw_Upper == HIGH || !comm1AntSelectSw == 0) {
  //   sendDcsBiosMessage("COMM1_ANT_SELECT_SW","0");
  //   comm1AntSelectSw = 0;
  // }
  // else if (comm1AntSelectSw_Lower==HIGH || !comm1AntSelectSw == 2) { 
  //   sendDcsBiosMessage("COMM1_ANT_SELECT_SW","2");
  //   comm1AntSelectSw = 2;
  // }
  // else if (comm1AntSelectSw_Upper==LOW || comm1AntSelectSw_Lower==LOW || !comm1AntSelectSw == 1){ 
  //   sendDcsBiosMessage("COMM1_ANT_SELECT_SW","1");
  //   comm1AntSelectSw = 1;
  // }


  // //Hydraulic Isolate Override Switch, NORM/ORIDE
  // uint8_t hydIsolateOverrideSw_Oride = pcf8575_1.digitalRead(P4);   // Hydraulic Isolate Override Switch, NORM

  // if (hydIsolateOverrideSw_Oride == HIGH || !hydIsolateOverrideSw == 1) {
  //   sendDcsBiosMessage("HYD_ISOLATE_OVERRIDE_SW","1");
  //   hydIsolateOverrideSw = 1;
  // }
  // else if (hydIsolateOverrideSw_Oride==LOW || !hydIsolateOverrideSw == 0) { 
  //   sendDcsBiosMessage("HYD_ISOLATE_OVERRIDE_SW","0");
  //   hydIsolateOverrideSw = 0;
  // }


  // //OBOGS Control Switch, ON/OFF
  // uint8_t obogsSw_On = pcf8575_1.digitalRead(P5);                   // OBOGS Control Switch, ON

  // if (obogsSw_On == HIGH || !obogsSw == 1) {
  //   sendDcsBiosMessage("HYD_ISOLATE_OVERRIDE_SW","1");
  //   obogsSw = 1;
  // }
  // else if (obogsSw_On==LOW || !obogsSw == 0) { 
  //   sendDcsBiosMessage("HYD_ISOLATE_OVERRIDE_SW","0");
  //   obogsSw = 0;
  // }

  // //MC Switch, 1 OFF/NORM/2 OFF
  // uint8_t mcSw_2off = pcf8575_1.digitalRead(P6);                    // MC Switch, 2 OFF
  // uint8_t mcSw_1off = pcf8575_1.digitalRead(P7);                    // MC Switch, 1 OFF

  // if (mcSw_1off == HIGH || !mcSw == 0) {
  //   sendDcsBiosMessage("MC_SW","0");
  //   mcSw = 0;
  // }
  // else if (mcSw_2off==HIGH || !mcSw == 2) { 
  //   sendDcsBiosMessage("MC_SW","2");
  //   mcSw = 2;
  // }
  // else if (mcSw_1off==LOW || mcSw_2off==LOW || !mcSw == 1){ 
  //   sendDcsBiosMessage("MC_SW","1");
  //   mcSw = 1;
  // }

  // //CRYPTO Switch, HOLD/NORM/ZERO
  // uint8_t comCryptoSw_Hold = pcf8575_1.digitalRead(P8);             // CRYPTO Switch, HOLD
  // uint8_t comCryptoSw_Zero = pcf8575_1.digitalRead(P9);             // CRYPTO Switch, ZERO

  // if (comCryptoSw_Hold == HIGH || !comCryptoSw == 0) {
  //   sendDcsBiosMessage("COM_CRYPTO_SW","0");
  //   comCryptoSw = 0;
  // }
  // else if (comCryptoSw_Zero==HIGH || !comCryptoSw == 2) { 
  //   sendDcsBiosMessage("COM_CRYPTO_SW","2");
  //   comCryptoSw = 2;
  // }
  // else if (comCryptoSw_Hold==LOW || comCryptoSw_Zero==LOW || !comCryptoSw == 1){ 
  //   sendDcsBiosMessage("COM_CRYPTO_SW","1");
  //   comCryptoSw = 1;
  // }


  // //IFF Mode 4 Switch, DIS/AUD /DIS/OFF
  // uint8_t comIffMode4Sw_DisAud = pcf8575_1.digitalRead(P10);        // IFF Mode 4 Switch, DIS/AUD
  // uint8_t comIffMode4Sw_Off = pcf8575_1.digitalRead(P11);           // IFF Mode 4 Switch, Off

  // if (comIffMode4Sw_DisAud == HIGH || !comIffMode4Sw == 0) {
  //   sendDcsBiosMessage("COM_IFF_MODE4_SW","0");
  //   comIffMode4Sw = 0;
  // }
  // else if (comIffMode4Sw_Off==HIGH || !comIffMode4Sw == 2) { 
  //   sendDcsBiosMessage("COM_IFF_MODE4_SW","2");
  //   comIffMode4Sw = 2;
  // }
  // else if (comIffMode4Sw_DisAud==LOW || comIffMode4Sw_Off==LOW || !comIffMode4Sw == 1){ 
  //   sendDcsBiosMessage("COM_IFF_MODE4_SW","1");
  //   comIffMode4Sw = 1;
  // }

  // //IFF Master Switch, EMER/NORM
  // uint8_t comIffMasterSw_Emer = pcf8575_1.digitalRead(P12);         // IFF Master Switch, EMER

  // if (comIffMasterSw_Emer == HIGH || !comIffMasterSw == 1) {
  //   sendDcsBiosMessage("COM_IFF_MASTER_SW","1");
  //   comIffMasterSw = 1;
  // }
  // else if (comIffMasterSw_Emer==LOW || !comIffMasterSw == 0) { 
  //   sendDcsBiosMessage("COM_IFF_MASTER_SW","0");
  //   comIffMasterSw = 0;
  // }

  // //ILS UFC/MAN Switch, UFC/MAN
  // uint8_t comIlsUfcManSw_Ufc = pcf8575_1.digitalRead(P13);          // ILS UFC/MAN Switch, UFC

  // if (comIlsUfcManSw_Ufc == HIGH || !comIlsUfcManSw == 1) {
  //   sendDcsBiosMessage("COM_ILS_UFC_MAN_SW","1");
  //   comIlsUfcManSw = 1;
  // }
  // else if (comIlsUfcManSw_Ufc==LOW || !comIlsUfcManSw == 0) { 
  //   sendDcsBiosMessage("COM_ILS_UFC_MAN_SW","0");
  //   comIlsUfcManSw = 0;
  // }

  // //COMM G XMT Switch, COMM 1/OFF/COMM 2;
  // uint8_t comCommGXmtSw_Comm2 = pcf8575_1.digitalRead(P14);         // COMM G XMT Switch, COMM 2
  // uint8_t comCommGXmtSw_Comm1 = pcf8575_1.digitalRead(P15);         // COMM G XMT Switch, COMM 1

  // if (comCommGXmtSw_Comm1 == HIGH || !comCommGXmtSw == 0) {
  //   sendDcsBiosMessage("COM_IFF_MODE4_SW","0");
  //   comCommGXmtSw = 0;
  // }
  // else if (comCommGXmtSw_Comm2==HIGH || !comCommGXmtSw == 2) { 
  //   sendDcsBiosMessage("COM_IFF_MODE4_SW","2");
  //   comCommGXmtSw = 2;
  // }
  // else if (comCommGXmtSw_Comm1==LOW || comCommGXmtSw_Comm2==LOW || !comCommGXmtSw == 1){ 
  //   sendDcsBiosMessage("COM_IFF_MODE4_SW","1");
  //   comCommGXmtSw = 1;
  // }

  // //+++++++++++++++++++++++++++++++++++++++++++++
  // //+ Señales de la Expansion 2, direccion 0x22 +
  // //+++++++++++++++++++++++++++++++++++++++++++++
  
  // //Probe Control Switch, EXTEND/RETRACT/EMERG EXTD
  // uint8_t probeSw = 0;
  // uint8_t probeSw_EmergExtd = pcf8575_2.digitalRead(P0);            // Probe Control Switch, EMERG EXTD
  // uint8_t probeSw_Extend = pcf8575_2.digitalRead(P1);               // Probe Control Switch, EXTEND

  // //T/O TRIM Button
  // uint8_t toTrimBtn = 0;
  // uint8_t toTrimBtn_On = pcf8575_2.digitalRead(P2);                 // T/O TRIM Button


  // //APU Control Switch, ON/OFF
  // uint8_t apuControlSw = 0;
  // uint8_t apuControlSw_On = pcf8575_2.digitalRead(P3);              // APU Control Switch, ON


  // //Engine Crank Switch, LEFT/OFF/RIGHT
  // //set the switch position -- 0 = held left/down, 1 = centered, 2 = held right/up
  // uint8_t engineCrankSw = 0;
  // uint8_t engineCrankSw_Right = pcf8575_2.digitalRead(P4);          // Engine Crank Switch, RIGHT
  // uint8_t engineCrankSw_Left = pcf8575_2.digitalRead(P5);           // Engine Crank Switch, LEFT


  // //IFF Antenna Selector Switch, UPPER/BOTH/LOWER
  // uint8_t iffAntSelectSw = 0;
  // uint8_t iffAntSelectSw_Lower = pcf8575_2.digitalRead(P6);         // IFF Antenna Selector Switch, LOWER
  // uint8_t iffAntSelectSw_Upper = pcf8575_2.digitalRead(P7);         // IFF Antenna Selector Switch, UPPER

  // //GAIN Switch
  // uint8_t gainSwitch = 0;
  // uint8_t gainSwitch_On = pcf8575_2.digitalRead(P8);                // GAIN Switch


  // //GAIN Switch Cover
  // uint8_t gainSwitchCover = 0;
  // uint8_t gainSwitchCover_On = pcf8575_2.digitalRead(P9);           // GAIN Switch Cover


  // //FCS RESET Button
  // uint8_t fcsResetBtn = 0;
  // uint8_t fcsResetBtn_On = pcf8575_2.digitalRead(P10);              // FCS RESET Button

  
  // //Fuel Dump Switch, ON/OFF
  // //set the switch position -- 0 = off, 1 = on
  // uint8_t fuelDumpSw = 0;
  // uint8_t fuelDumpSw_Off = pcf8575_2.digitalRead(P11);              // Fuel Dump Switch, OFF


  // //External Centerline Tank Fuel Control Switch, STOP/NORM/ORIDE
  // uint8_t extCntTankSw = 0;
  // uint8_t extCntTankSw_Oride = pcf8575_2.digitalRead(P12);          // External Centerline Tanks Fuel Control Switch, ORIDE 
  // uint8_t extCntTankSw_Stop = pcf8575_2.digitalRead(P13);           // External Centerline Tanks Fuel Control Switch, STOP
 

  // //External Wing Tanks Fuel Control Switch, STOP/NORM/ORIDE
  // uint8_t extWngTankSw = 0;
  // uint8_t extWngTankSw_Oride = pcf8575_2.digitalRead(P14);          // External Wing Tanks Fuel Control Switch, ORIDE
  // uint8_t extWngTankSw_Stop = pcf8575_2.digitalRead(P15);           // External Wing Tanks Fuel Control Switch, STOP



  // if (PosA == HIGH) {
  //   // Danger! Shut down the system.
  //   //
  //   DCS_Tag
  // }
  // else if (PosB == HIGH) { // 60 <= temperature < 70
  //   // Warning! User attention required.
  // }
  // else { // temperature < 60
  //   // Safe! Continue usual tasks.
  // }



}
