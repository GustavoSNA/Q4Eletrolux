#include "Response.h"
#include <stdio.h>

static int getResult(void);
static void toStr(char *outputBuffer, int *outputBufferSize);

static Response response = {
		.getResult = getResult,
		.toStr = toStr
};

static int result;
static bool validResponse;

Response *getResponse(int r, bool v) {
	result = r;
	validResponse = v;
	return &response;
}

static int getResult(void) {
	return result;
}

static void toStr(char *outputBuffer, int *outputBufferSize) {
	if(validResponse) {
		*outputBufferSize = sprintf(outputBuffer, "(%d)", result);
		return;
	}

	*outputBufferSize = sprintf(outputBuffer, "Request invalid!");
}
