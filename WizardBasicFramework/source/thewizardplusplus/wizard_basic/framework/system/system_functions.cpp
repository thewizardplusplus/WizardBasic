#include "SystemModule.h"

namespace thewizardplusplus {
namespace wizard_basic {
namespace framework {
namespace system {

static SystemModule system_module;

float GetRandomNumber(void) {
	return system_module.getRandomNumber();
}

float GetTimeFromStartInS(void) {
	return system_module.getTimeFromStartInS();
}

void Trace(float number) {
	system_module.trace(number);
}

void Trace(const std::string& string) {
	system_module.trace(string);
}

}
}
}
}
