#include "Arduino.h"
#include "PCF8575.h"

PCF8575 Periferia01(0x20);
PCF8575 Periferia02(0x22);
PCF8575 Periferia03(0x24);
PCF8575 Periferia04(0x26);

void setup() {
  
  Serial.begin(115200);

  //Set pinMode to INPUT for all inputs
  Periferia01.pinMode(P0, INPUT);
  Periferia01.pinMode(P1, INPUT);
  Periferia01.pinMode(P2, INPUT);
  Periferia01.pinMode(P3, INPUT);
  Periferia01.pinMode(P4, INPUT);
  Periferia01.pinMode(P5, INPUT);
  Periferia01.pinMode(P6, INPUT);
  Periferia01.pinMode(P7, INPUT);
  Periferia01.pinMode(P8, INPUT);
  Periferia01.pinMode(P9, INPUT);
  Periferia01.pinMode(P10, INPUT);
  Periferia01.pinMode(P11, INPUT);
  Periferia01.pinMode(P12, INPUT);
  Periferia01.pinMode(P13, INPUT);
  Periferia01.pinMode(P14, INPUT);
  Periferia01.pinMode(P15, INPUT);

  Periferia02.pinMode(P0, INPUT);
  Periferia02.pinMode(P1, INPUT);
  Periferia02.pinMode(P2, INPUT);
  Periferia02.pinMode(P3, INPUT);
  Periferia02.pinMode(P4, INPUT);
  Periferia02.pinMode(P5, INPUT);
  Periferia02.pinMode(P6, INPUT);
  Periferia02.pinMode(P7, INPUT);
  Periferia02.pinMode(P8, INPUT);
  Periferia02.pinMode(P9, INPUT);
  Periferia02.pinMode(P10, INPUT);
  Periferia02.pinMode(P11, INPUT);
  Periferia02.pinMode(P12, INPUT);
  Periferia02.pinMode(P13, INPUT);
  Periferia02.pinMode(P14, INPUT);
  Periferia02.pinMode(P15, INPUT);

  Periferia03.pinMode(P0, INPUT);
  Periferia03.pinMode(P1, INPUT);
  Periferia03.pinMode(P2, INPUT);
  Periferia03.pinMode(P3, INPUT);
  Periferia03.pinMode(P4, INPUT);
  Periferia03.pinMode(P5, INPUT);
  Periferia03.pinMode(P6, INPUT);
  Periferia03.pinMode(P7, INPUT);
  Periferia03.pinMode(P8, INPUT);
  Periferia03.pinMode(P9, INPUT);
  Periferia03.pinMode(P10, INPUT);
  Periferia03.pinMode(P11, INPUT);
  Periferia03.pinMode(P12, INPUT);
  Periferia03.pinMode(P13, INPUT);
  Periferia03.pinMode(P14, INPUT);
  Periferia03.pinMode(P15, INPUT);

  Periferia04.pinMode(P0, INPUT);
  Periferia04.pinMode(P1, INPUT);
  Periferia04.pinMode(P2, INPUT);
  Periferia04.pinMode(P3, INPUT);
  Periferia04.pinMode(P4, INPUT);
  Periferia04.pinMode(P5, INPUT);
  Periferia04.pinMode(P6, INPUT);
  Periferia04.pinMode(P7, INPUT);
  Periferia04.pinMode(P8, INPUT);
  Periferia04.pinMode(P9, INPUT);
  Periferia04.pinMode(P10, INPUT);
  Periferia04.pinMode(P11, INPUT);
  Periferia04.pinMode(P12, INPUT);
  Periferia04.pinMode(P13, INPUT);
  Periferia04.pinMode(P14, INPUT);
  Periferia04.pinMode(P15, INPUT);

  Periferia01.begin();
  Periferia02.begin();
  Periferia03.begin();
  Periferia04.begin();

}

void loop() {
  
  uint8_t val01 = Periferia01.digitalRead(P1);
  if (val01==HIGH) Serial.println(" Periferia 01 KEY PRESSED");

  uint8_t val02 = Periferia02.digitalRead(P1);
  if (val02==HIGH) Serial.println(" Periferia 02 KEY PRESSED");

  uint8_t val03 = Periferia03.digitalRead(P1);
  if (val03==HIGH) Serial.println(" Periferia 03 KEY PRESSED");

  uint8_t val04 = Periferia04.digitalRead(P1);
  if (val04==HIGH) Serial.println(" Periferia 04 KEY PRESSED");
  delay(50);


}
