#pragma once
#include "quantum.h"

// Custom keycodes and macros
enum userspace_custom_keycodes {
    // USER_CAPS_WORD_ENABLE
    KC_QWERTY = SAFE_RANGE,
    KC_SYMBOLS,
    KC_NAVI,
    KC_SWITCH,

    OS_SFT,
    OS_CTL,
    OS_LALT,
    OS_RALT,
    OS_GUI,

    KC_NUMWORD,

    DYNAMIC_MACRO_RANGE
};
