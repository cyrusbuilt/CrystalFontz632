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

CrystalFontz632::CrystalFontz632(uint8_t txPin)
	: _txPin(txPin), _backlightPin(0) {
	// Note: The display does not send any data back,
	// so we don't need a receive pin (TX only).
	this->_lcd = new SoftwareSerial(0, this->_txPin);
}

CrystalFontz632::CrystalFontz632(uint8_t txPin, uint8_t backlighPin)
	: _txPin(txPin), _backlightPin(backlighPin) {
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

void CrystalFontz632::end() {
	this->_lcd->end();
}

void CrystalFontz632::sendCommand(byte cmd) {
	this->_lcd->write(cmd);
}

void CrystalFontz632::rebootDisplay() {
	// The manual indicates this command needs to be sent twice.
	this->sendCommand((byte)CMD632_REBOOT);
	this->sendCommand((byte)CMD632_REBOOT);
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
	// If user provided a backlight pin, then turn it on.
	// Otherwise, just set the brighness all the way up.
	if (this->_backlightPin > 0) {
		digitalWrite(this->_backlightPin, HIGH);
	}
	else {
		this->sendCommand((byte)CMD632_CTRL_BACKLIGHT);
		this->sendCommand((byte)CF632_BRIGHTNESS_MAX);
	}
	this->_blEnabled = true;
}

void CrystalFontz632::disableBacklight() {
	// If user provided a backlight pin, then turn it off.
	// Otherwise, just set the brightness all the way down.
	if (this->_backlightPin > 0) {
		digitalWrite(this->_backlightPin, LOW);
	}
	else {
		this->sendCommand((byte)CMD632_CTRL_BACKLIGHT);
		this->sendCommand((byte)CF632_BRIGHTNESS_MIN);
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

	this->sendCommand((byte)CMD632_CTRL_CONTRAST);
	this->sendCommand((byte)level);
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

	this->sendCommand((byte)CMD632_CTRL_BACKLIGHT);
	this->sendCommand((byte)level);
	this->_brightness = level;
}

uint8_t CrystalFontz632::getBrightness() {
	return this->_brightness;
}

void CrystalFontz632::setCursorPos(uint8_t column, uint8_t row) {
	if (column < 0) {
		column = 0;
	}

	if (column > (CF632_COLUMNS - 1)) {
		column = (CF632_COLUMNS - 1);
	}

	if (row < 0) {
		row = 0;
	}

	if (row > (CF632_ROWS - 1)) {
		row = (CF632_ROWS - 1);
	}

	this->sendCommand((byte)CMD632_SET_CURSOR_POS);
	this->sendCommand((byte)column);
	this->sendCommand((byte)row);
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
	if ((startCol >= 0) && (startCol < CF632_COLUMNS) &&
		(endCol > startCol) && (endCol < CF632_COLUMNS) &&
		(row >= 0) && (row < CF632_ROWS)) {
		this->sendCommand((byte)CMD632_HORIZ_BAR_GRAPH);
		this->sendCommand(idx);
		this->sendCommand(s);
		this->sendCommand((byte)startCol);
		this->sendCommand((byte)endCol);
		this->sendCommand((byte)len);
		this->sendCommand((byte)row);
	}
}

void CrystalFontz632::scrollOn() {
	this->sendCommand((byte)CMD632_SCROLL_ON);
	this->_scroll = true;
}

void CrystalFontz632::scrollOff() {
	this->sendCommand((byte)CMD632_SCROLL_OFF);
	this->_scroll = false;
}

bool CrystalFontz632::isScrollOn() {
	return this->_scroll;
}

void CrystalFontz632::wrapOn() {
	this->sendCommand((byte)CMD632_WRAP_ON);
	this->_wrap = true;
}

void CrystalFontz632::wrapOff() {
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

void CrystalFontz632::crlf() {
	this->carriageReturn();
	this->lineFeed();
}