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

enum babe_thirty_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _ALOWER,
  _ARAISE
};

#define FN1_SPC     LT(1, KC_SPC)
#define FN2_BSPC    LT(2, KC_BSPC)
#define FN3_C       LT(3, KC_C)
#define FN4_V       LT(4, KC_V)
#define FN5_B       LT(5, KC_B)
#define CTL_Z       CTL_T(KC_Z)
#define ALT_X       ALT_T(KC_X)
#define ALT_N       ALGR_T(KC_N)
#define CTL_M       RCTL_T(KC_M)
#define SFT_ENT     RSFT_T(KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,---------------------------------------------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------+-------------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |
 * |------+------+------+------+------+------|------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |
 * `---------------------------------------------------------------------'
 */
  [_QWERTY] = LAYOUT_ortho_3x10(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_ESC,
    CTL_Z,   ALT_X,   FN3_C,   FN4_V,   FN2_BSPC,FN1_SPC, FN5_B,   ALT_N,   CTL_M,   SFT_ENT
  ),


/* Lower
 * ,---------------------------------------------------------------------.
 * |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |
 * |------+------+------+------+------+-------------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |
 * |------+------+------+------+------+------|------+------+------+------|
 * |      |      |      |      |  DEL |      |      |      |      |      |
 * `---------------------------------------------------------------------'
 */

  [_LOWER] = LAYOUT_ortho_3x10(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
    _______, _______, _______, _______, KC_DEL,  _______, _______, _______, _______, _______
  ),

/* Raise
 * ,---------------------------------------------------------------------.
 * |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |
 * |------+------+------+------+------+-------------+------+------+------|
 * |  F11 |  F12 |      |      |      |      |      |      |      |   `  |
 * |------+------+------+------+------+------|------+------+------+------|
 * |      |      |      |      |  DEL |      |      |      |      |      |
 * `---------------------------------------------------------------------'
 */
  [_RAISE] = LAYOUT_ortho_3x10(
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
    KC_F11,  KC_F12,  _______, _______, _______, _______, _______, _______, _______, KC_GRV,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

/* Adjust
 * ,---------------------------------------------------------------------.
 * |      |      |      |      |      |   -  |   =  |   {  |   }  |   \  |
 * |------+------+------+------+------+-------------+------+------+------|
 * |  Tab |      |      |      |      |   ,  |   .  |   /  |   ;  |   '  |
 * |------+------+------+------+------+------|------+------+------+------|
 * |      |      |      |      |      |      | Left |Right |  Up  | Down |
 * `---------------------------------------------------------------------'
 */
  [_ADJUST] = LAYOUT_ortho_3x10(
    _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    KC_TAB,  _______, _______, _______, _______, KC_COMM, KC_DOT,  KC_SLSH, KC_SCLN, KC_QUOT,
    _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
  ),

/* Adjust Lower
 * ,---------------------------------------------------------------------.
 * |      |      |      |      |      |   _  |   +  |   {  |   }  |   |  |
 * |------+------+------+------+------+-------------+------+------+------|
 * | Tab  |      |      |      |      |   <  |   >  |   ?  |   :  |   "  |
 * |------+------+------+------+------+------|------+------+------+------|
 * |      |      |      |      |      |      | Home | PgDn | PgUp |  End |
 * `---------------------------------------------------------------------'
 */
  [_ALOWER] = LAYOUT_ortho_3x10(
    _______, _______, _______, _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
    KC_TAB,  _______, _______, _______, _______, KC_LABK, KC_RABK, KC_QUES, KC_COLN, KC_DQUO,
    _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END
  ),

/* Adjust Raise
 * ,---------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |PrnSc |
 * |------+------+------+------+------+-------------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------|
 * |      |      |      |      |Reset |      |      |      |      |      |
 * `---------------------------------------------------------------------'
 */
  [_ARAISE] = LAYOUT_ortho_3x10(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PSCR,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, RESET,   _______, _______, _______, _______, _______
  )

};

