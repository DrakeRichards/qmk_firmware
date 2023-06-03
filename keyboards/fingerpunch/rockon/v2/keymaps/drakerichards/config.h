// Tap-hold behavior
#define TAPPING_TERM 200
#define PERMISSIVE_HOLD

// Cirque
#ifdef CIRQUE_ENABLE
#    define CIRQUE_PINNACLE_ADDR 0x2A
#    define POINTING_DEVICE_ROTATION_90
// If using fingerpunch case
// #define POINTING_DEVICE_ROTATION_270
// If using chewiedies case
// #    define CIRQUE_PINNACLE_TAP_ENABLE
#    define POINTING_DEVICE_TASK_THROTTLE_MS 5
#    define I2C1_CLOCK_SPEED 400000
#    define I2C1_DUTY_CYCLE FAST_DUTY_CYCLE_2
#    ifdef CIRQUE_PINNACLE_TAPPING_TERM
#        undef CIRQUE_PINNACLE_TAPPING_TERM
#        define CIRQUE_PINNACLE_TAPPING_TERM 9999
#    endif
#    ifdef CIRQUE_PINNACLE_TOUCH_DEBOUNCE
#        undef CIRQUE_PINNACLE_TOUCH_DEBOUNCE
#        define CIRQUE_PINNACLE_TOUCH_DEBOUNCE 9999
#    endif
#    define POINTING_DEVICE_GESTURES_CURSOR_GLIDE_ENABLE
#    define POINTING_DEVICE_GESTURES_SCROLL_ENABLE
#endif

// Encoder
#ifdef ENCODER_RESOLUTION
#    undef ENCODER_RESOLUTION
#endif
#define ENCODER_RESOLUTION 4

// OLED
#ifdef OLED_ENABLE
#    define OLED_DISPLAY_128X64
#endif

// RGB
#ifdef RGBLIGHT_ENABLE
#    define RGBLIGHT_LAYERS
#    define RGBLIGHT_LAYERS_RETAIN_VAL
#endif
