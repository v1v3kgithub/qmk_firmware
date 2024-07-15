/* Copyright 2021 @ Keychron (https://www.keychron.com)
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
#define ENABLE_RGB_MATRIX_TYPING_HEATMAP

enum td_keycodes {
    TD_C,
    TD_Z,
    TD_V,
    TD_L,
    TD_X,
    TD_A,
    TD_F,
    TD_B,
    TD_E,
    TD_R,
    TD_N,
    TD_T
};

// clang-format off
enum layers{
  MAC_BASE,
  MAC_FN,
  WIN_BASE,
  WIN_FN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[MAC_BASE] = LAYOUT_tkl_iso(
     KC_ESC,   KC_BRID,  KC_BRIU,  KC_MCTL,  KC_LPAD,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,           KC_SNAP,   KC_SIRI,  RGB_MOD,
     KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC, KC_INS,    KC_HOME,  KC_PGUP,
     KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,           KC_DEL,    KC_END,   KC_PGDN,
     KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_NUHS,  KC_ENT,
     KC_LSFT,  KC_NUBS,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,            KC_UP,
     KC_LCTL,  KC_LOPTN, KC_LCMMD,                               KC_SPC,                                 KC_RCMMD, KC_ROPTN, MO(MAC_FN),KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

[MAC_FN] = LAYOUT_tkl_iso(
     KC_TRNS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,             KC_TRNS,  KC_TRNS,  RGB_TOG,
     KC_TRNS,  BT_HST1,  BT_HST2,  BT_HST3,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
     RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,
     KC_TRNS,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  BAT_LVL,  NK_TOGG,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,            KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                                KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS),

[WIN_BASE] = LAYOUT_tkl_iso(
     KC_ESC,   KC_F1,       KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,      KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,             KC_PSCR,   KC_CTANA, RGB_MOD,
     KC_GRV,   KC_1,        KC_2,     KC_3,     KC_4,     KC_5,     KC_6,       KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_INS,    KC_HOME,  KC_PGUP,
     KC_TAB,   KC_Q,        KC_W,     TD(TD_E), TD(TD_R), TD(TD_T), KC_Y,       KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,            KC_DEL,    KC_END,   KC_PGDN,
     KC_CAPS,  TD(TD_A),    KC_S,     KC_D,     TD(TD_F), KC_G,     KC_H,       KC_J,     KC_K,     TD(TD_L), KC_SCLN,  KC_QUOT,  KC_NUHS,  KC_ENT,
     KC_LSFT,  KC_NUBS,     TD(TD_Z), TD(TD_X), TD(TD_C), TD(TD_V), TD(TD_B),   TD(TD_N), KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,             KC_UP,
     KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_SPC,                                 KC_MEH,  KC_RGUI, MO(WIN_FN),KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

[WIN_FN] = LAYOUT_tkl_iso(
     KC_TRNS,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,            KC_TRNS,  KC_TRNS,  RGB_TOG,
     KC_TRNS,  BT_HST1,  BT_HST2,  BT_HST3,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
     RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,
     KC_TRNS,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  BAT_LVL,  NK_TOGG,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,            KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                                KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS)

};


// Details on Tap Dance
// https://docs.qmk.fm/features/tap_dance#how-to-use
// Source Code on various Data Types : process_tap_dance.h

// Define a type containing as many tapdance states as you need
typedef enum {
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_DOUBLE_TAP,
    TD_DOUBLE_TAP_AND_HOLD,
    TD_MULTI_TAP
} td_state_t;

typedef struct {
    uint16_t key;
    uint16_t modifier;
} tap_dance_key_combo_t;

typedef struct {
    uint16_t tap_key;
    tap_dance_key_combo_t double_tap_combo;
    tap_dance_key_combo_t tap_and_hold_combo;
} tap_dance_double_tap_t;


bool is_null(tap_dance_key_combo_t *key_combo);


// Create a global instance of the tapdance state type
static td_state_t td_state;

// Declare your tapdance functions:

// Function to determine the current tapdance state
td_state_t cur_dance(tap_dance_state_t *state);

void _register_code(uint16_t modifier);
void _tap_code(uint16_t key);
void _unregister_code(uint16_t modifier);
void _unregister_code(uint16_t modifier);

// `finished` and `reset` functions for each tapdance keycode
void on_dance_finished(tap_dance_state_t *state, void *user_data);
void on_dance_reset(tap_dance_state_t *state, void *user_data);


bool is_null(tap_dance_key_combo_t *key_combo) {
    return key_combo->key == 0 && key_combo->modifier == 0;
}

// Determine the tapdance state to return
td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
    }

    if (state->count == 2) {
        if (state->pressed && !state->interrupted) return TD_DOUBLE_TAP_AND_HOLD;
        return TD_DOUBLE_TAP;
    }
    return TD_UNKNOWN; // Any number higher than the maximum state value you return above
}


// is called when the tap dance is interrupted or ends because TAPPING_TERM
//milliseconds have passed since the last tap. When the finished field of the
//dance state structure is set to true, the on_dance_finished_fn() is skipped.
void tap_dance_tap_hold_finished(tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    tap_dance_double_tap_t *keys = (tap_dance_double_tap_t*) user_data;
    uint16_t tap_key = keys->tap_key;
    tap_dance_key_combo_t double_tap_combo = keys->double_tap_combo;
    tap_dance_key_combo_t tap_and_hold_combo = keys->tap_and_hold_combo;

    switch (td_state) {
        case TD_SINGLE_TAP:
             _tap_code(tap_key);
            break;
        case TD_DOUBLE_TAP:
            // If we dont have a double tap combo
            // then just hit the normal key twice
            if (is_null(&double_tap_combo)) {
                _tap_code(tap_key);
                _tap_code(tap_key);
            } else {
                //Call the double tap with the modifier
                _register_code(double_tap_combo.modifier);
                _tap_code(double_tap_combo.key);
            }
            break;
        case TD_DOUBLE_TAP_AND_HOLD:
            _register_code(tap_and_hold_combo.modifier);
            _tap_code(tap_and_hold_combo.key);
            // For some reason the reset call back isnt called in this case
            // so I am unregistering the modifier here
            _unregister_code(tap_and_hold_combo.modifier);
            break;
        default:
            break;
    }
}

void _register_code(uint16_t modifier) {
    if (modifier) {
        register_code(modifier);
    }
}
void _unregister_code(uint16_t modifier) {
    if (modifier) {
        unregister_code(modifier);
    }
}
void _tap_code(uint16_t key) {
    if (key) {
        tap_code(key);
    }
}
 // After on_dance_finished_fn() was called or would have been called,
// but no sooner than when the tap dance key is released, on_dance_reset_fn() is
// called. It is possible to end a tap dance immediately,
// skipping on_dance_finished_fn(), but not on_dance_reset_fn,
//by calling reset_tap_dance(state).
void tap_dance_tap_hold_reset(tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    tap_dance_double_tap_t *keys = (tap_dance_double_tap_t*) user_data;
    //tap_dance_key_combo_t tap_combo = keys->tap_key;
    tap_dance_key_combo_t double_tap_combo = keys->double_tap_combo;
    tap_dance_key_combo_t tap_and_hold_combo = keys->tap_and_hold_combo;

    switch (td_state) {
        case TD_SINGLE_TAP:
            // Dont have to unregister a single key code
            break;
        case TD_DOUBLE_TAP:
            _unregister_code(double_tap_combo.modifier);
            break;
        case TD_DOUBLE_TAP_AND_HOLD:
            _unregister_code(tap_and_hold_combo.modifier);
            break;
        default:
            break;
    }
}


/**
This macro is used for setting the following short cuts
Double Tap C: Copy - Ctrl,C where is KC_LCTL is the double_tap_modifier  and double_tap_key is KC_C
In the case of the letter V I have the folllowing shortcuts
    _tap_key : KC_V
    // Dobule tap on the V letter results in a paste
    double_tap_key: KC_V
    double_tap_modifier : KC_LCTL
    // Double tap and hold on V results in Shift-Ins
    tap_and_hold_key : KC_INS
    tap_and_hold_modifier : KC_LSFT

The following parameters are provided for tap dance

_tap_key :
double_tap_key :
double_tap_modifier:
tap_and_hold_key :
tap_and_hold_modifier :
**/
#define ACTION_TAP_DANCE_TAP_AND_HOLD(_tap_key, double_tap_key,double_tap_modifier, \
                                        tap_and_hold_key,tap_and_hold_modifier ) \
    { .fn = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, \
    .user_data = (void *)&((tap_dance_double_tap_t){.tap_key = _tap_key, \
    .double_tap_combo = {double_tap_key,double_tap_modifier},\
    .tap_and_hold_combo = {tap_and_hold_key,tap_and_hold_modifier}}), }


