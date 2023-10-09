/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

/* choose which side of the keyboard to build the firmware for */
//#define LEFT

/* by default the right side will always be the master and handedness
 * is hardcoded into the firmware, which means that you are forced
 * to connect the right side to your device for the keyboard to work.
 * you can enable checking for a usb connection at runtime to make both
 * sides work as master at the cost of longer start times and your
 * device needing to be powered on when plugging in the keyboard*/
//#define DYNAMIC_HANDEDNESS_CHECK

/* mouse config */
#define MOUSEKEY_INTERVAL    20
#define MOUSEKEY_DELAY       0
#define MOUSEKEY_TIME_TO_MAX 10
#define MOUSEKEY_MAX_SPEED   7

/* mouse wheel config */
#define MOUSEKEY_WHEEL_INTERVAL 20
#define MOUSEKEY_WHEEL_DELAY 0
#define MOUSEKEY_WHEEL_TIME_TO_MAX 10
#define MOUSEKEY_WHEEL_MAX_SPEED 5
#define MOUSEKEY_WHEEL_DELAY 0

/* serial pin for both halfs */
#define USE_SERIAL
#define SOFT_SERIAL_PIN D0

/* key matrix size */
#define MATRIX_ROWS 10
#define MATRIX_COLS 5

/* wiring of left half */
#ifdef LEFT
#define DIODE_DIRECTION ROW2COL
#define MATRIX_ROW_PINS { F0, F5, F6, C7, C6 }
#define MATRIX_COL_PINS { F7, D4, D5, D2, D3 }
#define WS2812_DI_PIN F1

/* wiring of right half */
#else
#define DIODE_DIRECTION COL2ROW
#define MATRIX_ROW_PINS { B1, B2, D3, D6, D7 }
#define MATRIX_COL_PINS { C6, C7, D4, B5, B4 }
#define WS2812_DI_PIN B0
#endif

/* detecting handedness */
#ifdef DYNAMIC_HANDEDNESS_CHECK
#define SPLIT_HAND_PIN D6
#define SPLIT_USB_DETECT
#endif

/* typing behaviour */
#define PERMISSIVE_HOLD
#define HOLD_ON_OTHER_KEY_PRESS
#define QUICK_TAP_TERM 0

/* number of leds on each half */
#define RGBLED_NUM 44
#define RGBLED_SPLIT { 22, 22 }

/* led brightness and animations */
#define RGBLIGHT_LIMIT_VAL 200
#define RGBLIGHT_VAL_STEP 50
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL

/* remap the leds to make both sides symetrical */
#define RGBLIGHT_LED_MAP { 0, 1, 2, 3, 4, \
                           5, 6, 7, 8, 9, \
                           10, 11, 12, 13, 14, \
                           15, 16, 17, 18, 19, \
                           20, 21, \
                           26, 25, 24, 23, 22, \
                           31, 30, 29, 28, 27, \
                           36, 35, 34, 33, 32, \
                           41, 40, 39, 38, 37, \
                           43, 42 }
