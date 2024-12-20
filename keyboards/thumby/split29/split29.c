#include "quantum.h"

#include "split29.h"

/*void matrix_init_kb(void) {}*/
/*void matrix_scan_kb(void) {}*/
/*bool process_record_kb(uint16_t keycode, keyrecord_t *record) {*/
/*    return false;*/
/*}*/
/*bool led_update_kb(led_t led_state) {*/
/*    return false;*/
/*}*/

#ifdef OLED_ENABLE
static void render_logo(void) {
    /*static const char PROGMEM pacman_ghost[] = {*/
    /*    0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x3F, 0x1F, 0x0F, 0x07, 0x07, 0x03, 0x03, 0x01, 0x01, 0x01, 0x01,*/
    /*    0x01, 0x01, 0x01, 0x01, 0x03, 0x03, 0x07, 0x07, 0x0F, 0x1F, 0x3F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF,*/
    /*    0xFF, 0xFF, 0x1F, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0xFC, 0xFC, 0x8C, 0x84, 0x88,*/
    /*    0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0xFC, 0xFC, 0x8C, 0x84, 0x88, 0x00, 0x01, 0x1F, 0xFF, 0xFF,*/
    /*    0xFF, 0xFF, 0x24, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00,*/
    /*    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF,*/
    /*    0xFF, 0xFF, 0xE0, 0x80, 0x80, 0xC0, 0xE0, 0xF0, 0xF0, 0xE0, 0xC0, 0x80, 0x80, 0xC0, 0xE0, 0xF0,*/
    /*    0xF0, 0xE0, 0xC0, 0x80, 0x80, 0x80, 0xC0, 0xF0, 0xF0, 0xE0, 0xC0, 0x80, 0x80, 0xE0, 0xFF, 0xFF*/
    /*};*/
    /*oled_write_raw_P(pacman_ghost, sizeof(pacman_ghost));*/

    static const char PROGMEM pacman_ghost_inv[] = {0x00, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xE0, 0xF0, 0xF8, 0xF8, 0xFC, 0xFC, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFC, 0xFC, 0xF8, 0xF8, 0xF0, 0xE0, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x87, 0x03, 0x03, 0x73, 0x7B, 0x77, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x87, 0x03, 0x03, 0x73, 0x7B, 0x77, 0xFF, 0xFE, 0xE0, 0x00, 0x00, 0x00, 0x00, 0xDB, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x7F, 0x7F, 0x3F, 0x1F, 0x0F, 0x0F, 0x1F, 0x3F, 0x7F, 0x7F, 0x3F, 0x1F, 0x0F, 0x0F, 0x1F, 0x3F, 0x7F, 0x7F, 0x7F, 0x3F, 0x0F, 0x0F, 0x1F, 0x3F, 0x7F, 0x7F, 0x1F, 0x00, 0x00};
    oled_write_raw_P(pacman_ghost_inv, sizeof(pacman_ghost_inv));
}

bool render_status(void) {
    render_logo();
    // Host Keyboard Layer Status
    oled_set_cursor(32, 0);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("QWERTY\n"), false);
            break;
        case _QWERTZ:
            oled_write_P(PSTR("QWERTZ\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);

    return false;
}

// This is called from oled_init() in drivers/oled/oled_driver.c
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

// Wweak override in drivers/oled/oled_driver.c
bool oled_task_user(void) {
    render_logo();
    render_status();

    // Default keyboard drawing code
    return false;
}
#endif

#ifdef ENCODER_ENABLE

#endif

#ifdef LEDS
led_config_t g_led_config = { {
  // Key Matrix to LED Index
  {   5, NO_LED, NO_LED,   0 },
  { NO_LED, NO_LED, NO_LED, NO_LED },
  {   4, NO_LED, NO_LED,   1 },
  {   3, NO_LED, NO_LED,   2 }
}, {
  // LED Index to Physical Position
  { 188,  16 }, { 187,  48 }, { 149,  64 }, { 112,  64 }, {  37,  48 }, {  38,  16 }
}, {
  // LED Index to Flag
  1, 4, 4, 4, 4, 1
} };

const is31fl3743a_led_t PROGMEM g_is31fl3743a_leds[IS31FL3743A_LED_COUNT] = {
/* Driver
 *   |  R         G         B */
    {0, SW1_CS1,  SW1_CS2,  SW1_CS3},
    // etc...
};

#endif
