
enum layers {
    _DEFAULT,
    _MEDIA,
    _MAGIC
};

#define LAYER_COUNT 3

// Define the keycode, `QK_USER` avoids collisions with existing keycodes
enum my_keycodes {
  KC_ENC0 = SAFE_RANGE,
  KC_ENC1
};

#define GPIO_ENC_C C14

#define GPIO_LEFT_RIGHT A0

