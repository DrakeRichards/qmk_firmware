/*
Copyright 2025 Thomas Young <thomasjyoung8@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

// QMK_KEYBOARD_H doesn't play well with clangd. See [#23968](https://github.com/qmk/qmk_firmware/issues/23968).
// Solution is to use `bear` to generate the compilation database.
// See [this reply](https://github.com/qmk/qmk_firmware/issues/23968#issuecomment-2550321135).
// Command: `bear -- qmk compile -kb fingerpunch/rockon/v2 -km drakerichards`
// Run this any time you change config.h or rules.mk.

// Compilation command: `qmk compile -kb fingerpunch/rockon/v2 -km drakerichards`
#include QMK_KEYBOARD_H
#include <qp.h>
#include <ubuntu.qff.h>
#include <felyne-dance.qgf.h>
#include <draw.c>

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _CLM,
    _CLG,
    _LWR,
    _RSE,
    _FUN,
    _GAM,
    _ADJ,
    _MSE
};

static const layer_display my_layers[] = {
    {
        .display_name = "Colemak",
        .layer_number = _CLM,
        .left_text = {"F5", "GUI", "MEH"},
        .right_text = {"MPRV", "MNXT", "MPLY"},
        .layer_colors = RGBLIGHT_LAYER_SEGMENTS(
            {0, 65, HSV_RED}
        )
    },
    {
        .display_name = "Colemak Gaming",
        .layer_number = _CLG,
        .left_text = {"RSE", "GUI", "MEH"},
        .right_text = {"MPRV", "MNXT", "MPLY"},
        .layer_colors = RGBLIGHT_LAYER_SEGMENTS(
            {0, 65, HSV_ORANGE}
        )
    },
    {
        .display_name = "Lower",
        .layer_number = _LWR,
        .left_text = {"F5", "GUI", "WLFT"},
        .right_text = {"MPRV", "MNXT", "WRT"},
        .layer_colors = RGBLIGHT_LAYER_SEGMENTS(
            {0, 65, 213, 255, 64}
        )
    },
    {
        .display_name = "Raise",
        .layer_number = _RSE,
        .left_text = {"F5", "GUI", "MEH"},
        .right_text = {"MPRV", "MNXT", "MPLY"},
        .layer_colors = RGBLIGHT_LAYER_SEGMENTS(
            {0, 65, HSV_BLUE}
        )
    },
    {
        .display_name = "Function Keys",
        .layer_number = _FUN,
        .left_text = {"F5", "GUI", "MEH"},
        .right_text = {"MPRV", "MNXT", "MPLY"},
        .layer_colors = RGBLIGHT_LAYER_SEGMENTS(
            {0, 65, HSV_PURPLE}
        )
    },
    {
        .display_name = "QWERTY Gaming",
        .layer_number = _GAM,
        .left_text = {"RSE", "(", "["},
        .right_text = {"}", ")", "]"},
        .layer_colors = RGBLIGHT_LAYER_SEGMENTS(
            {0, 65, HSV_PURPLE}
        )
    },
    {
        .display_name = "Adjust",
        .layer_number = _ADJ,
        .left_text = {"", "", "BOOT"},
        .right_text = {"", "", ""},
        .layer_colors = RGBLIGHT_LAYER_SEGMENTS(
            {0, 65, HSV_PURPLE}
        )
    },
    {
        .display_name = "Mouse",
        .layer_number = _MSE,
        .left_text = {"", "", ""},
        .right_text = {"", "", ""},
        .layer_colors = RGBLIGHT_LAYER_SEGMENTS(
            {0, 65, HSV_PURPLE}
        )
    }
};

enum custom_keycodes {
    LOWER = SAFE_RANGE,
    RAISE,
    ADJUST,
    KC_IDLE
};

bool idle_enabled = false;

// Custom macros to help with the formatting of my keymaps.
#define MC_RESC LT(_RSE,KC_ESC)
#define MC_OSMM OSM(MOD_MEH)
#define MC_LBSP LT(_LWR,KC_BSPC)
#define MC_LSPC LT(_LWR,KC_SPC)
#define MC_WLFT LGUI(LCTL(KC_LEFT))
#define MC_WRGT LGUI(LCTL(KC_RIGHT))
#define MC_OSMG OSM(MOD_LGUI)

// NOTE: For the encoder clicks, regardless of which location you put them (under palm or in the center), in the keymap, they are represented by the center two keycodes in the bottom row
//                           KC_LCTL,   KC_LGUI,   LOWER,     KC_SPC,    KC_LALT, --->  KC_MUTE, LCTL(KC_BSPC), <--- KC_RALT,   KC_SPC,    RAISE,     KC_RGUI,   KC_RCTL
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// Colemak
[_CLM] = LAYOUT(
KC_GRV,     KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,     KC_PERC,    KC_F5,                                          KC_MPRV,    KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_LPRN,    KC_RPRN,    KC_EQL,
KC_TAB,     KC_Q,       KC_W,       KC_F,       KC_P,       KC_G,       KC_LGUI,                                        KC_MNXT,    KC_J,       KC_L,       KC_U,       KC_Y,       KC_SCLN,    KC_MINS,
MC_RESC,    KC_A,       KC_R,       KC_S,       KC_T,       KC_D,       MC_OSMM,                                        KC_MPLY,    KC_H,       KC_N,       KC_E,       KC_I,       KC_O,       KC_QUOT,
KC_ENT,     KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_LALT,                                        KC_DEL,     KC_K,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_BSLS,
                        KC_NO,      OSL(_FUN),  MC_LBSP,    KC_LSFT,    KC_LCTL,    KC_MUTE,                TG(_ADJ),   MO(_RSE),   KC_SPC,     KC_DEL,     TG(_CLG),   KC_NO
),

// Colemak Gaming (No layer taps, combos, or mod taps)
[_CLG] = LAYOUT(
_______,    KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       TG(_RSE),                                       _______,    KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       _______,
_______,    _______,    _______,    _______,    _______,    _______,    _______,                                        _______,    _______,    _______,    _______,    _______,    _______,    _______,
KC_ESC,     _______,    _______,    _______,    _______,    _______,    _______,                                        _______,    _______,    _______,    _______,    _______,    _______,    _______,
_______,    _______,    _______,    _______,    _______,    _______,    _______,                                        _______,    _______,    _______,    _______,    _______,    _______,    _______,
                        _______,    _______,    KC_BSPC,    _______,    _______,    _______,                _______,    _______,    _______,    _______,    TO(_GAM),   _______
),

// Lower
[_LWR] = LAYOUT(
KC_GRV,     _______,    _______,    _______,    _______,    _______,    _______,                                        _______,    _______,    _______,    _______,    KC_MINS,    KC_EQL,     _______,
_______,    KC_MINS,    KC_7,       KC_8,       KC_9,       KC_LCBR,    _______,                                        _______,    KC_RCBR,    _______,    _______,    _______,    _______,    _______,
KC_COLON,   KC_0,       KC_4,       KC_5,       KC_6,       KC_LPRN,    MC_WLFT,                                        MC_WRGT,    KC_RPRN,    _______,    _______,    _______,    _______,    _______,
_______,    KC_DOT,     KC_1,       KC_2,       KC_3,       KC_LBRC,    _______,                                        _______,    KC_RBRC,    _______,    _______,    _______,    _______,    _______,
                        _______,    KC_IDLE,    _______,    _______,    _______,    _______,                _______,    _______,    _______,    _______,    _______,    _______
),

// Raise
[_RSE] = LAYOUT(
_______,    _______,    _______,    KC_PGUP,    _______,    _______,    _______,                                        _______,    _______,    _______,    _______,    _______,    _______,    _______,
_______,    _______,    KC_HOME,    KC_UP,      KC_END,     _______,    _______,                                        _______,    _______,    _______,    _______,    _______,    _______,    _______,
_______,    _______,    KC_LEFT,    KC_DOWN,    KC_RGHT,    _______,    _______,                                        _______,    _______,    _______,    _______,    _______,    _______,    _______,
_______,    _______,    _______,    KC_PGDN,    _______,    _______,    _______,                                        _______,    _______,    _______,    _______,    _______,    _______,    _______,
                        _______,    _______,    _______,    _______,    _______,    _______,                _______,    _______,    _______,    _______,    _______,    _______
),

// Function Keys
[_FUN] = LAYOUT(
_______,    _______,    KC_F10,     KC_F11,     KC_F12,     KC_F16,     _______,                                        _______,    _______,    _______,    _______,    _______,    _______,    _______,
_______,    _______,    KC_F7,      KC_F8,      KC_F9,      KC_F15,     _______,                                        _______,    _______,    _______,    _______,    _______,    _______,    _______,
_______,    _______,    KC_F4,      KC_F5,      KC_F6,      KC_F14,     _______,                                        _______,    _______,    _______,    _______,    _______,    _______,    _______,
_______,    _______,    KC_F1,      KC_F2,      KC_F3,      KC_F13,     _______,                                        _______,    _______,    _______,    _______,    _______,    _______,    _______,
                        _______,    TG(_FUN),   _______,    _______,    _______,    _______,                _______,    _______,    _______,    _______,    _______,    _______
),

// QWERTY Gaming (No layer taps, combos, or mod taps)
// Columns are shifted to the right by one key to make the layout more comfortable for gaming.
[_GAM] = LAYOUT(
KC_GRV,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       TG(_RSE),                                       KC_RCBR,    KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_BSPC,
KC_TAB,     KC_T,       KC_Q,       KC_W,       KC_E,       KC_R,       KC_LPRN,                                        KC_RPRN,    KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_BSLS,
KC_ESC,     KC_G,       KC_A,       KC_S,       KC_D,       KC_F,       KC_LBRC,                                        KC_RBRC,    KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,
KC_ENT,     KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_BSPC,                                        ADJUST,     KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_ENT,
                        KC_NO,      KC_LALT,    KC_LCTL,    KC_SPC,     KC_LSFT,    _______,                _______,    KC_RALT,    KC_SPC,     MO(_RSE),   TO(_CLM),   KC_NO
),

// Adjust
[_ADJ] = LAYOUT(
QK_BOOT,    KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      _______,                                        _______,    _______,    _______,    _______,    _______,    _______,    _______,
_______,    UG_TOGG,    UG_PREV,    UG_NEXT,    _______,    TG(_GAM),   _______,                                        _______,    _______,    _______,    _______,    _______,    _______,    _______,
_______,    UG_SPDU,    UG_HUEU,    UG_SATU,    UG_VALU,    TG(_CLM),   CG_TOGG,                                        _______,    _______,    _______,    _______,    _______,    _______,    _______,
_______,    UG_SPDD,    UG_HUED,    UG_SATD,    UG_VALD,    _______,    _______,                                        _______,    _______,    _______,    _______,    _______,    _______,    _______,
                        _______,    _______,    _______,    _______,    _______,    QK_BOOT,                _______,    _______,    _______,    _______,    _______,    _______
),

// Mouse
[_MSE] = LAYOUT(
_______,    _______,    _______,    _______,    _______,    _______,    _______,                                        _______,    _______,    _______,    _______,    _______,    _______,    _______,
_______,    _______,    KC_WH_L,    KC_WH_U,    KC_WH_R,    _______,    _______,                                        _______,    _______,    _______,    _______,    _______,    _______,    _______,
_______,    _______,    KC_BTN3,    KC_BTN2,    KC_BTN1,    _______,    _______,                                        _______,    _______,    _______,    _______,    _______,    _______,    _______,
_______,    _______,    _______,    KC_WH_D,    _______,    _______,    _______,                                        _______,    _______,    _______,    _______,    _______,    _______,    _______,
                        _______,    _______,    _______,    _______,    _______,    _______,                _______,    _______,    _______,    _______,    _______,    _______
)
};

// [Encoders](https://docs.qmk.fm/features/encoders)
#if defined (ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_LEFT, KC_RIGHT) },
    [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_LEFT, KC_RIGHT) },
    [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_LEFT, KC_RIGHT) },
    [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_LEFT, KC_RIGHT) },
    [4] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_LEFT, KC_RIGHT) },
    [5] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_LEFT, KC_RIGHT) },
    [6] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_LEFT, KC_RIGHT) },
    [7] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_LEFT, KC_RIGHT) },
};
#endif

// [Pointing Device](https://docs.qmk.fm/features/pointing_device)
#ifdef POINTING_DEVICE_ENABLE
    void pointing_device_init_user(void) {
        // only required if AUTO_MOUSE_DEFAULT_LAYER is not set to index of <mouse_layer>
        set_auto_mouse_layer(_MSE);
        // always required before the auto mouse feature will work
        set_auto_mouse_enable(true);
    }
#endif

/*
[RGB Layer Lighting](https://docs.qmk.fm/features/rgblight#lighting-layers)

LED Indexes (66 total):
0   1   2   3   4   5   6   _   _   59  60  61  62  63  64  65
13  12  11  10  9   8   7   _   _   58  57  56  55  54  53  52
14  15  16  17  18  19  20  _   _   45  46  47  48  49  50  51
27  26  25  24  23  22  21  _   _   44  43  42  41  40  39  38
_   _   28e 29  30  31  32  _   _   33  34  35  36  37e _   _
LEDs marked with "e" are optional encoder positions.

If I ever decide to use [RGB Matrix](https://docs.qmk.fm/features/rgb_matrix) instead,
the matrix can be found in [sadekbaroudi's QMK fork](https://github.com/sadekbaroudi/qmk_firmware/blob/master/keyboards/fingerpunch/rockon/v2/v2.c).

The `RGBLIGHT_LAYER_SEGMENTS` macro takes a start index, length, and color (from HSV macros or in `,R,G,B` format).
*/
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_layers[0].layer_colors,
    my_layers[1].layer_colors,
    my_layers[2].layer_colors,
    my_layers[3].layer_colors,
    my_layers[4].layer_colors,
    my_layers[5].layer_colors,
    my_layers[6].layer_colors,
    my_layers[7].layer_colors
);