tap_dance_action_t tap_dance_actions[] = {
    [TD_L] = ACTION_TAP_DANCE_TAP_AND_HOLD(KC_L,0,0,KC_L,KC_LCTL),
    [TD_C] = ACTION_TAP_DANCE_TAP_AND_HOLD(KC_C,0,0,KC_C,KC_LCTL),
    [TD_R] = ACTION_TAP_DANCE_TAP_AND_HOLD(KC_R,0,0,KC_R,KC_LCTL),
    [TD_X] = ACTION_TAP_DANCE_DOUBLE(KC_X,LCTL(KC_X)),
    [TD_Z] = ACTION_TAP_DANCE_DOUBLE(KC_Z,LCTL(KC_Z)),
    [TD_T] = ACTION_TAP_DANCE_DOUBLE(KC_T,LCA(KC_T)),
//    [TD_X] = ACTION_TAP_DANCE_TAP_AND_HOLD(KC_X,KC_X,KC_LCTL,0,0),
//    [TD_Z] = ACTION_TAP_DANCE_TAP_AND_HOLD(KC_Z,KC_Z,KC_LCTL,0,0),
    [TD_V] = ACTION_TAP_DANCE_TAP_AND_HOLD(KC_V,KC_V,KC_LCTL,KC_INS,KC_LSFT),
    [TD_A] = ACTION_TAP_DANCE_TAP_AND_HOLD(KC_A,0,0,KC_A,KC_LCTL),
    [TD_B] = ACTION_TAP_DANCE_TAP_AND_HOLD(KC_B,0,0,KC_B,KC_LCTL),
    [TD_F] = ACTION_TAP_DANCE_TAP_AND_HOLD(KC_F,0,0,KC_F,KC_LCTL),
    [TD_E] = ACTION_TAP_DANCE_TAP_AND_HOLD(KC_E,0,0,KC_E,KC_LGUI),
    [TD_N] = ACTION_TAP_DANCE_TAP_AND_HOLD(KC_N,0,0,KC_N,KC_LCTL),
};
