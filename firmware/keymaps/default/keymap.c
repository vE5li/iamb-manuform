#include "quantum.h"
#include "keymap_german.h"

#include QMK_KEYBOARD_H

#define _BASE 0
#define _RAISE 1
#define _LOWER 2
#define _SYMBOLS 3

#define CTL_ESC CTL_T(KC_ESC)
#define CTL_LFT LCTL(KC_LEFT)
#define CTL_RGT LCTL(KC_RIGHT)
#define RS_SPC LT(_RAISE, KC_SPC)
#define SMB_BSP LT(_SYMBOLS, KC_BSPC)
#define SFT_ENT SFT_T(KC_ENT)

#define KC_ML KC_MS_LEFT
#define KC_MR KC_MS_RIGHT
#define KC_MU KC_MS_UP
#define KC_MD KC_MS_DOWN
#define KC_MB1 KC_MS_BTN1
#define KC_MB2 KC_MS_BTN2

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)
#define SYMBOLS MO(_SYMBOLS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT(
        DE_Q,    DE_W,    DE_F,    DE_P,    DE_B,                                         DE_J,    DE_L,    DE_U,    DE_Y,    DE_SS,
        DE_A,    DE_R,    DE_S,    DE_T,    DE_G,                                         DE_M,    DE_N,    DE_E,    DE_I,    DE_O,
        DE_Z,    DE_X,    DE_C,    DE_D,    DE_V,                                         DE_K,    DE_H,    DE_UDIA, DE_ODIA, DE_ADIA,
                 _______, _______,                                                                          _______, _______,
                                   CTL_ESC, RS_SPC,  KC_LGUI,                    LOWER,   SMB_BSP, SFT_ENT,
                                   KC_DEL,  KC_LSFT,                             KC_LALT, KC_LCTL
    ),

    [_RAISE] = LAYOUT(
        KC_WH_U, KC_MB1,  KC_MU,   KC_MB2,  KC_HOME,                                      KC_END,  KC_MB1,  KC_UP,   KC_MB2,  KC_PGUP,
        KC_WH_D, KC_ML,   KC_MD,   KC_MR,   KC_TAB,                                       KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,
        _______, _______, _______, _______, _______,                                      KC_DEL,  CTL_LFT, RGB_TOG, CTL_RGT, _______,
                 _______, _______,                                                                          RGB_VAI, RGB_VAD,
                                   _______, _______, _______,                    _______, _______, _______,
                                            _______, _______,                    _______, _______
    ),

    [_LOWER] = LAYOUT(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        _______, _______, _______, _______, _______,                                      _______, _______, _______, _______, _______,
                 _______, _______,                                                                          _______, _______,
                                   _______, _______, _______,                    _______, _______, _______,
                                            _______, _______,                    _______, _______
    ),

    [_SYMBOLS] = LAYOUT(
    	DE_EXLM, DE_DQUO, DE_QUES, DE_AT,   DE_DLR,                                       DE_AMPR, DE_EQL,  DE_SLSH, DE_QUOT, DE_ASTR,
    	DE_COLN, DE_LABK, DE_LCBR, DE_LBRC, DE_LPRN,                                      DE_RPRN, DE_RBRC, DE_RCBR, DE_RABK, DE_SCLN,
    	DE_BSLS, DE_PERC, DE_PIPE, DE_HASH, DE_COMM,                                      DE_DOT,  DE_MINS, DE_TILD, DE_UNDS, DE_PLUS,
                 DE_DEG,  DE_GRV,                                                                          _______, _______,
                                   DE_SECT, DE_CIRC, DE_EURO,                    _______, _______, _______,
                                            DE_MICR, _______,                    _______, _______
    )
};

static uint8_t combo_state = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

#ifdef LEFT
    uint16_t modifier = KC_LGUI;
    uint16_t trigger = DE_Z;
#else
    uint16_t modifier = LOWER;
    uint16_t trigger = DE_ADIA;
#endif

    if (keycode == modifier) {
      if (record->event.pressed)
          combo_state |= 0b1;
      else
          combo_state &= ~(0b1);
    }

    if (keycode == trigger) {
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

void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}
