// BEGIN PWM driver: uncomment if using STeMcell as it's a better led driver
// #define WS2812_PWM_DRIVER PWMD2  // default: PWMD2
// #define WS2812_PWM_CHANNEL 2  // default: 2
// #define WS2812_PWM_PAL_MODE 2  // Pin "alternate function", see the respective datasheet for the appropriate values for your MCU. default: 2
// #define WS2812_DMA_STREAM STM32_DMA1_STREAM2  // DMA Stream for TIMx_UP, see the respective reference manual for the appropriate values for your MCU.
// #define WS2812_DMA_CHANNEL 2  // DMA Channel for TIMx_UP, see the respective reference manual for the appropriate values for your MCU.
// #define WS2812_DMAMUX_ID STM32_DMAMUX1_TIM2_UP // DMAMUX configuration for TIMx_UP -- only required if your MCU has a DMAMUX peripheral, see the respective reference manual for the appropriate values for your MCU.
// END PWM driver: uncomment if using STeMcell as it's a better led driver

#define I2C1_CLOCK_SPEED 400000
#define I2C1_DUTY_CYCLE FAST_DUTY_CYCLE_2

#ifdef OLED_ENABLE
#    define OLED_DISPLAY_128X64
#endif

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

#define TAPPING_TERM 175
#define PERMISSIVE_HOLD

#ifdef ENCODER_RESOLUTION
#    undef ENCODER_RESOLUTION
#endif
#define ENCODER_RESOLUTION 4
