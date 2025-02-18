#include <qp.h>

typedef char side_display_text[5];

// Side-display text is stored in a vector of 3 strings with max length of 4 characters
typedef side_display_text side_display_text_rows[3];

typedef struct {
    // The name of the layer to display on the OLED screen
    const char *display_name;
    // The number of the layer
    const uint8_t layer_number;
    // The text to display on the left side of the OLED screen
    const side_display_text_rows left_text;
    // The text to display on the right side of the OLED screen
    const side_display_text_rows right_text;
    // The RGB segments for the layer
    const rgblight_segment_t layer_colors[2];
} layer_display;

static painter_device_t display;
static painter_font_handle_t my_font;
static painter_image_handle_t my_image;
static deferred_token my_anim;
