#include "ProtocolParser.h"
#include <stdbool.h>

#define BUFFER_RX_SIZE (32)

static bool hasValidRequestToBeProcessed(void);
static void copyValidRequestToBuffer(char *outputBuffer, int *outputSize);
static void onCharReceived(char c);
static void insertCharIntoBufferRX(char c);
static void resetParser(void);

static ProtocolParser parser = {
		.hasValidRequestToBeProcessed = hasValidRequestToBeProcessed,
		.copyValidRequestToBuffer = copyValidRequestToBuffer
};

static char endChar = ')';
static char startChar = '(';

static bool containsValidRequestToBeProcessed = false;
static char bufferRx[BUFFER_RX_SIZE];
static int bufferRxPointer = 0;
static bool initialCharReceived = false;
static bool endCharReceived = false;


ProtocolParser *getProtocolParser(UARTHAL *uart) {
	uart->setReceiverCharInterrupt(onCharReceived);
	resetParser();
	return &parser;
}

static bool hasValidRequestToBeProcessed(void) {
	return containsValidRequestToBeProcessed;
}

static void copyValidRequestToBuffer(char *outputBuffer, int *outputSize) {

	for(int i = 0; i < bufferRxPointer; i++) {
		outputBuffer[i] = bufferRx[i];
	}

	*outputSize = bufferRxPointer;
	resetParser();
}

static void resetParser(void) {
	containsValidRequestToBeProcessed = false;
	initialCharReceived = false;
	endCharReceived = false;
	bufferRxPointer = 0;

	for(int i = 0; i < BUFFER_RX_SIZE; i++) {
		bufferRx[i] = '\0';
	}
}

static void onCharReceived(char c) {

	if(endCharReceived) {
		return;
	}

	containsValidRequestToBeProcessed = false;

	if(c == startChar) {
		initialCharReceived = true;
		return;
	}

	if(c == endChar) {
		endCharReceived = true;
		containsValidRequestToBeProcessed = true;
		return;
	}

	if(initialCharReceived) {
		insertCharIntoBufferRX(c);
	}

}

static void insertCharIntoBufferRX(char c) {
	if(bufferRxPointer < BUFFER_RX_SIZE) {
		bufferRx[bufferRxPointer++] = c;
		return;
	}

	resetParser();
}
