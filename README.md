# CrystalFontz632 :: Serial LCD library for Arduino/Wiring
[![Build Status](https://github.com/cyrusbuilt/CrystalFontz632/actions/workflows/ci.yml/badge.svg)](https://github.com/cyrusbuilt/CrystalFontz632/actions?query=workflow%3APlatformIO)

## LICENSE

Licensed under GPL v2 (the "License"); you may not use this library except
in compliance with the License.  You may obtain a copy of the License at:

http://www.gnu.org/licenses/gpl-2.0.html

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

## Description

This is a library that provides a robust driver API for manipulating one or
more CrystalFontz 632 (16x2) intelligent serial LCD displays. This is a
multi-instance library, so can control multiple displays, as it uses the
SoftwareSerial library to communicate with the display. Only one pin is
required to control the display, so you can designate a digital I/O as
the data pin and one pin to control the backlight.  Alternately, if you
intend to leave the backlight always on, just tie the backlight pin to
+5V DC.

## Features
- Supports all known supported RS-232 BAUD rates.
- Supports 16x2 and 20x4 models.
- Supports both 1x and 2x firmware versions.
- Supports graphs.
- Supports backlight control.
- NEW: Now supports CGROM characters.

## How to use

Copy the entire folder containing this library to the "libraries" folder
of your Arduino installation. Then include both SoftwareSerial.h and
CrystalFontz632.h in your sketch.  See example below:

```cpp
#include <Arduino.h>
#include <SoftwareSerial.h>   // Need to include this so the linker will succeed
#include <CrystalFontz632.>

#define TX_PIN 3
#define BACKLIGHT 4

CrystalFontz632 lcd(TX_PIN, BACKLIGHT);  // Create library instance.

void setup() {
  lcd.begin();                 // Connect to display.
  lcd.clearDisplay();          // Clear the display of any contents.
  lcd.print("Hello, World!");  // Print line of text on top line starting at left-most column.
}

void loop() {
  delay(100);
}
```

## NOTE
Currently, this library doesn't support connecting the display via SPI despite the display supporting both RS-232 and SPI.  Although, I am planning to support SPI in the future.

## How to install

If you are using PlatformIO (http://platformio.org/), you can simply run the following command:
```
platformio lib install crystalfontz632
```

Otherwise, download the zip from https://github.com/cyrusbuilt/CrystalFontz632/archive/master.zip then extract its contents to a folder called "CrystalFontz632" and then move that folder to your libraries folder.

## Customization

If you need to save space and do not need CGROM support, you can comment or undefine the USE_CGROM_CHARS define. If you want CGROM support but have a display with 1x firmware, you can change the default firmware version by setting the DISPLAY_632_VERSION define to DISPLAY_632_VERSION_1X. (NOTE: The display firmware version affects what CGROM characters are supported. See "Appendix C" in 632full.pdf). This will likely become a settable parameter in the library in the future.

## Hardware Changes

There are solder pad jumpers on the back of the device.  You may need to close jumpers JPB (RS-232 data inverted) and JPE (DATA_IN is 0v to 5v swing) if you experience noise. (See "Crystalfontz Intelligent Serial Display Jumper Settings" in 632full.pdf)