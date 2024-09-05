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
    SET_ALL(HSV_ALPHAS),
    SET_LAYER_ID(HSV_ALPHAS)
);

// SYMBOL
const rgblight_segment_t PROGMEM layer_symbol_lights[] = RGBLIGHT_LAYER_SEGMENTS(
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

    {L_HAND + led_index[1][5], 1, HSV_FUNCTION},
    {L_HAND + led_index[2][0], 1, HSV_LAYER_SWITCH}, // MO(L_IDE)
    {L_HAND + led_index[2][1], 1, HSV_FUNCTION},
    {L_HAND + led_index[2][2], 1, HSV_NAVIGATION},
    {L_HAND + led_index[2][3], 1, HSV_NAVIGATION},
    {L_HAND + led_index[2][4], 1, HSV_NAVIGATION},
    {L_HAND + led_index[2][5], 1, HSV_FUNCTION},
    {L_HAND + led_index[3][1], 1, HSV_FUNCTION},
    {L_HAND + led_index[3][2], 1, HSV_FUNCTION},
    {L_HAND + led_index[3][3], 1, HSV_FUNCTION},
    {L_HAND + led_index[3][4], 1, HSV_FUNCTION},
    {L_HAND + led_index[3][5], 1, HSV_FUNCTION},

    {R_HAND + led_index[1][0], 1, HSV_NAVIGATION},
    {R_HAND + led_index[1][1], 1, HSV_NAVIGATION},
    {R_HAND + led_index[1][2], 1, HSV_FUNCTION},
    {R_HAND + led_index[1][3], 1, HSV_NAVIGATION},
    {R_HAND + led_index[1][4], 1, HSV_FUNCTION},
    {R_HAND + led_index[1][5], 1, HSV_NAVIGATION},
    {R_HAND + led_index[2][0], 1, HSV_FUNCTION},
    {R_HAND + led_index[2][1], 1, HSV_NAVIGATION},
    {R_HAND + led_index[2][2], 1, HSV_NAVIGATION},
    {R_HAND + led_index[2][3], 1, HSV_NAVIGATION},
    {R_HAND + led_index[2][4], 1, HSV_NAVIGATION},
    {R_HAND + led_index[2][5], 1, HSV_NAVIGATION},
    {R_HAND + led_index[3][0], 1, HSV_FUNCTION},
    {R_HAND + led_index[3][1], 1, HSV_FUNCTION},
    {R_HAND + led_index[3][2], 1, HSV_BLACK},
    {R_HAND + led_index[3][3], 1, HSV_FUNCTION},
    {R_HAND + led_index[3][4], 1, HSV_LAYER_SWITCH}, // TG_NUMPAD
    {R_HAND + led_index[3][5], 1, HSV_BLACK},

    SET_LAYER_ID(HSV_NAVIGATION),
    {R_HAND + led_index[4][3], 1, HSV_LAYER_SWITCH}, // NUMWORD
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

    SET_LAYER_ID(HSV_FUNCTION),
    SET_NON_CORNE_LIGHTS(HSV_BLACK)
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

// IDE
const rgblight_segment_t PROGMEM layer_ide_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_ALL(HSV_BLACK),

    {L_HAND + led_index[0][1], 1, HSV_FUNCTION},
    {L_HAND + led_index[1][4], 1, HSV_FUNCTION},
    {L_HAND + led_index[2][2], 1, HSV_FUNCTION},
    {L_HAND + led_index[2][4], 1, HSV_FUNCTION},
    {L_HAND + led_index[3][2], 1, HSV_FUNCTION},

    {R_HAND + led_index[1][0], 1, HSV_FUNCTION},
    {R_HAND + led_index[1][3], 1, HSV_FUNCTION},
    {R_HAND + led_index[2][2], 1, HSV_FUNCTION},
    {R_HAND + led_index[3][4], 1, HSV_FUNCTION},

    SET_LAYER_ID(HSV_BLACK)
);

// GAME_HW,
const rgblight_segment_t PROGMEM layer_game_hw_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_ALL(HSV_BLACK),
    {L_HAND + led_index[1][1], 1, HSV_ALPHAS}, // q
    {L_HAND + led_index[2][1], 5, HSV_ALPHAS}, // 1-5
    {L_HAND + led_index[3][1], 1, HSV_ALPHAS}, // a
    SET_LAYER_ID(HSV_ALPHAS)
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    layer_qwerty_lights,
    layer_game_hw_lights,
    layer_symbol_lights,
    layer_navigation_lights,
    layer_number_lights,
    layer_numpad_lights,
    layer_switch_lights,
    layer_media_lights,
    layer_ide_lights
);

layer_state_t layer_state_set_user(layer_state_t state) {
    int i = 0;
    rgblight_set_layer_state(i++, layer_state_cmp(state|default_layer_state, L_QWERTY));
    rgblight_set_layer_state(i++, layer_state_cmp(state, L_GAME_HW));
    rgblight_set_layer_state(i++, layer_state_cmp(state, L_SYMBOLS));
    rgblight_set_layer_state(i++, layer_state_cmp(state, L_NAVIGATION));
    rgblight_set_layer_state(i++, layer_state_cmp(state, L_NUMBERS));
    rgblight_set_layer_state(i++, layer_state_cmp(state, L_NUMPAD));
    rgblight_set_layer_state(i++, layer_state_cmp(state, L_SWITCH));
    rgblight_set_layer_state(i++, layer_state_cmp(state, L_MEDIA));
    rgblight_set_layer_state(i++, layer_state_cmp(state, L_IDE));

    return state;
}

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
    rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT); // haven't found a way to set this in a more useful way
}
