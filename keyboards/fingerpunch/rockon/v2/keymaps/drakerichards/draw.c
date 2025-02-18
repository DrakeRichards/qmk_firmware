#include <qp.h>
#include <draw.h>

int16_t draw_text_centered(const char *text, painter_font_handle_t font, int16_t y) {
    const int16_t display_width = qp_get_width(display);
    const int16_t text_width = qp_textwidth(font, text);
    const int16_t x = (display_width - text_width) / 2;
    return qp_drawtext(display, x, y, font, text);
}

int16_t get_line_number_y(const painter_font_handle_t font, int16_t line_number) {
    return line_number * font->line_height;
}

int16_t draw_text_centered_on_line(const char *text, painter_font_handle_t font, int16_t line_number) {
    return draw_text_centered(text, font, get_line_number_y(font, line_number));
}

int16_t draw_text_left_on_line(const char *text, painter_font_handle_t font, int16_t line_number) {
    const int16_t y = get_line_number_y(font, line_number);
    return qp_drawtext(display, 0, y, font, text);
}

int16_t draw_text_right_on_line(const char *text, painter_font_handle_t font, int16_t line_number) {
    const int16_t display_width = qp_get_width(display);
    const int16_t text_width = qp_textwidth(font, text);
    const int16_t y = get_line_number_y(font, line_number);
    return qp_drawtext(display, display_width - text_width, y, font, text);
}

void layer_display_draw_left_side_text(const layer_display *self, painter_device_t display, painter_font_handle_t font) {
    for (int line = 1; line < 4; line++) {
        draw_text_left_on_line(self->left_text[line-1], font, line);
    }
};

void layer_display_draw_right_side_text(const layer_display *self, painter_device_t display, painter_font_handle_t font) {
    for (int line = 1; line < 4; line++) {
        draw_text_right_on_line(self->right_text[line-1], font, line);
    }
};

void layer_display_draw(const layer_display *self, painter_device_t display, painter_font_handle_t font) {
    draw_text_centered_on_line(self->display_name, font, 0);
    layer_display_draw_left_side_text(self, display, font);
    draw_text_right_on_line(self->right_text[0], font, 1);
    draw_text_right_on_line(self->right_text[1], font, 2);
    draw_text_right_on_line(self->right_text[2], font, 3);
    return;
};
