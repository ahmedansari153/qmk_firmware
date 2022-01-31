#include "sun20p.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	KEYMAP(
		KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS,
		KC_P7, KC_P8, KC_P9,
		KC_P4, KC_P5, KC_P6, KC_PPLS,
		KC_P1, KC_P2, KC_P3, KC_MUTE,
		KC_INS, KC_PDOT, KC_PENT),

	KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS),

	KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS),

	KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS),

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {

	switch (id) {

	}
	return MACRO_NONE;
}

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
	if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 1000) {
      unregister_code(KC_LALT);
      unregister_code(KC_LSHIFT);
      is_alt_tab_active = false;
      is_alt_shift_tab_active = false;
    }
  }
}

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            if (!is_alt_tab_active) {
                is_alt_tab_active = true;
            unregister_code(KC_LSHIFT);
            register_code(KC_LALT);
            }
            alt_tab_timer = timer_read();
            tap_code(KC_TAB);
        } else {
            if (!is_alt_shift_tab_active) {
                is_alt_shift_tab_active = true;
            register_code(KC_LALT);
            register_code(KC_LSHIFT);
            }
            alt_tab_timer = timer_read();
            tap_code(KC_TAB);
    } else if (index == 1) { /* Second encoder */
        if (clockwise) {
            tap_code(KC_DOWN);
        } else {
            tap_code(KC_UP);
        }
    }
}


void led_set_user(uint8_t usb_led) {

	if (usb_led & (1 << USB_LED_NUM_LOCK)) {

	} else {

	}

	if (usb_led & (1 << USB_LED_CAPS_LOCK)) {

	} else {

	}

	if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {

	} else {

	}

	if (usb_led & (1 << USB_LED_COMPOSE)) {

	} else {

	}

	if (usb_led & (1 << USB_LED_KANA)) {

	} else {

	}

}
