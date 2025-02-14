
static void render_danceLeft(void) {
    static const char PROGMEM DanceLeft[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x02, 0xB4, 0xC8, 0xB0, 0x90, 0x10, 0x10,
    0x10, 0x10, 0x90, 0xB0, 0xC8, 0xB4, 0x02, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x20, 0x20, 0x20, 0x60, 0x54, 0x54, 0x7F, 0x8F, 0x90, 0x96, 0x96, 0x90, 0xAF, 0xC0,
    0xC0, 0xAF, 0x90, 0x96, 0x96, 0x90, 0x8F, 0x7F, 0x14, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x06, 0x1D, 0xF2, 0x81,
    0x02, 0x01, 0x02, 0x01, 0x07, 0x3E, 0xE6, 0x0C, 0x18, 0x10, 0x10, 0x30, 0x20, 0x20, 0x20, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x60, 0x31, 0x1F,
    0x04, 0x04, 0x04, 0x04, 0x04, 0x7C, 0x47, 0x07, 0x1C, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

    oled_write_raw_P(DanceLeft, sizeof(DanceLeft));

}

static void render_danceRight(void) {
    static const char PROGMEM DanceRight[] = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x02, 0xB4, 0xC8, 0xB0, 0x90, 0x10,
        0x10, 0x10, 0x10, 0x90, 0xB0, 0xC8, 0xB4, 0x02, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x14, 0x14, 0x7F, 0x8F, 0x90, 0x96, 0x96, 0x90, 0xAF,
        0xC0, 0xC0, 0xAF, 0x90, 0x96, 0x96, 0x90, 0x8F, 0x7F, 0x54, 0x54, 0x60, 0x20, 0x20, 0x20, 0x00,
        0x00, 0x00, 0x20, 0x20, 0x20, 0x30, 0x10, 0x10, 0x18, 0x0C, 0xE6, 0x3E, 0x07, 0x01, 0x02, 0x01,
        0x02, 0x81, 0xF2, 0x1D, 0x06, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x1C, 0x07, 0x47, 0x7C, 0x04, 0x04, 0x04, 0x04,
        0x04, 0x1F, 0x31, 0x60, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

    oled_write_raw_P(DanceRight, sizeof(DanceRight));

}

static void render_danceYah(void) {
    static const char PROGMEM DanceYah[] = {
        0x00, 0x00, 0x00, 0x00, 0xF0, 0x00, 0x00, 0x00, 0xFE, 0x82, 0xB4, 0x48, 0x30, 0x10, 0x10, 0x10,
        0x10, 0x10, 0x10, 0x30, 0x48, 0xB4, 0x82, 0xFE, 0x00, 0x00, 0x00, 0xF0, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x3F, 0x40, 0x94, 0x94, 0x7F, 0x80, 0x80, 0x91, 0x8A, 0x84, 0x90, 0xB0,
        0xB0, 0x90, 0x84, 0x8A, 0x91, 0x80, 0x80, 0x7F, 0x94, 0x94, 0x40, 0x3F, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x02, 0x02, 0xFF, 0x02, 0x01, 0x02, 0x01,
        0x02, 0x01, 0x02, 0x01, 0xFF, 0x02, 0x02, 0x01, 0x01, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x7C, 0xC8, 0x08, 0x08,
        0x08, 0x08, 0xC8, 0x7C, 0x07, 0x04, 0x06, 0x02, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

    oled_write_raw_P(DanceYah, sizeof(DanceYah));

};

void idle_anim(uint8_t anim_frame) {
    switch(anim_frame) {
        case 0:
            render_danceRight();
            break;
        case 1:
            render_danceLeft();
            break;
        case 2:
            render_danceRight();
            break;
        case 3:
            render_danceYah();
            break;
    };
};

