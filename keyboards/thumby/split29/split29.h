enum layers {
    _DEFAULT,
    _MEDIA,
    _MAGIC
};

#define LAYER_COUNT 3

// Define the keycode, `QK_USER` avoids collisions with existing keycodes
enum CUSTOM_KEYCODES {
  KC_ENC0 = SAFE_RANGE,
  KC_ENC1,
};

enum XF86_KEYCODES {
  KC_XF86_MON_BR_UP = 0x1008FF02,
  KC_XF86_MON_BR_DOWN,
  KC_XF86_KB_BR_UP = 0x1008FF05,
  KC_XF86_KB_BR_DOWN,
  KC_XF86_VOL_DOWN = 0x1008FF11,
  KC_XF86_MUTE,
  KC_XF86_VOL_UP,
  KC_XF86_PLAY,
  KC_XF86_STOP,
  KC_XF86_PREV,
  KC_XF86_NEXT,
  KC_XF86_SCROLL_UP = 0x1008FF78,
  KC_XF86_SCROLL_DOWN
};

#define GPIO_ENC_C C14

#define GPIO_LEFT_RIGHT A0

#define is_keyboard_left() gpio_read_pin(GPIO_LEFT_RIGHT)


