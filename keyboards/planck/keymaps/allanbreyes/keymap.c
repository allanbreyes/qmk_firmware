#include QMK_KEYBOARD_H

enum custom_keycodes {
    SPCEUS = SAFE_RANGE,
};

#define KC_SPCU SPCEUS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// Alpha
[0] = LAYOUT_ortho_4x12(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_ENT),

    KC_LCTL, SGUI(KC_NO), KC_LALT, KC_LGUI, MO(1),
    KC_SPCU, KC_SPCU,
    MO(2), RGUI_T(KC_LEFT), RALT_T(KC_DOWN), SGUI_T(KC_UP), RCTL_T(KC_RGHT)
),

// Number
[1] = LAYOUT_ortho_4x12(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS,
    KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_4,    KC_5,    KC_6,    KC_PMNS, KC_BSLS,
    KC_TRNS, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_1,    KC_2,    KC_3,    KC_PPLS, KC_TRNS,

    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,
    LT(3,KC_0), KC_PDOT, KC_PSLS, KC_PAST, KC_PEQL
),

// Symbol
[2] = LAYOUT_ortho_4x12(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
    KC_GRV,  KC_LBRC, KC_LCBR, KC_QUOT, KC_DQUO, KC_COLN, KC_PLUS, KC_MINS, KC_EQL,  KC_RCBR, KC_RBRC, KC_PIPE,
    KC_TRNS, KC_BSLS, KC_LT,   KC_LPRN, KC_COMM, LCTL(KC_B), LCTL(KC_W), KC_DOT, KC_RPRN, KC_GT, KC_SLSH, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(3),   KC_UNDS, KC_UNDS, KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END
),

// Adjust
[3] = LAYOUT_ortho_4x12(
    MO(4), DM_REC1, DM_PLY1, KC_NO, KC_END, KC_NO, KC_NO, KC_PGUP, KC_NO, KC_NO, KC_HOME, MO(4),
    KC_NO, KC_NO, KC_NO, KC_PGDN, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, MU_ON, MU_OFF, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, DM_RSTP,
    KC_TRNS, KC_TRNS, AG_SWAP, AG_NORM, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

// Reset
[4] = LAYOUT_ortho_4x12(
    RESET, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RESET,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static bool space_mods = false;
    switch (keycode) {
        case SPCEUS:
            if (record->event.pressed) {
                if (get_mods() & MOD_BIT(KC_LSFT)) {
                    register_code(KC_MINS);
                    space_mods = true;
                } else {
                    register_code(KC_SPC);
                }
            } else {
                if (space_mods) {
                    unregister_code(KC_MINS);
                    space_mods = false;
                } else {
                    unregister_code(KC_SPC);
                }
            }
            return false;
            break;
    }
    return true;
}
