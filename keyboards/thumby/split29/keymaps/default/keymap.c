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
 *        | LCTL | LALT | LGUI |SPACE |  ESC  | ENC0 |  | ENC1 | ENTER |SPACE | BSPC | "'   | \|   |
 *        |      |      |      |      |       |      |  |      |       |      |      |      |      |
 *        `------------------------------------------'  `------------------------------------------'
 */

    [_DEFAULT] = LAYOUT(
        // Left Half                                        // Right Half
        KC_GRV,  KC_1,    KC_2,    KC_3,   KC_4,   KC_5,    KC_6,   KC_7,   KC_8,    KC_9,    KC_0,     KC_MINS,
        KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,   KC_T,    KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,     KC_EQL,
        KC_LSFT, KC_A,    KC_S,    KC_D,   KC_F,   KC_G,    KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN,  KC_LBRC,
        KC_LCTL, KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,    KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH,  KC_RBRC,
        KC_CAPS, KC_LALT, KC_LGUI, KC_SPC, KC_ESC, KC_ENC0, KC_ENC1, KC_ENT, KC_SPC,  KC_BSPC, KC_QUOT,  KC_BSLS
    ),
/*
 * MEDIA
 * ,-----------------------------------------.                 ,-----------------------------------------.
 * |  F1  |   F2 |  F3  |  F4  |  F5  |  F6  |                 |  F7  |  F8  |  F9  |  F10 | F11  | F12  |
 * |------+------+------+------+------+------|                 |------+------+------+------+------+------|
 * | VOL+ | TRK +|      |      |      |      |                 |      |      |      |      |      | BR+  |
 * |------+------+------+------+------+------|                 |------+------+------+------+------+------|
 * | VOL- | TRK- |      |      |      |      |                 | LEFT | DOWN |  UP  | RIGHT|      | BR-  |
 * |------+------+------+------+------+------|                 |------+------+------+------+------+------|
 * | MUTE | P/P  |      |      |      |      |                 |      |      |      |      |      |      |
 * `-----------------------------------------*---------.  ,------*-------------------------------------------.
 *        |      | LGUI | LALT |SPACE |  ESC  | MUTE   |  | ENC1 | ENTER |       |      |      |      |      |
 *        |      |      |      |      |       | VOL +- |  |      |       |       |      |      |      |      |
 *        `--------------------------------------------'  `--------------------------------------------------'
 */
    [_MEDIA] = LAYOUT(
        // Left Half                                                      // Right Half
        KC_F1,        KC_F2,        KC_F3,   KC_F4, KC_F5,  KC_F6,        KC_F7,   KC_F8,   KC_F9, KC_F10,   KC_F11,             KC_F12,
        KC_XF86_PLAY, KC_XF86_PREV, KC_NO,   KC_NO, KC_NO,  KC_NO,        KC_NO,   KC_NO,   KC_NO, KC_NO,    KC_XF86_KB_BR_UP,   KC_XF86_MON_BR_UP,
        KC_XF86_STOP, KC_XF86_NEXT, KC_NO,   KC_NO, KC_NO,  KC_NO,        KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_XF86_KB_BR_DOWN, KC_XF86_MON_BR_DOWN,
        KC_NO,        KC_NO,        KC_NO,   KC_NO, KC_NO,  KC_NO,        KC_NO,   KC_NO,   KC_NO, KC_NO,    KC_NO,              KC_NO,
        KC_NO,        KC_LALT,      KC_LGUI, KC_NO, KC_ESC, KC_XF86_MUTE, KC_ENC1, KC_ENT,  KC_NO, KC_NO,    KC_NO,              KC_NO
    ),
    [_MAGIC] = LAYOUT(
        // Left Half                                        // Right Half
        KC_GRV,  KC_1,    KC_2,    KC_3,   KC_4,   KC_5,    KC_6,    KC_7,   KC_8,    KC_9,    KC_0,     KC_MINS,
        KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,   KC_T,    KC_Y,    KC_U,   KC_I,    KC_O,    KC_P,     KC_EQL,
        KC_LSFT, KC_A,    KC_S,    KC_D,   KC_F,   KC_G,    KC_H,    KC_J,   KC_K,    KC_L,    KC_SCLN,  KC_LBRC,
        KC_LCTL, KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,    KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_SLSH,  KC_RBRC,
        KC_CAPS, KC_LALT, KC_LGUI, KC_SPC, KC_ESC, KC_ENC0, KC_ENC1, KC_ENT, KC_SPC,  KC_BSPC, KC_QUOT,  KC_BSLS
    )
};
