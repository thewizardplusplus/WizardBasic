#include "system/system_functions.h"
#include <iostream>

using namespace thewizardplusplus::wizard_basic::framework::system;

int main(void) {
	Trace(GetRandomNumber());
	std::cout << std::endl;
	Trace(GetTimeFromStartInS());
	std::cout << std::endl;
	Trace("Test.");
	std::cout << std::endl;
}
