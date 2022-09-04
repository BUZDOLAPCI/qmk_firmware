/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#define _LAYER0 0
#define _LAYER1 1
#define _LAYER2 2

enum custom_keycodes {
    LAYER0 = SAFE_RANGE,
    LAYER1,
    LAYER2,
    MACRO_NVMAIL,
    MACRO_NVPASS,
    MACRO_PCLOGIN,
};

 const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 [_LAYER0] = LAYOUT(KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, MACRO_NVMAIL, KC_MUTE,
                    KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_GRV,
                    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,
                    MO(1), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_PGUP,
                    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_PGDN,
                    KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, MO(1), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT),

[_LAYER1] = LAYOUT( KC_MYCM, KC_MYCM, KC_CALC, KC_NO, KC_NO, KC_ACL0, KC_ACL1, KC_ACL2, KC_NO, KC_NO, KC_NO, KC_BRID, KC_BRIU, MACRO_NVPASS, KC_NO,
                    KC_MYCM, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO, KC_NO,
                    KC_NO, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, KC_NO, KC_NO, KC_NO, KC_UP, KC_NO, KC_PSCR, KC_NO, KC_NO, KC_NO, RESET,
                    KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO, KC_NO, KC_NO, RGB_VAI,
                    KC_NO, KC_MPRV, KC_MUTE, KC_MNXT, KC_NO, KC_NO, KC_NO, KC_NO, RGB_RMOD, RGB_MOD, RGB_TOG, KC_NO, RGB_HUI, RGB_VAD,
                    KC_NO, KC_NO, KC_NO, MACRO_PCLOGIN, KC_NO, KC_TRNS, KC_NO, RGB_SPD, RGB_HUD, RGB_SPI),

[_LAYER2] = LAYOUT( RGB_TOG, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RGB_TOG, KC_NO,
                    KC_NO, BL_TOGG, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, DEBUG,
                    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RESET,
                    KC_NO, RGB_HUI, RGB_SAI, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RGB_VAI,
                    KC_NO, RGB_HUD, RGB_SAD, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RGB_TOG, KC_NO, RGB_SPI, RGB_VAD,
                    KC_NO, KC_NO, KC_NO, RGB_TOG, KC_NO, KC_NO, KC_NO, RGB_RMOD, RGB_SPD, RGB_MOD)
};

 bool process_record_user(uint16_t keycode, keyrecord_t *record) {
     switch (keycode) {
         case MACRO_NVMAIL:
             if (record->event.pressed) 
             {
                 // when keycode MACRO_NVMAIL is pressed
                 SEND_STRING("MACRO_NVMAIL_REPLACE_TEXT");
             } 
             else 
             {
                 tap_code(KC_ENT);
                 // when keycode MACRO_NVMAIL is released
             }
             break;
         case MACRO_NVPASS:
             if (record->event.pressed) 
             {
                 // when keycode MACRO_NVPASS is pressed
                 SEND_STRING("MACRO_NVPASS_REPLACE_TEXT");
             } 
             else 
             {
                 // when keycode MACRO_NVPASS is released
             }
             break;
         case MACRO_PCLOGIN:
             if (record->event.pressed) 
             {
                 // when keycode MACRO_PCLOGIN is pressed
                 tap_code(KC_SPC);
                 SEND_STRING("123123");
             } 
             else 
             {
                 // when keycode MACRO_PCLOGIN is released
             }
             break;
     }
    return true;
 }

 bool encoder_update_user(uint8_t index, bool clockwise) {
     if ((keyboard_report->mods & MOD_BIT(KC_LSFT)) || (keyboard_report->mods & MOD_BIT(KC_RSFT))) { //  mouse scrollwheel with shift
         if (clockwise) {
             unregister_code(KC_LSFT);
             tap_code(KC_MS_WH_DOWN);
             register_code(KC_LSFT);
         } else {
             unregister_code(KC_LSFT);
             tap_code(KC_MS_WH_UP);
             register_code(KC_LSFT);
         }
         return false;
     } else if (IS_LAYER_ON(0)) { // volume on default
         if (clockwise) {
             tap_code(KC_VOLU);
         } else {
             tap_code(KC_VOLD);
         }
     } else { // undo redo with fn
         if (clockwise) {
             tap_code16(C(KC_Y));
         } else {
             tap_code16(C(KC_Z));
         }
     }
     return false;
 }