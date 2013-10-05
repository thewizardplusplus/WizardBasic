#include "SystemModulePrivate.h"
#include <cstdlib>
#include <ctime>

using namespace thewizardplusplus::wizard_basic::framework::system;

SystemModulePrivate::SystemModulePrivate(void) {
	std::srand(std::time(NULL));

	#ifdef OS_LINUX
	gettimeofday(&start_time, NULL);
	#elif defined(OS_WINDOWS)
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&start_time);
	#endif
}

float SystemModulePrivate::getRandomNumber(void) const {
	return static_cast<float>(std::rand()) / RAND_MAX;
}

float SystemModulePrivate::getTimeFromStartInS(void) const {
	#ifdef OS_LINUX
	timeval current_time;
	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec - start_time.tv_sec) + (current_time.tv_usec -
		start_time.tv_usec) / 1000000.0f;
	#elif defined(OS_WINDOWS)
	LARGE_INTEGER current_time;
	QueryPerformanceCounter(&current_time);
	return static_cast<float>(current_time.QuadPart - start_time.QuadPart) /
		frequency.QuadPart;
	#endif
}
