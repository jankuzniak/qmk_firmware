#include "ysaren.h"

#define HR_GUI OSM(MOD_LGUI)
#define HR_ALT OSM(MOD_LALT)
#define HR_SFT OSM(MOD_LSFT)
#define HR_CTL OSM(MOD_LCTL)
#define KC_DITTO    G(A(S(KC_V)))
#define KC_TO_PASTE G(A(S(KC_C)))
#define KC_D_MUTE   C(A(S(KC_UP)))
#define KC_SCRSHT   G(S(KC_S))

#define F_ZONE_1 LCAG(KC_1)
#define F_ZONE_2 LCAG(KC_2)

#define TG_NUMPAD   TG(L_NUMPAD)
#define MO_NUMBER   MO(L_NUMBERS)
#define COLON_MEDIA LT(L_MEDIA,KC_SCLN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[L_QWERTY] = LAYOUT(
           //,-----------------------------------------------------.                         ,------------------------------------------------------------------.
              KC_ESC,   KC_1,  KC_2,     KC_3,     KC_4,     KC_5,                              KC_6,    KC_7,     KC_8,     KC_9,     KC_0,       KC_MINUS,
           //|--------+------+-------+---------+--- -----+---------|                         |--------+---------+---------+--------+-------------+--------------|
              KC_TAB,   KC_Q,  KC_W,     KC_E,     KC_R,     KC_T,                              KC_Y,    KC_U,     KC_I,     KC_O,     KC_P,       MO(L_IDE),
           //|--------+------+-------+---------+--- -----+---------|                         |--------+---------+---------+--------+-------------+--------------|
              KC_LSFT,  KC_A,  KC_S,     KC_D,     KC_F,     KC_G,                              KC_H,    KC_J,     KC_K,     KC_L,   COLON_MEDIA,  KC_QUOT,
           //|--------+------+-------+---------+--- -----+---------|  ===  |     |  ===  |------------+---------+---------+--------+-------------+--------------|
              KC_LCTL,  KC_Z,  KC_X,     KC_C,     KC_V,     KC_B,   KC_MUTE,    KC_SCRSHT,     KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLASH,    KC_BACKSLASH,
           //|--------+------+-------+---------+--- -----+---------|  ===  |     |  ===  |------------+---------+---------+--------+-------------+--------------|
                              KC_LGUI,  XXXXXXX,  KC_LALT,  KC_SPC,  KC_NAVI_35,    KC_SYMBOLS_35,  KC_BSPC,  KC_RALT,  KC_RSFT,  KC_RCTL
           //             \----------+---------+---------+---------+-------|     |-------+------------+---------+---------+-------/
),

[L_QWERTY_35] = LAYOUT(
           //,-----------------------------------------------------.                           ,---------------------------------------------------------------------.
              KC_NO,   KC_NO,  KC_NO,    KC_NO,    KC_NO,    KC_NO,                                 KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,      KC_NO,
           //|--------+------+-------+---------+--- -----+---------|                           |-----------+---------+---------+--------+-------------+--------------|
              KC_TAB,   KC_Q,  KC_W,     KC_E,     KC_R,     KC_T,                                  KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,       KC_EQUAL,
           //|--------+------+-------+---------+--- -----+---------|                           |-----------+---------+---------+--------+-------------+--------------|
              KC_LSFT,  KC_A,  KC_S,     KC_D,     KC_F,     KC_G,                                  KC_H,     KC_J,     KC_K,     KC_L,   COLON_MEDIA,  KC_QUOT,
           //|--------+------+-------+---------+--- -----+---------|  ===  |       |  ===  |---------------+---------+---------+--------+-------------+--------------|
              KC_LCTL,  KC_Z,  KC_X,     KC_C,     KC_V,     KC_B,   KC_MUTE,       KC_SCRSHT,      KC_N,     KC_M,    KC_COMM,  KC_DOT,   KC_SLASH,    KC_BACKSLASH,
           //|--------+------+-------+---------+--- -----+---------|  ===  |       |  ===  |---------------+---------+---------+--------+-------------+--------------|
                             XXXXXXX,  XXXXXXX,  KC_LALT,  KC_SPC,  KC_NAVI_35,   KC_SYMBOLS_35,   KC_BSPC,  KC_RALT,  XXXXXXX,  XXXXXXX
           //             \----------+---------+---------+---------+-------|       |-------+---------------+---------+---------+-------/\n
),

