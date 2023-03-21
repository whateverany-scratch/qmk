/* Copyright 2020 Vinam Arora <vinam@posteo.de>
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

enum badd_fourty_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

#define QWERTY DF(_QWERTY)
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define ADJUST MO(_ADJUST)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Adjust|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Ins  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | GUI  |Shift |  Alt | Ctrl |Lower |Space |Enter |Raise |  Alt | Ctrl |Shift | GUI  |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12(
   KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
   KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
   ADJUST,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_INS , \
   KC_LGUI, KC_LSFT, KC_LALT, KC_LCTL, LOWER,   KC_ENT,  KC_SPC, RAISE,   KC_RCTL, KC_RALT, KC_RSFT, KC_RGUI \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | PgUp | Left |  Up  | Down |Right | PgDn |      |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      | Home | Left |  Up  | Down |Right | End  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12( \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,  \
  KC_PGUP, KC_LEFT, KC_UP, KC_DOWN,  KC_RGHT, KC_PGDN,  _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, \
  _______, _______, _______, _______, _______, _______, KC_HOME, KC_LEFT, KC_UP, KC_DOWN,  KC_RGHT, KC_END,   \
  _______, _______, _______, _______, _______,  KC_SPC, KC_ENT, _______, _______, _______, _______, _______  \
),



/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | PgUp | Left |  Up  | Down |Right | PgDn |      |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      | Print|Scroll|Pause |Insert|      | Home | Left |  Up  | Down |Right | End  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, \
  KC_PGUP, KC_LEFT, KC_UP  , KC_DOWN, KC_RGHT, KC_PGDN, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
  _______, KC_PSCR, KC_SLCK, KC_PAUS, KC_INS , _______, KC_HOME, KC_LEFT, KC_UP ,  KC_DOWN, KC_RGHT, KC_END,  \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F10 |  F12  | F13 |  F14 |  F15 |  F16 |  F17 |  F18 |  F19  | F20 |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      | Reset|      |Aud on|Audoff|AGnorm|AGswap|Qwerty|      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | CAPS |      |      |      |      |      |      |      |      | CAPS |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] =  LAYOUT_ortho_4x12( \
  _______,  KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, \
  _______,  KC_F11,  KC_F12,  KC_F13,  KC_F14, KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  _______, \
  _______, RESET,   _______,   AU_ON,  AU_OFF, AG_NORM, AG_SWAP, QWERTY,  _______, _______, _______, _______, \
  _______, KC_CAPS, _______, _______, _______, _______, _______, _______, _______, _______, KC_CAPS, _______ \
)

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
