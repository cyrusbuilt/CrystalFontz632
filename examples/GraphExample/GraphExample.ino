/*
    GraphExample.ino - Horizontal bar graph test.

This sketch demonstrates using a horizontal bar graph. It is not necessary to
power cycle the display prior to executing this sketch.
*/

#include <Arduino.h>
#include <SoftwareSerial.h>     // This MUST be included before CrystalFontz632
#include <CrystalFontz632.h>

#define TX_PIN 3
#define BACKLIGHT_PIN 7

CrystalFontz632 lcd(TX_PIN, BACKLIGHT_PIN);

void setup() {
	lcd.begin();              // Connect to the display.
	lcd.rebootDisplay();      // Reboot the display controller.
	lcd.enableBacklight();    // Turn on the backlight.
	lcd.hideCursor();         // Turn off the cursor.
}

void loop() {
	// Create a thick bar graph on the top row starting at the left-most column
	// and ending in the right-most column, displaying percentage between 0 and
	// 100, incrementing by 1 for every cycle.
	uint8_t startColumn = 0;
	uint8_t endColumn = 15;
	uint8_t topRow = 0;
	for (uint8_t length = 0; length <= 100; length++) {
		lcd.setBarGraph(GRAPH_INDEX1, GRAPH_STYLE_THICK, startColumn, endColumn, length, topRow);
		delay(200);
	}
}