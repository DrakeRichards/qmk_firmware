/* Copyright 2019 MechMerlin
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
#include QMK_KEYBOARD_H

enum LAYER_NAMES {
    NUMP,
    NUMS,
    NUMF,
    RUNE,
    TEXS
};

enum CUSTOM_KEYCODES {
    IDLE = SAFE_RANGE,
    DCLICK
};

enum COMBOS {
    PENT,
    PBSP,
    PESC,
    PTAB
};

const uint16_t PROGMEM pent_combo[] = {KC_PPLS, KC_PAST, COMBO_END};
const uint16_t PROGMEM pbsp_combo[] = {KC_PSLS, KC_KP_7, COMBO_END};
const uint16_t PROGMEM pesc_combo[] = {KC_KP_7, KC_KP_8, COMBO_END};
const uint16_t PROGMEM ptab_combo[] = {KC_KP_8, KC_KP_9, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [PENT] = COMBO(pent_combo, KC_PENT),
    [PBSP] = COMBO(pbsp_combo, KC_BSPC),
    [PESC] = COMBO(pesc_combo, KC_ESC),
    [PTAB] = COMBO(ptab_combo, KC_TAB)
};

bool idle_enabled = false;
uint16_t idle_timer = 0;
bool idle_led_state = false;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [NUMP] = LAYOUT_ortho_4x4( /* Base */
        KC_PSLS,    KC_KP_7,    KC_KP_8,    KC_KP_9,
        KC_PMNS,    KC_KP_4,    KC_KP_5,    KC_KP_6,
        KC_PPLS,    KC_KP_1,    KC_KP_2,    KC_KP_3,
        KC_PAST,       TO(NUMS),   KC_PDOT,    KC_KP_0
  ),

    [NUMS] = LAYOUT_ortho_4x4( /* Regular numbers */
        KC_PSLS,    KC_7,       KC_8,       KC_9,
        KC_PMNS,    KC_4,       KC_5,       KC_6,
        KC_PPLS,    KC_1,       KC_2,       KC_3,
        KC_PAST,    TO(NUMF),   KC_DOT,     KC_0
  ),

    [NUMF] = LAYOUT_ortho_4x4( /* Function keys */
        KC_PSLS,    KC_F7,      KC_F8,      KC_F9,
        KC_PMNS,    KC_F4,      KC_F5,      KC_F6,
        KC_PPLS,    KC_F1,      KC_F2,      KC_F3,
        KC_PAST,    TO(RUNE),   KC_DOT,     KC_F10
  ),

    [RUNE] = LAYOUT_ortho_4x4( /* Old School Runescape */
        KC_1,       KC_2,       KC_3,       KC_4,
        KC_F5,      KC_F6,      KC_F7,      KC_F8,
        KC_F1,      KC_F2,      KC_F3,      KC_F4,
        LCTL_T(KC_ESC),     TO(TEXS),   KC_SPC,     KC_LSFT
  ),

    [TEXS] = LAYOUT_ortho_4x4( /* Clicker/Idler */
        DCLICK,       KC_MS_BTN1,       KC_MS_BTN1,       KC_MS_BTN1,
        DCLICK,      KC_MS_BTN1,      KC_MS_BTN1,      KC_MS_BTN1,
        DCLICK,      DCLICK,      DCLICK,      DCLICK,
        IDLE,     TO(NUMP),   DCLICK,     DCLICK
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case IDLE:
            if (record->event.pressed) {
                if (idle_enabled == true) {
                    idle_enabled = false;
                    idle_timer = 0;
                } else {
                    idle_enabled = true;
                    idle_timer = 0;
                };
            }
            break;
        case DCLICK:
            if (record->event.pressed) {
                send_string(SS_TAP(X_MS_BTN1) SS_DELAY(200) SS_TAP(X_MS_BTN1));
            }
            break;
    }
    return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {
    if (idle_enabled == true) {
        ++idle_timer;
        if (idle_timer >= 3000) {
            tap_code(KC_F15);
            idle_timer = 0;
            /*
            if (idle_led_state == true) {
                rgblight_sethsv_at(HSV_RED, 15);
                idle_led_state = false;
            } else {
                rgblight_sethsv_at(HSV_YELLOW, 15);
                idle_led_state = true;
            };*/

            rgblight_toggle_noeeprom();

        } else {
        }
    }



}

void led_set_user(uint8_t usb_led) {

}

const rgblight_segment_t PROGMEM my_numlayers_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_BLUE},
    {1, 6, HSV_GREEN},
    {7, 2, HSV_BLUE},
    {9, 3, HSV_GREEN},
    {12, 2, HSV_GREEN},
    {14, 1, HSV_RED},
    {15, 1, HSV_BLUE}
);

const rgblight_segment_t PROGMEM my_fnum_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_PURPLE},
    {1, 6, HSV_TEAL},
    {7, 2, HSV_PURPLE},
    {9, 3, HSV_TEAL},
    {12, 2, HSV_TEAL},
    {14, 1, HSV_RED},
    {15, 1, HSV_PURPLE}
);

const rgblight_segment_t PROGMEM my_numnum_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_GOLD},
    {1, 6, HSV_CYAN},
    {7, 2, HSV_GOLD},
    {9, 3, HSV_CYAN},
    {12, 2, HSV_CYAN},
    {14, 1, HSV_RED},
    {15, 1, HSV_GOLD}
);

const rgblight_segment_t PROGMEM my_runelayer_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 4, HSV_TURQUOISE},
    {4, 8, HSV_BLUE},
    {12, 1, HSV_YELLOW},
    {13, 1, HSV_GOLD},
    {14, 1, HSV_RED},
    {15, 1, HSV_PURPLE}
);

const rgblight_segment_t PROGMEM texas_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_BLUE},
    {1, 6, HSV_WHITE},
    {7, 2, HSV_BLUE},
    {9, 6, HSV_RED},
    {15, 1, HSV_CYAN}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_numlayers_layer,
    my_fnum_layer,
    my_numnum_layer,
    my_runelayer_layer,
    texas_layer
);

void keyboard_post_init_user(void) {
    rgblight_layers = my_rgb_layers;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, NUMP));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, NUMS));
    rgblight_set_layer_state(2, layer_state_cmp(state, NUMF));
    rgblight_set_layer_state(3, layer_state_cmp(state, RUNE));
    rgblight_set_layer_state(4, layer_state_cmp(state, TEXS));
    return state;
}
