
 /* Copyright 2021 Dane Evans
  *
  * This program is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 2 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this program.  If not, see <http://www.gnu.org/licenses/>.
  */
  // SOFLE RGB
#include <stdio.h>
#include "oled_driver.h"
#include "ysaren_layers.h"

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}

static void print_layer(struct Layer layer) {
    oled_write_ln_P(PSTR(layer.name), layer.inverted);
}

static void print_status_narrow(void) {
    // Print current mode
    // oled_write_P(PSTR("\n\n"), false);
    oled_clear();
    oled_write_ln_P(PSTR("YSRN"), false);
    oled_write_ln_P(PSTR("\n"), false);

	//snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undef-%ld", layer_state)

    // "base" layers
    if (layer_state_is(layers[1].layer)) { // L_GAME_HW
        print_layer(layers[1]);
    } else {
        print_layer(layers[0]);
    }

    oled_write_ln_P(PSTR("\n"), false);

    for (int i = 2; i < LAYERS_COUNT; i++) {
        struct Layer layer = layers[i];
        if (layer_state_is(layer.layer)) {
            print_layer(layer);
        }
    }
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
    return false;
}

void oled_render_boot(bool bootloader) {
    oled_clear();
    if (bootloader) {
        oled_write_P(PSTR("\n\nAwait"), true);
        oled_write_P(PSTR("New\n"),     true);
        oled_write_P(PSTR("Firmw"),     true);
    } else {
        oled_write_P(PSTR("Rebooting"), false);
    }

    oled_render_dirty(true);
}

bool shutdown_user(bool jump_to_bootloader) {
    oled_render_boot(jump_to_bootloader);
    return false;
}
