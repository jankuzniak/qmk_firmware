#include "config.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------| MUTE  |    |DISCORD|------+------+------+------+------+------|
 * | LCTR |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |LShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | Bspc | WIN  |LOWER | Enter| /Space  /       \Enter \  |SPACE |RAISE | RCTR | RAlt |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[L_QWERTY] = LAYOUT(
            //,------------------------------------------------.                    ,---------------------------------------------------.
            KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,             LT(L_SWITCH,KC_6), KC_7,   KC_8,    KC_9,    KC_0,    KC_MINUS,
            //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  LT(L_NUMPAD,KC_TAB), KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,   KC_I,    KC_O,    KC_P,    KC_EQUAL,
            //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
            KC_LSFT,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,   KC_K,    KC_L,    LT(L_MEDIA,KC_SCLN), KC_QUOT,
            //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
            KC_LCTL,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,  KC_MUTE, G(S(KC_S)),KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_SLASH, KC_BACKSLASH,
            //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|

                          KC_LGUI, XXXXXXX, KC_LEFT_ALT, KC_SPC, KC_NAVIGATION,    KC_BACKSPACE, KC_SYMBOLS, KC_RALT, KC_RSFT,  KC_RCTL
            //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
),

[L_QWERTY_35] = LAYOUT(
            //,------------------------------------------------.                    ,---------------------------------------------------.
              XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
            //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  LT(L_NUMPAD,KC_TAB), KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,   KC_I,    KC_O,    KC_P,    KC_EQUAL,
            //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
            KC_LSFT,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,   KC_K,    KC_L,    LT(L_MEDIA,KC_SCLN), KC_QUOT,
            //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
            KC_LCTL,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,  KC_MUTE, G(S(KC_S)),KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_SLASH, KC_BACKSLASH,
            //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|

                          XXXXXXX, XXXXXXX, KC_LEFT_ALT, KC_SPC, KC_NAVIGATION_35,    KC_BACKSPACE, KC_SYMBOLS_35, KC_RALT, XXXXXXX,  XXXXXXX
            //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
),

[L_NAVIGATION] = LAYOUT(
  //,----------------------------------------------------------------------.                     ,---------------------------------------------------.
  _______, XXXXXXX,     XXXXXXX,    XXXXXXX,      XXXXXXX,      XXXXXXX,                          XXXXXXX,  XXXXXXX,        LCTL(KC_UP),    XXXXXXX ,     XXXXXXX,  XXXXXXX,
  //,-----------------+-----------+-------------+-------------+------------.                     ,---------------------------------------------------.
  _______,  KC_ESC,     LCTL(KC_W), LSFT(KC_ENT), LALT(KC_ENT), LCTL(KC_T),                       KC_HOME,  LCTL(KC_LEFT),  KC_UP,          LCTL(KC_UP),  KC_PGUP,  KC_INS,
  //,--------------+----------------------------------------.                                    ,---------------------------------------------------.
  _______,  LCTL(KC_A), KC_DEL,     LCTL(KC_ENT), KC_ENT,       KC_TO_PASTE,                       KC_END,   KC_LEFT,        KC_DOWN,        KC_RGHT,      KC_PGUP,  XXXXXXX,
  //|------+-------+--------+--------+--------+------|  ===  |                            |  ===  |--------+-------+--------+--------+--------+---------|
  _______,  LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C),   LCTL(KC_V),   KC_DITTO, _______,        _______, KC_NO,    KC_NO,          LCTL(KC_DOWN),  XXXXXXX,      XXXXXXX,  XXXXXXX,
  //|------+-------+--------+--------+--------+------|  ===  |                            |  ===  |--------+-------+--------+--------+--------+---------|
                                      _______, _______, _______, _______, _______,     KC_NUMWORD, _______, _______, _______, _______
  //                                    \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
),

