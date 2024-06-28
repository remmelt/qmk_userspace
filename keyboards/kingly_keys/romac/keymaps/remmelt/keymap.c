#include QMK_KEYBOARD_H

enum preonic_layers {
  _BASE,
  _NUMBERS
};

#define RUN2CUR A(KC_F9)     // Run to cursor
#define RUN G(A(KC_R))       // Run/resume program
#define STEPOVR KC_F8        // Step over
#define RECOMPL G(S(KC_F9))  // Recompile current file
#define MO_NMBR MO(_NUMBERS) // Momentarily switch to numbers layer

enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QMKBEST:
            if (record->event.pressed) {
                SEND_STRING("Foxes given today: ");
            } else {
                SEND_STRING("0");
            }
            break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_BASE] = LAYOUT(
		KC_PGUP, QMKBEST, KC_HOME, \
		KC_PGDN, STEPOVR, KC_END, \
		XXXXXXX, RUN2CUR, RUN, \
		MO_NMBR, XXXXXXX, RECOMPL \
	),

	[_NUMBERS] = LAYOUT(
		KC_7,    KC_8,    KC_9, \
		KC_4,    KC_5,    KC_6, \
		KC_1,    KC_2,    KC_3, \
		_______, KC_0,    KC_DOT \
	),

};
