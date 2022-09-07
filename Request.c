#include "Request.h"
#include "string.h"
#include <stdlib.h>

static Operation getOperation(void);
static int getN1(void);
static int getN2(void);

static void setOperation(char *operationStr);
static void setN1(char *n1Str);
static void setN2(char *n2Str);

static void initializeRequest(char *str);

static int number1;
static int number2;
static Operation operation;

static Request request = {
		.getOperation = getOperation,
		.getN1 = getN1,
		.getN2 = getN2
};

Request *getRequestFromStr(char *str) {
	initializeRequest(str);
	return &request;
}

static void initializeRequest(char *str) {
	char *operationStr = strtok(str, ",");
	char *n1Str = strtok(NULL, ",");
	char *n2Str = strtok(NULL, ",");
	while(strtok(NULL, ",") != NULL);
	setOperation(operationStr);
	setN1(n1Str);
	setN2(n2Str);
}

static void setOperation(char *operationStr) {
	if(operationStr == NULL) {
		operation = INVALID;
		return;
	}

	int operationInt = atoi(operationStr);

	switch(operationInt) {
	case 1:
		operation = SUM;
		break;
	case 2:
		operation = SUBTRACT;
		break;
	case 3:
		operation = MULTIPLY;
		break;
	case 4:
		operation = DIVIDE;
		break;
	default:
		operation = INVALID;
		break;
	}
}

static void setN1(char *n1Str) {
	if(n1Str != NULL) {
		number1 = atoi(n1Str);
	}
}

static void setN2(char *n2Str) {
	if(n2Str != NULL) {
		number2 = atoi(n2Str);
	}
}

static Operation getOperation(void) {
	return operation;
}

static int getN1(void) {
	return number1;
}

static int getN2(void) {
	return number2;
}
