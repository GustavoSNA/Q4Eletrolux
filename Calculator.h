#ifndef CALCULATOR_H_
#define CALCULATOR_H_

typedef struct {
	int (*sum)(int n1, int n2);
	int (*subtract)(int n1, int n2);
	int (*multiply)(int n1, int n2);
	int (*divide)(int n1, int n2);
} Calculator;

Calculator *getCalculator(void);

#endif
