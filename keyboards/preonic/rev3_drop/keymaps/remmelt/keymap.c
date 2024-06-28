/* Copyright 2015-2021 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

enum preonic_layers {
  _QWERTY,
  _RAISE,
  _MEDIA,
};

#define WIN_MAX    C(A(KC_ENT))          // Grow window to max size in Rectangle
#define NXTDSPL    G(C(A(KC_RIGHT)))     // Window to next display in Rectangle
#define LFTHLF     C(A(KC_LEFT))         // Left half in Rectangle
#define RGTHLF     C(A(KC_RIGHT))        // Right half in Rectangle
#define LAST2_3    MEH(KC_Q)             // Last 2/3 in Rectangle
#define FND_USG    G(A(KC_F7))           // Find usages in IntelliJ
#define ESC_CTL    MT(MOD_LCTL, KC_ESC)  // hold: L_CTL, tap: ESC
#define BACK       LGUI(KC_LBRC)
#define FORWARD    LGUI(KC_RBRC)
#define RSFT_SL    RSFT_T(KC_BACKSLASH)  // hold: R_SHIFT, tap: KC_BACKSLASH
#define LOCK       G(C(KC_Q))            // Lock screen
#define RESET      QK_BOOTLOADER         // Put the keyboard into bootloader mode for flashinga

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |EscCtl|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shft \|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Media| 1Pwd | Alt  |  GUI | Raise|    Space    |Enter | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_1x2uC( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  ESC_CTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFT_SL, \
  MO(2),   XXXXXXX, KC_LALT, KC_LGUI, MO(1),   KC_SPC,   KC_ENT,  KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |WinMax|  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  =   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |NXTDSP|   [  |   ]  |   {  |   }  |FndUsg|  No  |  No  |  No  |  F11 |  F12 | Del  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |(EscC)|      |      |      |      |      | Left | Down |  Up  |Right |      |Last23|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |(Shft)|      |      |      |Paste |      |      |      |      |      |      |   \  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | (Alt)|(GUI) | (xx) |   (Space)   |(Entr)| Back |      |      |Forwrd|
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_preonic_1x2uC( \
  WIN_MAX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_EQL,  \
  NXTDSPL, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, FND_USG, XXXXXXX, XXXXXXX, XXXXXXX, KC_F11,  KC_F12,  KC_DEL,  \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, LAST2_3,   \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSLS, \
  XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, BACK,    XXXXXXX, XXXXXXX, FORWARD
),

/* Media
 * ,-----------------------------------------------------------------------------------.
 * |WINMMX|LFTHLF|RGTHLF|      |      |      |      |      |      |      |      | Reset|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |NXTDSP| LOCK |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | Mute |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |  Play/Pause |      | TrBck| Vol- | Vol+ | TrFwd|
 * `-----------------------------------------------------------------------------------'
 */
[_MEDIA] = LAYOUT_preonic_1x2uC( \
  WIN_MAX, LFTHLF,  RGTHLF,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RESET,   \
  NXTDSPL, LOCK,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPLY, XXXXXXX, KC_MRWD, KC_VOLD, KC_VOLU, KC_MFFD
),
};
