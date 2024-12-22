#include "quantum.h"

#include "split29.h"

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

#ifdef RGB_MATRIX_ENABLE

led_config_t g_led_config = {
    {// Tell the system wich LED represents wich LED
        {0,   1,  2,  3,  4,       5}, {     6,  7,  8,  9, 10, 11},
        {12, 13, 14, 15, 16,      17}, {    18, 19, 20, 21, 22, 23},
        {24, 25, 26, 27, 28,      29}, {    30, 31, 32, 33, 34, 35},
        {36, 37, 38, 39, 40,      41}, {    42, 43, 44, 45, 46, 47},
        {48, 49, 50, 51, 52,  NO_LED}, {NO_LED, 53, 54, 55, 56, 57}
    }, {// LED Index to Physical Position. // Top left key is at {0,0}
        {0, 0},  {20, 0},  {40, 0},  {60, 0},  {80, 0},  {100, 0},  {120, 0},  {140, 0},  {160, 0},  {180, 0},  {200, 0},  {220, 0},
        {0, 20}, {20, 20}, {40, 20}, {60, 20}, {80, 20}, {100, 20}, {120, 20}, {140, 20}, {160, 20}, {180, 20}, {200, 20}, {220, 20},
        {0, 40}, {20, 40}, {40, 40}, {60, 40}, {80, 40}, {100, 40}, {120, 40}, {140, 40}, {160, 40}, {180, 40}, {200, 40}, {220, 40},
        {0, 60}, {20, 60}, {40, 60}, {60, 60}, {80, 60}, {100, 60}, {120, 60}, {140, 60}, {160, 60}, {180, 60}, {200, 60}, {220, 60},
        {0, 80}, {20, 80}, {40, 80}, {60, 80}, {80, 80},                       {140, 80}, {160, 80}, {180, 80}, {200, 80}, {220, 80}
    }, {// LED Index to Flag
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4,       4, 4, 4, 4, 4
        }
    };

const is31fl3743a_led_t PROGMEM g_is31fl3743a_leds[IS31FL3743A_LED_COUNT] = {
    /* Driver
     *   |  R         G         B */
    // First Row
    {0, SW5_CS1, SW5_CS2, SW5_CS3},
    {0, SW3_CS1, SW3_CS2, SW3_CS3},
    {0, SW6_CS1, SW6_CS2, SW6_CS3},
    {0, SW4_CS1, SW4_CS2, SW4_CS3},
    {0, SW2_CS1, SW2_CS2, SW2_CS3},
    {0, SW1_CS1, SW1_CS2, SW1_CS3},
    // Second Row
    {0, SW5_CS4, SW5_CS5, SW5_CS6},
    {0, SW3_CS4, SW3_CS5, SW3_CS6},
    {0, SW6_CS4, SW6_CS5, SW6_CS6},
    {0, SW4_CS4, SW4_CS5, SW4_CS6},
    {0, SW2_CS4, SW2_CS5, SW2_CS6},
    {0, SW1_CS4, SW1_CS5, SW1_CS6},

    {0, SW5_CS7, SW5_CS8, SW5_CS9},
    {0, SW3_CS7, SW3_CS8, SW3_CS9},
    {0, SW6_CS7, SW6_CS8, SW6_CS9},
    {0, SW4_CS7, SW4_CS8, SW4_CS9},
    {0, SW2_CS7, SW2_CS8, SW2_CS9},
    {0, SW1_CS7, SW1_CS8, SW1_CS9},

    {0, SW5_CS13, SW5_CS14, SW5_CS15},
    {0, SW3_CS13, SW3_CS14, SW3_CS15},
    {0, SW6_CS13, SW6_CS14, SW6_CS15},
    {0, SW4_CS13, SW4_CS14, SW4_CS15},
    {0, SW2_CS13, SW2_CS14, SW2_CS15},
    {0, SW1_CS13, SW1_CS14, SW1_CS15},

    {0, SW5_CS10, SW5_CS11, SW5_CS12},
    {0, SW3_CS10, SW3_CS11, SW3_CS12},
    {0, SW6_CS10, SW6_CS11, SW6_CS12},
    {0, SW4_CS10, SW4_CS11, SW4_CS12},
    {0, SW2_CS10, SW2_CS11, SW2_CS12}
};

#endif
