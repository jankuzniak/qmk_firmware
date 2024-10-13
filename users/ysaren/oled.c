#include "oled.h"

// static void render_logo(void) {
//     static const char PROGMEM qmk_logo[] = {
//         0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
//         0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
//         0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
//     };

//     oled_write_P(qmk_logo, false);
// }

// required for the right second screen to see the state of the left keyboard
// also requires #define SPLIT_TRANSPORT_MIRROR in config.h
bool should_process_keypress(void) {
    return true;
}

static void print_mod(bool enabled, char *name, bool narrow) {
    if (enabled) {
        oled_write_P(PSTR(name), true);
    } else {
        if (narrow) {
            oled_write_P(PSTR("."), false);
        } else {
            oled_write_P(PSTR(name), false);
        }
    }
}

static void print_mods_short(void) {
    uint8_t mod_state = get_mods();
    print_mod((mod_state & MOD_MASK_GUI  ) > 0, "G", true);
    print_mod((mod_state & MOD_MASK_ALT  ) > 0, "A", true);
    print_mod((mod_state & MOD_MASK_SHIFT) > 0, "S", true);
    print_mod((mod_state & MOD_MASK_CTRL ) > 0, "C", true);
}

static void print_mods_long(void) {
    oled_clear();
    oled_write_ln_P(PSTR("MODS"), false);
    oled_write_ln_P(PSTR("\n"), false);

    uint8_t mod_state = get_mods();
    print_mod((mod_state & MOD_MASK_GUI  ) > 0, "GUI  ", false);
    print_mod((mod_state & MOD_MASK_ALT  ) > 0, "ALT  ", false);
    print_mod((mod_state & MOD_MASK_SHIFT) > 0, "SHIFT", false);
    print_mod((mod_state & MOD_MASK_CTRL ) > 0, "CTRL ", false);
}

static void print_layer(struct Layer layer) {
    oled_write_ln_P(PSTR(layer.name), layer.inverted);
}

static void print_status_narrow(void) {
    oled_clear();
    oled_write_ln_P(PSTR("YSRN"), false);
    oled_write_ln_P(PSTR("\n"), false);

    // "base" layers
    if (layer_state_is(layers[1].layer)) { // L_GAME_HW
        print_layer(layers[1]);
    } else {
        print_layer(layers[0]);
    }

    oled_write_ln_P(PSTR("\n"), false);

    int current_line = 4;

    for (int i = 2; i < LAYERS_COUNT; i++) {
        struct Layer layer = layers[i];
        if (layer_state_is(layer.layer)) {
            print_layer(layer);
            current_line++;
        }
    }

    for (int i = current_line; i < 8; i++) {
        oled_write_ln_P(PSTR("\n"), false);
    }

    print_mods_short();
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    // if (is_keyboard_master()) {
    return OLED_ROTATION_270;
    // }
    // return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        // render_logo();
        print_mods_long();
    }
    return false;
}

void oled_render_boot(bool bootloader) {
    oled_clear();
    if (bootloader) {
        oled_write_P(PSTR("\n\n"), true);
        oled_write_P(PSTR("push "), true);
        oled_write_P(PSTR(" new "), true);
        oled_write_P(PSTR("firm."), true);
    } else {
        oled_write_P(PSTR("Rebooting"), false);
    }

    oled_render_dirty(true);
}

bool shutdown_user(bool jump_to_bootloader) {
    if (is_keyboard_master()) {
        oled_render_boot(jump_to_bootloader);
    }
    return false;
}
