#include "quantum.h"

#include "split29.h"


/*#ifdef RGB_MATRIX_ENABLE*/

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

/*#endif*/

/*#ifdef ENCODER_ENABLE*/

bool oled_render_status(void);

// The right hand encoder will be used for RGB settings
typedef struct {
    uint8_t func;
    uint8_t num_funcs;
    bool state_changed;
} encoder_t;

enum ENCODER_FUNCTIONS_1 {
    ENC_FUNC_OLED_BRIGHTNESS,
    ENC_FUNC_RGB_BRIGHTNESS,
    ENC_FUNC_RGB_EFFECT,
    ENC_FUNC_RGB_SPEED,
    ENC_FUNC_RGB_HUE
};

enum ENCODER_FUNCTIONS_0 {
    ENC_FUNC_LAYER_CHANGE,
    ENC_FUNC_VOLUME,
    ENC_FUNC_SCROLL
};

void encoder_inc_func(encoder_t *enc) {
    enc->state_changed = TRUE;
    if (enc->func < enc->num_funcs) {
        enc->func++;
    } else {
        enc->func = 0;
    }
#ifdef CONSOLE_ENABLE
    uprintf("Enc1 function: %d\n", enc->func);
#endif
}

encoder_t enc0 = {0, 2, true};
encoder_t enc1 = {0, 4, true};

void layer_change(bool direction) {
    uint8_t current_layer = get_highest_layer(layer_state);
#ifdef CONSOLE_ENABLE
    uprintf("Current Layer: %d\n", current_layer);
#endif
    if (direction) {
        if (current_layer < (LAYER_COUNT - 1)) {
            layer_move(current_layer + 1);
        } else {
            layer_move(0);
        }
    } else {
        if (current_layer > 0) {
            layer_move(current_layer - 1);
        } else {
            layer_move(LAYER_COUNT - 1);
        }
    }
}

// Used to iniceate sync with the slave
bool oled_brightness_changed = false;

bool encoder_update_kb(uint8_t index, bool clockwise){
     if (!encoder_update_user(index, clockwise)) {
      return false; /* Don't process further events if user function exists and returns false */
    }
    if (index == 0) { /* First encoder */
#ifdef CONSOLE_ENABLE
        static int position = 0;
        if (clockwise) {
            position++;
        } else {
            position--;
        }
        uprintf("Enc0 position: %d\n", position);
#endif
        switch (enc0.func) {
        case ENC_FUNC_LAYER_CHANGE:
            layer_change(clockwise);
            break;
        case ENC_FUNC_VOLUME:
            if (clockwise) {
                tap_code(KC_AUDIO_VOL_UP);
            } else {
                tap_code(KC_AUDIO_VOL_DOWN);
            }
            break;
        case ENC_FUNC_SCROLL:
            if (clockwise) {
                tap_code(KC_PGUP);
            } else {
                tap_code(KC_PGDN);
            }
            break;
        }
    } else if (index == 1) { /* Second encoder */
#ifdef CONSOLE_ENABLE
        static int position = 0;
        if (clockwise) {
            position++;
        } else {
            position--;
        }
        uprintf("Enc0 position: %d\n", position);
#endif
        switch (enc1.func) {
        case ENC_FUNC_OLED_BRIGHTNESS:
            if (clockwise) {
                oled_set_brightness(oled_get_brightness() - 5);
            } else {
                oled_set_brightness(oled_get_brightness() + 5);
            }
            oled_brightness_changed = true;
            break;
        case ENC_FUNC_RGB_BRIGHTNESS:
            if (clockwise) {
                rgb_matrix_decrease_val();
            } else {
                rgb_matrix_increase_val();
            }
            break;
        case ENC_FUNC_RGB_EFFECT:
            if (clockwise) {
                rgb_matrix_step_reverse();
            } else {
                rgb_matrix_step();
            }
            break;
        case ENC_FUNC_RGB_SPEED:
            if (clockwise) {
                rgb_matrix_decrease_speed();
            } else {
                rgb_matrix_increase_speed() ;
            }
            break;
        case ENC_FUNC_RGB_HUE:
            if (clockwise) {
                rgb_matrix_decrease_hue();
            } else {
                rgb_matrix_increase_hue();
            }
            break;
        }
    }
    return true;
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif
    switch (keycode) {
        case KC_ENC0:
            if (record->event.pressed) {
                encoder_inc_func(&enc0);
            } else {
            // Do something else when release
            }
            break;
        case KC_ENC1:
            if (record->event.pressed) {
                encoder_inc_func(&enc1);
            } else {
                // Do something else when release
            }
            break;
        default:
            return true; // Process all other keycodes normally
            break;
    }
    return false;
}

