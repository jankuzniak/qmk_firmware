#include "ysaren.h"

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        switch (get_highest_layer(layer_state)) {
            case L_QWERTY:
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
                break;
            case L_NAVIGATION:
            case L_NAVIGATION_35:
                if (clockwise) {
                    tap_code(KC_DOWN);
                } else {
                    tap_code(KC_UP);
                }
                break;
        }
    } else if (index == 1) {
        switch (get_highest_layer(layer_state)) {
            case L_QWERTY:
                if (clockwise) {
                    tap_code(KC_WH_D);
                } else {
                    tap_code(KC_WH_U);
                }
                break;
            case L_SYMBOLS:
            case L_SYMBOLS_35:
                if (clockwise) {
                    tap_code(KC_MS_BTN1);
                } else {
                    tap_code(KC_MS_BTN1);
                }
                break;
            case L_NAVIGATION:
            case L_NAVIGATION_35:
                if (clockwise) {
                    tap_code(KC_DOWN);
                } else {
                    tap_code(KC_UP);
                }
                break;
            default:
                if (clockwise) {
                    tap_code(KC_WH_D);
                } else {
                    tap_code(KC_WH_U);
                }
                break;
        }
    }
    return false;
}
