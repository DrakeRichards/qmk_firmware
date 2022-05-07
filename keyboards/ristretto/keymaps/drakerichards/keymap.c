/* Copyright 2021 Brandon Lewis
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
#include "oled.c"

enum layers {
	_BASE,
    _QWER,
	_RAISE,
	_LOWER,
	_FUNC,
    _SYMB,
	_ADJUST
};

enum CUSTOM_KEYCODES {
    KC_IDLE = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_BASE] = LAYOUT(
		KC_TAB  			, KC_Q    	, KC_W    				, KC_F    			, KC_P    	, KC_G                              , KC_J      , KC_L    			, KC_U      , KC_Y      , KC_SCLN   , KC_MINUS ,
		LT(_RAISE, KC_ESC)  , KC_A    	, KC_R    				, KC_S    			, KC_T    	, KC_D                              , KC_H      , KC_N    			, KC_E      , KC_I      , KC_O      , KC_QUOT ,
		KC_LALT 			, KC_Z    	, KC_X    				, KC_C    			, KC_V    	, KC_B      			            , KC_K      , KC_M    			, KC_COMM   , KC_DOT    , KC_SLSH   , KC_BSLASH  ,
	    LT(_SYMB, KC_ENTER) , KC_LGUI 	, OSL(_FUNC)	        , MO(_LOWER)        , KC_LCTL   , LSFT_T(KC_BSPC)   , OSM(MOD_MEH)  , KC_SPC    , LT(_RAISE, KC_DEL), KC_LEFT   ,KC_UP 	    , KC_DOWN   , KC_RIGHT
	),
	[_QWER] = LAYOUT(
		KC_TAB  			, KC_Q    	, KC_W    				, KC_E    			, KC_R    	, KC_T                              , KC_Y      , KC_U    			, KC_I      , KC_O      , KC_P   , KC_MINUS ,
		LT(_RAISE, KC_ESC)  , KC_A    	, KC_S    				, KC_D    			, KC_F    	, KC_G                              , KC_H      , KC_J    			, KC_K      , KC_L      , KC_SCLN      , KC_QUOT ,
		KC_LALT 			, KC_Z    	, KC_X    				, KC_C    			, KC_V    	, KC_B      			            , KC_N      , KC_M    			, KC_COMM   , KC_DOT    , KC_SLSH   , KC_BSLASH  ,
	    LT(_SYMB, KC_ENTER) , KC_LGUI 	, KC_BSPC	        , MO(_LOWER)        , KC_LCTL   , KC_LSFT   , KC_SPC  , KC_SPC    , LT(_RAISE, KC_DEL), KC_LEFT   ,KC_UP 	    , KC_DOWN   , KC_RIGHT
	),
    [_LOWER] = LAYOUT(
		KC_GRV              , KC_MINUS  , KC_7                  , KC_8              , KC_9      , KC_LCBR	            , KC_RCBR   , KC_NO             , KC_NO     , KC_NO     , KC_NO     , KC_PLUS  ,
		KC_COLN	            , KC_0      , KC_4	                , KC_5              , KC_6      , KC_LPRN               , KC_RPRN   , KC_NO             , KC_NO     , KC_NO     , KC_NO     , KC_EQL   ,
		KC_TRNS             , KC_DOT    , KC_1                  , KC_2              , KC_3      , KC_LBRC               , KC_RBRC   , KC_NO             , KC_NO     , KC_NO     , KC_NO     , KC_NO   ,
		KC_TRNS             , KC_TRNS   , KC_TRNS               , KC_TRNS           , KC_TRNS   , KC_TRNS   , KC_IDLE   , KC_NO     , MO(_ADJUST)       ,KC_HOME    ,KC_PGUP    , KC_PGDN   , KC_END
	),
	[_RAISE] = LAYOUT(
		KC_TRNS	, KC_PGUP	  , KC_HOME    , KC_UP    , KC_END	, KC_NO              , KC_NO    , KC_7    , KC_8    , KC_9    , KC_NO    , KC_NO  ,
		KC_TRNS	, KC_PGDN , KC_LEFT  , KC_DOWN , KC_RIGHT , KC_NO           , KC_NO   , KC_4 , KC_5 , KC_6   , KC_0 , KC_NO ,
		KC_TRNS	, KC_NO	  , KC_NO   , KC_NO   , KC_NO   , KC_NO             , KC_NO   , KC_1   , KC_2   , KC_3   , KC_NO   , KC_NO   ,
		KC_TRNS , KC_TRNS , KC_TRNS ,KC_NO,KC_NO , KC_NO   , TG(_QWER) , KC_MUTE   , KC_TRNS , LCTL_T(LGUI_T(KC_LEFT))   , KC_VOLU , KC_VOLD , LCTL_T(LGUI_T(KC_RIGHT))
	),
	[_FUNC] = LAYOUT(
		KC_NO	, KC_NO	  , KC_F7    , KC_F8    , KC_F9	, KC_F12              , KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO  ,
		KC_NO	, KC_NO , KC_F4  , KC_F5 , KC_F6 , KC_F11           , KC_NO   , KC_NO , KC_NO , KC_NO   , KC_NO , KC_NO ,
		KC_NO	, KC_NO	  , KC_F1   , KC_F2   , KC_F3   , KC_F10             , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   ,
		KC_NO , KC_NO , KC_TRNS ,KC_NO,KC_NO , KC_NO   , KC_NO , KC_NO   , KC_NO , KC_NO   , KC_NO , KC_NO , KC_NO
	),
    [_SYMB] = LAYOUT(
		KC_TRNS             , KC_TRNS             , KC_AMPR             , KC_ASTR                 , KC_TILDE             , KC_NO	                            , KC_NO         , KC_NO         , KC_NO         , KC_NO         , KC_NO         , KC_NO  ,
		KC_TRNS	            , KC_TRNS	            , KC_DLR             , KC_PERC	                , KC_CIRC             , KC_NO                           , KC_NO         , KC_NO         , KC_NO         , KC_NO         , KC_NO         , KC_NO   ,
		KC_TRNS             , KC_TRNS             , KC_EXLM             , KC_AT                 , KC_HASH             , KC_NO                           , KC_NO         , KC_NO         , KC_NO         , KC_NO         , KC_NO         , KC_NO   ,
		KC_TRNS             , KC_TRNS           , KC_NO                 , KC_TRNS             , KC_NO         , KC_NO       , KC_NO               , KC_NO         , KC_NO         ,KC_NO          , KC_NO         , KC_NO         , KC_NO
	),
	[_ADJUST] = LAYOUT(
		XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX           , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
		XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_CAPS           , KC_NLCK , KC_SLCK , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
		XXXXXXX , XXXXXXX , TG(_BASE) , XXXXXXX , XXXXXXX , XXXXXXX           , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
		KC_TRNS , KC_TRNS , KC_TRNS , XXXXXXX , XXXXXXX , XXXXXXX , RESET , XXXXXXX , XXXXXXX , XXXXXXX , KC_TRNS , KC_TRNS , KC_TRNS
	)
/*  [_BLANK] = LAYOUT(
		KC_TRNS             , KC_NO             , KC_NO                 , KC_NO             , KC_NO         , KC_NO	                            , KC_NO         , KC_NO         , KC_NO         , KC_NO         , KC_NO         , KC_NO  ,
		KC_TRNS	            , KC_NO             , KC_NO	                , KC_NO             , KC_NO          , KC_NO                            , KC_NO         , KC_NO         , KC_NO         , KC_NO         , KC_NO         , KC_NO   ,
		KC_TRNS             , KC_NO             , KC_NO                 , KC_NO             , KC_NO         , KC_NO                             , KC_NO         , KC_NO         , KC_NO         , KC_NO         , KC_NO         , KC_NO   ,
		KC_TRNS             , KC_TRNS           , KC_NO                 , KC_NO             , KC_NO         , KC_NO       , KC_NO               , KC_NO         , KC_NO         ,KC_NO          , KC_NO         , KC_NO         , KC_NO
	),*/
};

