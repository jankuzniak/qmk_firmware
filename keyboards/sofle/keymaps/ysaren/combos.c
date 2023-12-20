#include "process_combo.h"

const uint16_t PROGMEM qw_esc[] = {KC_Q, KC_W, COMBO_END};
combo_t key_combos[] = {
    COMBO(qw_esc, KC_LGUI),
};
