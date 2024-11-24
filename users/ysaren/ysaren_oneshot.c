#include "ysaren_oneshot.h"

void process_record_oneshot(uint16_t keycode, keyrecord_t *record) {
    update_oneshot(
        &os_shft_state, KC_LSFT, OS_SFT,
        keycode, record
    );
    update_oneshot(
        &os_ctrl_state, KC_LCTL, OS_CTL,
        keycode, record
    );
    update_oneshot(
        &os_lalt_state, KC_LALT, OS_LALT,
        keycode, record
    );
    update_oneshot(
        &os_ralt_state, KC_RALT, OS_RALT,
        keycode, record
    );
    update_oneshot(
        &os_cmd_state, KC_LCMD, OS_GUI,
        keycode, record
    );
}

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
        //case KC_SYMBOLS: // ignored
        case KC_NAVI:    // ignored
            return true;
        default:
            return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
        case KC_SYMBOLS:
        case KC_NAVI:
        case KC_SWITCH:
        case KC_LSFT:
        case OS_SFT:
        case OS_CTL:
        case OS_LALT:
        case OS_RALT:
        case OS_GUI:
            return true;
        default:
            return false;
    }
}