[L_NAVIGATION_35] = LAYOUT(
  //,----------------------------------------------------------------------.                     ,---------------------------------------------------.
  XXXXXXX,  XXXXXXX,    XXXXXXX,    XXXXXXX,      XXXXXXX,      XXXXXXX,                          XXXXXXX,  XXXXXXX,        XXXXXXX ,       XXXXXXX ,     XXXXXXX,  XXXXXXX,
  //,-----------------+-----------+-------------+-------------+------------.                     ,---------------------------------------------------.
  _______,  KC_ESC,     LCTL(KC_W), LSFT(KC_ENT), LALT(KC_ENT), LCTL(KC_T),                       KC_HOME,  LCTL(KC_LEFT),  KC_UP,          LCTL(KC_UP),  KC_PGUP,  KC_INS,
  //,--------------+----------------------------------------.                                    ,---------------------------------------------------.
  _______,  LCTL(KC_A), KC_DEL,     LCTL(KC_ENT), KC_ENT,       KC_TO_PASTE,                       KC_END,   KC_LEFT,        KC_DOWN,        KC_RGHT,      KC_PGUP,  XXXXXXX,
  //|------+-------+--------+--------+--------+------|  ===  |                            |  ===  |--------+-------+--------+--------+--------+---------|
  _______,  LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C),   LCTL(KC_V),   KC_DITTO, _______,        _______, KC_NO,    KC_NO,          LCTL(KC_DOWN),  XXXXXXX,      XXXXXXX,  XXXXXXX,
  //|------+-------+--------+--------+--------+------|  ===  |                            |  ===  |--------+-------+--------+--------+--------+---------|
                                      XXXXXXX, XXXXXXX, _______, _______, _______,     KC_NUMWORD, _______, _______, XXXXXXX, XXXXXXX
  //                                    \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
),

[L_SYMBOLS] = LAYOUT(
  //,------------------------------------------------.                               ,---------------------------------------------------.
  _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,                            KC_F6,        KC_F7,    KC_F8,    KC_F9,   KC_F10,         KC_F11,
  //|------+-------+--------+--------+--------+------|                              |--------+-------+--------+--------+--------+---------|
  _______,  KC_EXLM,  KC_AT,    KC_LCBR,  KC_RCBR,  KC_PIPE,                          KC_KP_PLUS,   KC_KP_7,  KC_KP_8,  KC_KP_9, KC_KP_MINUS,    KC_F12,
  //|------+-------+--------+--------+--------+------|                              |--------+-------+--------+--------+--------+---------|
  _______,  KC_HASH,  KC_DLR,   KC_LPRN,  KC_RPRN,  KC_GRV,                           KC_EQUAL,     KC_KP_4,  KC_KP_5,  KC_KP_6, KC_KP_ASTERISK, KC_ENT,
  //|------+-------+--------+--------+--------+------|  ===  |              |  ===  |--------+-------+--------+--------+--------+---------|
  _______,  KC_PERC,  KC_CIRC,  KC_LBRC,  KC_RBRC,  KC_TILDE,  _______,      _______, KC_AMPR,      KC_KP_1,  KC_KP_2,  KC_KP_3, KC_KP_SLASH,    XXXXXXX,
  //|------+-------+--------+--------+--------+------|  ===  |              |  ===  |--------+-------+--------+--------+--------+---------|
                           _______, KC_LABK, KC_RABK, _______, _______,      _______, _______,      KC_KP_0,  KC_KP_0,  KC_KP_DOT
  //                      \--------+--------+--------+---------+-------|    |--------+---------+--------+---------+-------/
),

