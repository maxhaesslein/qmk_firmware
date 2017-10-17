/*
 * hex layout Copyright 2017 Max Haesslein
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

#include "planck.h"
#include "action_layer.h"

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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Programmer Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |Esc/Sh|   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |Enter | (short press: ESC, long press: SHIFT)
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |   \  |   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |  /   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  GUI | Alt  | Comp |Lower |    Space    |Raise | Left | Down |  Up  |Right | (use RIGHT GUI as compose key)
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = {
  {KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC},
  {F(0),    KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_ENT},   /* F(0): ESCAPE on press and SHIFT on hold */
  {KC_BSLS, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_SLASH},
  {KC_LCTL, KC_LGUI, KC_LALT, KC_RGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},

/* Lower
* ,-----------------------------------------------------------------------------------.
* |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
* |------+------+------+------+------+-------------+------+------+------+------+------|
* |      |   {  |   }  |   [  |   ]  |   (  |   )  |   ~  |   !  |   $  |   =  |      |
* |------+------+------+------+------+------|------+------+------+------+------+------|
* |      |   -  |   +  |   %  |   *  |   &  |   #  |   _  |   `  |   ^  |   @  |      |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |      |      |      |      |      |             |      |      |      |      |      |
* `-----------------------------------------------------------------------------------'
*/
[_LOWER] = {
  {_______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL},
  {_______, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, KC_TILD, KC_EXLM, KC_DLR,  KC_EQL,  _______},
  {_______, KC_MINS, KC_PLUS, KC_PERC, KC_ASTR, KC_AMPR, KC_HASH, KC_UNDS, KC_GRV,  KC_CIRC, KC_AT,   _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* Raise
* ,-----------------------------------------------------------------------------------.
* |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  |  Del |
* |------+------+------+------+------+-------------+------+------+------+------+------|
* |      |  F11 |  F12 |  F13 |  F14 |  F15 |  F16 | LEFT | DOWN |  UP  | RIGHT|      |
* |------+------+------+------+------+------|------+------+------+------+------+------|
* |      |      |      |      |      |      |      |      |      |      |      |      |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |      |      |      |      |      |             |      | HOME |PGDOWN| PGUP | END  |
* `-----------------------------------------------------------------------------------'
*/
[_RAISE] = {
  {_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL},
  {_______, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END}
},

/* Adjust (Lower + Raise)
* ,-----------------------------------------------------------------------------------.
* |      |      |      |      |      |      |      |      |      |      |      |      |
* |------+------+------+------+------+-------------+------+------+------+------+------|
* |      |      |      |      |      |      |      | HOME |PGDOWN| PGUP | END  |      |
* |------+------+------+------+------+------|------+------+------+------+------+------|
* |      | LED- | LED+ |      |      |      |      |      |      |      |      |      |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |      |      |      |      |      |             |      | PREV | STOP | PLAY | NEXT |
* `-----------------------------------------------------------------------------------'
*/
[_ADJUST] = {
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______},
  {_______, BL_DEC,  BL_INC,  _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_MSTP, KC_MPLY, KC_MNXT}
}

};

const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_MODS_TAP_KEY(MOD_LSFT, KC_ESC), /* F(0) */
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
  }
  return true;
}
