// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    _QWERTY,
    _QWERTZ
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

    [BASE] = LAYOUT_default(
        // Left Half                                        // Right Half
        KC_GRV,  KC_1,    KC_2,    KC_3,   KC_4,   KC_5,    KC_6,   KC_7,   KC_8,    KC_9,    KC_0,     KC_MINS,
        KC_TAB,  KC_Q,    KC_W,    KC_R,   KC_E,   KC_T,    KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,     KC_EQL,
        KC_CAPS, KC_A,    KC_S,    KC_D,   KC_F,   KC_G,    KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN,  KC_LEFT_BRACKET,
        KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,    KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLASH, KC_RIGHT_BRACKET,
        KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_ESC, KC_MUTE, KC_DEL, KC_ENT, KC_SPC,  KC_BSPC, KC_QUOTE, KC_NONUS_BACKSLASH,
    ),
};
