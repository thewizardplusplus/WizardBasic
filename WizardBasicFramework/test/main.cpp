#include <SystemModule.h>
#include <iostream>

using namespace thewizardplusplus::wizard_basic::framework::system;
using namespace thewizardplusplus::wizard_basic::framework::base;

int main(void) {
	SystemModule::getInstance().trace(SystemModule::getInstance().
		getRandomNumber());
	std::cout << std::endl;
	SystemModule::getInstance().trace(SystemModule::getInstance().
		getTimeFromStartInS());
	std::cout << std::endl;
	WIZARD_BASIC_STRING(test_string, "Test.");
	SystemModule::getInstance().trace(test_string);
	std::cout << std::endl;
}

