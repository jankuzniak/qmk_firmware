 /* Copyright 2021 Dane Evans
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
  // SOFLE RGB
#include "ysaren_layers.h"

#define L_HAND 0
#define R_HAND L_HAND + 35

// Light combinations
#define SET_ALL(...) \
    {0, 2 * 35, __VA_ARGS__}

#define SET_LAYER_SWITCHERS(...) \
    {L_HAND + 26, 1, __VA_ARGS__}, \
    {R_HAND + 25, 1, __VA_ARGS__}

#define SET_UNDERGLOW(...) \
    {L_HAND + 0, 6, __VA_ARGS__}, \
    {R_HAND + 0, 6, __VA_ARGS__}

#define SET_NUMPAD(...) \
    {R_HAND + 15, 5, __VA_ARGS__}, \
    {R_HAND + 22, 3, __VA_ARGS__}, \
    {R_HAND + 27, 3, __VA_ARGS__}

#define SET_NUMROW(...) \
    {L_HAND + 10, 2, __VA_ARGS__}, \
    {R_HAND + 10, 2, __VA_ARGS__}, \
    {L_HAND + 20, 2, __VA_ARGS__}, \
    {R_HAND + 20, 2, __VA_ARGS__}, \
    {L_HAND + 30, 2, __VA_ARGS__}, \
    {R_HAND + 30, 2, __VA_ARGS__}

#define SET_INNER_COL(...) \
    {L_HAND + 33, 4, __VA_ARGS__}, \
    {R_HAND + 33, 4, __VA_ARGS__}

#define SET_OUTER_COL(...) \
    {L_HAND + 7, 4, __VA_ARGS__}, \
    {R_HAND + 7, 4, __VA_ARGS__}


#define SET_THUMB_CLUSTER(...) \
    {L_HAND + 25, 2, __VA_ARGS__}, \
    {R_HAND + 25, 2, __VA_ARGS__}

#define SET_BOTTOM_MODIFIERS(...) \
    {L_HAND + 6, 1, __VA_ARGS__}, \
    {R_HAND + 6, 1, __VA_ARGS__}, \
    {L_HAND + 15, 2, __VA_ARGS__}, \
    {R_HAND + 15, 2, __VA_ARGS__}

#define SET_NON_CORNE_LIGHTS(...) \
    SET_NUMROW(__VA_ARGS__), \
    {L_HAND + 6, 1, __VA_ARGS__}, \
    {R_HAND + 6, 1, __VA_ARGS__}, \
    {L_HAND + 15, 1, __VA_ARGS__}, \
    {R_HAND + 15, 1, __VA_ARGS__}

#define SET_LAYER_ID(...)     \
    SET_UNDERGLOW(__VA_ARGS__), \
    SET_BOTTOM_MODIFIERS(__VA_ARGS__), \
    SET_OUTER_COL(__VA_ARGS__), \
    SET_THUMB_CLUSTER(__VA_ARGS__), \
    SET_LAYER_SWITCHERS(HSV_CADMIUM_YELLOW)


char layer_state_str[70];
// Now define the array of layers. Later layers take precedence

// QWERTY,
const rgblight_segment_t PROGMEM layer_qwerty_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_ALL(HSV_GRAY),
    SET_LAYER_ID(HSV_GRAY)
);

// QWERTY_35,
const rgblight_segment_t PROGMEM layer_qwerty_lights_35[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_ALL(HSV_GRAY),
    SET_NON_CORNE_LIGHTS(HSV_RED),
    SET_LAYER_ID(HSV_GRAY)
);

// _SYMBOL
const rgblight_segment_t PROGMEM layer_symbol_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_ALL(HSV_GRAY),
    SET_LAYER_ID(HSV_THE_GRAPE_WAR_OF_97)
);

// _SYMBOL_35
const rgblight_segment_t PROGMEM layer_symbol_lights_35[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_ALL(HSV_GRAY),
    SET_NON_CORNE_LIGHTS(HSV_RED),
    SET_LAYER_ID(HSV_THE_GRAPE_WAR_OF_97)
);

// NAVIGATION
const rgblight_segment_t PROGMEM layer_navigation_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_ALL(HSV_GRAY),
    SET_LAYER_ID(HSV_DEEP_GREEN)
);

// NAVIGATION_35
const rgblight_segment_t PROGMEM layer_navigation_lights_35[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_ALL(HSV_GRAY),
    SET_NON_CORNE_LIGHTS(HSV_RED),
    SET_LAYER_ID(HSV_DEEP_GREEN)
);

// NUMPAD
const rgblight_segment_t PROGMEM layer_numpad_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_ALL(HSV_GRAY),
    SET_NUMPAD(HSV_CADMIUM_YELLOW),
    SET_LAYER_ID(HSV_GIANTS_ORANGE)
);

// SWITCH   // light up top row
const rgblight_segment_t PROGMEM layer_switch_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_LAYER_ID(HSV_GIANTS_ORANGE),
    SET_NUMROW(HSV_GREEN)
);

// SWITCH_35   // light up top row
const rgblight_segment_t PROGMEM layer_switch_lights_35[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_LAYER_ID(HSV_GIANTS_ORANGE),
    SET_NON_CORNE_LIGHTS(HSV_RED)
);

// MEDIA
const rgblight_segment_t PROGMEM layer_media_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_ALL(HSV_BLACK),
    SET_LAYER_ID(HSV_BLACK),

    {L_HAND + 32, 2, HSV_GIANTS_ORANGE},       // T, G
    {L_HAND + 29, 2, HSV_THE_GRAPE_WAR_OF_97}, // R, F

    {R_HAND + 10, 2, HSV_GIANTS_ORANGE},  // -
    {R_HAND + 13, 1, HSV_CADMIUM_YELLOW}, // ;
    {R_HAND + 18, 1, HSV_GIANTS_ORANGE},  // L
    {R_HAND +  8, 1, HSV_GIANTS_ORANGE}   // '

);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    layer_qwerty_lights,
    layer_symbol_lights,
    layer_navigation_lights,
    layer_numpad_lights,
    layer_switch_lights,
    layer_media_lights,

    layer_qwerty_lights_35,
    layer_symbol_lights_35,
    layer_navigation_lights_35,
    layer_switch_lights_35
);

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, L_BASE) && layer_state_cmp(default_layer_state, L_QWERTY));
    rgblight_set_layer_state(1, layer_state_cmp(state, L_SYMBOLS));
    rgblight_set_layer_state(2, layer_state_cmp(state, L_NAVIGATION));
    rgblight_set_layer_state(3, layer_state_cmp(state, L_NUMPAD));
    rgblight_set_layer_state(4, layer_state_cmp(state, L_SWITCH));
    rgblight_set_layer_state(5, layer_state_cmp(state, L_MEDIA));

    rgblight_set_layer_state(6, layer_state_cmp(state, L_BASE) && layer_state_cmp(default_layer_state, L_QWERTY_35));
    rgblight_set_layer_state(7, layer_state_cmp(state, L_SYMBOLS_35));
    rgblight_set_layer_state(8, layer_state_cmp(state, L_NAVIGATION_35));
    rgblight_set_layer_state(9, layer_state_cmp(state, L_SWITCH_35));

    return state;
}

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
    rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT); // haven't found a way to set this in a more useful way
}

    // {R_HAND + 20, 1, HSV_RED},
    // {R_HAND + 20 + 1, 1, HSV_GREEN},
    // {R_HAND + 20 + 2, 1, HSV_BLUE},
    // {R_HAND + 20 + 3, 1, HSV_ORANGE},
    // {R_HAND + 20 + 4, 1, HSV_TEAL},
    // {R_HAND + 20 + 5, 1, HSV_PINK},
    // {R_HAND + 20 + 6, 1, HSV_CHARTREUSE},
    // {R_HAND + 20 + 7, 1, HSV_AZURE},
    // {R_HAND + 20 + 8 , 1, HSV_MAGENTA},
    // {R_HAND + 20 + 9 , 1, HSV_PURPLE}



/*
  // Physical Layout
  // Columns
  // 0  1  2  3  4  5  6  7  8  9  10 11 12 13
  //                                           ROWS
  // 10 11 20 21 30 31       31 30 21 20 11 10  0
  //    00    01    02       00    01    02
  // 09 12 19 22 29 32       32 29 22 19 12 09  1
  //
  // 08 13 18 23 28 33       33 28 23 18 13 08  2
  //
  // 07 14 17 24 27 34       34 27 24 17 14 07  3
  //
  //     06 15 16 25 26     26 25 16 15 06      4
  //    05    04    03       03    04    05

*/
