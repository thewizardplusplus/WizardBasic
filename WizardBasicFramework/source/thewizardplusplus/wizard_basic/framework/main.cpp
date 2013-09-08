#include "system/System.h"
#include <iostream>

using namespace thewizardplusplus::wizard_basic::framework::system;

int main(void) {
	System::getInstance().trace(System::getInstance().getRandomNumber());
	std::cout << std::endl;
	System::getInstance().trace(System::getInstance().getTimeFromStartInS());
	std::cout << std::endl;
	System::getInstance().trace("Test.");
	std::cout << std::endl;
}
