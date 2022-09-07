#ifndef REQUEST_H_
#define REQUEST_H_

typedef enum {
	SUM,
	SUBTRACT,
	MULTIPLY,
	DIVIDE,
	INVALID
} Operation;

typedef struct {
	Operation(*getOperation)(void);
	int(*getN1)(void);
	int(*getN2)(void);
} Request;

Request *getRequestFromStr(char *str);

#endif
