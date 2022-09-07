#ifndef RESPONSE_H_
#define RESPONSE_H_

#include <stdbool.h>

typedef struct {
	int(*getResult)(void);
	void(*toStr)(char *outputBuffer, int *outputBufferSize);
} Response;

Response *getResponse(int result, bool validResponse);

#endif
