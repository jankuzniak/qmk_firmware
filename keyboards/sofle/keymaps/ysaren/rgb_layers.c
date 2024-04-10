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
#include "ysaren_sofle.h"

char layer_state_str[70];
// Now define the array of layers. Later layers take precedence

// QWERTY,
const rgblight_segment_t PROGMEM layer_qwerty_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_ALL(HSV_ALPHAS),
    SET_LAYER_ID(HSV_ALPHAS)
);

// QWERTY_35,
const rgblight_segment_t PROGMEM layer_qwerty_lights_35[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_ALL(HSV_ALPHAS),
    SET_LAYER_ID(HSV_ALPHAS),
    SET_NON_CORNE_LIGHTS(HSV_BLACK)
);

// _SYMBOL
const rgblight_segment_t PROGMEM layer_symbol_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_ALL(HSV_ALPHAS),
    SET_HAND(R_HAND, HSV_BLACK),
    SET_OSM(R_HAND, 2),
    SET_BRACKETS(),
    SET_LAYER_ID(HSV_MODS)
);

// _SYMBOL_35
const rgblight_segment_t PROGMEM layer_symbol_lights_35[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_ALL(HSV_ALPHAS),
    SET_HAND(R_HAND, HSV_BLACK),
    SET_OSM(R_HAND, 2),
    SET_BRACKETS(),
    {R_HAND + led_index[1][5], 1, HSV_ALPHAS},
    {R_HAND + led_index[2][5], 1, HSV_ALPHAS},
    {R_HAND + led_index[3][5], 1, HSV_ALPHAS},
    {R_HAND + led_index[3][3], 1, HSV_ALPHAS},
    {R_HAND + led_index[3][2], 1, HSV_ALPHAS},
    SET_LAYER_ID(HSV_MODS),
    SET_NON_CORNE_LIGHTS(HSV_BLACK)
);

// NAVIGATION
const rgblight_segment_t PROGMEM layer_navigation_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_ALL(HSV_ALPHAS),
    SET_OSM(L_HAND, 1),
    SET_NAVIGATION(),
    SET_LAYER_ID(HSV_NAVIGATION)
);

// NAVIGATION_35
const rgblight_segment_t PROGMEM layer_navigation_lights_35[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_ALL(HSV_ALPHAS),
    SET_OSM(L_HAND, 1),
    SET_NAVIGATION(),
    {R_HAND + led_index[3][4], 1, HSV_LAYER_SWITCH}, // L_NUMBERS
    {R_HAND + led_index[4][2], 1, HSV_LAYER_SWITCH}, // L_NUMPAD
    SET_LAYER_ID(HSV_NAVIGATION),
    SET_NON_CORNE_LIGHTS(HSV_BLACK)
);

// NUMBERS
const rgblight_segment_t PROGMEM layer_number_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_ALL(HSV_BLACK),
    SET_ROW_1(HSV_ALPHAS),
    SET_ROW_2(HSV_NUMBERS),
    {R_HAND + led_index[1][0], 1, HSV_ALPHAS},
    {R_HAND + led_index[2][0], 1, HSV_ALPHAS},
    {R_HAND + led_index[3][0], 1, HSV_ALPHAS},
    {R_HAND + led_index[3][1], 1, HSV_ALPHAS},
    {R_HAND + led_index[3][2], 1, HSV_ALPHAS},
    {R_HAND + led_index[3][3], 1, HSV_ALPHAS},
    {R_HAND + led_index[3][4], 1, HSV_ALPHAS},
    {R_HAND + led_index[3][5], 1, HSV_ALPHAS},
    SET_LAYER_ID(HSV_NUMBERS),
    SET_NON_CORNE_LIGHTS(HSV_BLACK)
);

