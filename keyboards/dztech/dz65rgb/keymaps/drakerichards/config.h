//Space Cadet for [] on shift
#ifdef LSPO_KEYS
    #undef LSPO_KEYS
#endif

#define LSPO_KEYS KC_LSFT, KC_TRNS, KC_LBRC

#ifdef RSPC_KEYS
    #undef RSPC_KEYS
#endif

#define RSPC_KEYS KC_RSFT, KC_TRNS, KC_RBRC

//Combos
#ifdef COMBO_COUNT
    #undef COMBO_COUNT
#endif

#define COMBO_COUNT 2

//Tapping Term for combos
#ifdef TAPPING_TERM
    #undef TAPPING_TERM
#endif

#define TAPPING_TERM 200
#ifndef PERMISSIVE_HOLD
    #define PERMISSIVE_HOLD
#endif
#ifndef IGNORE_MOD_TAP_INTERRUST
    #define IGNORE_MOD_TAP_INTERRUPT
#endif
