/*
  LiquidCrystal Library - Serial Input

  Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
  library works with all LCD displays that are compatible with the
  Hitachi HD44780 driver. There are many of them out there, and you
  can usually tell them by the 16-pin interface.

  This sketch displays text sent over the serial port
  (e.g. from the Serial Monitor) on an attached LCD.

  The circuit:
   LCD RS pin to digital pin 12
   LCD Enable pin to digital pin 11
   LCD D4 pin to digital pin 5
   LCD D5 pin to digital pin 4
   LCD D6 pin to digital pin 3
   LCD D7 pin to digital pin 2
   LCD R/W pin to ground
   10K resistor:
   ends to +5V and ground
   wiper to LCD VO pin (pin 3)

  Library originally added 18 Apr 2008
  by David A. Mellis
  library modified 5 Jul 2009
  by Limor Fried (http://www.ladyada.net)
  example added 9 Jul 2009
  by Tom Igoe
  modified 22 Nov 2010
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/LiquidCrystalSerial
*/

#include <LiquidCrystal.h>

// RS to D11, R/W to GND , E1 to D10, E2 to D12, DB7-DB0 to D9-D2
LiquidCrystal lcd1(11, 10, 9, 8, 7, 6, 5, 4, 3, 2);
LiquidCrystal lcd2(11, 12, 9, 8, 7, 6, 5, 4, 3, 2);

// mode=0 : 40char,4row  mode=4 : 20char,8row
const byte mode = 4;
byte line;

char blank40[] = "                                        ";
char blank20[] = "                    ";

void setup() {
  lcd1.begin(40, 2);
  lcd2.begin(40, 2);
  lcd1.print("Creates a variable of type LiquidCrystal. The display can be controlled using 4#");
  lcd2.print(" or 8 data lines. If the former, omit the pin numbers for d0 to d3 and leave th#");
  Serial.begin(9600);

  line = mode;
}

void loop() {
  if (Serial.available()) {
    switch (line) {
      case 0:
        lcd2.noBlink();
        lcd1.setCursor(0, 0);
        lcd1.print(blank40);
        lcd1.setCursor(0, 0);
        for (int i = 0; i < 40 && Serial.available() > 0; i++) {
          lcd1.write(Serial.read());
          delay(1);
        }
        line++;
        lcd1.blink();
        break;

      case 1:
        lcd1.setCursor(0, 1);
        lcd1.print(blank40);
        lcd1.setCursor(0, 1);
        for (int i = 0; i < 40 && Serial.available() > 0; i++) {
          lcd1.write(Serial.read());
          delay(1);
        }
        line++;
        break;

      case 2:
        lcd1.noBlink();
        lcd2.setCursor(0, 0);
        lcd2.print(blank40);
        lcd2.setCursor(0, 0);
        for (int i = 0; i < 40 && Serial.available() > 0; i++) {
          lcd2.write(Serial.read());
          delay(1);
        }
        line++;
        lcd2.blink();
        break;

      case 3:
        lcd2.setCursor(0, 1);
        lcd2.print(blank40);
        lcd2.setCursor(0, 1);
        for (int i = 0; i < 40 && Serial.available() > 0; i++) {
          lcd2.write(Serial.read());
          delay(1);
        }
        line = 0;
        break;

      case 4:
        lcd2.noBlink();
        lcd1.setCursor(0, 0);
        lcd1.print(blank20);
        lcd1.setCursor(0, 0);
        for (int i = 0; i < 20 && Serial.available() > 0; i++) {
          lcd1.write(Serial.read());
          delay(1);
        }
        line++;
        lcd1.blink();
        break;

      case 5:
        lcd1.setCursor(0, 1);
        lcd1.print(blank20);
        lcd1.setCursor(0, 1);
        for (int i = 0; i < 20 && Serial.available() > 0; i++) {
          lcd1.write(Serial.read());
          delay(1);
        }
        line++;
        break;

      case 6:
        lcd1.noBlink();
        lcd2.setCursor(0, 0);
        lcd2.print(blank20);
        lcd2.setCursor(0, 0);
        for (int i = 0; i < 20 && Serial.available() > 0; i++) {
          lcd2.write(Serial.read());
          delay(1);
        }
        line++;
        lcd2.blink();
        break;

      case 7:
        lcd2.setCursor(0, 1);
        lcd2.print(blank20);
        lcd2.setCursor(0, 1);
        for (int i = 0; i < 20 && Serial.available() > 0; i++) {
          lcd2.write(Serial.read());
          delay(1);
        }
        line++;
        break;

      case 8:
        lcd2.noBlink();
        lcd1.setCursor(20, 0);
        lcd1.print(blank20);
        lcd1.setCursor(20, 0);
        for (int i = 0; i < 20 && Serial.available() > 0; i++) {
          lcd1.write(Serial.read());
          delay(1);
        }
        line++;
        lcd1.blink();
        break;

      case 9:
        lcd1.setCursor(20, 1);
        lcd1.print(blank20);
        lcd1.setCursor(20, 1);
        for (int i = 0; i < 20 && Serial.available() > 0; i++) {
          lcd1.write(Serial.read());
          delay(1);
        }
        line++;
        break;

      case 10:
        lcd1.noBlink();
        lcd2.setCursor(20, 0);
        lcd2.print(blank20);
        lcd2.setCursor(20, 0);
        for (int i = 0; i < 20 && Serial.available() > 0; i++) {
          lcd2.write(Serial.read());
          delay(1);
        }
        line++;
        lcd2.blink();
        break;

      case 11:
        lcd2.setCursor(20, 1);
        lcd2.print(blank20);
        lcd2.setCursor(20, 1);
        for (int i = 0; i < 20 && Serial.available() > 0; i++) {
          lcd2.write(Serial.read());
          delay(1);
        }
        line = 4;
        break;

      default:
        line = mode;
        lcd1.noBlink();
        lcd2.noBlink();
        break;
    }
  }
}
