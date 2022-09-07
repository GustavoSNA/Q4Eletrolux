#ifndef CALCULATORSERVICE_H_
#define CALCULATORSERVICE_H_

typedef struct {
	void(*setup)(void);
	void(*loop)(void);
} CalculatorService;


CalculatorService *getCalculatorService(void);

#endif
