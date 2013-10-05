#include "SystemModule.h"
#include "SystemModulePrivate.h"
#include <iostream>

using namespace thewizardplusplus::wizard_basic::framework::system;
using namespace thewizardplusplus::wizard_basic::framework::base;

void SystemModule::trace(float number) {
	std::cout << std::fixed << number;
}

void SystemModule::trace(const base::Array &string) {
	std::cout << string.toString();
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
