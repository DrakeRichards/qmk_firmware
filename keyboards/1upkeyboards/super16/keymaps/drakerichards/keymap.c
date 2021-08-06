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
    NUMF,
    NUMS,
    RUNE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [NUMP] = LAYOUT_ortho_4x4( /* Base */
        KC_PSLS,    KC_KP_7,    KC_KP_8,    KC_KP_9,
        KC_PMNS,    KC_KP_4,    KC_KP_5,    KC_KP_6,
        KC_PPLS,    KC_KP_1,    KC_KP_2,    KC_KP_3,
        KC_PAST,    TO(NUMS),   KC_PDOT,    KC_KP_0
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
        KC_LSFT,    TO(NUMP),   KC_ESC,     KC_SPC
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}

const rgblight_segment_t PROGMEM my_numlayers_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 3, HSV_WHITE},
    {4, 1, HSV_RED},
    {5, 3, HSV_WHITE},
    {8, 1, HSV_RED},
    {9, 3, HSV_WHITE},
    {12, 1, HSV_RED},
    {13, 2, HSV_WHITE},
    {15, 1, HSV_YELLOW},
    {16, 1, HSV_RED}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_numlayers_layer
);

void keyboard_post_init_user(void) {
    rgblight_layers = my_rgb_layers;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, NUMP));
    return state;
}
