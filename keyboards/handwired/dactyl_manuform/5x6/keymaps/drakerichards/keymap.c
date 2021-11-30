//Includes
#include QMK_KEYBOARD_H

//Defines
#define _QWER 5
#define _CTRL 2
#define _SYST 4
#define _NUMP 3
#define _COLE 0
#define _GAME 1
#define _CLGM 6
#define _RUNE 7

//Variable Declaration
bool is_alt_tab_active = false;    // ADD this near the begining of keymap.c
uint16_t alt_tab_timer = 0;        // we will be using them soon.

bool bnumlock = false;
bool numlock_changed = false;

//Custom keycodes
enum custom_keycodes {             // Make sure have the awesome keycode ready
  ALT_TAB   =   SAFE_RANGE,
  LT_STAB   =   LT(_SYST,KC_TAB),
  LT_NTAB   =   LT(_NUMP,KC_TAB)
};

//Layers

//    [_QWER] = LAYOUT_5x6(
//       KC_ESC , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_BSPC,
//       KC_TAB , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                         KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,KC_MINS,
//       KC_LSFT, KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,                         KC_H  , KC_J  , KC_K  , KC_L  ,KC_SCLN,KC_QUOT,
//       KC_LCTL, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,                         KC_N  , KC_M  ,KC_COMM,KC_DOT ,KC_SLSH,KC_BSLASH,
//                        KC_LBRC,KC_RBRC,                                                       KC_PLUS, KC_EQL,
//                                        RAISE,KC_SPC,                        KC_ENT, LOWER,
//                                        KC_TAB,KC_HOME,                         KC_END,  KC_DEL,
//                                        KC_BSPC, KC_GRV,                        KC_LGUI, KC_LALT
//    ),

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWER] = LAYOUT_5x6(
        KC_MUTE,KC_1,   KC_2,   KC_3,   KC_4,   KC_5,                           KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_GRV,
        KC_TAB, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                           KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_MINS,
        KC_ESC, KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                           KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,
        KC_ENT, KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,                           KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_BSLASH,
                        KC_LGUI, ALT_TAB,                                                       KC_EQL, TG(_GAME),
                                        LT(_CTRL,KC_BSPC), LSFT_T(KC_SPC),      RSFT_T(KC_SPC), LT(_CTRL,KC_DEL),
                                        LALT_T(KC_DEL), LCTL_T(KC_TAB),         KC_INS, KC_HOME,
                                        OSL(_CTRL), TT(_NUMP),                  TG(_SYST), KC_END),

    [_CTRL] = LAYOUT_5x6(
        KC_TRNS,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,                          KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11,
        KC_MNXT,KC_HOME,KC_PGUP,KC_PGDN,KC_END, KC_LCBR,                        KC_RCBR,KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_F12,
        KC_MPRV,KC_LEFT,KC_UP,  KC_DOWN,KC_RGHT,KC_LPRN,                        KC_RPRN,KC_LEFT,KC_DOWN,KC_UP,  KC_RGHT,KC_NO,
        KC_MPLY,KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_LBRC,                        KC_RBRC,KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
                        LGUI(LCTL(KC_LEFT)), LGUI(LCTL(KC_RIGHT)),                              LGUI(KC_LEFT), LGUI(KC_RGHT),
                                        KC_TRNS, KC_DEL,                        KC_TRNS, KC_TRNS,
                                        KC_LALT, KC_LCTRL,                      KC_TRNS, KC_PGDN,
                                        KC_TRNS, KC_TRNS,                       KC_TRNS, KC_PGUP),

	[_SYST] = LAYOUT_5x6(
        RESET,   RGB_M_P, RGB_M_B, RGB_M_SN, RGB_M_K, KC_NO,                    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
        RGB_TOG, KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,                    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
        RGB_MOD, RGB_SPI, RGB_VAI, RGB_SAI,  RGB_HUI, KC_NO,                    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
        RGB_RMOD,RGB_SPD, RGB_VAD, RGB_SAD,  RGB_HUD, KC_NO,                    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
                        KC_SLEP,KC_NO,                                                          KC_NO, KC_TRNS,
                                             KC_NO, KC_NO,                      KC_NO, KC_NO,
                                             KC_NO, KC_NO,                      KC_NO, KC_NO,
                                             KC_NO, KC_NO,                      KC_TRNS, KC_NO),

	[_NUMP] = LAYOUT_5x6(
        KC_NO,  KC_NO,  KC_NO,  KC_PSLS,KC_PAST,KC_NO,                          KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO, KC_NO,
        KC_TRNS,KC_BSPC,KC_P7,  KC_P8,  KC_P9,  KC_PMNS,                        KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO, KC_NO,
        KC_NO,  KC_P0,  KC_P4,  KC_P5,  KC_P6,  KC_PPLS,                        KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO, KC_NO,
        KC_PENT,KC_PDOT,KC_P1,  KC_P2,  KC_P3,  KC_PENT,                        KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO, KC_NO,
                        KC_P0,  KC_PDOT,                                                        KC_NO,  KC_NO,
                                        KC_BSPC,KC_SPC,                         KC_NO,  KC_NO,
                                        KC_NO,  KC_TAB,                         KC_NO,  KC_NO,
                                        KC_NO,  KC_TRNS,                        KC_NO,  KC_NO),

    [_GAME] = LAYOUT_5x6(
        KC_MUTE,KC_1,   KC_2,   KC_3,   KC_4,   KC_5,                           KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_GRV,
        KC_TAB, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                           KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_MINS,
        KC_ESC, KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                           KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,
        KC_ENTER,KC_Z,  KC_X,   KC_C,   KC_V,   KC_B,                           KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_BSLS,
                        KC_LGUI,ALT_TAB,                                                        KC_EQL, TG(_GAME),
                                        KC_BSPC,KC_SPC,                         KC_SPC, KC_DEL,
                                        KC_LALT,KC_LCTL,                        KC_ENT, KC_HOME,
                                        LSFT(KC_TAB),KC_TAB,                    LT(_NUMP,KC_TAB), KC_END),

    [_CLGM] = LAYOUT_5x6(
        KC_MUTE,KC_1,   KC_2,   KC_3,   KC_4,   KC_5,                           KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_GRV,
        KC_TAB, KC_Q,   KC_W,   KC_F,   KC_P,   KC_G,                           KC_J,   KC_L,   KC_U,   KC_Y,   KC_SCLN,KC_MINS,
        KC_ESC, KC_A,   KC_R,   KC_S,   KC_T,   KC_D,                           KC_H,   KC_N,   KC_E,   KC_I,   KC_O,   KC_QUOT,
        KC_ENTER,KC_Z,  KC_X,   KC_C,   KC_V,   KC_B,                           KC_K,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_BSLS,
                        KC_LGUI,ALT_TAB,                                                        KC_EQL, TO(_RUNE),
                                        KC_BSPC, KC_SPC,                        KC_SPC,KC_DEL,
                                        KC_LALT,KC_LCTL,                        KC_ENT, KC_HOME,
                                        LSFT(KC_TAB),KC_TAB,                    LT(_NUMP,KC_TAB), KC_END),

    [_RUNE] = LAYOUT_5x6(
        KC_MUTE,KC_1,   KC_2,   KC_3,   KC_4,   KC_5,                           KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_GRV,
        KC_TAB, KC_Q,   KC_W,   KC_F,   KC_P,   KC_G,                           KC_J,   KC_L,   KC_U,   KC_Y,   KC_SCLN,KC_MINS,
        KC_ESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                           KC_H,   KC_N,   KC_E,   KC_I,   KC_O,   KC_QUOT,
        KC_ENTER,KC_Z,  KC_X,   KC_C,   KC_V,   KC_B,                           KC_K,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_BSLS,
                        KC_LGUI,ALT_TAB,                                                        KC_EQL, TO(_COLE),
                                        LT(_CTRL,KC_BSPC), LSFT_T(KC_SPC),                        KC_SPC,KC_DEL,
                                        KC_LALT,KC_LCTL,                        KC_ENT, KC_HOME,
                                        LSFT(KC_TAB),LT(_NUMP,KC_TAB),                    LT(_NUMP,KC_TAB), KC_END),

    [_COLE] = LAYOUT_5x6(
        KC_MUTE,KC_1,   KC_2,   KC_3,   KC_4,   KC_5,                           KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_GRV,
        KC_TAB, KC_Q,   KC_W,   KC_F,   KC_P,   KC_G,                           KC_J,   KC_L,   KC_U,   KC_Y,   KC_SCLN,KC_MINS,
        KC_ESC, KC_A,   KC_R,   KC_S,   KC_T,   KC_D,                           KC_H,   KC_N,   KC_E,   KC_I,   KC_O,   KC_QUOT,
        KC_ENTER,KC_Z,  KC_X,   KC_C,   KC_V,   KC_B,                           KC_K,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_BSLS,
                        KC_LGUI,ALT_TAB,                                                        KC_EQL, TO(_CLGM),
                                        LT(_CTRL,KC_BSPC), LSFT_T(KC_SPC),    RSFT_T(KC_SPC), LT(_CTRL,KC_DEL),
                                        KC_LALT,LCTL_T(KC_TAB),                        KC_ENT, KC_HOME,
                                        LSFT(KC_TAB), LT(_NUMP,KC_TAB),       TG(_SYST), KC_END),

};