// Userspace functions
bool cg_toggle_enabled = false;

void keyboard_post_init_user(void) {
    rgblight_layers = my_rgb_layers;
    display = qp_sh1106_make_i2c_device(128, 64, 0x3c);
    qp_init(display, QP_ROTATION_180);
    my_font = qp_load_font_mem(font_ubuntu);
    my_image = qp_load_image_mem(gfx_felyne_dance);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // Toggle the idle macro
        case KC_IDLE:
            if (record->event.pressed) {
                const uint16_t width = qp_get_width(display);
                const uint16_t height = qp_get_height(display);
                const uint16_t x = (width - my_image->width) / 2;
                const uint16_t y = height - my_image->height;

                if (idle_enabled) {
                    qp_stop_animation(my_anim);
                    // Clear a rectangle in the size of the image
                    qp_rect(display, x, y, x + my_image->width, y + my_image->height, HSV_BLACK, true);
                } else {
                    if (my_image != NULL) {
                        // Start the animation in the center bottom of the display
                        my_anim = qp_animate(display, x, y, my_image);
                    }
                }
                idle_enabled = !idle_enabled;
            };
            break;
        // Switch Ctrl/GUI for Mac
        case CG_TOGG:
            if (record->event.pressed) {
                cg_toggle_enabled = !cg_toggle_enabled;
            }
        default:
            break;
    }

    return true;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(_CLM, layer_state_cmp(state, _CLM));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    // Set the RGB lighting based on the current layer
    // These are applied IN ORDER, so the last one will take precedence
    rgblight_set_layer_state(_CLG, layer_state_cmp(state, _CLG));
    rgblight_set_layer_state(_LWR, layer_state_cmp(state, _LWR));
    rgblight_set_layer_state(_RSE, layer_state_cmp(state, _RSE));
    rgblight_set_layer_state(_FUN, layer_state_cmp(state, _FUN));
    rgblight_set_layer_state(_GAM, layer_state_cmp(state, _GAM));
    rgblight_set_layer_state(_ADJ, layer_state_cmp(state, _ADJ));
    rgblight_set_layer_state(_MSE, layer_state_cmp(state, _MSE));

    // Display the current layer on the OLED screen
    if (my_font != NULL) {
        // Clear the top of the display
        const int16_t display_width = qp_get_width(display);
        const int16_t display_height = qp_get_height(display);
        qp_rect(display, 0,0, display_width, my_font->line_height, HSV_BLACK, true);
        // Clear the left side
        qp_rect(display, 0, my_font->line_height, qp_textwidth(my_font, "AAAA"), display_height, HSV_BLACK, true);
        // Clear the right side
        qp_rect(display, display_width - qp_textwidth(my_font, "AAAA"), my_font->line_height, display_width, display_height, HSV_BLACK, true);
        switch (get_highest_layer(state)) {
            case _CLM:
                layer_display_draw(&my_layers[_CLM], display, my_font);
                break;
            case _GAM:
                layer_display_draw(&my_layers[_GAM], display, my_font);
                break;
            case _CLG:
                layer_display_draw(&my_layers[_CLG], display, my_font);
                break;
            case _LWR:
                layer_display_draw(&my_layers[_LWR], display, my_font);
                break;
            case _RSE:
                layer_display_draw(&my_layers[_RSE], display, my_font);
                break;
            case _FUN:
                layer_display_draw(&my_layers[_FUN], display, my_font);
                break;
            case _ADJ:
                layer_display_draw(&my_layers[_ADJ], display, my_font);
                break;
            case _MSE:
                layer_display_draw(&my_layers[_MSE], display, my_font);
                break;
            default:
                break;
        }
    }

    return state;
}

