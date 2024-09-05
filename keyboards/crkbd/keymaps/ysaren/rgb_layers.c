#include "ysaren_crkbd.h"

char layer_state_str[70];
// Now define the array of layers. Later layers take precedence
// QWERTY,
const rgblight_segment_t PROGMEM layer_qwerty_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_ALL(HSV_ALPHAS),
    SET_LAYER_ID(HSV_ALPHAS)
);

// _SYMBOL
const rgblight_segment_t PROGMEM layer_symbol_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_ALL(HSV_ALPHAS),
    SET_HAND(R_HAND, HSV_BLACK),
    SET_OSM(R_HAND, 1),
    SET_BRACKETS(),
    {R_HAND + led_index[0][3], 1, HSV_ALPHAS},
    {R_HAND + led_index[0][4], 1, HSV_ALPHAS},
    {R_HAND + led_index[0][5], 1, HSV_ALPHAS},
    {R_HAND + led_index[1][5], 1, HSV_ALPHAS},
    {R_HAND + led_index[2][5], 1, HSV_ALPHAS},
    {R_HAND + led_index[2][3], 1, HSV_ALPHAS},
    {R_HAND + led_index[2][2], 1, HSV_ALPHAS},
    SET_LAYER_ID(HSV_MODS)
);

// NAVIGATION
const rgblight_segment_t PROGMEM layer_navigation_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_ALL(HSV_ALPHAS),
    SET_OSM(L_HAND, 0),
    SET_NAVIGATION(),
    {R_HAND + led_index[2][4], 1, HSV_LAYER_SWITCH}, // L_NUMBERS
    {R_HAND + led_index[3][2], 1, HSV_LAYER_SWITCH}, // L_NUMPAD
    SET_LAYER_ID(HSV_NAVIGATION)
);

// NUMBERS
const rgblight_segment_t PROGMEM layer_number_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_ALL(HSV_BLACK),
    SET_ROW(L_HAND, 0, HSV_ALPHAS),
    SET_ROW(R_HAND, 0, HSV_ALPHAS),
    SET_ROW(L_HAND, 1, HSV_NUMBERS),
    SET_ROW(R_HAND, 1, HSV_NUMBERS),
    {R_HAND + led_index[0][0], 1, HSV_ALPHAS},
    {R_HAND + led_index[1][0], 1, HSV_ALPHAS},
    {R_HAND + led_index[2][0], 1, HSV_ALPHAS},
    {R_HAND + led_index[2][1], 1, HSV_ALPHAS},
    {R_HAND + led_index[2][2], 1, HSV_ALPHAS},
    {R_HAND + led_index[2][3], 1, HSV_ALPHAS},
    {R_HAND + led_index[2][4], 1, HSV_ALPHAS},
    {R_HAND + led_index[2][5], 1, HSV_ALPHAS},
    SET_LAYER_ID(HSV_NUMBERS)
);

// NUMPAD
const rgblight_segment_t PROGMEM layer_numpad_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_ALL(HSV_BLACK),
    SET_NUMPAD(HSV_NUMBERS),
    {R_HAND + led_index[3][1], 3, HSV_ALPHAS},
    {R_HAND + led_index[3][0], 1, HSV_ALPHAS},
    {R_HAND + led_index[2][0], 1, HSV_NAVIGATION},
    {R_HAND + led_index[3][5], 3, HSV_ALPHAS},

    {L_HAND + led_index[0][2], 1, HSV_FUNCTION},
    {L_HAND + led_index[0][3], 1, HSV_NAVIGATION},
    {L_HAND + led_index[0][4], 1, HSV_FUNCTION},

    {L_HAND + led_index[1][1], 1, HSV_ALPHAS},
    {L_HAND + led_index[1][2], 1, HSV_NAVIGATION},
    {L_HAND + led_index[1][3], 1, HSV_SPECIAL},
    {L_HAND + led_index[1][4], 1, HSV_NAVIGATION},
    {L_HAND + led_index[1][5], 1, HSV_ALPHAS},

    {L_HAND + led_index[2][1], 1, HSV_ALPHAS},
    {L_HAND + led_index[2][2], 1, HSV_SPECIAL},
    {L_HAND + led_index[2][3], 1, HSV_SPECIAL},
    {L_HAND + led_index[2][4], 1, HSV_SPECIAL},
    {L_HAND + led_index[2][5], 1, HSV_ALPHAS},
    SET_LAYER_ID(HSV_NUMBERS)
);

// SWITCH
const rgblight_segment_t PROGMEM layer_switch_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_ALL(HSV_BLACK),
    SET_ROW(L_HAND, 0, HSV_FUNCTION),
    SET_ROW(R_HAND, 0, HSV_FUNCTION),
    {L_HAND + led_index[2][1], 1, HSV_FUNCTION},
    {L_HAND + led_index[2][2], 1, HSV_FUNCTION},
    {L_HAND + led_index[2][3], 1, HSV_FUNCTION},

    {R_HAND + led_index[0][0], 1, HSV_FUNCTION},
    {R_HAND + led_index[1][0], 1, HSV_FUNCTION},
    {R_HAND + led_index[1][3], 1, HSV_LAYER_SWITCH},
    {R_HAND + led_index[1][4], 1, HSV_LAYER_SWITCH},

    {R_HAND + led_index[2][3], 1, HSV_NAVIGATION},
    {R_HAND + led_index[2][4], 1, HSV_FUNCTION},
    {R_HAND + led_index[2][5], 1, HSV_FUNCTION},

    SET_LAYER_ID(HSV_FUNCTION)
);

// MEDIA
const rgblight_segment_t PROGMEM layer_media_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_ALL(HSV_BLACK),

    // {L_HAND + 31, 3, HSV_SPECIAL},      // 5, T, G
    // {L_HAND + 28, 3, HSV_MODS},         // 4, R, F

    // {L_HAND +  9, 2, HSV_SPECIAL},      // tab, esc

    {R_HAND + led_index[0][0], 1, HSV_SPECIAL},      // -
    {R_HAND + led_index[1][0], 1, HSV_LAYER_SWITCH}, // '
    {R_HAND + led_index[1][1], 1, HSV_LAYER_SWITCH}, // ;
    {R_HAND + led_index[1][2], 1, HSV_LAYER_SWITCH},  // L
    SET_LAYER_ID(HSV_BLACK)
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    layer_qwerty_lights,
    layer_symbol_lights,
    layer_navigation_lights,

    layer_number_lights,
    layer_numpad_lights,
    layer_switch_lights,
    layer_media_lights
);

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state|default_layer_state, L_QWERTY));
    rgblight_set_layer_state(1, layer_state_cmp(state, L_SYMBOLS));
    rgblight_set_layer_state(2, layer_state_cmp(state, L_NAVIGATION));
    rgblight_set_layer_state(3, layer_state_cmp(state, L_NUMBERS));
    rgblight_set_layer_state(4, layer_state_cmp(state, L_NUMPAD));
    rgblight_set_layer_state(5, layer_state_cmp(state, L_SWITCH));
    rgblight_set_layer_state(6, layer_state_cmp(state, L_MEDIA));

    return state;
}

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
    rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT); // haven't found a way to set this in a more useful way                set_single_persistent_default_layer(L_QWERTY_35);
}
