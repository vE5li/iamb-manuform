#include "quantum.h"
#include "keymap_german.h"

#include QMK_KEYBOARD_H

#define _BASE 0
#define _SPECIAL 1
#define _NUMBERS 2
#define _SYMBOLS 3

#define CTL_ESC CTL_T(KC_ESC)
#define CTL_LFT LCTL(KC_LEFT)
#define CTL_RGT LCTL(KC_RIGHT)
#define SPL_SPC LT(_SPECIAL, KC_SPC)
#define SMB_BSP LT(_SYMBOLS, KC_BSPC)
#define SFT_ENT SFT_T(KC_ENT)

#define KC_ML KC_MS_LEFT
#define KC_MR KC_MS_RIGHT
#define KC_MU KC_MS_UP
#define KC_MD KC_MS_DOWN
#define KC_MB1 KC_MS_BTN1
#define KC_MB2 KC_MS_BTN2

#define SPECIAL MO(_SPECIAL)
#define NUMBERS MO(_NUMBERS)
#define SYMBOLS MO(_SYMBOLS)

// extern symbols used in iamb_manuform.c
const uint16_t RESET_LAYER = NUMBERS;
const uint16_t RESET_KEY = KC_F10;
const uint16_t ONESHOT_KEYS[] = { DE_CIRC, DE_GRV };
const uint16_t ONESHOT_COUNT = sizeof(ONESHOT_KEYS) / sizeof(ONESHOT_KEYS[0]);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT(
        DE_Q,    DE_W,    DE_E,    DE_R,    DE_T,                                         DE_Z,    DE_U,    DE_I,    DE_O,    DE_P,
        DE_A,    DE_S,    DE_D,    DE_F,    DE_G,                                         DE_H,    DE_J,    DE_K,    DE_L,    DE_SS,
        DE_Y,    DE_X,    DE_C,    DE_V,    DE_B,                                         DE_N,    DE_M,    DE_UDIA, DE_ODIA, DE_ADIA,
                 _______, _______,                                                                          _______, _______,
                                   CTL_ESC, SPL_SPC, KC_LGUI,                    NUMBERS, SMB_BSP, SFT_ENT,
                                            KC_LSFT, KC_LALT,                    KC_LALT, KC_LCTL
    ),

    [_SPECIAL] = LAYOUT(
        KC_WH_U, KC_MB1,  KC_MU,   KC_MB2,  KC_HOME,                                      KC_END,  KC_INS,  KC_UP,   KC_MB2,  KC_PGUP,
        KC_WH_D, KC_ML,   KC_MD,   KC_MR,   KC_TAB,                                       KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,
        _______, _______, _______, _______, _______,                                      KC_DEL,  CTL_LFT, RGB_TOG, CTL_RGT, RGB_MOD,
                 _______, _______,                                                                          RGB_VAI, RGB_VAD,
                                   _______, _______, _______,                    _______, _______, _______,
                                            _______, _______,                    _______, _______
    ),

    [_NUMBERS] = LAYOUT(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        _______, _______, _______, _______, _______,                                      _______, _______, _______, _______, _______,
                 _______, _______,                                                                          KC_F11,  KC_F12,
                                   _______, _______, _______,                    _______, _______, _______,
                                            _______, _______,                    _______, _______
    ),

    [_SYMBOLS] = LAYOUT(
        DE_EXLM, DE_DQUO, DE_QUES, DE_AT,   DE_DLR,                                       DE_AMPR, DE_EQL,  DE_SLSH, DE_QUOT, DE_ASTR,
        DE_COLN, DE_LABK, DE_LCBR, DE_LBRC, DE_LPRN,                                      DE_RPRN, DE_RBRC, DE_RCBR, DE_RABK, DE_SCLN,
        DE_BSLS, DE_PERC, DE_PIPE, DE_HASH, DE_COMM,                                      DE_DOT,  DE_MINS, DE_TILD, DE_UNDS, DE_PLUS,
                 _______, _______,                                                                          _______, _______,
                                   DE_GRV,  _______, DE_CIRC,                    _______, _______, _______,
                                            DE_DEG,  DE_EURO,                    _______, _______
    )
};