[L_SYMBOLS_35] = LAYOUT(
  //,------------------------------------------------.                            ,---------------------------------------------------.
  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                       XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,
  //|------+-------+--------+--------+--------+------|                           |--------+-------+--------+--------+--------+---------|
  _______,  KC_EXLM,  KC_AT,    KC_LCBR,  KC_RCBR,  KC_PIPE,                       XXXXXXX,   KC_LABK,  KC_RABK,  XXXXXXX,  XXXXXXX, XXXXXXX,
  //|------+-------+--------+--------+--------+------|                           |--------+-------+--------+--------+--------+---------|
  _______,  KC_HASH,  KC_DLR,   KC_LPRN,  KC_RPRN,  KC_GRV,                        XXXXXXX,   KC_MINUS, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,
  //|------+-------+--------+--------+--------+------|  ===  |              |  ===  |--------+-------+--------+--------+--------+---------|
  _______,  KC_PERC,  KC_CIRC,  KC_LBRC,  KC_RBRC,  KC_TILDE,  _______,   _______, KC_AMPR,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,
  //|------+-------+--------+--------+--------+------|  ===  |              |  ===  |--------+-------+--------+--------+--------+---------|
                      XXXXXXX,  XXXXXXX,  _______,   _______,  _______,   _______, _______,   _______,  XXXXXXX,  XXXXXXX
  //                      \--------+--------+--------+---------+-------|    |--------+---------+--------+---------+-------/
),

