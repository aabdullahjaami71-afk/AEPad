// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum custom_keynotes {
    DUPLICATE = SAFE_RANGE, 
    CUT,
    NULLLAYER, 
    ADJUST,
    BEAT,
    PRECOMP,
    COPY, 
    PASTE
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) }
};
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┐
     * │ 7 │ 8 │ 9 │ / │
     * ├───┼───┼───┼───┤
     * │ 4 │ 5 │ 6 │ * │
     * ├───┼───┼───┼───┤
     * │ 1 │ 2 │ 3 │ - │
     * ├───┼───┼───┼───┤
     * │ 0 │ . │Ent│ + │
     * └───┴───┴───┴───┘
     */

    [0] = LAYOUT_ortho_3x3(
        DUPLICATE,  KC_F9,   CUT,
        NULLLAYER,   ADJUST,   BEAT,
        PRECOMP,   COPY,   PASTE
    )
};



#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;
}

bool oled_task_user(void) {
    oled_write_P(PSTR("AEPAD :)\n"), false);
    oled_write_P(PSTR("\n"), false);
    oled_write_P(PSTR("Built by\n"), false);
    oled_write_P(PSTR("Aabdullah"), false);
    return false;
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case DUPLICATE:
            if (record->event.pressed) {
                SEND_STRING(SS_LCMD("d"));
            }
            else {

            }

            break;
        case CUT:
            if (record->event.pressed) {
                SEND_STRING(SS_LCMD(SS_LSFT("d")));
            }
            else {

            }
            break;
        case NULLLAYER:
            if (record->event.pressed) {
                SEND_STRING(SS_LCMD(SS_LSFT(SS_LALT("y"))));
            }
            else {

            }
            break;
        case ADJUST:
            if (record->event.pressed) {
                SEND_STRING(SS_LCMD(SS_LALT("y")));
            }
            else {
                
            }
            break;
        case BEAT :
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("8"));
            }
            else {
                
            }
            break;
        case PRECOMP :
            if (record->event.pressed) {
                SEND_STRING(SS_LCMD(SS_LSFT("c")));
            }
            else {
                
            }
            break;
        case COPY :
            if (record->event.pressed) {
                SEND_STRING(SS_LCMD("c"));
            }
            else {
                
            }
            break;
        case PASTE :
            if (record->event.pressed) {
                SEND_STRING(SS_LCMD("v"));
            }
            else {
                
            }
            break;
    }
    return true;
};