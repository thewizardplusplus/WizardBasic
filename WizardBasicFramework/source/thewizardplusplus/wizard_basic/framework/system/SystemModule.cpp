#include "SystemModule.h"
#include "SystemModulePrivate.h"
#include <iostream>

using namespace thewizardplusplus::wizard_basic::framework::system;

void SystemModule::trace(float number) {
	std::cout << std::fixed << number;
}

void SystemModule::trace(const std::string& string) {
	std::cout << string;
}

SystemModule& SystemModule::getInstance(void) {
	static SystemModule module;
	return module;
}

float SystemModule::getRandomNumber(void) const {
	return private_realization->getRandomNumber();
}

float SystemModule::getTimeFromStartInS(void) const {
	return private_realization->getTimeFromStartInS();
}

SystemModule::SystemModule(void) {
	private_realization.reset(new SystemModulePrivate());
}