/*
 * Navigation
 * ,----------------------------------------------------.                    ,------------------------------------------------------.
 * |       |        |        |        |        |        |                    |        |        |        |        |        |        |
 * |-------+--------+--------+--------+--------+--------|                    |---------+--------+--------+--------+--------+--------|
 * | tab   |  win   |  alt   | shift  |  ctrl  | ctrl+T |                    |  home  |        |   up   |        | pg up  |  ins   |
 * |-------+--------+--------+--------+--------+--------|                    |---------+--------+--------+--------+--------+--------|
 * | shift | ctrl+A |  del   |  esc   | enter  |txtPaste|-------.    ,-------|  end   |  left  |  down  | right  | pg dn  | ctrl++ |
 * |-------+--------+--------+--------+--------+--------|       |    |       |---------+--------+--------+--------+--------+--------|
 * | ctrl  | ctrl+Z | ctrl+X | ctrl+C | ctrl+V | ditto  |-------|    |-------|        | numpad |        |        | ctrl+0 | ctrl+- |
 * `----------------------------------------------------/       /     \      \------------------------------------------------------'
 *               |        |        |        |        | /       /       \      \  |        |  num   |        |        |
 *               |        |        |        |        |/       /         \      \ |        |  word  |        |        |
 *                `-----------------------------------------'           '------''------------------------------------'
 */

[L_NAVIGATION] = LAYOUT(
//,-----------------------------------------------------------------------------.                       ,-------------------------------------------------------------------.
   _______,  XXXXXXX,      XXXXXXX,     XXXXXXX,       XXXXXXX,    XXXXXXX,                               XXXXXXX,   XXXXXXX,    C(KC_UP),    XXXXXXX,   XXXXXXX,  XXXXXXX,
//,--------+---------+---------------+---------------+---------------+----------.                       ,---------+------------+------------+----------+---------+----------.
   _______,  OS_GUI,       OS_LALT,     OS_SFT,        OS_CTL,     C(KC_T),                               KC_HOME,  C(KC_LEFT),    KC_UP,   C(KC_RIGHT), KC_PGUP,  KC_INS,
//,--------+---------+---------------+---------------+---------------+----------.                       ,---------+------------+------------+----------+---------+----------.
   MO(L_IDE),  C(KC_A),      KC_DEL,      KC_ESC,        KC_ENT,     KC_TO_PASTE,                           KC_END,     KC_LEFT,     KC_DOWN,   KC_RGHT,   KC_PGDN,     C(KC_PLUS),
//,--------+---------+---------------+---------------+---------------+---------- | ====  |     |  ====  |---------+------------+------------+----------+---------+----------.
   _______,  C(KC_Z),      C(KC_X),     C(KC_C),       C(KC_V),    KC_DITTO,     _______,       _______,  XXXXXXX,   TG_NUMPAD,  C(KC_DOWN),  XXXXXXX,   C(KC_0),     C(KC_MINUS),
//,--------+---------+---------------+---------------+---------------+----------|  ====  |     |  ====  |---------+------------+------------+----------+---------+----------.
                       _______,        _______,         _______,       _______,  _______,       _______,  KC_NUMWORD,  _______,    _______,   _______
//                   \---------------+---------------+---------------+----------|--------|     |--------|---------+------------+------------+----------/
),

[L_NAVIGATION_35] = LAYOUT(
//,-----------------------------------------------------------------.                       ,------------------------------------------------------------.
   XXXXXXX,  XXXXXXX,     XXXXXXX,     XXXXXXX,  XXXXXXX,  XXXXXXX,                           XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
//,--------+---------+---------------+---------+---------+----------.                       ,---------+---------+---------+---------+---------+----------.
   _______,  _______,     _______,     _______,  _______,  _______,                           _______,  _______,  _______,  _______,  _______,  _______,
//,--------+---------+---------------+---------+---------+----------.                       ,---------+---------+---------+---------+---------+----------.
   _______,  _______,     _______,     _______,  _______,  _______,                           _______,  _______,  _______,  _______,  _______,  _______,
//,--------+---------+---------------+---------+---------+---------- | ====  |     |  ====  |---------+---------+---------+---------+---------+----------.
   _______,  _______,     _______,     _______,  _______,  _______,  _______,       _______,  _______,  _______,  _______,  _______,  _______,  _______,
//,--------+---------+---------------+---------+---------+----------|  ====  |     |  ====  |---------+---------+---------+---------+---------+----------.
                          XXXXXXX,     XXXXXXX,  _______,  _______,  _______,       _______,  _______,  _______,  XXXXXXX,  XXXXXXX
//                   \---------------+---------+---------+----------|--------|     |--------|---------+---------+---------+---------/
),