// NUMPAD
const rgblight_segment_t PROGMEM layer_numpad_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_ALL(HSV_BLACK),
    SET_NUMPAD(HSV_NUMBERS),
    {R_HAND + 12, 3, HSV_ALPHAS},
    {R_HAND +  7, 1, HSV_ALPHAS},
    {R_HAND +  8, 1, HSV_NAVIGATION},
    {R_HAND + 32, 3, HSV_ALPHAS},

    {L_HAND + led_index[1][2], 1, HSV_FUNCTION},
    {L_HAND + led_index[1][3], 1, HSV_NAVIGATION},
    {L_HAND + led_index[1][4], 1, HSV_FUNCTION},

    {L_HAND + led_index[2][1], 1, HSV_ALPHAS},
    {L_HAND + led_index[2][2], 1, HSV_NAVIGATION},
    {L_HAND + led_index[2][3], 1, HSV_SPECIAL},
    {L_HAND + led_index[2][4], 1, HSV_NAVIGATION},
    {L_HAND + led_index[2][5], 1, HSV_ALPHAS},

    {L_HAND + led_index[3][1], 1, HSV_ALPHAS},
    {L_HAND + led_index[3][2], 1, HSV_SPECIAL},
    {L_HAND + led_index[3][3], 1, HSV_SPECIAL},
    {L_HAND + led_index[3][4], 1, HSV_SPECIAL},
    {L_HAND + led_index[3][5], 1, HSV_ALPHAS},
    SET_LAYER_ID(HSV_NUMBERS),
    SET_NON_CORNE_LIGHTS(HSV_BLACK)
);

// SWITCH
const rgblight_segment_t PROGMEM layer_switch_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_ALL(HSV_BLACK),
    SET_ROW_1(HSV_FUNCTION),
    {L_HAND + led_index[3][1], 1, HSV_FUNCTION},
    {L_HAND + led_index[3][2], 1, HSV_FUNCTION},
    {L_HAND + led_index[3][3], 1, HSV_FUNCTION},

    {R_HAND + led_index[1][0], 1, HSV_FUNCTION},
    {R_HAND + led_index[2][0], 1, HSV_FUNCTION},
    {R_HAND + led_index[2][3], 1, HSV_LAYER_SWITCH},
    {R_HAND + led_index[2][4], 1, HSV_LAYER_SWITCH},

    {R_HAND + led_index[3][3], 1, HSV_NAVIGATION},
    {R_HAND + led_index[3][4], 1, HSV_FUNCTION},
    {R_HAND + led_index[3][5], 1, HSV_FUNCTION},

    SET_LAYER_ID(HSV_FUNCTION)
);

// MEDIA
const rgblight_segment_t PROGMEM layer_media_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_ALL(HSV_BLACK),

    {L_HAND + 31, 3, HSV_SPECIAL},      // 5, T, G
    {L_HAND + 28, 3, HSV_MODS},         // 4, R, F

    {L_HAND +  9, 2, HSV_SPECIAL},      // tab, esc

    {R_HAND + 10, 2, HSV_SPECIAL},      // -
    {R_HAND + 13, 1, HSV_LAYER_SWITCH}, // ;
    {R_HAND + 18, 1, HSV_SPECIAL},      // L
    {R_HAND +  8, 1, HSV_SPECIAL},       // '
    SET_LAYER_ID(HSV_BLACK)
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    layer_qwerty_lights,
    layer_symbol_lights,
    layer_navigation_lights,

    layer_qwerty_lights_35,
    layer_symbol_lights_35,
    layer_navigation_lights_35,

    layer_number_lights,
    layer_numpad_lights,
    layer_switch_lights,
    layer_media_lights
);

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state|default_layer_state, L_QWERTY));
    rgblight_set_layer_state(1, layer_state_cmp(state, L_SYMBOLS));
    rgblight_set_layer_state(2, layer_state_cmp(state, L_NAVIGATION));

    rgblight_set_layer_state(3, layer_state_cmp(state|default_layer_state, L_QWERTY_35));
    rgblight_set_layer_state(4, layer_state_cmp(state, L_SYMBOLS_35));
    rgblight_set_layer_state(5, layer_state_cmp(state, L_NAVIGATION_35));

    rgblight_set_layer_state(6, layer_state_cmp(state, L_NUMBERS));
    rgblight_set_layer_state(7, layer_state_cmp(state, L_NUMPAD));
    rgblight_set_layer_state(8, layer_state_cmp(state, L_SWITCH));
    rgblight_set_layer_state(9, layer_state_cmp(state, L_MEDIA));

    return state;
}

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
    rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT); // haven't found a way to set this in a more useful way
}
