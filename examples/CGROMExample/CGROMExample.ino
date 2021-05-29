#include <Arduino.h>
#include <SoftwareSerial.h>
#include "CrystalFontz632.h"

#define TX_PIN 3
#define BACKLIGHT_PIN 7

CrystalFontz632 lcd(TX_PIN, BACKLIGHT_PIN);

void setup() {
	lcd.begin();                      // Init library
	lcd.clearDisplay();               // Clear the screen
	lcd.enableBacklight();            // Turn backlight on.
	lcd.cursorHome();                 // Send the cursor to the top left corner (0, 0)

	int col = 0;
	int row = 0;
	lcd.printCgRomChar(CGRomChar::CGROM_144_0); // Display music note.

	col++;
	lcd.setCursorPos(col, row); // Advance cursor position to the right.
	lcd.printCgRomChar(CGRomChar::CGROM_224_0); // Display down arrow.

	col++;
	lcd.setCursorPos(col, row);
	lcd.printCgRomChar(CGRomChar::CGROM_144_2); // Display bell.

	col++;
	lcd.setCursorPos(col, row);
	lcd.printCgRomChar(CGRomChar::CGROM_144_3); // Display heart.

	col++;
	lcd.setCursorPos(col, row);
	lcd.printCgRomChar(CGRomChar::CGROM_176_5); // Display omega.
}

void loop() {
	delay(100);
}