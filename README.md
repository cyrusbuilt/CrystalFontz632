==========================================================================
CrystalFontz632 :: Serial LCD library for Arduino/Wiring
==========================================================================

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

This is a library that provides a robust API for manipulating one or more
CrystalFontz 632 (16x2) intelligent serial LCD displays. This is a
multi-instance library, so can control multiple displays, as it uses the
SoftwareSerial library to communicate with the display. Only one pin is
required to control the display, so you can designate a digital I/O as
the data pin and one pin to control the backlight.  Alternately, if you
intend to leave the backlight always on, just tie the backlight pin to
+5V DC.

## How to use

Copy the entire folder containing this library to the "libraries" folder
of your Arduino installation. Then include both SoftwareSerial.h and
CrystalFontz632.h in your sketch.  See example below:

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

