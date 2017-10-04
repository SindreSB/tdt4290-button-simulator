// 
// 
// 

#include "programs.h"
#include "constants.h"

//WEAPON_1_PIN
//WEAPON_2_PIN

// Test button press durations
void programOne() {
	// Turn on input on both swords
	digitalWrite(WEAPON_1_PIN, HIGH);
	digitalWrite(WEAPON_2_PIN, HIGH);

	// Delay for 5 ms
	delay(5);

	// Turn both inputs off
	digitalWrite(WEAPON_1_PIN, LOW);
	digitalWrite(WEAPON_2_PIN, LOW);
}

// Test double hit, should give points
void programTwo() {
	simulateSwordOne(6);
	delayMicroseconds(25000);
	simulateSwordTwo(6);
}

// Test double hit, should NOT give points
void programThree() {
	simulateSwordOne(8);
	delay(60);
	simulateSwordTwo(8);
}

void programFour()
{
	digitalWrite(WEAPON_1_PIN, HIGH);
	delay(1000);
	digitalWrite(WEAPON_1_PIN, LOW);
}

void simulateSwordOne(int duration)
{
	digitalWrite(WEAPON_1_PIN, HIGH);
	delay(duration);
	digitalWrite(WEAPON_1_PIN, LOW);
}

void simulateSwordTwo(int duration)
{
	digitalWrite(WEAPON_2_PIN, HIGH);
	delay(duration);
	digitalWrite(WEAPON_2_PIN, LOW);
}
