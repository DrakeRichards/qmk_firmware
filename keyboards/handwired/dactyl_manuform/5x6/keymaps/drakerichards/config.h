/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

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


#pragma once


#define USE_SERIAL

#define MASTER_LEFT

#undef RGBLED_NUM
#undef RGB_DI_PIN
#define RGBLIGHT_SPLIT
#define RGBLED_SPLIT { 22, 22 }
#define RGBLED_NUM 44
#define RGB_DI_PIN D1
#define RGBLIGHT_LIMIT_VAL 200

#undef RGBLIGHT_ANIMATIONS
#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_KNIGHT
#define RGBLIGHT_EFFECT_SNAKE
#define RGBLIGHT_SLEEP

#define RGBLIGHT_EFFECT_KNIGHT_LED_NUM 44

#define PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_TERM 200

#ifdef DEBOUNCE
#undef DEBOUNCE
#endif
#define DEBOUNCE 10

#define ENCODERS_PAD_A { F4 }
#define ENCODERS_PAD_B { F5 }

#define TAPPING_TOGGLE 2

#define LCPO_KEYS KC_LCTL, KC_TRNS, KC_TAB
#define LAPO_KEYS KC_LALT, KC_LSFT, KC_TAB

// #define MASTER_RIGHT
//#define EE_HANDS
// Rows are doubled-up
