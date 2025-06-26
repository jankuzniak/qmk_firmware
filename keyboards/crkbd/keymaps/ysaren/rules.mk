MOUSEKEY_ENABLE = no
EXTRAKEY_ENABLE = yes
CONSOLE_ENABLE = no
LTO_ENABLE = no
OLED_ENABLE = yes

SWAP_HANDS_ENABLE = no
TAP_DANCE_ENABLE = no
CAPS_WORD_ENABLE = yes

# combos - with gboards dictionaries
# see https://combos.gboards.ca/docs/
VPATH  +=  keyboards/gboards/
COMBO_ENABLE = yes

RGBLIGHT_ENABLE = yes

RGB_MATRIX_ENABLE = no
RGB_MATRIX_DRIVER = ws2812
WS2812_DRIVER = vendor

# note: enabling VIA may cause layout changes to be "cached" in EEPROM and layout.c changes not to be picked up
VIA_ENABLE = no

SERIAL_DRIVER = vendor
