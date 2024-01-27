/*
 KeyPressed on PIN1
 by Mischianti Renzo <http://www.mischianti.org>

 https://www.mischianti.org/2019/01/02/pcf8575-i2c-digital-i-o-expander-fast-easy-usage/
*/

#include "Arduino.h"
#include "PCF8575.h"

// Set i2c address
PCF8575 pcf8575_1(0x20);
PCF8575 pcf8575_2(0x22);
unsigned long timeElapsed;
void setup()
{
  Serial.begin(115200);

  pcf8575_1.pinMode(P1, INPUT);
  pcf8575_2.pinMode(P9, INPUT);
  //pcf8575.pinMode(P8, INPUT);

  pcf8575_1.begin();
  pcf8575_2.begin();
}

void loop()
{
  uint8_t val = pcf8575_2.digitalRead(P9);
  if (val==HIGH) Serial.println("KEY PRESSED1");
  delay(200);

    uint8_t val2 = pcf8575_1.digitalRead(P1);
  if (val2==HIGH) Serial.println("KEY PRESSED2");
  delay(200);
}
