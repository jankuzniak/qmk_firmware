#pragma once

#include "oneshot.h"
#include "ysaren_keycodes.h"

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_lalt_state = os_up_unqueued;
oneshot_state os_ralt_state = os_up_unqueued;
oneshot_state os_cmd_state  = os_up_unqueued;

void process_record_oneshot(uint16_t keycode, keyrecord_t *record);
