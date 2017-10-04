// 
// 
// 

#include "utils.h"
#include "constants.h"

void turnLedOn(int led) {
	digitalWrite(led, HIGH);
}

void turnLedOff(int led) {
	digitalWrite(led, LOW);
}

void updateProgramLEDs(int decimalValue) {
	Serial.print("Updating leds with value: ");
	Serial.println(decimalValue);

	// LED 0 is determined by MOD 2
	if (decimalValue % 2) {
		digitalWrite(SELECT_LED_0_PIN, HIGH);
	}
	else {
		digitalWrite(SELECT_LED_0_PIN, LOW);
	}

	// LED 1 is determined by MOD(QUOTIENT(x, 2),2)
	if ((decimalValue / 2) % 2) {
		digitalWrite(SELECT_LED_1_PIN, HIGH);
	}
	else {
		digitalWrite(SELECT_LED_1_PIN, LOW);
	}

	// LED 2 is determined by MOD(QUOTIENT(x, 4),2)
	if ((decimalValue / 4) % 2) {
		digitalWrite(SELECT_LED_2_PIN, HIGH);
	}
	else {
		digitalWrite(SELECT_LED_2_PIN, LOW);
	}

	// LED 3 is determined by MOD(QUOTIENT(x, 4),2)
	if (decimalValue / 8) {
		digitalWrite(SELECT_LED_3_PIN, HIGH);
	}
	else {
		digitalWrite(SELECT_LED_3_PIN, LOW);
	}
}
