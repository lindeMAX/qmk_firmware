#include "quantum.h"

#include "split29.h"

#ifdef OLED_ENABLE
static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {0x00};

    oled_write_P(qmk_logo, false);
}

bool render_status(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer:\n"), false);
    switch (get_highest_layer(layer_state)) {
        case BASE:
            oled_write_P(PSTR("BASE\n"), false);
            break;
        case MOD:
            oled_write_P(PSTR("MOD\n"), false);
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
