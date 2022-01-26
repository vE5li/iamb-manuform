#include QMK_KEYBOARD_H

#define _BASE 0
#define _RAISE 1
#define _LOWER 2

#define CTL_ESC    CTL_T(KC_ESC)
#define RAISE_SPC  LT(_RAISE, KC_SPC)
#define LOWER_BSPC LT(_LOWER, KC_BSPC)
#define SHIFT_ENT  SFT_T(KC_ENT)

#define KC_ML KC_MS_LEFT
#define KC_MR KC_MS_RIGHT
#define KC_MU KC_MS_UP
#define KC_MD KC_MS_DOWN
#define KC_MB1 KC_MS_BTN1
#define KC_MB2 KC_MS_BTN2

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base (qwerty)
     * ,----------------------------------,                             ,----------------------------------,
     * |   q  |   w  |   e  |   r  |   t  |                             |   z  |   u  |   i  |   o  |   p  |
     * |------+------+------+------+------|                             |-------------+------+------+------|
     * |   a  |   s  |   d  |   f  |   g  |                             |   h  |   j  |   k  |   l  |   ;  |
     * |------+------+------+------+------|                             |------|------+------+------+------|
     * |   y  |   x  |   c  |   v  |   b  |                             |   n  |   m  |   ,  |   .  |   '  |
     * |------+------+------+-------------,                             ,-------------+------+------+------,
     *        |  [   |   ]  |                                                         |   -  |   =  |
     *        '------+------'-------------'                             '-------------'------+------'
     *                      | ESC  |SPACE |                             |  BS  |ENTER |
     *                      |  +   |   +  |                             |  +   |  +   |
     *                      | CTRL |Raise |                             | Lower|SHIFT |
     *                      '------+------'                             '------+------'
     *                                    '------+------' '------+------'
     *                                    |  TAB | GUI  | |  ALT | DEL  |
     *                                    '------+------' '------+------'
     *                                    | HOME |  ~   | |INSERT| END  |
     *                                    '------+------' '------+------'
     */

    [_BASE] = LAYOUT(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                         KC_Z,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
        KC_Y,    KC_X,    KC_C,    KC_V,    KC_B,                                         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_QUOT,
                          KC_LBRC, KC_RBRC,                                                        KC_MINS, KC_EQL,
                                                     CTL_ESC, RAISE_SPC, LOWER_BSPC, SHIFT_ENT,
                                                     KC_TAB,  KC_LGUI,   KC_LALT,    KC_DEL,
                                                     KC_HOME, KC_GRV,    KC_INSERT,  KC_END
    ),

    /* Raise
     * ,----------------------------------,                             ,----------------------------------,
     * |      | mbtn |  mup |mbtn2 |      |                             | VOL+ |      |  up  |      | PgUp |
     * |------+------+------+------+------|                             |-------------+------+------+------|
     * |      | mleft| mdown|mright|      |                             | MUTE | left | down |right | PgDn |
     * |------+------+------+------+------|                             |------|------+------+------+------|
     * |      |      |      |      |      |                             | VOL- |  /   |  \   |  ?   |  |   |
     * |------+------+------+-------------,                             ,-------------+------+------+------,
     *        |      |      |                                                         |      |      |
     *        '------+------'-------------'                             '-------------'------+------'
     *                      |      |      |                             |  TOG |      |
     *                      |      |      |                             |      |      |
     *                      |      |      |                             |      |      |
     *                      '------+------'                             '------+------'
     *                                    '------+------' '------+------'
     *                                    |      |      | |  MOD | HUI  |
     *                                    '------+------' '------+------'
     *                                    |      |      | |  VAI | SAI  |
     *                                    '------+------' '------+------'
     */
    [_RAISE] = LAYOUT(
        _______, KC_MB1,  KC_MU,   KC_MB2,  _______,                                      KC_VOLU, _______, KC_UP,   _______, KC_PGUP,
        _______, KC_ML,   KC_MD,   KC_MR,   _______,                                      KC_MUTE, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,
        _______, _______, _______, _______, _______,                                      KC_VOLD, KC_SLSH, KC_BSLS, KC_QUES, KC_PIPE,
                 _______, _______,                                                                          _______, _______,
                                   _______, _______,                                      RGB_TOG, _______,
                                                     _______, _______,  RGB_MOD, RGB_HUI,
                                                     _______, _______,  RGB_VAI, RGB_SAI
    ),

    /* Lower
     * ,----------------------------------,                             ,----------------------------------,
     * | F1   | F2   | F3   | F4   | F5   |                             |  F6  | F7   |  F8  |  F9  |  F10 |
     * |------+------+------+------+------|                             |-------------+------+------+------|
     * |  1   |  2   |  3   |  4   |  5   |                             |  6   |  7   |  8   |  9   |  0   |
     * |------+------+------+------+------|                             |------|------+------+------+------|
     * |  !   |  @   |  #   |  $   |  %   |                             |  ^   |  &   |  *   |  (   |  )   |
     * |------+------+------+-------------,                             ,-------------+------+------+------,
     *        | F11  | F12  |                                                         |  -   |  =   |
     *        '------+------'-------------'                             '-------------'------+------'
     *                      |      |      |                             |      |      |
     *                      |      |      |                             |      |      |
     *                      |      |      |                             |      |      |
     *                      '------+------'                             '------+------'
     *                                    '------+------' '------+------'
     *                                    |      |      | |      |      |
     *                                    '------+------' '------+------'
     *                                    |      |      | |      |      |
     *                                    '------+------' '------+------'
     */
    [_LOWER] = LAYOUT(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
                 KC_F11,  KC_F12,                                                                           _______, _______,
                                   _______, _______,                                      _______, _______,
                                                     _______, _______,  _______, _______,
                                                     _______, _______,  _______, _______
    )
};

void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}