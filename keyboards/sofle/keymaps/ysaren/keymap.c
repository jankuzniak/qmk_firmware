
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

#include QMK_KEYBOARD_H
#include "ysaren.h"

#include "num_word.c"
#include "oneshot.c"
#include "ysaren_oneshot.c"

#include "layout.c"

#ifdef RGBLIGHT_ENABLE
    #include "rgb_layers.c"
#endif

#ifdef OLED_ENABLE
    #include "oled.c"
#endif

#ifdef ENCODER_ENABLE
    #include "encoder.c"
#endif

#ifdef COMBO_ENABLE
// replaced by gboards combo engine
//    #include "combos.c"
    #include "g/keymap_combo.h"
#endif