// SYMBOLS 4x5
[L_SYMBOLS] = LAYOUT(
  //,------------------------------------------------.                               ,---------------------------------------------------.
  _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,                            KC_F6,        KC_F7,    KC_F8,    KC_F9,   KC_F10,         KC_F11,
  //|------+-------+--------+--------+--------+------|                              |--------+-------+--------+--------+--------+---------|
  _______,  KC_EXLM,  KC_AT,    KC_LCBR,  KC_RCBR,  KC_PIPE,                          KC_KP_PLUS,   KC_KP_7,  KC_KP_8,  KC_KP_9, KC_KP_MINUS,    KC_F12,
  //|------+-------+--------+--------+--------+------|                              |--------+-------+--------+--------+--------+---------|
  KC_LSFT,  KC_HASH,  KC_DLR,   KC_LPRN,  KC_RPRN,  KC_GRV,                           KC_MINUS,     KC_KP_4,  KC_KP_5,  KC_KP_6, KC_KP_ASTERISK, KC_ENT,
  //|------+-------+--------+--------+--------+------|  ===  |              |  ===  |--------+-------+--------+--------+--------+---------|
  _______,  KC_PERC,  KC_CIRC,  KC_LBRC,  KC_RBRC,  KC_TILDE,  _______,      _______, KC_EQUAL,     KC_KP_1,  KC_KP_2,  KC_KP_3, KC_KP_SLASH,    XXXXXXX,
  //|------+-------+--------+--------+--------+------|  ===  |              |  ===  |--------+-------+--------+--------+--------+---------|
                           _______, KC_LABK, KC_RABK, _______, _______,      _______, _______,      KC_KP_0,  KC_KP_0,  KC_KP_DOT
  //                      \--------+--------+--------+---------+-------|    |--------+---------+--------+---------+-------/
),