// Keymap formatting using [qmk-keyboard-format](https://github.com/jurgen-kluft/go-qmk-keymap)
// To format the keymap, run `cat ./keyboards/fingerpunch/rockon/v2/keymaps/drakerichards/keymap.c | ./go-qmk-keymap > ./keymap.c`
// The formatted file can then be moved back to the original location with `mv -f ./keymap.c ./keyboards/fingerpunch/rockon/v2/keymaps/drakerichards/keymap.c`

/*
qmk-keyboard-format:json:begin
{
    "name": "RockOn",
    "numkeys": 68,
    "svg": "rockon.svg",
    "rows": [
        [  0,  1,  2,  3,  4,  5,  6, -1, -2, -1,  7,  8,  9, 10, 11, 12, 13 ],
        [ 14, 15, 16, 17, 18, 19, 20, -1, -2, -1, 21, 22, 23, 24, 25, 26, 27 ],
        [ 28, 29, 30, 31, 32, 33, 34, -1, -2, -1, 35, 36, 37, 38, 39, 40, 41 ],
        [ 42, 43, 44, 45, 46, 47, 48, -1, -2, -1, 49, 50, 51, 52, 53, 54, 55 ],
        [ -1, -1, 56, 57, 58, 59, 60, 61, -2, 62, 63, 64, 65, 66, 67, -1, -1 ]
    ],
    "spacing": [
        10,
        6,
        8
    ],
    "vizemits": [
        { "line": "[_CLM] = LAYOUT_(", "layer": "_CLM" },
        { "line": "[_GAM] = LAYOUT_(", "layer": "_GAM" },
        { "line": "[_RSC] = LAYOUT_(", "layer": "_RSC" },
        { "line": "[_LWR] = LAYOUT_(", "layer": "_LWR" },
        { "line": "[_RSE] = LAYOUT_(", "layer": "_RSE" },
        { "line": "[_FUN] = LAYOUT_(", "layer": "_FUN" },
        { "line": "[_ADJ] = LAYOUT_(", "layer": "_ADJ" }
    ],
    "vizline": "//#",
    "vizboard": [
        "    //#                         |-------|                                                                   |-------|                         ",
        "    //#                 |-------| _003_ |-------|                                                   |-------| _010_ |-------|                 ",
        "    //#                 | _002_ |       | _004_ |-------|-------|                   |-------|-------| _009_ |       | _011_ |                 ",
        "    //# |-------|-------|       |-------|       | _005_ | _006_ |                   | _007_ | _008_ |       |-------|       |-------|-------| ",
        "    //# | _000_ | _001_ |-------| _017_ |-------|       |       |                   |       |       |-------| _024_ |-------| _012_ | _013_ | ",
        "    //# |       |       | _016_ |       | _018_ |-------|-------|                   |-------|-------| _023_ |       | _025_ |       |       | ",
        "    //# |-------|-------|       |-------|       | _019_ | _020_ |                   | _021_ | _022_ |       |-------|       |-------|-------| ",
        "    //# | _014_ | _015_ |-------| _031_ |-------|       |       |                   |       |       |-------| _038_ |-------| _026_ | _027_ | ",
        "    //# |       |       | _030_ |       | _032_ |-------|-------|                   |-------|-------| _037_ |       | _039_ |       |       | ",
        "    //# |-------|-------|       |-------|       | _033_ | _034_ |                   | _035_ | _036_ |       |-------|       |-------|-------| ",
        "    //# | _028_ | _029_ |-------| _045_ |-------|       |       |                   |       |       |-------| _052_ |-------| _040_ | _041_ | ",
        "    //# |       |       | _044_ |       | _046_ |-------|-------|                   |-------|-------| _051_ |       | _053_ |       |       | ",
        "    //# |-------|-------|       |-------|       | _047_ |-------|                   |-------| _050_ |       |-------|       |-------|-------| ",
        "    //# | _042_ | _043_ |-------|       |-------|       | _048_ |                   | _049_ |       |-------|       |-------| _054_ | _055_ | ",
        "    //# |       |       |                       |-------|       |                   |       |-------|                       |       |       | ",
        "    //# |-------|-------|-------|-------|-------|-------|-------|-------|   |-------|-------|-------|-------|-------|-------|-------|-------| ",
        "    //#                 | _056_ | _057_ | _058_ | _059_ | _060_ | _061_ |   | _062_ | _063_ | _064_ | _065_ | _066_ | _067_ |                 ",
        "    //#                 |       |       |       |       |       |       |   |       |       |       |       |       |       |                 ",
        "    //#                 |encodr-|-------|-------|-------|-------|-------|   |-------|-------|-------|-------|-------|encodr-|                 "
    ],
    "vizsymbols": {
        "KC_TRANS": "     ",
        "KC_A": "  A  " ,
        "KC_B": "  B  " ,
        "KC_C": "  C  " ,
        "KC_D": "  D  " ,
        "KC_E": "  E  " ,
        "KC_F": "  F  " ,
        "KC_G": "  G  " ,
        "KC_H": "  H  " ,
        "KC_I": "  I  " ,
        "KC_J": "  J  " ,
        "KC_K": "  K  " ,
        "KC_L": "  L  " ,
        "KC_M": "  M  " ,
        "KC_N": "  N  " ,
        "KC_O": "  O  " ,
        "KC_P": "  P  " ,
        "KC_Q": "  Q  " ,
        "KC_R": "  R  " ,
        "KC_S": "  S  " ,
        "KC_T": "  T  " ,
        "KC_U": "  U  " ,
        "KC_V": "  V  " ,
        "KC_W": "  W  " ,
        "KC_X": "  X  " ,
        "KC_Y": "  Y  " ,
        "KC_Z": "  Z  " ,
        "KC_COMMA": "  ,  ",
        "KC_DOT": "  .  ",
        "KC_SCOLON": "  ;  ",
        "KC_SCLN": "  :  ",
        "KC_SLASH": "  /  ",
        "KC_ESC": " ⎋  " ,
        "KC_CUT": " ✄  " ,
        "KC_UNDO": " ↶  " ,
        "KC_REDO": " ↷  " ,
        "KC_VOLU": " 🕪  " ,
        "KC_VOLD": " 🕩  " ,
        "KC_MUTE":   "  🕨" ,
        "KC_TAB": " ⭾  " ,
        "KC_MENU": "  𝌆  " ,
        "KC_CAPSLOCK": "  ⇪  " ,
        "KC_NUMLK": "  ⇭  " ,
        "KC_SCRLK": "  ⇳  " ,
        "KC_PRSCR": "  ⎙  " ,
        "KC_PAUSE": "  ⎉  " ,
        "KC_BREAK": "  ⎊  " ,
        "KC_ENTER": "  ⏎  " ,
        "KC_BSPACE": " ⌫  " ,
        "KC_DELETE": " ⌦ " ,
        "KC_INSERT": " ⎀  " ,
        "KC_LEFT": " ◁  " ,
        "KC_RIGHT": " ▷  " ,
        "KC_UP": " △  " ,
        "KC_DOWN": " ▽  " ,
        "KC_HOME": " ⇤  " ,
        "KC_END": " ⇥  " ,
        "KC_PGUP": " ⇞  " ,
        "KC_PGDOWN": " ⇟  " ,
        "KC_LSFT": "  ⇧  " ,
        "KC_RSFT": "  ⇧  " ,
        "KC_LCTL": "  ^  " ,
        "KC_RCTL": "  ^  " ,
        "KC_LALT": " ⎇  " ,
        "KC_RALT": " ⎇  " ,
        "KC_HYPER": "  ✧  " ,
        "KC_LGUI": " ⌘  " ,
        "KC_RGUI": " ⌘  "
    }
}
qmk-keyboard-format:json:end
*/
