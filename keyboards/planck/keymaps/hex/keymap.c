/*
 * hex layout Copyright 2017-2018 Max Haesslein
 * Original Layout Copyright 2015-2017 Jack Humbert
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
#include "muse.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _DVORAK,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum planck_keycodes {
  DVORAK = SAFE_RANGE,
  LOWER,
  RAISE
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * |   /  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  |   \  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  Tab |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Esc/Sh|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  | Bksp | (Esc/Shift -- tap: ESC, hold: SHIFT)
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Comp | Meta | Alt  |Lower |    Space    |Raise | Left |  Up  | Down |Right | (use Right Control as compose key)
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT_planck_grid(
  KC_SLSH, KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSLS,
  KC_TAB,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_ENT,
  F(0),    KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_BSPC,
  KC_LCTL, KC_RCTL, KC_LGUI, KC_LALT, LOWER,   KC_SPACE,KC_SPC,  RAISE,   KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT
),

/* Lower
* ,-----------------------------------------------------------------------------------.
* |   0  |   7  |   8  |   9  |   -  |   =  |   !  |   &  |   _  |   ^  |   |  |      |
* |------+------+------+------+------+-------------+------+------+------+------+------|
* |      |   4  |   5  |   6  |   +  |   /  |   $  |   {  |   [  |   (  |   ~  |      |
* |------+------+------+------+------+------|------+------+------+------+------+------|
* |      |   1  |   2  |   3  |   *  |   \  |   #  |   }  |   ]  |   )  |   %  |      |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |      |      |      |      |      |             |      | HOME | PGUP |PGDOWN| END  |
* `-----------------------------------------------------------------------------------'
*/
[_LOWER] = LAYOUT_planck_grid(
  KC_0,    KC_7,    KC_8,    KC_9,    KC_MINS, KC_EQL,  KC_EXLM, KC_AMPR, KC_UNDS, KC_CIRC, KC_PIPE, _______,
  _______, KC_4,    KC_5,    KC_6,    KC_PLUS, KC_PSLS, KC_DLR,  KC_LCBR, KC_LBRC, KC_LPRN, KC_TILD, _______,
  _______, KC_1,    KC_2,    KC_3,    KC_ASTR, KC_BSLS, KC_HASH, KC_RCBR, KC_RBRC, KC_RPRN, KC_PERC, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END
),

/* Raise
* ,-----------------------------------------------------------------------------------.
* |      | Cut  | Copy |  UP  | Paste|SelAll| Cut  | Copy |  UP  | Paste|      |      |
* |------+------+------+------+------+-------------+------+------+------+------+------|
* |      |   @  | LEFT | DOWN | RIGHT|      |      | LEFT | DOWN | RIGHT|      |      |
* |------+------+------+------+------+------|------+------+------+------+------+------|
* |      |      |      |      |      |      |      |      |      |      |      |  Del |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |      |      |      |      |      |             |      | HOME | PGUP |PGDOWN| END  |
* `-----------------------------------------------------------------------------------'
*/
[_RAISE] = LAYOUT_planck_grid(
  _______, LCTL(KC_X), LCTL(KC_C), KC_UP, LCTL(KC_V), LCTL(KC_A), LCTL(KC_X),  LCTL(KC_C), KC_UP, LCTL(KC_V), _______, _______,
  _______, KC_AT,   KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END
),

/* Adjust (Lower + Raise)
* ,-----------------------------------------------------------------------------------.
* |      | F1   | F2   | F3   | F4   | F5   | F6   | F7   | F8   | F9   | F10  |      |
* |------+------+------+------+------+-------------+------+------+------+------+------|
* |      | F11  | F12  | F13  | F14  | F15  | F16  | HOME | PGUP |PGDOWN| END  |      |
* |------+------+------+------+------+------|------+------+------+------+------+------|
* |      | LED- | LED+ |      |      |      |      |      | VOL- | VOL+ | MUTE |      |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |      |      |      |      |      |             |      | PREV | STOP | PLAY | NEXT |
* `-----------------------------------------------------------------------------------'
*/
[_ADJUST] = LAYOUT_planck_grid(
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
  _______, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_HOME, KC_PGUP, KC_PGDN, KC_END,  _______,
  _______, BL_DEC,  BL_INC,  _______, _______, _______, _______, _______, KC_VOLD, KC_VOLU, KC_MUTE, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_MSTP, KC_MPLY, KC_MNXT
)

};

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_MODS_TAP_KEY(MOD_LSFT, KC_ESC) /* F(0) */
};
