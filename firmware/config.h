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

#include "config_common.h"

/* choose which side of the keyboard to build the firmware for */
//#define LEFT

/* USB Device descriptor parameter */
#define VENDOR_ID    0x444D
#define MANUFACTURER vE5li
#define PRODUCT_ID   0x3435
#define DEVICE_VER   0x0001

/* mouse config */
#define MOUSEKEY_INTERVAL    20
#define MOUSEKEY_DELAY       0
#define MOUSEKEY_TIME_TO_MAX 10
#define MOUSEKEY_MAX_SPEED   7


#define MOUSEKEY_WHEEL_INTERVAL 20
#define MOUSEKEY_WHEEL_DELAY 0
#define MOUSEKEY_WHEEL_TIME_TO_MAX 10
#define MOUSEKEY_WHEEL_MAX_SPEED 5
#define MOUSEKEY_WHEEL_DELAY 0

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

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
#define RGB_DI_PIN F1

/* wiring of right half */
#else
#define DIODE_DIRECTION COL2ROW
#define MATRIX_ROW_PINS { B1, B2, D3, D6, D7 }
#define MATRIX_COL_PINS { C6, C7, D4, B5, B4 }
#define RGB_DI_PIN B0
#endif

/*#define RGBLIGHT_LED_MAP { 1, 2, 3, 4, 5, \
                           6, 7, 8, 9, 10, \
                           11, 12, 13, 14, 15, \
                           16, 17, 18, 19, 20, \
                           21, 22, 23 }*/

/* pin to detect handedness */
#define SPLIT_HAND_PIN D6

/* typing behaviour */
#define PERMISSIVE_HOLD
#define TAPPING_FORCE_HOLD

/* number of leds on each half */
#define RGBLED_NUM 44
#define RGBLED_SPLIT { 22, 22 }

/* led brightness and animations */
#define RGBLIGHT_LIMIT_VAL 150
#define RGBLIGHT_VAL_STEP 30
#define RGBLIGHT_ANIMATIONS

/* temporary */
#define SPLIT_USB_DETECT
