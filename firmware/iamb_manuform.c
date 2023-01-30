#include "usb_util.h"
#include "iamb_manuform.h"

#ifndef DYNAMIC_HANDEDNESS_CHECK
bool is_keyboard_master(void) {
#ifdef LEFT
    /* without this call the left side will not work */
    usb_disconnect();
    return false;
#else
    return true;
#endif
}

bool is_keyboard_left(void) {
#ifdef LEFT
    return true;
#else
    return false;
#endif
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    /* defined in the keymaps */
    extern const uint16_t RESET_LAYER;
    extern const uint16_t RESET_KEY;

    static uint8_t combo_state = 0;

    if (keycode == RESET_LAYER) {
        if (record->event.pressed)
            combo_state |= 0b1;
        else
            combo_state &= ~(0b1);
    }

    if (keycode == RESET_KEY) {
        if (record->event.pressed)
            combo_state |= 0b10;
        else
            combo_state &= ~(0b10);
    }

    if (combo_state == 0b11) {
        bootloader_jump();
        return false;
    }

    return true;
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {

    /* defined in the keymaps */
    extern const uint16_t ONESHOT_KEYS[];
    extern const uint16_t ONESHOT_COUNT;

    if (ONESHOT_COUNT > 0) {
        for (uint16_t i = 0; i < ONESHOT_COUNT; i++) {
            if (keycode == ONESHOT_KEYS[i]) {
                if (record->event.pressed)
                    tap_code16(KC_SPC);
            }
        }
    }
}

void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}
