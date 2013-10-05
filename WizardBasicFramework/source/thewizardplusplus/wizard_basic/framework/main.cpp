#include "system/SystemModule.h"
#include <iostream>

using namespace thewizardplusplus::wizard_basic::framework::system;

int main(void) {
	SystemModule::getInstance().trace(SystemModule::getInstance().
		getRandomNumber());
	std::cout << std::endl;
	SystemModule::getInstance().trace(SystemModule::getInstance().
		getTimeFromStartInS());
	std::cout << std::endl;
	SystemModule::getInstance().trace("Test.");
	std::cout << std::endl;
}
