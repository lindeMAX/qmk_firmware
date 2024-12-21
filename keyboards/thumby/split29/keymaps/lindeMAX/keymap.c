// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                 ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                 |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                 |------+------+------+------+------+------|
 * | TAB  |   Q  |   W  |   E  |   R  |   T  |                 |   Y  |   U  |   I  |   O  |   P  |  =+  |
 * |------+------+------+------+------+------|                 |------+------+------+------+------+------|
 * | CAPS |   A  |   S  |   D  |   F  |   G  |                 |   H  |   J  |   K  |   L  |   ;  |  [{  |
 * |------+------+------+------+------+------|                 |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |                 |   N  |   M  |   ,  |   .  |   /  |  }]  |
 * `-----------------------------------------*-------.  ,------*-----------------------------------------'
 *        | LCTL | LGUI | LALT |SPACE |  ESC  | Mute |  | DEL  | ENTER |SPACE | BSPC | "'   | \|   |
 *        |      |      |      |      |       |      |  |      |       |      |      |      |      |
 *        `------------------------------------------'  `------------------------------------------'
 */

    [_QWERTY] = LAYOUT(
        // Left Half                                        // Right Half
        KC_GRV,  KC_1,    KC_2,    KC_3,   KC_4,   KC_5,    KC_6,   KC_7,   KC_8,    KC_9,    KC_0,     KC_MINS,
        KC_TAB,  KC_Q,    KC_W,    KC_R,   KC_E,   KC_T,    KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,     KC_EQL,
        KC_CAPS, KC_A,    KC_S,    KC_D,   KC_F,   KC_G,    KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN,  KC_LBRC,
        KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,    KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH,  KC_RBRC,
        KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_ESC, KC_MUTE, KC_DEL, KC_ENT, KC_SPC,  KC_BSPC, KC_QUOT,  KC_BSLS
    ),
};
