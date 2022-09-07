#ifndef UARTHALSIMULATOR_H_
#define UARTHALSIMULATOR_H_

#include "UARTHAL.h"

typedef struct {
	UARTHAL *(*getUARTHAL)(void);
	void (*sendStrToRXUARTFromCode)(char *buffer, int bufferSize);
	void (*readStrFromConsoleAndSendToRXUART)(void);
} UARTHALSimulator;

UARTHALSimulator *getUARTHALSimulator(void);

#endif
