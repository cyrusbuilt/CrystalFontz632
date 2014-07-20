/*
   BrightnessAndContrastExample.ino basic brightness and contrast test.

This sketch demonstrates stepping through brightness levels from minimum to
maximum and then stepping through contrast levels from minimum to maximum. It
is not necessary to power cycle the display prior to executing this sketch.
*/

#include <Arduino.h>
#include <SoftwareSerial.h>    // This MUST be included before CrystalFontz632
#include <CrystalFontz632.h>
#include <CF632Commands.h>     // Need for CF632 brightness and contrast constants

#define TX_PIN 3
#define BACKLIGHT_PIN 7

CrystalFontz632 lcd(TX_PIN, BACKLIGHT_PIN);

void setup() {
	lcd.begin();             // Connect to display.
	lcd.rebootDisplay();     // Reboot controller
	lcd.enableBacklight();   // Turn backlight on
	lcd.hideCursor();        // Turn off cursor
}

void loop() {
	// Do brightness test.
	lcd.clearDisplay();      // Clear display
	lcd.print("Brightness test");
	for (uint8_t i = CF632_BRIGHTNESS_MIN; i <= CF632_BRIGHTNESS_MAX; i++) {
		lcd.setBrightness(i);
		delay(200);
	}

	// Do contrast test.
	delay(2000);
	lcd.clearDisplay();
	lcd.print("Contrast test");
	delay(1000);
	for (uint8_t j = CF632_CONTRAST_MIN; j <= CF632_CONTRAST_MAX; j++) {
		lcd.setContrast(j);
		delay(200);
	}
	lcd.setContrast(50);    // Return contrast to default.
}