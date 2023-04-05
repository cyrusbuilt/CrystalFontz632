/*
 CrystalFontz632 basic example with display init.

This example demonstrates display text on both lines of the 16x2 display with
proper initialization first. It is not necessary to power cycle the display
prior to executing this sketch.
*/

#include <Arduino.h>
#include <SoftwareSerial.h>     // This MUST be included before CrystalFontz632
#include "CrystalFontz632.h"

#define TX_PIN 3
#define BACKLIGHT_PIN 7

CrystalFontz632 lcd(TX_PIN, BACKLIGHT_PIN);

void setup() {
	lcd.begin();                      // Init library
	lcd.rebootDisplay();              // Reboot the display
	lcd.clearDisplay();               // Clear the screen
	lcd.enableBacklight();            // Turn the backlight on
	lcd.cursorHome();                 // Send the cursor to the top left corner (0, 0)
	lcd.print("What's up");
	lcd.crlf();                       // Carriage return, line feed. Send cursor to first column of next line.
	lcd.print("jive turkey!!!");
	lcd.hideCursor();                 // Turn off blinking cursor
}

void loop() {
	delay(100);
}
