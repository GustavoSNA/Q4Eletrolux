#include "Calculator.h"


static int sum(int n1, int n2);
static int subtract(int n1, int n2);
static int multiply(int n1, int n2);
static int divide(int n1, int n2);

static Calculator calculator = {
		.sum = sum,
		.subtract = subtract,
		.multiply = multiply,
		.divide = divide,
};

Calculator *getCalculator(void) {
	return &calculator;
}

static int sum(int n1, int n2) {
	return n1 + n2;
}

static int subtract(int n1, int n2) {
	return n1 - n2;
}

static int multiply(int n1, int n2) {
	return n1 * n2;
}

static int divide(int n1, int n2) {
	return n1 / n2;
}
