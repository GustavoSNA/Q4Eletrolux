#ifndef PROTOCOLPARSER_H_
#define PROTOCOLPARSER_H_

#include "UARTHAL.h"
#include <stdbool.h>

typedef struct {
	bool(*hasValidRequestToBeProcessed)(void);
	void(*copyValidRequestToBuffer)(char *outputBuffer, int *outputSize);
} ProtocolParser;

ProtocolParser *getProtocolParser(UARTHAL *uart);

#endif
