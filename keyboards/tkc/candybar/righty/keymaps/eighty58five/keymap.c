/* Copyright 2018 Jack Humbert
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
#include "keymap_uk.h"

enum custom_keycodes {
    OLOOK = SAFE_RANGE,
    TEAM,
    RMOTE,
    SAP,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case OLOOK:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_LGUI) "outlook" SS_DELAY(500) SS_TAP(X_ENT));
            } else {
                // when keycode is released
            }
            break;
    
        case TEAM:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_LGUI) "Teams" SS_DELAY(500) SS_TAP(X_ENT));
            } else {
                // when keycode is released
            }
            break;
    
        case RMOTE:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_WSCH) SS_DELAY(500) "https://remote.belfasttrust.hscni.net/citrix/CTXExternalWeb/" SS_DELAY(500) SS_TAP(X_ENT));
            } else {
                // when keycode is released
            }
            break;
    
        case SAP:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_LGUI) "SAP" SS_DELAY(500) SS_TAP(X_ENT));
            } else {
                // when keycode is released
            }
            break;
    }
    return true;
}

#define _BL 0
#define _FL 1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BL: Base Layer (Default Layer)
   */
[_BL] = LAYOUT(
  KC_ESC,   KC_Q,     KC_W,     KC_E,   KC_R,   KC_T,     KC_Y,   KC_U,     KC_I,     KC_O,     KC_P,   KC_BSPC,KC_BSPC,      KC_7,    KC_8,  KC_9,    KC_PAST, \
  KC_TAB,   KC_A,     KC_S,     KC_D,   KC_F,   KC_G,     KC_H,   KC_J,     KC_K,     KC_L,     KC_QUOT,        KC_ENT,       KC_4,    KC_5,  KC_6,    KC_MINS, \
  KC_LSFT,  KC_Z,     KC_X,     KC_C,   KC_V,   KC_B,     KC_N,   KC_M,     KC_COMM,  KC_DOT,   KC_SLASH,       RSFT_T(KC_UP),KC_1,    KC_2,  KC_3,    KC_PPLS, \
  KC_LCTL,  KC_LGUI,  KC_LALT,  KC_SPC,         KC_SPC,   KC_SPC,           KC_APP,   MO(_FL),  KC_LEFT,        KC_DOWN,      KC_RGHT, KC_0,  KC_DOT,  KC_PENT),
 
  /* Keymap _FL: Function Layer
   */
[_FL] = LAYOUT(
  RESET,    KC_Q,     KC_W,     OLOOK,  KC_R,   TEAM,     KC_Y,   KC_U,     KC_I,     KC_LBRC,   KC_RBRC, KC_DEL, KC_DEL,      KC_F7,   KC_F8,  KC_F9,    KC_VOLU, \
  KC_CAPS,  UK_AT,    SAP,      KC_D,   KC_F,   KC_G,     UK_HASH,KC_J,     KC_K,     KC_L,      KC_SCLN,         KC_BSLS,     KC_F4,   KC_F5,  KC_F6,    KC_VOLD, \
  KC_LSFT,  KC_NUBS,  KC_MYCM,  KC_C,   KC_V,   KC_B,     KC_N,   KC_M,     KC_SCLN,  S(UK_SCLN),KC_SLASH,        KC_PGUP,     KC_F1,   KC_F2,  KC_F3,    KC_EQL, \
  KC_LCTL,  KC_APP,   KC_RALT,  KC_SPC,         KC_SPC,   KC_SPC,           KC_SPC,   MO(_FL),   KC_HOME,         KC_PGDN,     KC_END,  KC_F10, KC_F11,   KC_F12),
};
