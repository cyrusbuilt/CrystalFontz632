/*
CrystalFontz632.cpp - Multi-instance CrystalFontz 632/634 2x16 LCD
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

#include <Arduino.h>
#include <CrystalFontz632.h>
#include <CF632Commands.h>
#include <SoftwareSerial.h>
#include <WString.h>

CrystalFontz632::CrystalFontz632(uint8_t txPin)
	: _txPin(txPin),
	_backlightPin(0),
	_blEnabled(false),
	_hidden(false),
	_scroll(false),
	_wrap(false),
	_cursorHidden(false),
	_contrast(CF632_CONTRAST_DEFAULT),
	_brightness(CF632_BRIGHTNESS_DEFAULT),
	_type(DT_SIXTEENBYTWO) {
	// Note: The display does not send any data back,
	// so we don't need a receive pin (TX only).
	this->_lcd = new SoftwareSerial(0, this->_txPin);
}

CrystalFontz632::CrystalFontz632(uint8_t txPin, uint8_t backlighPin)
	: _txPin(txPin),
	_backlightPin(backlighPin),
	_blEnabled(false),
	_hidden(false),
	_scroll(false),
	_wrap(false),
	_cursorHidden(false),
	_contrast(CF632_CONTRAST_DEFAULT),
	_brightness(CF632_BRIGHTNESS_DEFAULT),
	_type(DT_SIXTEENBYTWO) {
	this->_lcd = new SoftwareSerial(0, this->_txPin);
}

CrystalFontz632::~CrystalFontz632() {
	this->end();
	delete this->_lcd;
}

void CrystalFontz632::begin() {
	this->_lcd->begin(CF632_BAUD);
	if (this->_backlightPin > 0) {
		// User provided a backlight pin, so set it up.
		pinMode(this->_backlightPin, OUTPUT);
	}
}

void CrystalFontz632::begin(DisplayType dt) {
	this->_type = dt;
	this->begin();
}

void CrystalFontz632::begin(DisplayType dt, DisplayBaudRate baud) {
	this->_lcd->begin((int)baud);
	this->begin(dt);
}

void CrystalFontz632::end() {
	this->_lcd->end();
}

void CrystalFontz632::sendCommand(byte cmd) {
	this->_lcd->write(cmd);
}

void CrystalFontz632::sendCommand(const byte buffer[], size_t size) {
	for (uint8_t i = 0; i < size; i++) {
		this->sendCommand(buffer[i]);
	}
}

void CrystalFontz632::rebootDisplay() {
	// The manual indicates this command needs to be sent twice.
	byte* buf = new byte[2];
	buf[0] = (byte)CMD632_REBOOT;
	buf[1] = (byte)CMD632_REBOOT;
	this->sendCommand(buf, 2);
	delete[] buf;
	delay(500); // Give it time to reboot.
}

void CrystalFontz632::clearDisplay() {
	// Send a form feed (clear), then make sure
	// the cursor is in the home position.
	this->sendCommand((byte)CMD632_FORM_FEED);
	delay(20);
	this->sendCommand((byte)CMD632_CURSOR_HOME);
	delay(20);
}

void CrystalFontz632::enableBacklight() {
	if (this->_blEnabled) {
		return;
	}

	// If user provided a backlight pin, then turn it on.
	// Otherwise, just set the brighness all the way up.
	if (this->_backlightPin > 0) {
		digitalWrite(this->_backlightPin, HIGH);
	}
	else {
		byte* buf = new byte[2];
		buf[0] = (byte)CMD632_CTRL_BACKLIGHT;
		buf[1] = (byte)CF632_BRIGHTNESS_MAX;
		this->sendCommand(buf, 2);
		delete[] buf;
	}
	this->_blEnabled = true;
}

void CrystalFontz632::disableBacklight() {
	if (!this->_blEnabled) {
		return;
	}

	// If user provided a backlight pin, then turn it off.
	// Otherwise, just set the brightness all the way down.
	if (this->_backlightPin > 0) {
		digitalWrite(this->_backlightPin, LOW);
	}
	else {
		byte* buf = new byte[2];
		buf[0] = (byte)CMD632_CTRL_BACKLIGHT;
		buf[1] = (byte)CF632_BRIGHTNESS_MIN;
		this->sendCommand(buf, 2);
		delete[] buf;
	}
	this->_blEnabled = false;
}

bool CrystalFontz632::isBacklightEnabled() {
	return this->_blEnabled;
}

void CrystalFontz632::cursorHome() {
	this->sendCommand((byte)CMD632_CURSOR_HOME);
	delay(10);
}

void CrystalFontz632::hideDisplay() {
	this->sendCommand((byte)CMD632_HIDE_DISPLAY);
	this->_hidden = true;
}

void CrystalFontz632::restoreDisplay() {
	this->sendCommand((byte)CMD632_RESTORE_DISPLAY);
	this->_hidden = false;
}

bool CrystalFontz632::isDisplayHidden() {
	return this->_hidden;
}

void CrystalFontz632::hideCursor() {
	this->sendCommand((byte)CMD632_HIDE_CURSOR);
	this->_cursorHidden = true;
}

void CrystalFontz632::showUnderlineCursor() {
	this->sendCommand((byte)CMD632_UNDERLINE_CURSOR);
	this->_cursorHidden = false;
}

void CrystalFontz632::showBlockCursor() {
	this->sendCommand((byte)CMD632_BLOCK_CURSOR);
	this->_cursorHidden = false;
}

void CrystalFontz632::showInvertingBlockCursor() {
	this->sendCommand((byte)CMD632_INVERT_BLOCK_CURSOR);
	this->_cursorHidden = false;
}

bool CrystalFontz632::isCursorShown() {
	return !this->_cursorHidden;
}

void CrystalFontz632::backspace() {
	this->sendCommand((byte)CMD632_BACKSPACE);
}

void CrystalFontz632::lineFeed() {
	this->sendCommand((byte)CMD632_LINE_FEED);
	delay(10);
}

void CrystalFontz632::deleteInPlace() {
	this->sendCommand((byte)CMD632_DEL_IN_PLACE);	
}

void CrystalFontz632::formFeed() {
	this->sendCommand((byte)CMD632_FORM_FEED);
	delay(10);
}

void CrystalFontz632::carriageReturn() {
	this->sendCommand((byte)CMD632_CARRIAGE_RETURN);
}

void CrystalFontz632::setContrast(uint8_t level) {
	if (level < CF632_CONTRAST_MIN) {
		level = CF632_CONTRAST_MIN;
	}

	if (level > CF632_CONTRAST_MAX) {
		level  = CF632_CONTRAST_MAX;
	}

	byte* buf = new byte[2];
	buf[0] = (byte)CMD632_CTRL_CONTRAST;
	buf[1] = (byte)level;
	this->sendCommand(buf, 2);
	delete[] buf;
	this->_contrast = level;
}

uint8_t CrystalFontz632::getContrast() {
	return this->_contrast;
}

void CrystalFontz632::setBrightness(uint8_t level) {
	if (level < CF632_BRIGHTNESS_MIN) {
		level = CF632_BRIGHTNESS_MIN;
	}

	if (level > CF632_BRIGHTNESS_MAX) {
		level = CF632_BRIGHTNESS_MAX;
	}

	byte* buf = new byte[2];
	buf[0] = (byte)CMD632_CTRL_BACKLIGHT;
	buf[1] = (byte)level;
	this->sendCommand(buf, 2);
	delete[] buf;
	this->_brightness = level;
}

uint8_t CrystalFontz632::getBrightness() {
	return this->_brightness;
}

void CrystalFontz632::setCursorPos(uint8_t column, uint8_t row) {
	if (column < 0) {
		column = 0;
	}

	if (row < 0) {
		row = 0;
	}

	// Adjust max dimensions according to display type.
	switch (this->_type) {
		case DT_SIXTEENBYTWO:
			if (column > (CF632_COLUMNS - 1)) {
				column = (CF632_COLUMNS - 1);
			}

			if (row > (CF632_ROWS - 1)) {
				row = (CF632_ROWS -1);
			}
			break;
		case DT_TWENTYBYFOUR:
			if (column > (CF634_COLUMNS - 1)) {
				column = (CF634_COLUMNS - 1);
			}

			if (row > (CF634_ROWS - 1)) {
				row = (CF634_ROWS - 1);
			}
			break;
	}

	byte* buf = new byte[3];
	buf[0] = (byte)CMD632_SET_CURSOR_POS;
	buf[1] = (byte)column;
	buf[2] = (byte)row;
	this->sendCommand(buf, 3);
	delete[] buf;
}

void CrystalFontz632::setBarGraph(GraphIndex index, GraphStyle style, uint8_t startCol, uint8_t endCol, uint8_t len, uint8_t row) {
	byte idx;
	switch (index) {
		case GRAPH_INDEX1:
			idx = (byte)CF632_GRAPH_INDEX1;
			break;
		case GRAPH_INDEX2:
			idx = (byte)CF632_GRAPH_INDEX2;
			break;
		case GRAPH_INDEX3:
			idx = (byte)CF632_GRAPH_INDEX3;
			break;
		case GRAPH_INDEX4:
			idx = (byte)CF632_GRAPH_INDEX4;
			break;
	}

	byte s;
	switch (style) {
		case GRAPH_STYLE_THICK:
			s = (byte)CF632_GRAPH_STYLE_THICK;
			break;
		case GRAPH_STYLE_INVISIBLE:
			s = (byte)CF632_GRAPH_STYLE_INVISIBLE;
			break;
		case GRAPH_STYLE_STRIPED:
			s = (byte)CF632_GRAPH_STYLE_STRIPED;
			break;
		case GRAPH_STYLE_MEDIUM_CENTER:
			s = (byte)CF632_GRAPH_STYLE_MED_CENT;
			break;
		case GRAPH_STYLE_MEDIUM_LOW:
			s = (byte)CF632_GRAPH_STYLE_MED_LOW;
			break;
		case GRAPH_STYLE_MEDIUM_HIGH:
			s = (byte)CF632_GRAPH_STYLE_MED_HIGH;
			break;
	}

	// Make sure start and end columns are valid. Also make sure the row is legit.
	if (startCol < 0) {
		startCol = 0;
	}

	if (endCol < 0) {
		endCol = 0;
	}

	if (row < 0) {
		row = 0;
	}

	// Adjust max dimensions according to display type.
	switch (this->_type) {
		case DT_SIXTEENBYTWO:
			if (startCol > (CF632_COLUMNS - 1)) {
				startCol = (CF632_COLUMNS - 1);
			}

			if (endCol > (CF632_COLUMNS - 1)) {
				endCol = (CF632_COLUMNS - 1);
			}

			if (row > (CF632_ROWS - 1)) {
				row = (CF632_ROWS - 1);
			}
			break;
		case DT_TWENTYBYFOUR:
			if (startCol > (CF634_COLUMNS - 1)) {
				startCol = (CF634_COLUMNS - 1);
			}

			if (endCol > (CF634_COLUMNS - 1)) {
				endCol = (CF634_COLUMNS - 1);
			}

			if (row > (CF634_ROWS - 1)) {
				row = (CF634_ROWS - 1);
			}
			break;
	}

	if (endCol > startCol) {
		// Create the command buffer with all params.
		byte* buf = new byte[7];
		buf[0] = (byte)CMD632_HORIZ_BAR_GRAPH;
		buf[1] = idx;
		buf[2] = s;
		buf[3] = (byte)startCol;
		buf[4] = (byte)endCol;
		buf[5] = (byte)len;
		buf[6] = (byte)row;

		// Send the command and destroy the buffer.
		this->sendCommand(buf, 7);
		delete[] buf;
	}
}

void CrystalFontz632::scrollOn() {
	if (this->_scroll) {
		return;
	}
	this->sendCommand((byte)CMD632_SCROLL_ON);
	this->_scroll = true;
}

void CrystalFontz632::scrollOff() {
	if (!this->_scroll) {
		return;
	}
	this->sendCommand((byte)CMD632_SCROLL_OFF);
	this->_scroll = false;
}

bool CrystalFontz632::isScrollOn() {
	return this->_scroll;
}

void CrystalFontz632::wrapOn() {
	if (this->_wrap) {
		return;
	}
	this->sendCommand((byte)CMD632_WRAP_ON);
	this->_wrap = true;
}

void CrystalFontz632::wrapOff() {
	if (!this->_wrap) {
		return;
	}
	this->sendCommand((byte)CMD632_WRAP_OFF);
	this->_wrap = false;
}

bool CrystalFontz632::isWrapOn() {
	return this->_wrap;
}

void CrystalFontz632::showInfoScreen() {
	this->sendCommand((byte)CMD632_SHOW_INFO);
}

void CrystalFontz632::print(char* message) {
	this->_lcd->print(message);
}

void CrystalFontz632::print(String message) {
	this->_lcd->print(message);
}

void CrystalFontz632::print(const __FlashStringHelper *fmsg) {
	this->_lcd->print(fmsg);
}

void CrystalFontz632::print(uint8_t num) {
	this->_lcd->print(num, DEC);
}

#ifdef USE_CGROM_CHARS
void CrystalFontz632::printCgRomChar(CGRomChar chr) {
	this->_lcd->write((byte)chr);
}
#endif

void CrystalFontz632::crlf() {
	this->carriageReturn();
	this->lineFeed();
}