/*#endif*/

/*#ifdef OLED_ENABLE*/
static void oled_render_logo(void) {
    static const char PROGMEM pacman_ghost[] = {
        0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x3F, 0x1F, 0x0F, 0x07, 0x07, 0x03, 0x03, 0x01, 0x01, 0x01, 0x01,
        0x01, 0x01, 0x01, 0x01, 0x03, 0x03, 0x07, 0x07, 0x0F, 0x1F, 0x3F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0x1F, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0xFC, 0xFC, 0x8C, 0x84, 0x88,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0xFC, 0xFC, 0x8C, 0x84, 0x88, 0x00, 0x01, 0x1F, 0xFF, 0xFF,
        0xFF, 0xFF, 0x24, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF,
        0xFF, 0xFF, 0xE0, 0x80, 0x80, 0xC0, 0xE0, 0xF0, 0xF0, 0xE0, 0xC0, 0x80, 0x80, 0xC0, 0xE0, 0xF0,
        0xF0, 0xE0, 0xC0, 0x80, 0x80, 0x80, 0xC0, 0xF0, 0xF0, 0xE0, 0xC0, 0x80, 0x80, 0xE0, 0xFF, 0xFF
    };

    static const char PROGMEM pacman_ghost_inv[] = {
        0x00, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xE0, 0xF0, 0xF8, 0xF8, 0xFC, 0xFC, 0xFE, 0xFE, 0xFE, 0xFE,
        0xFE, 0xFE, 0xFE, 0xFE, 0xFC, 0xFC, 0xF8, 0xF8, 0xF0, 0xE0, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0xE0, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x87, 0x03, 0x03, 0x73, 0x7B, 0x77,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x87, 0x03, 0x03, 0x73, 0x7B, 0x77, 0xFF, 0xFE, 0xE0, 0x00, 0x00,
        0x00, 0x00, 0xDB, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFE, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00,
        0x00, 0x00, 0x1F, 0x7F, 0x7F, 0x3F, 0x1F, 0x0F, 0x0F, 0x1F, 0x3F, 0x7F, 0x7F, 0x3F, 0x1F, 0x0F,
        0x0F, 0x1F, 0x3F, 0x7F, 0x7F, 0x7F, 0x3F, 0x0F, 0x0F, 0x1F, 0x3F, 0x7F, 0x7F, 0x1F, 0x00, 0x00
    };
    if (is_keyboard_left()) {
        oled_write_raw_P(pacman_ghost_inv, sizeof(pacman_ghost_inv));
    } else {
        oled_write_raw_P(pacman_ghost, sizeof(pacman_ghost));
    }
}

