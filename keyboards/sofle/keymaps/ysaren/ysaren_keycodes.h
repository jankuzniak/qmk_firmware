/* Copyright 2021 Joshua T.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once
#include "quantum.h"

// Custom keycodes and macros
enum userspace_custom_keycodes {
    // USER_CAPS_WORD_ENABLE
    KC_QWERTY = SAFE_RANGE,
    KC_SYMBOLS,
    KC_NAVI,
    KC_NUMPAD,
    KC_SWITCH,

    KC_QWERTY_35,
    KC_SYMBOLS_35,
    KC_NAVI_35,
    KC_SWITCH_35,

    OS_SFT,
    OS_CTL,
    OS_ALT,
    OS_GUI,

    KC_NUMWORD,

    DYNAMIC_MACRO_RANGE
};
