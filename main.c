#include "CalculatorService.h"
#include "UserManual.h"

int main() {
	UserManual *userManual = getUserManual();
	CalculatorService *service = getCalculatorService();
	userManual->print();
	service->setup();

	while(1) {
		service->loop();
	}

	return 0;
}
