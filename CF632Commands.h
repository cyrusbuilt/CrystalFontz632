/*
CF632Commands.h - Multi-instance CrystalFontz 632/634 2x16 LCD
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

#ifndef CF632Commands_h
#define CF632Commands_h

// The following is the instruction set for the CrystalFontz 16x2 (632)
// intelligent serial interface display. These commands are sent to the
// display as bytes that represent ASCII codes. This instruction set is
// also compatible with the 20x4 (634) display model as well, but the
// size definitions (CF632_COLUMNS and CF632_ROWS) would have to be changed
// to 20 and 4, respectively. Note: This command set is known to be compatible
// with hardware v2.0 and firmware v2.0 (and probably higher).

// CrystalFontz 632/634 command definitions
#define CMD632_NULL 0                    // Null
#define CMD632_CURSOR_HOME 1             // Cursor home position
#define CMD632_HIDE_DISPLAY 2            // Hide display
#define CMD632_RESTORE_DISPLAY 3         // Restore display
#define CMD632_HIDE_CURSOR 4             // Hide the cursor
#define CMD632_UNDERLINE_CURSOR 5        // Show underline cursor
#define CMD632_BLOCK_CURSOR 6            // Show block cursor
#define CMD632_INVERT_BLOCK_CURSOR 7     // Show inverting block cursor
#define CMD632_BACKSPACE 8               // Backspace (destructive)
#define CMD632_CTRL_BOOTSCREEN 9         // Control the boot screen
#define CMD632_LINE_FEED 10              // Line feed
#define CMD632_DEL_IN_PLACE 11           // Delete in place
#define CMD632_FORM_FEED 12              // Form feed (clear display)
#define CMD632_CARRIAGE_RETURN 13        // Carriage return
#define CMD632_CTRL_BACKLIGHT 14         // Backlight control
#define CMD632_CTRL_CONTRAST 15          // Contrast control
#define CMD632_SET_CURSOR_POS 17         // Set cursor position (column and row)
#define CMD632_HORIZ_BAR_GRAPH 18        // Horizontal bar graph
#define CMD632_SCROLL_ON 19              // Turn scrolling ON
#define CMD632_SCROLL_OFF 20             // Turn scrolling OFF
#define CMD632_SET_SCROLL_CHARS 21       // Set scrolling marquee characters
#define CMD632_MARQUEE_ENABLE 22         // Enable scrolling marquee
#define CMD632_WRAP_ON 23                // Line wrapping ON
#define CMD632_WRAP_OFF 24               // Line wrapping OFF
#define CMD632_SET_CUST_BITMAP 25        // Set custom character bitmap
#define CMD632_REBOOT 26                 // Reboot
#define CMD632_ESCAPE 27                 // Escape sequence prefix
#define CMD632_DIRECT_SEND 30            // Send data directly to the LCD controller
#define CMD632_SHOW_INFO 31              // Show the information screen

// Display dimensions
// NOTE: These *can* be modified to support screens of different dimensions
// such as 20x4.
#define CF632_COLUMNS 16                 // For a 16x2 display
#define CF632_ROWS 2

// Contrast limits
#define CF632_CONTRAST_MIN 0
#define CF632_CONTRAST_MAX 100

// Brightness limits
#define CF632_BRIGHTNESS_MIN 0
#define CF632_BRIGHTNESS_MAX 100

// Graph indices
#define CF632_GRAPH_INDEX1 0
#define CF632_GRAPH_INDEX2 1
#define CF632_GRAPH_INDEX3 2
#define CF632_GRAPH_INDEX4 3

// Graph styles
#define CF632_GRAPH_STYLE_THICK 255      // A thick bar
#define CF632_GRAPH_STYLE_INVISIBLE 0    // Will not be visible (all pixels are off)
#define CF632_GRAPH_STYLE_STRIPED 85     // A striped bar
#define CF632_GRAPH_STYLE_MED_CENT 60    // Medium width bar, centered
#define CF632_GRAPH_STYLE_MED_LOW 15     // Medium width bar, low in the row
#define CF632_GRAPH_STYLE_MED_HIGH 240   // Medium width bar, high in the row

#endif