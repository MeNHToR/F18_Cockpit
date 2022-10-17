//Probado con la versión 1.0.1
//la 1.0.2, bajada desde el GIT del desarrollador no tira.


#include <DM8BA10.h>
#include <charset/latin_basic.h>

// pins
#define CS_PIN        49
#define WR_PIN        51
#define DATA_PIN      53
#define BACKLIGHT_PIN 0

DM8BA10* LCD;

void setup()
{   
  LCD = new DM8BA10(new LatinBasicCharset(), CS_PIN, WR_PIN, DATA_PIN, BACKLIGHT_PIN);
  LCD->backlight();
}

void loop()
{
  LCD->println("Soy Bueno");
}
