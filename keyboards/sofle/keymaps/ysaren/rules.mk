MOUSEKEY_ENABLE = yes
EXTRAKEY_ENABLE = yes
CONSOLE_ENABLE = no
ENCODER_ENABLE = yes
LTO_ENABLE = yes
OLED_ENABLE = yes

SWAP_HANDS_ENABLE = no
TAP_DANCE_ENABLE = no
CAPS_WORD_ENABLE = yes

# see https://docs.qmk.fm/#/feature_debounce_type
# DEBOUNCE_TYPE = sym_eager_pk
DEBOUNCE_TYPE = sym_defer_pk

# combos - with gboards dictionaries
# see https://combos.gboards.ca/docs/
VPATH  +=  keyboards/gboards/
COMBO_ENABLE = yes

RGBLIGHT_ENABLE = yes

RGB_MATRIX_ENABLE = no
RGB_MATRIX_DRIVER = ws2812

VIA_ENABLE = no

