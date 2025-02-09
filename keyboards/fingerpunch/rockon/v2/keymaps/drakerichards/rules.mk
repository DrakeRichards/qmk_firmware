# Cirque settings
MOUSEKEY_ENABLE := yes  # not required, but enabling for mouse button keys
POINTING_DEVICE_ENABLE := yes
POINTING_DEVICE_DRIVER := cirque_pinnacle_i2c
OPT_DEFS += -DCIRQUE_ENABLE

RGBLIGHT_ENABLE = yes
OLED_ENABLE = yes
ENCODER_ENABLE = yes

# Stemcell settings
CONVERT_TO = stemcell
