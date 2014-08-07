/*
CrystalFontz632.h - Multi-instance CrystalFontz 632/634 2x16 LCD
serial display library for Arduino/Wiring.  This library uses the
SoftwareSerial library.

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef CrystalFontz632_h
#define CrystalFontz632_h

#include <Arduino.h>

// The serial BAUD rate to connect to the display at. This value should
// correspond with the DIP settings on the back of the display.
#define CF632_BAUD 9600

// Forward declaration of SoftwareSerial class.
class SoftwareSerial;

// Possible graph indices
typedef enum {
	GRAPH_INDEX1,
	GRAPH_INDEX2,
	GRAPH_INDEX3,
	GRAPH_INDEX4
} GraphIndex;

// Possible graph styles
typedef enum {
	GRAPH_STYLE_THICK,
	GRAPH_STYLE_INVISIBLE,
	GRAPH_STYLE_STRIPED,
	GRAPH_STYLE_MEDIUM_CENTER,
	GRAPH_STYLE_MEDIUM_LOW,
	GRAPH_STYLE_MEDIUM_HIGH
} GraphStyle;

// Display types.
typedef enum {
	DT_SIXTEENBYTWO,
	DT_TWENTYBYFOUR
} DisplayType;

/**
 * @brief The CrystalFontz632 class provides an API for manipulating a
 * CrystalFontz 632/634 serial LCD display. This API currently *only* works
 * with serial (SPI not yet supported) displays that are 16x2 (16 column,
 * 2 row).
 */
class CrystalFontz632
{
private:
	uint8_t _txPin;
	uint8_t _backlightPin;
	bool _blEnabled;
	bool _hidden;
	bool _scroll;
	bool _wrap;
	bool _cursorHidden;
	uint8_t _contrast;
	uint8_t _brightness;
	DisplayType _type;
	SoftwareSerial* _lcd;

    /**
     * @brief sendCommand Sends commands to the LCD controller.
     * @param cmd The command to send.
     */
	void sendCommand(byte cmd);

    /**
     * @brief sendCommand Sends commands to the LCD controller. This overload
     * can be used to send multiple commands at a time, or a single command
     * with one or more parameters.
     * @param buffer The command buffer.
     * @param size The size (length) of the buffer.
     */
    void sendCommand(const byte buffer[], size_t size);

public:
    /**
     * @brief CrystalFontz632 Initializes a new instance of the CrystalFontz632
     * class with the desired Arduino pin to use for serial TX. This constructor
     * assumes the backlight is permanently enabled by being connected to a 5V
     * supply or not being used at all.
     * @param txPin The desired pin to use for serial TX.
     */
	CrystalFontz632(uint8_t txPin);

    /**
     * @brief CrystalFontz632 Initializes a new instance of the CrystalFontz632
     * class with the desired Arduino pin to use for serial TX and the desired
     * pin to use for controlling the backlight.
     * @param txPin The desired pin to use for serial TX.
     * @param backlightPin The desired pin to use to control the backlight.
     */
	CrystalFontz632(uint8_t txPin, uint8_t backlightPin);

    /**
     * @brief Class destructor.
     */
	~CrystalFontz632();

    /**
     * @brief begin Connect to the display and init.
     */
	void begin();

	/**
	 * @brief begin Connect to the display and init.
	 * @param dt Specifies the display type.
	 */
	void begin(DisplayType dt);

    /**
     * @brief end Disconnect from display.
     */
	void end();

    /**
     * @brief rebootDisplay Reboot the LCD display. This should only be used to
     * return the display to a usable state, perhaps due to invalid contrast or
     * brightness values or if the display is printing garbage. However, this
     * method is not likely to succeed if the display's controller is in an
     * inoperable or indeterminate state. In such cases, it is best to power-cycle
     * the controller instead.
     */
    void rebootDisplay();

    /**
     * @brief clearDisplay Clear the contents of the display and return the
     * cursor to its home position (upper left corner, or position 0, 0).
     */
    void clearDisplay();

    /**
     * @brief enableBacklight Turns on the backlight. If the backlight is
     * permanently enabled, this will simply set the brightness to its maximum
     * value.
     */
    void enableBacklight();

    /**
     * @brief disableBacklight Turns the backlight off. If the backlight is
     * permanently enabled, this will simply set the brightness to its minimum
     * value.
     */
    void disableBacklight();

    /**
     * @brief isBacklightEnabled Gets whether or not the backlight is enabled.
     * @return true if enabled; Otherwise, false.
     */
    bool isBacklightEnabled();

    /**
     * @brief cursorHome Returns the cursor to its home position (upper left corner).
     */
    void cursorHome();