/*
 * SYMBOLS 3x5
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   !  |   @  |   {  |   }  |   |  |                    |   +  |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   #  |   $  |   (  |   )  |   `  |-------.    ,-------|   -  | ctrl | shft | alt  | gui  |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * | LCTR |   %  |   ^  |   [  |   ]  |   ~  |-------|    |-------|   &  |      |  <   |   >  |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[L_SYMBOLS_35] = LAYOUT(
//,-----------------------------------------------------------.                       ,------------------------------------------------------------.
   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                           XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
//,--------+---------+---------+---------+---------+----------.                       ,---------+---------+---------+---------+---------+----------.
   _______,  _______,  _______,  _______,  _______,  _______,                          KC_PLUS,   KC_AMPR,  KC_ASTR,  XXXXXXX,  XXXXXXX,  XXXXXXX,
//,--------+---------+---------+---------+---------+----------.                       ,---------+---------+---------+---------+---------+----------.
   _______,  _______,  _______,  _______,  _______,  _______,                          KC_MINUS,  OS_CTL,   OS_SFT,   OS_RALT,  OS_GUI,   XXXXXXX,
//,--------+---------+---------+---------+---------+---------- | ====  |     |  ====  |---------+---------+---------+---------+---------+----------.
   _______,  _______,  _______,  _______,  _______,  _______,  _______,       _______, KC_EQUAL,  XXXXXXX,  KC_LABK,  KC_RABK,  XXXXXXX,  XXXXXXX,
//,--------+---------+---------+---------+---------+----------|  ====  |     |  ====  |---------+---------+---------+---------+---------+----------.
                       XXXXXXX,  XXXXXXX,  _______,  _______,  _______,       _______,  _______,  _______,  XXXXXXX,  XXXXXXX
//                   \---------+---------+---------+----------|--------|     |--------|---------+---------+---------+---------/
),

[L_NUMPAD] = LAYOUT(
//,-----------------------------------------------------------.                       ,--------------------------------------------------------------------.
   _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                           XXXXXXX,  XXXXXXX,   XXXXXXX, XXXXXXX,  XXXXXXX,         XXXXXXX,
//,--------+---------+---------+---------+---------+----------.                       ,---------+---------+---------+---------+-------------+--------------.
   _______,  KC_RALT,  KC_F2,    KC_ESC,   KC_F4,    XXXXXXX,                         KC_KP_PLUS,  KC_P7,     KC_P8,   KC_P9,   KC_KP_MINUS,     XXXXXXX,
//,--------+---------+---------+---------+---------+----------.                       ,---------+---------+---------+---------+-------------+--------------.
   _______,  KC_LPRN,  KC_DEL,   KC_UP,    KC_ENT,   KC_RPRN,                        KC_KP_MINUS,  KC_P4,     KC_P5,   KC_P6,   KC_KP_ASTERISK,  KC_ENT,
//,--------+---------+---------+---------+---------+---------- | ====  |     |  ====  |---------+---------+---------+---------+-------------+--------------.
   _______,  KC_LABK,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_RABK,  _______,       _______,  KC_EQUAL,  KC_P1,     KC_P2,   KC_P3,   KC_KP_SLASH,     KC_DOT,
//,--------+---------+---------+---------+---------+---------- | ====  |     |  ====  |---------+---------+---------+---------+-------------+--------------.
                       _______,  _______,  _______,  _______,  TG_NUMPAD,     _______,  _______,  KC_KP_0,   KC_KP_0,  KC_DOT
//                   \---------+---------+---------+----------|--------|     |--------|---------+---------+---------+---------/
),

[L_NUMBERS] = LAYOUT(
//,-----------------------------------------------------------.                       ,--------------------------------------------------------------------.
   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                            XXXXXXX, XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,     XXXXXXX,
//,--------+---------+---------+---------+---------+----------.                       ,---------+---------+---------+---------+-------------+--------------.
   _______,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,                            KC_CIRC, KC_AMPR,   KC_ASTR,  KC_LPRN,  KC_RPRN,     KC_UNDS,
//,--------+---------+---------+---------+---------+----------.                       ,---------+---------+---------+---------+-------------+--------------.
   _______,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                               KC_6,    KC_7,      KC_8,     KC_9,     KC_0,        KC_MINS,
//,--------+---------+---------+---------+---------+---------- | ====  |     |  ====  |---------+---------+---------+---------+-------------+--------------.
   _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,       _______,   KC_EQL,  KC_PPLS,   KC_COMM,  KC_DOT,   KC_PSLS,     KC_PAST,
//,--------+---------+---------+---------+---------+---------- | ====  |     |  ====  |---------+---------+---------+---------+-------------+--------------.
                       _______,  _______,  _______,  _______,  _______,       _______,  _______,  _______,  _______,   _______
//                   \---------+---------+---------+----------|--------|     |--------|---------+---------+---------+---------/
),

[L_SWITCH] = LAYOUT(
//,-------------------------------------------------------------.                       ,--------------------------------------------------------------------.
   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,                           XXXXXXX,   XXXXXXX,    XXXXXXX,       XXXXXXX,  XXXXXXX,  XXXXXXX,
//,--------+---------+---------+---------+-----------+----------.                       ,---------+----------+---------------+----------+---------+----------.
   _______,   KC_F1,    KC_F2,    KC_F3,      KC_F4,    KC_F5,                             KC_F6,     KC_F7,     KC_F8,         KC_F9,    KC_F10,   KC_F11,
//,--------+---------+---------+---------+-----------+----------.                       ,---------+----------+---------------+----------+---------+----------.
   KC_LSFT,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,                           XXXXXXX,   KC_QWERTY,  KC_QWERTY_35,  KC_NO,    KC_NO,    KC_F12,
//,--------+---------+---------+---------+-----------+----------|  ====  |     |  ====  |---------+----------+---------------+----------+---------+----------.
   _______,  KC_PSCR,  KC_SCRL,  G(KC_PAUS), XXXXXXX,  XXXXXXX,  XXXXXXX,       XXXXXXX,  F_ZONE_1,  F_ZONE_2,   KC_APP,        XXXXXXX,  XXXXXXX,  XXXXXXX,
//,--------+---------+---------+---------+-----------+----------|  ====  |     |  ====  |---------+----------+- -------------+----------+---------+----------.
                       XXXXXXX,  XXXXXXX,    _______,  _______,  _______,       _______,  _______,   _______,    XXXXXXX,       XXXXXXX
//                   \---------+---------+-----------+----------|--------|     |--------|---------+----------+---------------+----------/
),

// LSA(KC_4 .. KC_9) are to handled by autohotkey
[L_MEDIA] = LAYOUT(
//,----------------------------------------------------------------.                       ,------------------------------------------------------------.
   EE_CLR,   XXXXXXX,  XXXXXXX,  XXXXXXX,  LSA(KC_5),    LSA(KC_4),                           XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  QK_BOOT,
//,--------+---------+---------+---------+------------+------------.                       ,---------+---------+---------+---------+---------+----------.
  QK_REBOOT, XXXXXXX,  XXXXXXX,  XXXXXXX,  LSA(KC_9),    LSA(KC_8),                           XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
//,--------+---------+---------+---------+------------+------------.                       ,---------+---------+---------+---------+---------+----------.
   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  LSA(KC_7),    LSA(KC_6),                           XXXXXXX,  XXXXXXX,  XXXXXXX,  G(KC_L),  _______,  KC_SYSTEM_SLEEP,
//,--------+---------+---------+---------+------------+------------ | ====  |     |  ====  |---------+---------+---------+---------+---------+----------.
   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,     XXXXXXX,    XXXXXXX,       XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
//,--------+---------+---------+---------+------------+------------|  ====  |     |  ====  |---------+---------+---------+---------+---------+----------.
                       XXXXXXX,  XXXXXXX,   XXXXXXX,     XXXXXXX,    XXXXXXX,       XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
//                   \---------+---------+------------+------------|--------|     |--------|---------+---------+---------+---------/
),

[L_IDE] = LAYOUT(
//,------------------------------   ---------------------   -------------.                           ,------------------------------------------------------------.
   XXXXXXX,  C(KC_1),  XXXXXXX,     XXXXXXX,  XXXXXXX,        XXXXXXX,                              XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
//,--------+---------+---------+-   --------+------------   +------------.                           ,---------+---------+---------+---------+---------+----------.
   XXXXXXX,  XXXXXXX,  XXXXXXX,     XXXXXXX,  A(S(KC_R)),     XXXXXXX,                              XXXXXXX,  XXXXXXX,  A(S(KC_I)),  XXXXXXX,  XXXXXXX,  C(KC_F11),
//,--------+---------+---------+-   --------+------------   +------------.                           ,---------+---------+---------+---------+---------+----------.
   XXXXXXX,  XXXXXXX,  A(S(KC_S)),  XXXXXXX,  C(S(KC_F)),     XXXXXXX,                              XXXXXXX,  XXXXXXX,  XXXXXXX,  A(S(KC_L)),  XXXXXXX,  XXXXXXX,
//,--------+---------+---------+-   --------+------------   +------------ | ====  |     |  ====  |---------+---------+---------+---------+---------+----------.
   XXXXXXX,  XXXXXXX,  A(S(KC_X)),  XXXXXXX,  XXXXXXX,        XXXXXXX,    XXXXXXX,        XXXXXXX,  XXXXXXX, A(S(KC_M)), XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
//,--------+---------+---------+-   --------+------------   +------------|  ====  |     |  ====  |---------+---------+---------+---------+---------+----------.
                       XXXXXXX,     XXXXXXX,  XXXXXXX,        XXXXXXX,    XXXXXXX,        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
//                   \---------+-   --------+------------   +------------|--------|     |--------|---------+---------+---------+---------/
),

};

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_lalt_state = os_up_unqueued;
oneshot_state os_ralt_state = os_up_unqueued;
oneshot_state os_cmd_state  = os_up_unqueued;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);

    process_record_num_word(keycode, record);

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

    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(L_QWERTY);
            }
            return false;
        case KC_NAVI:
            if (record->event.pressed) {
                layer_on(L_NAVIGATION);
            } else {
                layer_off(L_NAVIGATION);
            }
            update_tri_layer(L_NAVIGATION, L_SYMBOLS, L_SWITCH);
            return false;
        case KC_SYMBOLS:
            if (record->event.pressed) {
                layer_on(L_SYMBOLS);
            } else {
                layer_off(L_SYMBOLS);
            }
            update_tri_layer(L_NAVIGATION, L_SYMBOLS, L_SWITCH);
            return false;

        case KC_QWERTY_35:
            if (record->event.pressed) {
                set_single_persistent_default_layer(L_QWERTY_35);
            }
            return false;
        case KC_NAVI_35:
            if (record->event.pressed) {
                layer_on(L_NAVIGATION);
                layer_on(L_NAVIGATION_35);
            } else {
                layer_off(L_NAVIGATION);
                layer_off(L_NAVIGATION_35);
            }
            update_tri_layer(L_NAVIGATION_35, L_SYMBOLS_35, L_SWITCH);
            return false;
        case KC_SYMBOLS_35:
            if (record->event.pressed) {
                layer_on(L_SYMBOLS);
                layer_on(L_SYMBOLS_35);
            } else {
                layer_off(L_SYMBOLS);
                layer_off(L_SYMBOLS_35);
            }
            update_tri_layer(L_NAVIGATION_35, L_SYMBOLS_35, L_SWITCH);
            return false;

        case KC_SWITCH:
            if (record->event.pressed) {
                layer_on(L_SWITCH);
            } else {
                layer_off(L_SWITCH);
            }
            return false;
    }
    return true;
}

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
        case KC_SYMBOLS:
        case KC_NAVI:
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
        case KC_SYMBOLS_35:
        case KC_NAVI_35:
        case KC_SWITCH_35:
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
