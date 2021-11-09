/*
  LiquidCrystal Library - Autoscroll

  Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
  library works with all LCD displays that are compatible with the
  Hitachi HD44780 driver. There are many of them out there, and you
  can usually tell them by the 16-pin interface.

  This sketch demonstrates the use of the autoscroll()
  and noAutoscroll() functions to make new text scroll or not.

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
  modified 7 Nov 2016
  by Arturo Guadalupi

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/LiquidCrystalAutoscroll

*/

// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
}




int pin8 = 0, pin9 = 0;
void print() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(pin8);

}
void loop() {
  // set the cursor to (0,0):


  if (digitalRead(8)) {

    pin8++;
    //print();
    while (digitalRead(8)) delay(10);
  }

  if (digitalRead(9)) {
    //
    pin9++;
    //print();
    while (digitalRead(9)) delay(10);
  }
  lcd.setCursor(0, 0);
  lcd.print("-----PLACAR-----");
  lcd.setCursor(0, 1);
  lcd.print("time1 ");
  lcd.print(pin8);
  lcd.print("x");
  lcd.print(pin9);
  lcd.print(" time2");
  lcd.print("                ");
}
