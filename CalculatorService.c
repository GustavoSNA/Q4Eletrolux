#include "CalculatorService.h"
#include <stdbool.h>
#include "UARTHAL.h"
#include "UARTHALSimulator.h"
#include "Calculator.h"
#include "Request.h"
#include "Response.h"
#include "ProtocolParser.h"

#define BUFFER_MAX_SIZE (32)

static void setup(void);
static void loop(void);
static void processNextRequest(void);
static Response *invoke(Request *request);
static void sendResponde(Response *response);
static void simulateNextRequest(void);
static void clearBuffer(char *buffer, int size);

static CalculatorService service = {
		.setup = setup,
		.loop = loop
};

static Calculator *calculator;
static UARTHALSimulator *simulator;
static UARTHAL *uartHAL;
static ProtocolParser *parser;
static char bufferRXStr[BUFFER_MAX_SIZE];
static int bufferRXSize;
static char bufferTXStr[BUFFER_MAX_SIZE];
static int bufferTXSize;
static bool firstSimulation = true;


CalculatorService *getCalculatorService(void) {
	return &service;
}

static void setup(void) {
	calculator = getCalculator();
	simulator = getUARTHALSimulator();
	uartHAL = simulator->getUARTHAL();
	parser = getProtocolParser(uartHAL);
}

static void loop(void) {
	if(parser->hasValidRequestToBeProcessed()) {
		processNextRequest();
		return;
	}

	simulateNextRequest();
}

static void processNextRequest(void) {
	parser->copyValidRequestToBuffer(bufferRXStr, &bufferRXSize);
	Request *request = getRequestFromStr(bufferRXStr);
	Response *response = invoke(request);
	sendResponde(response);
	clearBuffer(bufferRXStr, bufferRXSize);
	clearBuffer(bufferTXStr, bufferTXSize);
}

static Response *invoke(Request *request) {
	Operation operation = request->getOperation();
	int result;

	switch(operation) {
	case SUM:
		result = calculator->sum(request->getN1(), request->getN2());
		break;
	case SUBTRACT:
		result = calculator->subtract(request->getN1(), request->getN2());
		break;
	case MULTIPLY:
		result = calculator->multiply(request->getN1(), request->getN2());
		break;
	case DIVIDE:
		result = calculator->divide(request->getN1(), request->getN2());
		break;
	default:
		return getResponse(0, false);
	}

	return getResponse(result, true);
}

static void sendResponde(Response *response) {
	response->toStr(bufferTXStr, &bufferTXSize);
	uartHAL->write(bufferTXStr, bufferTXSize);
}

static void simulateNextRequest(void) {
	if(firstSimulation) {
		simulator->sendStrToRXUARTFromCode("(1,4,-3)", 8);
		firstSimulation = false;
		return;
	}

	simulator->readStrFromConsoleAndSendToRXUART();
}

static void clearBuffer(char *buffer, int size) {
	for(int i = 0; i < size; i++) {
		buffer[i] = '\0';
	}
}
