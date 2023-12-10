
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

#define INDICATOR_BRIGHTNESS 30

#define UNDERGLOW_COUNT 6
#define KEY_COUNT 29
#define L_HAND 0
#define R_HAND L_HAND + UNDERGLOW_COUNT + KEY_COUNT

#define HSV_OVERRIDE_HELP(h, s, v, Override) h, s , Override
#define HSV_OVERRIDE(hsv, Override) HSV_OVERRIDE_HELP(hsv,Override)

// Light combinations
#define SET_ALL(hsv) \
    {0, 2 * RGBLED_NUM, hsv}

#define SET_LAYER_SWITCHERS(hsv) \
    {L_HAND + 26, 1, hsv}, \
    {R_HAND + 25, 1, hsv}

#define SET_INDICATORS(hsv) \
    {L_HAND + 0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \
    {R_HAND + 0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}

#define SET_UNDERGLOW(hsv) \
    {L_HAND + 1, 6, hsv}, \
    {R_HAND + 1, 6, hsv}

#define SET_NUMPAD(hsv) \
    {R_HAND + 15, 5, hsv}, \
    {R_HAND + 22, 3, hsv}, \
    {R_HAND + 27, 3, hsv}

#define SET_NUMROW(hsv) \
    {L_HAND + 10, 2, hsv}, \
    {L_HAND + 20, 2, hsv}, \
    {L_HAND + 30, 2, hsv}, \
    {R_HAND + 10, 2, hsv}, \
    {R_HAND + 20, 2, hsv}, \
    {R_HAND + 30, 2, hsv}

#define SET_INNER_COL(hsv) \
    {33, 4, hsv}, \
      {35+ 33, 4, hsv}

#define SET_OUTER_COL(hsv) \
    {L_HAND + 7, 4, hsv}, \
    {R_HAND + 7, 4, hsv}


#define SET_THUMB_CLUSTER(hsv) \
    {L_HAND + 25, 2, hsv}, \
    {R_HAND + 25, 2, hsv}

#define SET_LAYER_ID(hsv)     \
    {L_HAND + 0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \
    {R_HAND + 0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \
    {L_HAND + 1, 6, hsv}, \
    {R_HAND + 1, 6, hsv}, \
    {L_HAND + 7, 4, hsv}, \
    {R_HAND + 7, 4, hsv}, \
    {L_HAND + 25, 2, hsv}, \
    {R_HAND + 25, 2, hsv}

char layer_state_str[70];
// Now define the array of layers. Later layers take precedence

// QWERTY,
// Light on inner column and underglow
const rgblight_segment_t PROGMEM layer_qwerty_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_ALL(HSV_BLACK),
    SET_LAYER_ID(HSV_GRAY),
    SET_LAYER_SWITCHERS(HSV_CADMIUM_YELLOW)
);

const rgblight_segment_t PROGMEM layer_colemakdh_lights[] = RGBLIGHT_LAYER_SEGMENTS(
  SET_LAYER_ID(HSV_PINK)
);

// _NUM, LOWER
// Light on outer column and underglow
const rgblight_segment_t PROGMEM layer_num_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_ALL(HSV_BLACK),
    SET_LAYER_SWITCHERS(HSV_CADMIUM_YELLOW),
    SET_LAYER_ID(HSV_DEEP_GREEN)
);

// _SYMBOL, RAISE
// Light on inner column and underglow
const rgblight_segment_t PROGMEM layer_symbol_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_ALL(HSV_BLACK),
    SET_LAYER_ID(HSV_THE_GRAPE_WAR_OF_97),
    SET_LAYER_SWITCHERS(HSV_CADMIUM_YELLOW)
);

// _COMMAND,
// Light on inner column and underglow
const rgblight_segment_t PROGMEM layer_command_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_ALL(HSV_BLACK),
    SET_LAYER_ID(HSV_GIANTS_ORAGNE)
);

//_NUMPAD
const rgblight_segment_t PROGMEM layer_numpad_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_INDICATORS(HSV_ORANGE),
    SET_UNDERGLOW(HSV_ORANGE),
    SET_NUMPAD(HSV_CADMIUM_YELLOW),
    {7, 4, HSV_ORANGE},
    {25, 2, HSV_ORANGE},
    {35+6, 4, HSV_ORANGE},
    {35+25, 2, HSV_ORANGE}
    );
// _SWITCHER   // light up top row
const rgblight_segment_t PROGMEM layer_switcher_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_LAYER_ID(HSV_GREEN),
    SET_NUMROW(HSV_GREEN)
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    layer_qwerty_lights,
    layer_num_lights,// overrides layer 1
    layer_symbol_lights,
    layer_command_lights,
    layer_numpad_lights,
    layer_switcher_lights,  // Overrides other layers
    layer_colemakdh_lights
);

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _DEFAULTS) && layer_state_cmp(default_layer_state,_QWERTY));
    rgblight_set_layer_state(7, layer_state_cmp(state, _DEFAULTS) && layer_state_cmp(default_layer_state,_COLEMAKDH));


    rgblight_set_layer_state(1, layer_state_cmp(state, _LOWER));
    rgblight_set_layer_state(2, layer_state_cmp(state, _RAISE));
    rgblight_set_layer_state(3, layer_state_cmp(state, _ADJUST));
    rgblight_set_layer_state(4, layer_state_cmp(state, _NUMPAD));
    rgblight_set_layer_state(5, layer_state_cmp(state, _SWITCH));
    return state;
}
void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;

    rgblight_mode(10);// haven't found a way to set this in a more useful way

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
    // {R_HAND + 20 + 9 , 1, HSV_TURQUOISE}
