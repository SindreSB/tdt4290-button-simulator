// programs.h

#ifndef _PROGRAMS_h
#define _PROGRAMS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

void programOne();

void programTwo();

void programThree();

void programFour();

void simulateSwordOne(int duration);

void simulateSwordTwo(int duration);

#endif

