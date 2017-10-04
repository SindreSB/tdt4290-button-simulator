// utils.h

#ifndef _UTILS_h
#define _UTILS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif


void turnLedOff(int);

void turnLedOn(int);

void updateProgramLEDs(int);


#endif

