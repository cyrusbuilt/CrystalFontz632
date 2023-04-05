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

#define USE_CGROM_CHARS  // Comment to disable CGROM Character code support.

#ifdef USE_CGROM_CHARS
// Define appropriate display version.
#define DISPLAY_632_VERSION_1X 1
#define DISPLAY_632_VERSION_2X 2
#define DISPLAY_632_VERSION DISPLAY_632_VERSION_2X

/**
 * @brief See "Appendix C" in 632full.pdf
 */
enum class CGRomChar
{
#if (DISPLAY_632_VERSION == DISPLAY_632_VERSION_2X)
    CGROM_16_0   =  16 + 0,
#endif
    CGROM_32_0   =  32 + 0,
    CGROM_48_0   =  48 + 0,
    CGROM_64_0   =  64 + 0,
    CGROM_80_0   =  80 + 0,
    CGROM_96_0   =  96 + 0,
    CGROM_112_0  = 112 + 0,
#if (DISPLAY_632_VERSION == DISPLAY_632_VERSION_2X)
    CGROM_128_0  = 128 + 0,
#endif
    CGROM_144_0  = 144 + 0,
    CGROM_160_0  = 160 + 0,
    CGROM_176_0  = 176 + 0,
    CGROM_192_0  = 192 + 0,
    CGROM_208_0  = 208 + 0,
    CGROM_224_0  = 224 + 0,
    CGROM_240_0  = 240 + 0,
#if (DISPLAY_632_VERSION == DISPLAY_632_VERSION_2X)
    CGROM_16_1   = 16 + 1,
#endif
    CGROM_32_1   = 32 + 1,
    CGROM_48_1   = 48 + 1,
    CGROM_64_1   = 64 + 1,
    CGROM_80_1   = 80 + 1,
    CGROM_96_1   = 96 + 1,
    CGROM_112_1  = 112 + 1,
#if (DISPLAY_632_VERSION == DISPLAY_632_VERSION_2X)
    CGROM_128_1  = 128 + 1,
#endif
    CGROM_144_1  = 144 + 1,
    CGROM_160_1  = 160 + 1,
    CGROM_176_1  = 176 + 1,
    CGROM_192_1  = 192 + 1,
    CGROM_208_1  = 208 + 1,
    CGROM_224_1  = 224 + 1,
    CGROM_240_1  = 240 + 1,
#if (DISPLAY_632_VERSION == DISPLAY_632_VERSION_2X)
    CGROM_16_2   = 16 + 2,
#endif
    CGROM_32_2   = 32 + 2,
    CGROM_48_2   = 48 + 2,
    CGROM_64_2   = 64 + 2,
    CGROM_80_2   = 80 + 2,
    CGROM_96_2   = 96 + 2,
    CGROM_112_2  = 112 + 2,
#if (DISPLAY_632_VERSION == DISPLAY_632_VERSION_2X)
    CGROM_128_2  = 128 + 2,
#endif
    CGROM_144_2  = 144 + 2,
    CGROM_160_2  = 160 + 2,
    CGROM_176_2  = 176 + 2,
    CGROM_192_2  = 192 + 2,
    CGROM_208_2  = 208 + 2,
    CGROM_224_2  = 224 + 2,
    CGROM_240_2  = 240 + 2,
#if (DISPLAY_632_VERSION == DISPLAY_632_VERSION_2X)
    CGROM_16_3   = 16 + 3,
#endif
    CGROM_32_3   = 32 + 3,
    CGROM_48_3   = 48 + 3,
    CGROM_64_3   = 64 + 3,
    CGROM_80_3   = 80 + 3,
    CGROM_96_3   = 96 + 3,
    CGROM_112_3  = 112 + 3,
#if (DISPLAY_632_VERSION == DISPLAY_632_VERSION_2X)
    CGROM_128_3  = 128 + 3,
#endif
    CGROM_144_3  = 144 + 3,
    CGROM_160_3  = 160 + 3,
    CGROM_176_3  = 176 + 3,
    CGROM_192_3  = 192 + 3,
    CGROM_208_3  = 208 + 3,
    CGROM_224_3  = 224 + 3,
    CGROM_240_3  = 240 + 3,
#if (DISPLAY_632_VERSION == DISPLAY_632_VERSION_2X)
    CGROM_16_4   = 16 + 4,
#endif
    CGROM_32_4   = 32 + 4,
    CGROM_48_4   = 48 + 4,
    CGROM_64_4   = 64 + 4,
    CGROM_80_4   = 80 + 4,
    CGROM_96_4   = 96 + 4,
    CGROM_112_4  = 112 + 4,
#if (DISPLAY_632_VERSION == DISPLAY_632_VERSION_2X)
    CGROM_128_4  = 128 + 4,
#endif
    CGROM_144_4  = 144 + 4,
    CGROM_160_4  = 160 + 4,
    CGROM_176_4  = 176 + 4,
    CGROM_192_4  = 192 + 4,
    CGROM_208_4  = 208 + 4,
    CGROM_224_4  = 224 + 4,
    CGROM_240_4  = 240 + 4,
#if (DISPLAY_632_VERSION == DISPLAY_632_VERSION_2X)
    CGROM_16_5   = 16 + 5,
#endif
    CGROM_32_5   = 32 + 5,
    CGROM_48_5   = 48 + 5,
    CGROM_64_5   = 64 + 5,
    CGROM_80_5   = 80 + 5,
    CGROM_96_5   = 96 + 5,
    CGROM_112_5  = 112 + 5,
#if (DISPLAY_632_VERSION == DISPLAY_632_VERSION_2X)
    CGROM_128_5  = 128 + 5,
#endif
    CGROM_144_5  = 144 + 5,
    CGROM_160_5  = 160 + 5,
    CGROM_176_5  = 176 + 5,
    CGROM_192_5  = 192 + 5,
    CGROM_208_5  = 208 + 5,
    CGROM_224_5  = 224 + 5,
    CGROM_240_5  = 240 + 5,
#if (DISPLAY_632_VERSION == DISPLAY_632_VERSION_2X)
    CGROM_16_6   = 16 + 6,
#endif
    CGROM_32_6   = 32 + 6,
    CGROM_48_6   = 48 + 6,
    CGROM_64_6   = 64 + 6,
    CGROM_80_6   = 80 + 6,
    CGROM_96_6   = 96 + 6,
    CGROM_112_6  = 112 + 6,
#if (DISPLAY_632_VERSION == DISPLAY_632_VERSION_2X)
    CGROM_128_6  = 128 + 6,
#endif
    CGROM_144_6  = 144 + 6,
    CGROM_160_6  = 160 + 6,
    CGROM_176_6  = 176 + 6,
    CGROM_192_6  = 192 + 6,
    CGROM_208_6  = 208 + 6,
    CGROM_224_6  = 224 + 6,
    CGROM_240_6  = 240 + 6,
#if (DISPLAY_632_VERSION == DISPLAY_632_VERSION_2X)
    CGROM_16_7   = 16 + 7,
#endif
    CGROM_32_7   = 32 + 7,
    CGROM_48_7   = 48 + 7,
    CGROM_64_7   = 64 + 7,
    CGROM_80_7   = 80 + 7,
    CGROM_96_7   = 96 + 7,
    CGROM_112_7  = 112 + 7,
#if (DISPLAY_632_VERSION == DISPLAY_632_VERSION_2X)
    CGROM_128_7  = 128 + 7,
#endif
    CGROM_144_7  = 144 + 7,
    CGROM_160_7  = 160 + 7,
    CGROM_176_7  = 176 + 7,
    CGROM_192_7  = 192 + 7,
    CGROM_208_7  = 208 + 7,
    CGROM_224_7  = 224 + 7,
    CGROM_240_7  = 240 + 7,
#if (DISPLAY_632_VERSION == DISPLAY_632_VERSION_2X)
    CGROM_16_8   = 16 + 8,
#endif
    CGROM_32_8   = 32 + 8,
    CGROM_48_8   = 48 + 8,
    CGROM_64_8   = 64 + 8,
    CGROM_80_8   = 80 + 8,
    CGROM_96_8   = 96 + 8,
    CGROM_112_8  = 112 + 8,
#if (DISPLAY_632_VERSION == DISPLAY_632_VERSION_2X)
    CGROM_128_8  = 128 + 8,
#endif
    CGROM_144_8  = 144 + 8,
    CGROM_160_8  = 160 + 8,
    CGROM_176_8  = 176 + 8,
    CGROM_192_8  = 192 + 8,
    CGROM_208_8  = 208 + 8,
    CGROM_224_8  = 224 + 8,
    CGROM_240_8  = 240 + 8,
#if (DISPLAY_632_VERSION == DISPLAY_632_VERSION_2X)
    CGROM_16_9   = 16 + 9,
#endif
    CGROM_32_9   = 32 + 9,
    CGROM_48_9   = 48 + 9,
    CGROM_64_9   = 64 + 9,
    CGROM_80_9   = 80 + 9,
    CGROM_96_9   = 96 + 9,
    CGROM_112_9  = 112 + 9,
#if (DISPLAY_632_VERSION == DISPLAY_632_VERSION_2X)
    CGROM_128_9  = 128 + 9,
#endif
    CGROM_144_9  = 144 + 9,
    CGROM_160_9  = 160 + 9,
    CGROM_176_9  = 176 + 9,
    CGROM_192_9  = 192 + 9,
    CGROM_208_9  = 208 + 9,
    CGROM_224_9  = 224 + 9,
    CGROM_240_9  = 240 + 9,
#if (DISPLAY_632_VERSION == DISPLAY_632_VERSION_2X)
    CGROM_16_10  = 16 + 10,
#endif
    CGROM_32_10  = 32 + 10,
    CGROM_48_10  = 48 + 10,
    CGROM_64_10  = 64 + 10,
    CGROM_80_10  = 80 + 10,
    CGROM_96_10  = 96 + 10,
    CGROM_112_10 = 112 + 10,
#if (DISPLAY_632_VERSION == DISPLAY_632_VERSION_2X)
    CGROM_128_10 = 128 + 10,
#endif
    CGROM_144_10 = 144 + 10,
    CGROM_160_10 = 160 + 10,
    CGROM_176_10 = 176 + 10,
    CGROM_192_10 = 192 + 10,
    CGROM_208_10 = 208 + 10,
    CGROM_224_10 = 224 + 10,
    CGROM_240_10 = 240 + 10,
#if (DISPLAY_632_VERSION == DISPLAY_632_VERSION_2X)
    CGROM_16_11  = 16 + 11,
#endif
    CGROM_32_11  = 32 + 11,
    CGROM_48_11  = 48 + 11,
    CGROM_64_11  = 64 + 11,
    CGROM_80_11  = 80 + 11,
    CGROM_96_11  = 96 + 11,
    CGROM_112_11 = 112 + 11,
#if (DISPLAY_632_VERSION == DISPLAY_632_VERSION_2X)
    CGROM_128_11 = 128 + 11,
#endif
    CGROM_144_11 = 144 + 11,
    CGROM_160_11 = 160 + 11,
    CGROM_176_11 = 176 + 11,
    CGROM_192_11 = 192 + 11,
    CGROM_208_11 = 208 + 11,
    CGROM_224_11 = 224 + 11,
    CGROM_240_11 = 240 + 11,
#if (DISPLAY_632_VERSION == DISPLAY_632_VERSION_2X)
    CGROM_16_12  = 16 + 12,
#endif
    CGROM_32_12  = 32 + 12,
    CGROM_48_12  = 48 + 12,
    CGROM_64_12  = 64 + 12,
    CGROM_80_12  = 80 + 12,
    CGROM_96_12  = 96 + 12,
    CGROM_112_12 = 112 + 12,
#if (DISPLAY_632_VERSION == DISPLAY_632_VERSION_2X)
    CGROM_128_12 = 128 + 12,
#endif
    CGROM_144_12 = 144 + 12,
    CGROM_160_12 = 160 + 12,
    CGROM_176_12 = 176 + 12,
    CGROM_192_12 = 192 + 12,
    CGROM_208_12 = 208 + 12,
    CGROM_224_12 = 224 + 12,
    CGROM_240_12 = 240 + 12,
#if (DISPLAY_632_VERSION == DISPLAY_632_VERSION_2X)
    CGROM_16_13  = 16 + 13,
#endif
    CGROM_32_13  = 32 + 13,
    CGROM_48_13  = 48 + 13,
    CGROM_64_13  = 64 + 13,
    CGROM_80_13  = 80 + 13,
    CGROM_96_13  = 96 + 13,
    CGROM_112_13 = 112 + 13,
#if (DISPLAY_632_VERSION == DISPLAY_632_VERSION_2X)
    CGROM_128_13 = 128 + 13,
#endif
    CGROM_144_13 = 144 + 13,
    CGROM_160_13 = 160 + 13,
    CGROM_176_13 = 176 + 13,
    CGROM_192_13 = 192 + 13,
    CGROM_208_13 = 208 + 13,
    CGROM_224_13 = 224 + 13,
    CGROM_240_13 = 240 + 13,
#if (DISPLAY_632_VERSION == DISPLAY_632_VERSION_2X)
    CGROM_16_14  = 16 + 14,
#endif
    CGROM_32_14  = 32 + 14,
    CGROM_48_14  = 48 + 14,
    CGROM_64_14  = 64 + 14,
    CGROM_80_14  = 80 + 14,
    CGROM_96_14  = 96 + 14,
    CGROM_112_14 = 112 + 14,
#if (DISPLAY_632_VERSION == DISPLAY_632_VERSION_2X)
    CGROM_128_14 = 128 + 14,
#endif
    CGROM_144_14 = 144 + 14,
    CGROM_160_14 = 160 + 14,
    CGROM_176_14 = 176 + 14,
    CGROM_192_14 = 192 + 14,
    CGROM_208_14 = 208 + 14,
    CGROM_224_14 = 224 + 14,
    CGROM_240_14 = 240 + 14,
#if (DISPLAY_632_VERSION == DISPLAY_632_VERSION_2X)
    CGROM_16_15  = 16 + 15,
#endif
    CGROM_32_15  = 32 + 15,
    CGROM_48_15  = 48 + 15,
    CGROM_64_15  = 64 + 15,
    CGROM_80_15  = 80 + 15,
    CGROM_96_15  = 96 + 15,
    CGROM_112_15 = 112 + 15,
#if (DISPLAY_632_VERSION == DISPLAY_632_VERSION_2X)
    CGROM_128_15 = 128 + 15,
#endif
    CGROM_144_15 = 144 + 15,
    CGROM_160_15 = 160 + 15,
    CGROM_176_15 = 176 + 15,
    CGROM_192_15 = 192 + 15,
    CGROM_208_15 = 208 + 15,
    CGROM_224_15 = 224 + 15,
    CGROM_240_15 = 240 + 15
};
#endif