void oled_render_layer_status(void) {
    switch (get_highest_layer(layer_state)) {
        case _DEFAULT:
            oled_write_P(PSTR("DFLT\n"), false);
            break;
        case _MEDIA:
            oled_write_P(PSTR("MEDIA\n"), false);
            break;
        case _MAGIC:
            oled_write_P(PSTR("MAGIC\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }
}

void oled_render_indicator_status(void) {
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM\n") : PSTR("\n"), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP\n") : PSTR("\n"), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR\n") : PSTR("\n"), false);
}

void oled_render_enc_left_status(void) {
#ifdef CONSOLE_ENABLE
#endif
    oled_write_P(PSTR("ENC\n"), false);
    switch (enc0.func) {
    case ENC_FUNC_LAYER_CHANGE:
        oled_write_P(PSTR("LAYER\n"), false);
        break;
    case ENC_FUNC_VOLUME:
        oled_write_P(PSTR("VOL.\n"), false);
        break;
    case ENC_FUNC_SCROLL:
        oled_write_P(PSTR("SCROL\n"), false);
        break;
    }
}

void oled_render_enc_right_status(void) {
    oled_write_P(PSTR("ENC\n"), false);
    char buff[5];
    switch (enc1.func) {
    case ENC_FUNC_OLED_BRIGHTNESS:
        oled_write_P(PSTR("OLED\n"), false);
        oled_write_P(PSTR("Bright\n"), false);
        sprintf(buff, "%d\n", oled_get_brightness());
        oled_write_ln((const char*) buff, false);
        break;
    case ENC_FUNC_RGB_BRIGHTNESS:
        oled_write_P(PSTR("RGB\n"), false);
        oled_write_P(PSTR("Bright\n"), false);
        sprintf(buff, "%d\n", rgb_matrix_get_val());
        oled_write_ln((const char*) buff, false);
        break;
    case ENC_FUNC_RGB_EFFECT:
        oled_write_P(PSTR("RGB\n"), false);
        oled_write_P(PSTR("Effect\n"), false);
        sprintf(buff, "%d\n", rgb_matrix_get_mode());
        oled_write_ln((const char*) buff, false);
        break;
    case ENC_FUNC_RGB_SPEED:
        oled_write_P(PSTR("RGB\n"), false);
        oled_write_P(PSTR("Speed\n"), false);
        sprintf(buff, "%d\n", rgb_matrix_get_speed());
        oled_write_ln((const char*) buff, false);
        break;
    case ENC_FUNC_RGB_HUE:
        oled_write_P(PSTR("RGB\n"), false);
        oled_write_P(PSTR("Hue.\n"), false);
        sprintf(buff, "%d\n", rgb_matrix_get_hue());
        oled_write_ln((const char*) buff, false);
        break;
    }
}

bool oled_render_status(void) {
    /*if (is_keyboard_master()) {*/
    if (is_keyboard_left()) {
        oled_set_cursor(32, 0);
        oled_render_layer_status();
        oled_render_indicator_status();
        oled_render_enc_left_status();
    } else {
        oled_set_cursor(32, 0);
        oled_render_enc_right_status();
    }
    return false;
}

// This is called from oled_init() in drivers/oled/oled_driver.c
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

// Wweak override in drivers/oled/oled_driver.c
bool oled_task_kb(void) {
    oled_render_logo();
    oled_render_status();
    // Default keyboard drawing code
    return false;
}
/*#endif*/

#include "transaction_id_define.h"
#include "transactions.h"

typedef struct {
    uint8_t data;
} master_to_slave_t;

typedef master_to_slave_t slave_to_master_t ;

void sync_slave_encoder_state(uint8_t in_buflen, const void* in_data, uint8_t out_buflen, void* out_data) {
    const master_to_slave_t *m2s = (const master_to_slave_t*)in_data;
    /*slave_to_master_t *s2m = (slave_to_master_t*)out_data;*/
    /*s2m->data = m2s->data; // whatever comes in, can be sent back*/
    if (is_keyboard_left()) {
        enc0.func = m2s->data;
    } else {
        enc1.func = m2s->data;
    }
}

void sync_slave_oled_brightness(uint8_t in_buflen, const void* in_data, uint8_t out_buflen, void* out_data) {
    const master_to_slave_t *m2s = (const master_to_slave_t*)in_data;
    /*slave_to_master_t *s2m = (slave_to_master_t*)out_data;*/
    /*s2m->data = m2s->data; // whatever comes in, can be sent back*/
    oled_set_brightness(m2s->data);
}

void housekeeping_task_kb(void) {
    // Only the master side seems to handly the encoder states correclty
    // To display on the correctly on the slave side, data needs to be transmitted
    if (is_keyboard_master()) {
        static uint32_t last_enc_sync = 0;
        if (timer_elapsed32(last_enc_sync) > 100) {
            encoder_t *enc_sync;
            if (is_keyboard_left()) {
                enc_sync = &enc1;
            } else {
                enc_sync = &enc0;
            }
            // Send to slave if states changed
            if (enc_sync->state_changed) {
                master_to_slave_t m2s = {enc_sync->func};
                slave_to_master_t s2m = {0};
                if(transaction_rpc_exec(KEYBOARD_SYNC_A, sizeof(m2s), &m2s, sizeof(s2m), &s2m)) {
                    enc_sync->state_changed = false;
                    last_enc_sync = timer_read32();
                } else {
#ifdef CONSOLE_ENABLE
                    uprintf("Failed syncting encoder state with slave.\n");
#endif
                }
            }
        }
        static uint32_t last_oled_sync = 0;
        if (timer_elapsed32(last_oled_sync) > 500) {
            if (oled_brightness_changed) {
                master_to_slave_t m2s = {oled_get_brightness()};
                slave_to_master_t s2m = {0};
                if(transaction_rpc_exec(KEYBOARD_SYNC_B, sizeof(m2s), &m2s, sizeof(s2m), &s2m)) {
                    oled_brightness_changed = false;
                    last_oled_sync = timer_read32();
                } else {
#ifdef CONSOLE_ENABLE
                    uprintf("Failed syncting oled brightness with slave.\n");
#endif
                }
            }
        }
    }
}

void keyboard_post_init_kb() {
    transaction_register_rpc(KEYBOARD_SYNC_A, sync_slave_encoder_state);
    transaction_register_rpc(KEYBOARD_SYNC_B, sync_slave_oled_brightness);
    gpio_set_pin_output(GPIO_ENC_C);
    gpio_write_pin_low(GPIO_ENC_C);
    gpio_set_pin_input(GPIO_LEFT_RIGHT);
}