//Set the proper backlight color at power on
void keyboard_post_init_user(void) {
    layer_state_set_user(layer_state);
}

//Alt-tab keycode control
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {               // This will do most of the grunt work with the keycodes.
    case ALT_TAB:
      if (record->event.pressed) {
        if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          register_code(KC_LALT);
        }
        alt_tab_timer = timer_read();
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
      }
      break;
  }
  return true;
}

void matrix_scan_user(void) {     // The very important timer.
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 500) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
}

//Backlight color control
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _COLE:
        rgblight_sethsv_noeeprom (HSV_TEAL);
        break;
    case _CTRL:
        rgblight_sethsv_noeeprom (HSV_GREEN);
        break;
    case _SYST:
        rgblight_sethsv_noeeprom (HSV_PINK);
        break;
    case _NUMP:
        rgblight_sethsv_noeeprom (HSV_GOLD);
        if(!bnumlock) {
            numlock_changed = true;
            register_code(KC_NLCK);
            unregister_code(KC_NLCK);
        }
        break;
    case _QWER:
        rgblight_sethsv_noeeprom (HSV_BLUE);
        break;
    case _GAME:
        rgblight_sethsv_noeeprom (HSV_RED);
        break;
    case _CLGM:
        rgblight_sethsv_noeeprom (HSV_RED);
        break;
    case _RUNE:
        rgblight_sethsv_noeeprom (HSV_ORANGE);
        break;
    default: //  for any other layers, or the default layer
        rgblight_sethsv_noeeprom (HSV_TEAL);
        break;
    }
  return state;
}

//Encoder control
void encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) { /* First encoder */
    if (clockwise) {
      tap_code(KC_VOLD);
    } else {
      tap_code(KC_VOLU);
    }
  } else if (index == 1) { /* Second encoder */
    if (clockwise) {
      tap_code(KC_UP);
    } else {
      tap_code(KC_DOWN);
    }
  }
}

//Num Lock enabler for numpad layer.
void led_set_kb(uint8_t usb_led) {
    if (usb_led & (1<<USB_LED_NUM_LOCK)) {
        bnumlock = true;
    } else {
        bnumlock = false;
    }
}