    /**
     * @brief hideDisplay Blanks the display, no data is changed.
     */
    void hideDisplay();

    /**
     * @brief restoreDisplay Restores a blanked display, nothing else is changed.
     */
    void restoreDisplay();

    /**
     * @brief isDisplayHidden Gets whether or not the display is blanked.
     * @return true if blanked; Otherwise, false.
     */
    bool isDisplayHidden();

    /**
     * @brief hideCursor Hides the cursor, no data is changed.
     */
    void hideCursor();

    /**
     * @brief showUnderlineCursor Shows a non-blinking underline cursor at the
     * current cursor position.
     */
    void showUnderlineCursor();

    /**
     * @brief showBlockCursor Shows a blinking block cursor at the current
     * cursor positiion.
     */
    void showBlockCursor();

    /**
     * @brief showInvertingBlockCursor Shows a blinking block cursor at the
     * current cursor position. This cursor inverts the character rather than
     * replacing the character with a block (default cursor style at boot).
     */
    void showInvertingBlockCursor();

    /**
     * @brief isCursorShown Gets whether or not the cursor is displayed.
     * @return true if cursor is shown; Otherwise, false.
     */
    bool isCursorShown();

    /**
     * @brief backspace Moves the cursor back one space and erases the character
     * in that space.
     */
    void backspace();

    /**
     * @brief lineFeed Moves the cursor down one row. If scrolling is enabled and
     * the cursor is in the bottom row, the display will scroll up one row and the
     * bottom row will be cleared. If scrolling is NOT enabled, and the cursor is
     * in the bottom row, then it will wrap up to the same character position on
     * the top row.
     */
    void lineFeed();

    /**
     * @brief deleteInPlace Deletes the character at the current cursor position
     * but does not move the cursor.
     */
    void deleteInPlace();

    /**
     * @brief formFeed Clears the display. All data is erased.
     */
    void formFeed();

    /**
     * @brief carriageReturn Moves the cursor to the left-most column of the
     * current row.
     */
    void carriageReturn();

    /**
     * @brief setContrast Sets the display contrast.
     * @param level The contrast level to set (0 - 100).
     */
    void setContrast(uint8_t level);

    /**
     * @brief getContrast Gets the current contrast value.
     * @return The contrast value (0 - 100).
     */
    uint8_t getContrast();

    /**
     * @brief setBrightness Sets the display's brightness value.
     * @param level The brightness value (0 - 100).
     */
    void setBrightness(uint8_t level);

    /**
     * @brief getBrightness Gets the display's brightness value.
     * @return The current brightness value (0 - 100).
     */
    uint8_t getBrightness();

    /**
     * @brief setCursorPos Sets the cursor position.
     * @param column The column to put the cursor in (0 - 15).
     * @param row The row to put the cursor in (0 or 1).
     */
    void setCursorPos(uint8_t column, uint8_t row);

    /**
     * @brief setBarGraph Displays a bar graph.
     * @param index The graph index to use.
     * @param style The graph style to use.
     * @param startCol The starting column for the graph (0 - 15).
     * @param endCol The ending column for the graph (0 - 15).
     * @param len The graph bar length (should be a value between startCol and endCol).
     * @param row The row to place the bar graph in (0 or 1).
     */
    void setBarGraph(GraphIndex index, GraphStyle style, uint8_t startCol, uint8_t endCol, uint8_t len, uint8_t row);

    /**
     * @brief scrollOn Enables scrolling.
     */
    void scrollOn();

    /**
     * @brief scrollOff Disables scrolling.
     */
    void scrollOff();

    /**
     * @brief isScrollOn Gets whether or not scrolling is enabled.
     * @return true if enabled; Otherwise, false.
     */
    bool isScrollOn();

    /**
     * @brief wrapOn Enables text wrapping.
     */
    void wrapOn();

    /**
     * @brief wrapOff Disables text wrapping.
     */
    void wrapOff();

    /**
     * @brief isWrapOn Gets whether or not text wrapping is enabled.
     * @return true if enabled; Otherwise, false.
     */
    bool isWrapOn();

    /**
     * @brief showInfoScreen Displays the LCD controller info screen.
     */
    void showInfoScreen();

    /**
     * @brief print Prints text to the display.
     * @param message The text to print.
     */
    void print(char* message);

    /**
     * @brief print Prints a number to the display.
     * @param num The number to print.
     */
    void print(uint8_t num);

    /**
     * @brief crlf Carriage return, line feed. This will move the
     * cursor to the left-most column of the next row (same as calling
     * carriageReturn() followed by lineFeed()).
     */
    void crlf();
};

#endif