// OLED and Encoder function is located in the ristretto.c File

bool idle_enabled = false;
const uint16_t timer_max = 1000;
uint16_t idle_timer = timer_max;
uint8_t anim_frame = 0;

bool oled_task_user(void) {
	oled_write_P(PSTR("\n\n"), false);
	oled_write_ln_P(PSTR("LAYER"), false);
	switch (get_highest_layer(layer_state)) {
		case _BASE:
			oled_write_P(PSTR("BASE\n"), false);
			break;
		case _RAISE:
			oled_write_P(PSTR("RAISE\n"), false);
			break;
		case _LOWER:
			oled_write_P(PSTR("LOWER\n"), false);
			break;
		case _ADJUST:
			oled_write_P(PSTR("ADJ\n"), false);
			break;
        case _FUNC:
            oled_write_P(PSTR("FUNC\n"), false);
            break;
        case _SYMB:
            oled_write_P(PSTR("SYMB\n"), false);
            break;
        case _QWER:
            oled_write_P(PSTR("QWER\n"), false);
            break;
	};
    if (idle_enabled == true) {
        --idle_timer;
        if (idle_timer <= 0) {
            idle_timer = timer_max;
            tap_code(KC_F15);
            oled_set_cursor(0,8);
            idle_anim(anim_frame);
            if (anim_frame < 3) {
                ++anim_frame;
                }
            else {
                anim_frame = 0;
            };
        };
    };
    return false;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_IDLE:
            if (record->event.pressed) {
                if (idle_enabled == true) {
                    idle_enabled = false;
                    idle_timer = timer_max;
                    oled_clear();
                } else {
                    idle_enabled = true;
                    idle_timer = timer_max;
                };
            };
            break;
    };
    return true;
};

void matrix_init_user(void) {
};

void matrix_scan_user(void) {
};
