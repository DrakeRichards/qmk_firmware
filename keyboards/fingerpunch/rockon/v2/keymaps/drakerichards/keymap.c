#include QMK_KEYBOARD_H
#include "pointing_device.h"
#include "color.h"
#include "oled_cat_dance.c"

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _CLM,
    _GAM,
    _RSC,
    _LWR,
    _RSE,
    _ADJ,
    _MSE
};

enum custom_keycodes {
    LOWER = SAFE_RANGE,
    RAISE,
    ADJUST,
    KC_IDLE
};

bool is_caps_lock_on;
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

[_CLM] = LAYOUT(
KC_GRV,     KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,     KC_PERC,    KC_F5,                                          KC_MPRV,    KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_LPRN,    KC_RPRN,    KC_EQL,
KC_TAB,     KC_Q,       KC_W,       KC_F,       KC_P,       KC_G,       KC_INS,                                         KC_MNXT,    KC_J,       KC_L,       KC_U,       KC_Y,       KC_SCLN,    KC_MINS,
MC_RESC,    KC_A,       KC_R,       KC_S,       KC_T,       KC_D,       MC_OSMM,                                        KC_MPLY,    KC_H,       KC_N,       KC_E,       KC_I,       KC_O,       KC_QUOT,
KC_ENT,     KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_LALT,                                        KC_DEL,     KC_K,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_BSLS,
                        KC_NO,      KC_LGUI,    MC_LBSP,    KC_LSFT,    KC_LCTL,    KC_MUTE,                TG(_ADJ),   MO(_RSE),   KC_SPC,     KC_DEL,     TO(_GAM),   KC_NO
),

[_GAM] = LAYOUT(
KC_GRV,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_LCBR,                                        KC_RCBR,    KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_BSPC,
KC_TAB,     KC_T,       KC_Q,       KC_W,       KC_E,       KC_R,       KC_LPRN,                                        KC_RPRN,    KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_BSLS,
KC_ESC,     KC_G,       KC_A,       KC_S,       KC_D,       KC_F,       KC_LBRC,                                        KC_RBRC,    KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,
KC_ENT,     KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_BSPC,                                        ADJUST,     KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_ENT,
                        KC_NO,      KC_LALT,    KC_LCTL,    KC_SPC,     KC_LSFT,    _______,                _______,    KC_RALT,    KC_SPC,     MO(_RSE),   TO(_RSC),   KC_NO
),

[_RSC] = LAYOUT(
MC_OSMG,    KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F5,                                          KC_MPRV,    KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,
KC_TAB,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_GRV,                                         KC_MNXT,    KC_J,       KC_L,       KC_U,       KC_Y,       KC_SCLN,    KC_MINS,
MC_RESC,    KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_BSPC,                                        KC_MPLY,    KC_H,       KC_N,       KC_E,       KC_I,       KC_O,       KC_QUOT,
KC_ENT,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_LALT,                                        KC_DEL,     KC_K,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_BSLS,
                        KC_NO,      KC_BTN1,    MC_LSPC,    KC_LSFT,    KC_LCTL,    KC_MUTE,                TG(_ADJ),   MO(_RSE),   KC_SPC,     KC_DEL,     TO(_CLM),   KC_NO
),

[_LWR] = LAYOUT(
KC_GRV,     _______,    _______,    _______,    _______,    _______,    _______,                                        _______,    _______,    _______,    _______,    KC_MINS,    KC_EQL,     _______,
_______,    KC_MINS,    KC_7,       KC_8,       KC_9,       KC_LCBR,    _______,                                        _______,    KC_RCBR,    _______,    _______,    _______,    _______,    _______,
KC_COLON,   KC_0,       KC_4,       KC_5,       KC_6,       KC_LPRN,    MC_WLFT,                                        MC_WRGT,    KC_RPRN,    _______,    _______,    _______,    _______,    _______,
_______,    KC_DOT,     KC_1,       KC_2,       KC_3,       KC_LBRC,    _______,                                        _______,    KC_RBRC,    _______,    _______,    _______,    _______,    _______,
                        _______,    KC_IDLE,    _______,    _______,    _______,    _______,                _______,    _______,    _______,    _______,    _______,    _______
),

[_RSE] = LAYOUT(
_______,    _______,    _______,    KC_PGUP,    _______,    _______,    _______,                                        _______,    KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,
_______,    _______,    KC_HOME,    KC_UP,      KC_END,     _______,    _______,                                        _______,    _______,    _______,    _______,    _______,    _______,    _______,
_______,    _______,    KC_LEFT,    KC_DOWN,    KC_RGHT,    _______,    _______,                                        _______,    _______,    _______,    _______,    _______,    _______,    _______,
_______,    _______,    _______,    KC_PGDN,    _______,    _______,    _______,                                        _______,    _______,    _______,    _______,    _______,    _______,    _______,
                        _______,    _______,    _______,    _______,    _______,    _______,                _______,    _______,    _______,    _______,    _______,    _______
),

[_ADJ] = LAYOUT(
RESET,      KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      _______,                                        _______,    KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     _______,
_______,    RGB_TOG,    RGB_RMOD,   RGB_MOD,    _______,    TG(_GAM),   _______,                                        _______,    _______,    _______,    _______,    KC_F11,     KC_F12,     _______,
_______,    RGB_SPI,    RGB_HUI,    RGB_SAI,    RGB_VAI,    TG(_CLM),   CG_TOGG,                                        _______,    _______,    _______,    _______,    _______,    _______,    _______,
_______,    RGB_SPD,    RGB_HUD,    RGB_SAD,    RGB_VAD,    _______,    _______,                                        _______,    _______,    _______,    _______,    _______,    _______,    _______,
                        _______,    _______,    _______,    _______,    _______,    QK_BOOT,                _______,    _______,    _______,    _______,    _______,    _______
),

