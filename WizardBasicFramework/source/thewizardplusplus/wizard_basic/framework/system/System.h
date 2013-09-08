#ifndef SYSTEM_H
#define SYSTEM_H

#include "os.h"
#ifdef OS_LINUX
#include <sys/time.h>
#elif defined(OS_WINDOWS)
#include <windows.h>
#endif
#include <string>

namespace thewizardplusplus {
namespace wizard_basic {
namespace framework {
namespace system {

class System {
public:
	static const System& getInstance(void);

	float getRandomNumber(void) const;
	float getTimeFromStartInS(void) const;
	void trace(float number) const;
	void trace(const std::string& string) const;

private:
	System(void);
	System(const System& sample);
	System& operator=(const System& sample);

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
