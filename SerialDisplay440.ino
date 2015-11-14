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

// pushMode=0 : 40char,4row  pushMode=1 : 20char,8row
const byte pushMode = 1;
byte lcdLine;

char blank40[] = "                                        ";
char blank20[] = "                    ";

void setup() {
  lcdLine = pushMode * 4;
  lcd1.begin(40, 2);
  lcd2.begin(40, 2);
  
  lcd1.setCursor(0, 0);
  lcd1.print("This LCD can show 40characters, 4lines.");
  lcd1.setCursor(0, 1);
  lcd1.print("When I receive any serial data, will sh");
  lcd2.setCursor(0, 0);
  lcd2.print("ow those here. ");
  Serial.begin(9600);

  while(!Serial.available()){
    lcd2.setCursor(30, 1);
    lcd2.print(millis());
  }
  lcd1.clear();
  lcd2.clear();
}

void loop() {
  if (Serial.available()) {
    sendLCD440();
  }
}

void sendLCD440() {
  switch (lcdLine) {
    case 0:
      lcd2.noBlink();
      lcd1.setCursor(0, 0);
      lcd1.print(blank40);
      lcd1.setCursor(0, 0);
      for (int i = 0; i < 39 && Serial.available(); i++) {
        lcd1.write(Serial.read());
        delay(1);
      }
      if (Serial.available()) lcd1.write(0xA3);
      lcdLine++;
      lcd1.blink();
      break;

    case 1:
      lcd1.setCursor(0, 1);
      lcd1.print(blank40);
      lcd1.setCursor(0, 1);
      for (int i = 0; i < 39 && Serial.available(); i++) {
        lcd1.write(Serial.read());
        delay(1);
      }
      if (Serial.available()) lcd1.write(0xA3);
      lcdLine++;
      break;

    case 2:
      lcd1.noBlink();
      lcd2.setCursor(0, 0);
      lcd2.print(blank40);
      lcd2.setCursor(0, 0);
      for (int i = 0; i < 39 && Serial.available(); i++) {
        lcd2.write(Serial.read());
        delay(1);
      }
      if (Serial.available()) lcd2.write(0xA3);
      lcdLine++;
      lcd2.blink();
      break;

    case 3:
      lcd2.setCursor(0, 1);
      lcd2.print(blank40);
      lcd2.setCursor(0, 1);
      for (int i = 0; i < 39 && Serial.available(); i++) {
        lcd2.write(Serial.read());
        delay(1);
      }
      if (Serial.available()) lcd2.write(0xA3);
      lcdLine = 0;
      break;

    case 4:
      lcd2.noBlink();
      lcd1.setCursor(0, 0);
      lcd1.print(blank20);
      lcd1.setCursor(0, 0);
      for (int i = 0; i < 19 && Serial.available(); i++) {
        lcd1.write(Serial.read());
        delay(1);
      }
      if (Serial.available()) lcd1.write(0xA3);
      lcdLine++;
      lcd1.blink();
      break;

    case 5:
      lcd1.setCursor(0, 1);
      lcd1.print(blank20);
      lcd1.setCursor(0, 1);
      for (int i = 0; i < 19 && Serial.available(); i++) {
        lcd1.write(Serial.read());
        delay(1);
      }
      if (Serial.available()) lcd1.write(0xA3);
      lcdLine++;
      break;

    case 6:
      lcd1.noBlink();
      lcd2.setCursor(0, 0);
      lcd2.print(blank20);
      lcd2.setCursor(0, 0);
      for (int i = 0; i < 19 && Serial.available(); i++) {
        lcd2.write(Serial.read());
        delay(1);
      }
      if (Serial.available()) lcd2.write(0xA3);
      lcdLine++;
      lcd2.blink();
      break;

    case 7:
      lcd2.setCursor(0, 1);
      lcd2.print(blank20);
      lcd2.setCursor(0, 1);
      for (int i = 0; i < 19 && Serial.available(); i++) {
        lcd2.write(Serial.read());
        delay(1);
      }
      if (Serial.available()) lcd2.write(0xA3);
      lcdLine++;
      break;

    case 8:
      lcd2.noBlink();
      lcd1.setCursor(20, 0);
      lcd1.print(blank20);
      lcd1.setCursor(20, 0);
      for (int i = 0; i < 19 && Serial.available(); i++) {
        lcd1.write(Serial.read());
        delay(1);
      }
      if (Serial.available()) lcd1.write(0xA3);
      lcdLine++;
      lcd1.blink();
      break;

    case 9:
      lcd1.setCursor(20, 1);
      lcd1.print(blank20);
      lcd1.setCursor(20, 1);
      for (int i = 0; i < 19 && Serial.available(); i++) {
        lcd1.write(Serial.read());
        delay(1);
      }
      if (Serial.available()) lcd1.write(0xA3);
      lcdLine++;
      break;

    case 10:
      lcd1.noBlink();
      lcd2.setCursor(20, 0);
      lcd2.print(blank20);
      lcd2.setCursor(20, 0);
      for (int i = 0; i < 19 && Serial.available(); i++) {
        lcd2.write(Serial.read());
        delay(1);
      }
      if (Serial.available()) lcd2.write(0xA3);
      lcdLine++;
      lcd2.blink();
      break;

    case 11:
      lcd2.setCursor(20, 1);
      lcd2.print(blank20);
      lcd2.setCursor(20, 1);
      for (int i = 0; i < 19 && Serial.available(); i++) {
        lcd2.write(Serial.read());
        delay(1);
      }
      if (Serial.available()) lcd2.write(0xA3);
      lcdLine = 4;
      break;

    default:
      lcdLine = pushMode * 4;
      lcd1.noBlink();
      lcd2.noBlink();
      break;
  }
}
