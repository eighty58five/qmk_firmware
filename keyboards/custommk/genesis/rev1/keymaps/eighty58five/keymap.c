/* Copyright 2020 customMK
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[0] = LAYOUT_ortho_5x4(
			MO(1),   KC_PGUP, KC_PGDN, KC_MUTE, 
			OLOOK,   RMOTE,   SAP,   KC_HOME, 
			KC_MSEL, KC_MYCM, KC_WHOM, KC_INS, 
			KC_WSCH, KC_MAIL, TEAM,    KC_SLCK,
			KC_MPLY, KC_MPRV, KC_MNXT, KC_END),

	[1] = LAYOUT_ortho_5x4(
			KC_TRNS, RGB_MOD, RGB_TOG, KC_TRNS, 
			KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
			RGB_VAI, RGB_VAD, RGB_SPI, RGB_SPD, 
			KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
			RGB_HUI, KC_TRNS, KC_TRNS, RGB_HUD),

};
void encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        tap_code(KC_VOLU);
    } else {
        tap_code(KC_VOLD);
    }
}

