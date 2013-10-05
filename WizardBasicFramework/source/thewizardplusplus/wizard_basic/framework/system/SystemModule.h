#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>
#include <memory>

namespace thewizardplusplus {
namespace wizard_basic {
namespace framework {
namespace system {

class SystemModulePrivate;

class SystemModule {
public:
	static void trace(float number);
	static void trace(const std::string& string);
	static SystemModule& getInstance(void);

	float getRandomNumber(void) const;
	float getTimeFromStartInS(void) const;

private:
	std::auto_ptr<SystemModulePrivate> private_realization;

	SystemModule(void);
	SystemModule(const SystemModule& sample);
	SystemModule& operator=(const SystemModule& sample);
};

}
}
}
}
#endif
