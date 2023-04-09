// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
/* A 4 Layer layout for the Shoebill 5x6 Keyboard */ 

#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0 
#define _SUPER 1 
#define _HYPER 2
#define _COLEMAK 3

#define SUPER MO(_SUPER)
#define HYPER MO(_HYPER)
#define COLEMAK TG(_COLEMAK)
#define QWERTY TG(_QWERTY)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


  [_QWERTY] = LAYOUT_5x6(
     QK_GESC , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_MINS,
     KC_TAB , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                         KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,KC_PLUS,
     KC_LSFT, KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,                         KC_H  , KC_J  , KC_K  , KC_L  ,KC_SCLN,KC_QUOT,
     KC_LCTL, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,                         KC_N  , KC_M  ,KC_COMM,KC_DOT ,KC_SLSH,KC_BSLS,
                      KC_LEFT,KC_RGHT,                                                       KC_UP, KC_DOWN,
                                      KC_BSPC,                                           KC_SPC,
                                      KC_DEL,                                  SUPER, HYPER,
                                      KC_LALT,KC_LGUI,                         COLEMAK, KC_ENT
  ),
  
   [_SUPER] = LAYOUT_5x6(
     QK_GESC , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_F1  , KC_F2  , KC_F3  , KC_7  , KC_8  ,KC_9,
     KC_TAB , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                         KC_F4  , KC_F5  , KC_F6  , KC_6  , KC_5  ,KC_4,
     KC_LSFT, KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,                         KC_F7  , KC_F8  , KC_F9  , KC_1  ,KC_2,KC_3,
     KC_LCTL, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,                         KC_F10  , KC_F11  ,KC_F12,KC_0 ,KC_DOT,KC_ENT,
                      KC_LBRC,KC_RBRC,                                                       KC_LCBR, KC_RCBR,
                                      KC_BSPC,                                           KC_SPC,
                                      KC_DEL,                                 KC_NO,  KC_HOME,
                                      QK_BOOT,KC_SLEP,                         KC_END, KC_ENT
  ),
  
     [_HYPER] = LAYOUT_5x6(
     QK_GESC , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_F1  , KC_F2  , KC_F3  , KC_7  , KC_8  ,KC_9,
     KC_TAB , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                         KC_F4  , KC_F5  , KC_F6  , KC_6  , KC_5  ,KC_4,
     KC_LSFT, KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,                         KC_F7  , KC_F8  , KC_F9  , KC_1  ,KC_2,KC_3,
     KC_LCTL, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,                         KC_F10  , KC_F11  ,KC_F12,KC_0 ,KC_DOT,KC_ENT,
                      KC_MPRV,KC_MNXT,                                                       KC_VOLU, KC_VOLD,
                                      KC_BSPC,                                           KC_SPC,
                                      KC_DEL,                                 KC_PGUP,  KC_HOME,
                                      KC_LALT,KC_LGUI,                         KC_PGDN, KC_END
  ),
    [_COLEMAK] = LAYOUT_5x6(
     QK_GESC , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_MINS,
     KC_TAB , KC_Q  , KC_W  , KC_F  , KC_P  , KC_G  ,                         KC_J  , KC_L  , KC_U  , KC_Y  , KC_SCLN  ,KC_PLUS,
     KC_LSFT, KC_A  , KC_R  , KC_S  , KC_T  , KC_D  ,                         KC_H  , KC_N  , KC_E  , KC_I  ,KC_O,KC_QUOT,
     KC_LCTL, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,                         KC_K  , KC_M  ,KC_COMM,KC_DOT ,KC_SLSH,KC_BSLS,
                      KC_LEFT,KC_RGHT,                                                       KC_UP, KC_DOWN,
                                      KC_BSPC,                                           KC_SPC,
                                      KC_DEL,                                 SUPER,  KC_HOME,
                                      KC_LALT,KC_LGUI,                         QWERTY, KC_END
  )
};


joystick_config_t joystick_axes[JOYSTICK_AXIS_COUNT] = {
    JOYSTICK_AXIS_IN(F5, 900, 575, 285),
    JOYSTICK_AXIS_IN(F6, 900, 575, 286),
};

static bool precision = false;
static uint16_t precision_mod = 64;
static uint16_t axis_val = 127;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    int16_t precision_val = axis_val;
    if (precision) {
        precision_val -= precision_mod;
    }

    switch (keycode) {
        case KC_P8:
            joystick_set_axis(1, record->event.pressed ? -precision_val : 0);
            return false;
        case KC_P2:
            joystick_set_axis(1, record->event.pressed ? precision_val : 0);
            return false;
        case KC_P4:
            joystick_set_axis(0, record->event.pressed ? -precision_val : 0);
            return false;
        case KC_P6:
            joystick_set_axis(0, record->event.pressed ? precision_val : 0);
            return false;
        case KC_P0:
            precision = record->event.pressed;
            return false;
    }
    return true;
}
