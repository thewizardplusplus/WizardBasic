#ifndef SYSTEMMODULEPRIVATE_H
#define SYSTEMMODULEPRIVATE_H

#include "os.h"
#ifdef OS_LINUX
#include <sys/time.h>
#elif defined(OS_WINDOWS)
#include <windows.h>
#endif

namespace thewizardplusplus {
namespace wizard_basic {
namespace framework {
namespace system {

class SystemModulePrivate {
public:
	SystemModulePrivate(void);
	float getRandomNumber(void) const;
	float getTimeFromStartInS(void) const;

private:
	#ifdef OS_LINUX
	timeval       start_time;
	#elif defined(OS_WINDOWS)
	LARGE_INTEGER frequency;
	LARGE_INTEGER start_time;
	#endif
};

}
}
}
}
#endif
