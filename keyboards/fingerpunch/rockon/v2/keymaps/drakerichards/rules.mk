ENCODER_MAP_ENABLE = yes
POINTING_DEVICE_ENABLE := yes
POINTING_DEVICE_DRIVER := cirque_pinnacle_i2c
OPT_DEFS += -DCIRQUE_ENABLE
OLED_ENABLE = yes
CONVERT_TO = stemcell
QUANTUM_PAINTER_ENABLE = yes
QUANTUM_PAINTER_DRIVERS += sh1106_i2c
SRC += ubuntu.qff.c
SRC += felyne-dance.qgf.c
DEFERRED_EXEC_ENABLE = yes
