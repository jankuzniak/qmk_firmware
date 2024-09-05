/*
This is the c configuration file for the keymap

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

//#define USE_MATRIX_I2C

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 250U

/* Select hand configuration */

#define MASTER_LEFT
#undef SPLIT_USB_DETECT // fix for keyboard not being recognised at boot
// #define MASTER_RIGHT
// #define EE_HANDS

//#define QUICK_TAP_TERM 0
//#define TAPPING_TERM 100

#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD

#ifdef RGBLIGHT_ENABLE
    // #undef  RGBLED_NUM
    // #define RGBLED_NUM 54
    // #define RGBLED_SPLIT { 27, 27 } // haven't figured out how to use this yet
    #define RGBLIGHT_LAYERS
    #define RGBLIGHT_MAX_LAYERS 10

    #define RGBLIGHT_SLEEP
    #define RGB_DISABLE_WHEN_USB_SUSPENDED true // turn off effects when suspended

    // #define RGBLIGHT_EFFECT_BREATHING
    // #define RGBLIGHT_EFFECT_RAINBOW_MOOD
    // #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
    // #define RGBLIGHT_EFFECT_SNAKE
    // #define RGBLIGHT_EFFECT_KNIGHT
    // #define RGBLIGHT_EFFECT_CHRISTMAS
    // #define RGBLIGHT_EFFECT_STATIC_GRADIENT
    // #define RGBLIGHT_EFFECT_RGB_TEST
    // #define RGBLIGHT_EFFECT_ALTERNATING
    // #define RGBLIGHT_EFFECT_TWINKLE
    #define RGBLIGHT_LIMIT_VAL 120
    #define RGBLIGHT_HUE_STEP 10
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 17
#endif

#ifdef VIA_ENABLE
    #define DYNAMIC_KEYMAP_LAYER_COUNT 8
#endif