[_MSE] = LAYOUT(
_______,    _______,    _______,    _______,    _______,    _______,    _______,                                        _______,    KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,
_______,    _______,    KC_WH_L,    KC_WH_U,    KC_WH_R,    _______,    _______,                                        _______,    _______,    _______,    _______,    _______,    _______,    _______,
_______,    _______,    KC_BTN3,    KC_BTN2,    KC_BTN1,    _______,    _______,                                        _______,    _______,    _______,    _______,    _______,    _______,    _______,
_______,    _______,    _______,    KC_WH_D,    _______,    _______,    _______,                                        _______,    _______,    _______,    _______,    _______,    _______,    _______,
                        _______,    _______,    _______,    _______,    _______,    _______,                _______,    _______,    _______,    _______,    _______,    _______
)
};

// Encoder
bool encoder_update_user(uint8_t index, bool clockwise) {
    switch (index)
    {
    case 0:
        if (clockwise) {
            tap_code_delay(KC_VOLD, 10);
        } else {
            tap_code_delay(KC_VOLU, 10);
        }
        break;
    case 1:
        if (clockwise) {
            tap_code_delay(KC_LEFT, 10);
        } else {
            tap_code_delay(KC_RIGHT, 10);
        }
        break;
    default:
        break;
    }
    return false;
}

// status constants
bool cg_toggle_enabled = false;

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;
}

// OLED
void render_cat_dance(void) {
    if (idle_enabled) {
        oled_set_cursor(0,0);
        if (timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
            tap_code(KC_F15);
            anim_timer = timer_read32();
            curr_anim_frame = (curr_anim_frame + 1) % ANIM_FRAMES;
            oled_write_raw_P(DanceAnimation[abs((ANIM_FRAMES - 1) - curr_anim_frame)], ANIM_SIZE);
        }
    }
}

void render_status(void) {
    // Host Keyboard Layer Status
    switch (get_highest_layer(layer_state|default_layer_state)) {
        case _GAM:
            oled_write_P(PSTR("Gaming\n"), false);
            break;
        case _CLM:
            oled_write_P(PSTR("\n"), false);
            break;
        case _LWR:
            oled_write_P(PSTR("Lower\n"), false);
            break;
        case _RSE:
            oled_write_P(PSTR("Raise\n"), false);
            break;
        case _ADJ:
            oled_write_P(PSTR("Adjust\n"), false);
            break;
        case _RSC:
            oled_write_P(PSTR("RuneScape\n"), false);
            break;
        case _MSE:
            oled_write_P(PSTR("Mouse\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined\n"), false);
    }

    if (cg_toggle_enabled) { oled_write_P(PSTR("Mac mode\n"), false); }
    else { oled_write_P(PSTR("\n"), false); }
}

bool oled_task_user(void) {
    render_status();
    render_cat_dance();

    return true;
};

// RGB Lights
const rgblight_segment_t PROGMEM my_layer0_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 65, HSV_RED}
);
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 65, HSV_ORANGE}
);
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 65, 213, 255, 64}
);
const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 65, HSV_BLUE}
);
const rgblight_segment_t PROGMEM my_layer4_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 65, HSV_PURPLE}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_layer0_layer,
    my_layer1_layer,
    my_layer2_layer,
    my_layer3_layer,
    my_layer4_layer
);

// Pointing device
void pointing_device_init_user(void) {
    set_auto_mouse_layer(_MSE); // only required if AUTO_MOUSE_DEFAULT_LAYER is not set to index of <mouse_layer>
    set_auto_mouse_enable(true);         // always required before the auto mouse feature will work
}

// Main functions
void keyboard_post_init_user(void) {
    is_caps_lock_on = false;
    rgblight_layers = my_rgb_layers;
}

// Custom keycode processing
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_CAPS_LOCK:
            if (record->event.pressed) {
                if (is_caps_lock_on) {
                    is_caps_lock_on = false;
                } else {
                    is_caps_lock_on = true;
                }
            }
            break;

        case LOWER:
            if (record->event.pressed) {
                layer_on(_LWR);
                update_tri_layer(_LWR, _RSE, _ADJ);
            } else {
                layer_off(_LWR);
                update_tri_layer(_LWR, _RSE, _ADJ);
            }
            break;

        case RAISE:
            if (record->event.pressed) {
                layer_on(_RSE);
                update_tri_layer(_LWR, _RSE, _ADJ);
            } else {
                layer_off(_RSE);
                update_tri_layer(_LWR, _RSE, _ADJ);
            }
            break;

        case ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJ);
            } else {
                layer_off(_ADJ);
            }
            break;

        case KC_IDLE:
            if (record->event.pressed) {
                if (idle_enabled == true) {
                    idle_enabled = false;
                    oled_clear();
                } else {
                    idle_enabled = true;
                };
            };
            break;

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
    rgblight_set_layer_state(0, layer_state_cmp(state, _CLM));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, _LWR));
    rgblight_set_layer_state(2, layer_state_cmp(state, _RSE));
    rgblight_set_layer_state(3, layer_state_cmp(state, _ADJ));
    rgblight_set_layer_state(4, layer_state_cmp(state, _MSE));
    return state;
}

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
