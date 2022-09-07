#include "UserManual.h"
#include <stdio.h>

static void printUserManual(void);

static UserManual userManual = {
		.print = printUserManual
};

UserManual *getUserManual(void) {
	return &userManual;
}

void printUserManual(void) {
	printf("In this exercice, i will simulate a calculator service.\n");
	printf("The MCU will recive a command via UART (It was used console for simulations) and return the result based on the operation required by the client.\n");
	printf("The protocol has a start request char '(', end request char ')' and the payload is separed by ','.\n");
	printf("First information is this operation (1: sum, 2: subtract, 3: multiply, 4: divide)\n");
	printf("Second and third information is the numbers)\n");
	printf("Example: sum 4 and -3 you have to send (1,4,-3)\n");
}


