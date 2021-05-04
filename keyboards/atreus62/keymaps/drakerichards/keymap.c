// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _DEFAULT 0
#define _NAV 1
#define _RIGHT 2
#define _RESET 3

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DEFAULT] = LAYOUT( /* colemak */
    KC_GRAVE,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS ,
    KC_TAB,     KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                        KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_PLUS,
    KC_ESC,     KC_A,    KC_R,    KC_S,    KC_T,    KC_D,                        KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT ,
    KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                        KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS ,
    KC_ENT,     KC_LGUI, LGUI(LSFT(KC_S)), KC_LALT, KC_LCTL, KC_LSFT, LT(_NAV, KC_BSPC), KC_DEL, KC_SPC, KC_NO,KC_LEFT,KC_UP,KC_DOWN,KC_RIGHT
  ),

  [_NAV] = LAYOUT(
    KC_F12,        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11  ,
    KC_TRNS,       KC_HOME, KC_PGUP, KC_PGDN, KC_END, KC_LCBR,                     KC_RCBR, KC_7,    KC_8,    KC_9,    KC_PLUS, KC_TRNS ,
    KC_TRNS,       KC_LEFT, KC_UP, KC_DOWN, KC_RIGHT, KC_LPRN,                     KC_RPRN, KC_4,    KC_5,    KC_6,    KC_MINS, KC_TRNS ,
    KC_TRNS,       KC_BTN1, KC_BTN2, KC_TRNS, KC_TRNS, KC_LBRC,                     KC_RBRC, KC_1,    KC_2,    KC_3,    KC_TRNS,  KC_TRNS,
    KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  MO(_RESET),  KC_0, KC_DOT,    LGUI(LCTL(KC_LEFT)),  KC_VOLU, KC_VOLD, LGUI(LCTL(KC_RIGHT))
  ),

    [_RIGHT] = LAYOUT(
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS ,
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS ,
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, KC_LEFT, KC_UP, KC_DOWN, KC_RIGHT, KC_TRNS ,
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS ,
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [_RESET] = LAYOUT(
    KC_NO,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,                     KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO   ,
    KC_NO  ,       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,                     KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO   ,
    KC_NO  ,       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,                     KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO   ,
    KC_NO  ,       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,                     KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO   ,
    KC_NO  ,       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,  KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , RESET
  )

  /*
  [_TRNS] = LAYOUT(
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS ,
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS ,
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS ,
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS ,
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
  */
};
