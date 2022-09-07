#include "UARTHALSimulator.h"
#include <stdio.h>
#include <stdlib.h>

static UARTHAL *getUARTHAL(void);
static void sendStrToRXUARTFromCode(char *buffer, int bufferSize);
static void readStrFromConsoleAndSendToRXUART(void);

void write(char *buffer, int bufferSize);
void setReceiverCharInterrupt(receiverCharInterrupt interrupt);

static UARTHAL uartHAL = {
		.write = write,
		.setReceiverCharInterrupt = setReceiverCharInterrupt
};

static UARTHALSimulator simulator = {
		.getUARTHAL = getUARTHAL,
		.sendStrToRXUARTFromCode = sendStrToRXUARTFromCode,
		.readStrFromConsoleAndSendToRXUART = readStrFromConsoleAndSendToRXUART
};

static receiverCharInterrupt interrupt = NULL;

UARTHALSimulator *getUARTHALSimulator(void) {
	return &simulator;
}

static UARTHAL *getUARTHAL(void) {
	return &uartHAL;
}

static void sendStrToRXUARTFromCode(char *buffer, int bufferSize) {
	if(interrupt != NULL) {
		for(int i = 0; i < bufferSize; i++) {
			interrupt(buffer[i]);
		}
	}
}

static void readStrFromConsoleAndSendToRXUART(void) {
	int requestStrSize = 32;
	char requestStr[requestStrSize];
	printf("Try yourself: ");
	scanf("%s", requestStr);

	if(interrupt != NULL) {
		for(int i = 0; i < requestStrSize; i++) {
			interrupt(requestStr[i]);
		}
	}

}

void write(char *buffer, int bufferSize) {
	for(int i = 0; i < bufferSize; i++) {
		printf("%c", buffer[i]);
	}

	printf("\n");
}

void setReceiverCharInterrupt(receiverCharInterrupt i) {
	interrupt = i;
}