/* NUMPAD
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | trans|      |      |      |      |      |                    |      |NumLck|      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |      |      |      |      |      |                    |   ^  |   7  |   8  |   9  |   *  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | trans|      |      |      |      |      |-------.    ,-------|   -  |   4  |   5  |   6  |      |   |  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | trans|      |      |      |      |      |-------|    |-------|   +  |   1  |   2  |   3  |   \  | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | Bspc | WIN  |LOWER | Enter| /Space  /       \Enter \  |SPACE | 0    |  .   | RAlt |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[L_NUMPAD] = LAYOUT(
  //,------------------------------------------------.                    ,---------------------------------------------------.
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     KC_NUM,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  _______, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE,                   KC_KP_PLUS, KC_P7,  KC_P8,   KC_P9,   KC_KP_MINUS,     XXXXXXX,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  _______, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_LABK,                   KC_EQUAL,   KC_P4,  KC_P5,   KC_P6,   KC_KP_ASTERISK,  KC_ENT,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
  _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_RABK,_______,   _______,  KC_P0,    KC_P1,  KC_P2,   KC_P3,   KC_KP_SLASH,     KC_KP_DOT,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
                   _______, _______, _______, _______, _______,   _______, _______,   KC_P0,  KC_KP_0, KC_KP_DOT
  //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
),

/* SWITCH
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | qwer | cole |col_dh| low  | raise| adj  |                    |numpad|      |      |      |      |QK_BOOT |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |EE_CLR|
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | SLEEP|      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | Bspc | WIN  |LOWER | Enter| /Space  /       \Enter \  |SPACE | 0    |  .   | RAlt |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
  // layer switcher
[L_SWITCH] = LAYOUT(
  //,------------------------------------------------.                    ,---------------------------------------------------.
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  TO(0),   TO(1),   TO(2),   TO(3),   TO(4),   TO(5),                      TO(6),   KC_NO,   KC_NO,   KC_NO,   KC_NO,   QK_BOOT,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  KC_NO,   KC_NO, KC_BRIU,   KC_NO,   KC_NO,   KC_NO,                      KC_NO,   KC_QWERTY,   KC_QWERTY_35,   KC_NO,   KC_NO,   EE_CLR,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
  KC_SYSTEM_SLEEP,KC_NO,KC_NO,KC_NO,  KC_NO,   KC_NO, KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
                  KC_NO,    KC_NO,  _______,  _______,  _______,  _______,  _______,  _______,   KC_NO,   KC_NO
  //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
),

[L_SWITCH_35] = LAYOUT(
  //,------------------------------------------------.                        ,---------------------------------------------------.
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX,
  //|------+-------+--------+--------+--------+------|                       |--------+-------+--------+--------+--------+---------|
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                          KC_F6,   KC_F7,   KC_F8,  KC_F9,   KC_F10,  KC_F11,
  //|------+-------+--------+--------+--------+------|                       |--------+-------+--------+--------+--------+---------|
  TO(0),   TO(1),   TO(2),   TO(3),   TO(4),   TO(5),                          TO(6),  KC_QWERTY,  KC_QWERTY_35,  KC_NO,   KC_NO,   KC_F12,
  //|------+-------+--------+--------+--------+------|  ===  |       |  ===  |--------+-------+--------+--------+--------+---------|
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|------+-------+--------+--------+--------+------|  ===  |       |  ===  |--------+-------+--------+--------+--------+---------|
                    XXXXXXX, XXXXXXX, _______, _______, _______,     _______, _______, _______, XXXXXXX, XXXXXXX
  //            \--------+--------+--------+---------+-------|        |--------+---------+--------+---------+-------/
),

[L_MEDIA] = LAYOUT(
  //,------------------------------------------------.                    ,---------------------------------------------------.
  _______, XXXXXXX, XXXXXXX, XXXXXXX, A(S(KC_5)), A(S(KC_4)),             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX, QK_BOOT,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   A(S(KC_9)), A(S(KC_8)),             KC_NO,   KC_NO,   KC_NO,  KC_NO,   KC_NO,   KC_NO,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   A(S(KC_7)), A(S(KC_6)),             KC_NO,   KC_NO,   KC_NO,  G(KC_L), KC_NO,   KC_SYSTEM_SLEEP,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
  KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,   KC_NO,   KC_NO,      KC_NO,  KC_NO,   KC_NO,   KC_NO,  KC_NO,  KC_NO,   KC_NO,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
                  KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO
  //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    process_record_num_word(keycode, record);

    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(L_QWERTY);
            }
            return false;
        case KC_NAVIGATION:
            if (record->event.pressed) {
                layer_on(L_NAVIGATION);
                update_tri_layer(L_NAVIGATION, L_SYMBOLS, L_SWITCH);
            } else {
                layer_off(L_NAVIGATION);
                update_tri_layer(L_NAVIGATION, L_SYMBOLS, L_SWITCH);
            }
            return false;
        case KC_SYMBOLS:
            if (record->event.pressed) {
                layer_on(L_SYMBOLS);
                update_tri_layer(L_NAVIGATION, L_SYMBOLS, L_SWITCH);
            } else {
                layer_off(L_SYMBOLS);
                update_tri_layer(L_NAVIGATION, L_SYMBOLS, L_SWITCH);
            }
            return false;

        case KC_QWERTY_35:
            if (record->event.pressed) {
                set_single_persistent_default_layer(L_QWERTY_35);
            }
            return false;
        case KC_NAVIGATION_35:
            if (record->event.pressed) {
                layer_on(L_NAVIGATION_35);
                update_tri_layer(L_NAVIGATION_35, L_SYMBOLS_35, L_SWITCH_35);
            } else {
                layer_off(L_NAVIGATION_35);
                update_tri_layer(L_NAVIGATION_35, L_SYMBOLS_35, L_SWITCH_35);
            }
            return false;
        case KC_SYMBOLS_35:
            if (record->event.pressed) {
                layer_on(L_SYMBOLS_35);
                update_tri_layer(L_NAVIGATION_35, L_SYMBOLS_35, L_SWITCH_35);
            } else {
                layer_off(L_SYMBOLS_35);
                update_tri_layer(L_NAVIGATION_35, L_SYMBOLS_35, L_SWITCH_35);
            }
            return false;

        case KC_SWITCH:
            if (record->event.pressed) {
                layer_on(L_SWITCH);
            } else {
                layer_off(L_SWITCH);
            }
            return false;

        case KC_D_MUTE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_MEH));
                register_code(KC_UP);
            } else {
                unregister_mods(mod_config(MOD_MEH));
                unregister_code(KC_UP);
            }
            return false;
        case KC_TO_PASTE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LSFT | MOD_LGUI | MOD_LALT));
                register_code(KC_C);
            } else {
                unregister_mods(mod_config(MOD_LSFT | MOD_LGUI | MOD_LALT));
                unregister_code(KC_C);
            }
            return false;
        case KC_DITTO:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LSFT | MOD_LGUI | MOD_LALT));
                register_code(KC_V);
            } else {
                unregister_mods(mod_config(MOD_LSFT | MOD_LGUI | MOD_LALT));
                unregister_code(KC_V);
            }
            return false;
    }
    return true;
}