// Forward declaration of SoftwareSerial class.
class SoftwareSerial;

/**
 * @brief Supported BAUD rates (see SW1).
 */
enum class DisplayBaudRate : int {
    BAUD_2400 = 2400,
    BAUD_4800 = 4800,
    BAUD_9600 = 9600,
    BAUD_19200 = 19200
};

// The default serial BAUD rate to connect to the display at.
#define CF632_BAUD (int)DisplayBaudRate::BAUD_9600

/**
 * @brief Possible graph indices
 */
typedef enum {
	GRAPH_INDEX1,
	GRAPH_INDEX2,
	GRAPH_INDEX3,
	GRAPH_INDEX4
} GraphIndex;

/**
 * @brief Possible graph styles
 */
typedef enum {
	GRAPH_STYLE_THICK,
	GRAPH_STYLE_INVISIBLE,
	GRAPH_STYLE_STRIPED,
	GRAPH_STYLE_MEDIUM_CENTER,
	GRAPH_STYLE_MEDIUM_LOW,
	GRAPH_STYLE_MEDIUM_HIGH
} GraphStyle;

/**
 * @brief Display types.
 */
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
     * @param baud The baud rate to connect at. This should correspond to the
     * dip switch setting on the back of the display (SW1).
     */
    void begin(DisplayBaudRate baud);

	/**
	 * @brief begin Connect to the display and init.
	 * @param dt Specifies the display type.
	 */
	void begin(DisplayType dt);

    /**
     * @brief begin Connect to the display and init.
     * @param dt The display type.
     * @param baud The baud rate to connect at. This should correspond to the
     * dip switch setting on the back of the display (SW1).
     */
    void begin(DisplayType dt, DisplayBaudRate baud);

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
     * @brief print Prints string to the display.
     * @param message The string to print.
     */
    void print(String message);

    /**
     * @brief print Prints text from flash memory to the display.
     * @param fmsg A string stored in flash memory (instead of program memory)
     * using the F() macro.
     */
    void print(const __FlashStringHelper *fmsg);

    /**
     * @brief print Prints a number to the display.
     * @param num The number to print.
     */
    void print(uint8_t num);

#ifdef USE_CGROM_CHARS
    /**
     * @brief printCgRomChar Prints a charactor from the CGROM table (see
     * "Appendix C") at the current cursor position. NOTE: This does NOT
     * advance the cursor position upon printing the character. It is
     * recommended to call setCursorPos() prior to calling this method to
     * position the cursor where you want the character to go and then
     * call setCursorPos() again to put the cursor somewhere else.
     * @param chr The CGROM charactor code.
     */
    void printCgRomChar(CGRomChar chr);
#endif

    /**
     * @brief crlf Carriage return, line feed. This will move the
     * cursor to the left-most column of the next row (same as calling
     * carriageReturn() followed by lineFeed()).
     */
    void crlf();
};

#endif