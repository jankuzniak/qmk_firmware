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
#include "ysaren.h"

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
    SET_LAYER_ID(HSV_GRAY),
    SET_LAYER_SWITCHERS(HSV_VIBRANT_BLUE),
    SET_NON_CORNE_LIGHTS(HSV_BLACK)
);

// _SYMBOL
const rgblight_segment_t PROGMEM layer_symbol_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_ALL(HSV_GRAY),
    SET_LAYER_ID(HSV_THE_GRAPE_WAR_OF_97)
);

// _SYMBOL_35
const rgblight_segment_t PROGMEM layer_symbol_lights_35[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_ALL(HSV_GRAY),
    SET_LAYER_ID(HSV_THE_GRAPE_WAR_OF_97),
    SET_LAYER_SWITCHERS(HSV_VIBRANT_BLUE),
    SET_NON_CORNE_LIGHTS(HSV_BLACK)
);

// NAVIGATION
const rgblight_segment_t PROGMEM layer_navigation_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_ALL(HSV_GRAY),
    SET_LAYER_ID(HSV_DEEP_GREEN)
);

// NAVIGATION_35
const rgblight_segment_t PROGMEM layer_navigation_lights_35[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_ALL(HSV_GRAY),
    SET_LAYER_ID(HSV_DEEP_GREEN),
    SET_LAYER_SWITCHERS(HSV_VIBRANT_BLUE),
    SET_NON_CORNE_LIGHTS(HSV_BLACK)
);

// NUMPAD
const rgblight_segment_t PROGMEM layer_number_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_ALL(HSV_GRAY),
    SET_NUMBER(HSV_CADMIUM_YELLOW),
    SET_LAYER_ID(HSV_GIANTS_ORANGE)
);

const rgblight_segment_t PROGMEM layer_numpad_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_ALL(HSV_GRAY),
    SET_NUMPAD(HSV_CADMIUM_YELLOW),
    SET_LAYER_ID(HSV_CADMIUM_YELLOW)
);

// SWITCH   // light up top row
const rgblight_segment_t PROGMEM layer_switch_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_LAYER_ID(HSV_GIANTS_ORANGE),
    SET_NUMROW(HSV_GREEN)
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
    layer_number_lights,
    layer_switch_lights,
    layer_media_lights,

    layer_qwerty_lights_35,
    layer_symbol_lights_35,
    layer_navigation_lights_35,
    layer_numpad_lights
);

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, L_BASE) && layer_state_cmp(default_layer_state, L_QWERTY));
    rgblight_set_layer_state(1, layer_state_cmp(state, L_SYMBOLS));
    rgblight_set_layer_state(2, layer_state_cmp(state, L_NAVIGATION));
    rgblight_set_layer_state(3, layer_state_cmp(state, L_NUMBERS));
    rgblight_set_layer_state(4, layer_state_cmp(state, L_SWITCH));
    rgblight_set_layer_state(5, layer_state_cmp(state, L_MEDIA));

    rgblight_set_layer_state(6, layer_state_cmp(state, L_BASE) && layer_state_cmp(default_layer_state, L_QWERTY_35));
    rgblight_set_layer_state(7, layer_state_cmp(state, L_SYMBOLS_35));
    rgblight_set_layer_state(8, layer_state_cmp(state, L_NAVIGATION_35));
    rgblight_set_layer_state(9, layer_state_cmp(state, L_NUMPAD));

    return state;
}

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
    rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT); // haven't found a way to set this in a more useful way
}
