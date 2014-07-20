/*
  CrystalFontz632 basic example

For best results, power-cycle the controller prior to executing this sketch.
*/

#include <Arduino.h>
#include <SofwareSerial.h>     // This MUST be included before CrystalFontz632
#include <CrystalFontz632.h>

#define TX_PIN 3
#define BACKLIGHT_PIN 7

CrystalFontz632 lcd(TX_PIN, BACKLIGHT_PIN);

void setup() {
	lcd.begin();                      // Init library
	lcd.enableBacklight();            // Turn backlight on.
	lcd.print("Hello, World!");
}

void loop() {
	delay(100);
}