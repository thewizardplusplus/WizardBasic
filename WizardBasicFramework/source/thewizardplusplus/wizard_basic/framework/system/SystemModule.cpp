#include "SystemModule.h"
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace thewizardplusplus::wizard_basic::framework::system;

SystemModule::SystemModule(void) {
	std::srand(std::time(NULL));

	#ifdef OS_LINUX
	gettimeofday(&start_time, NULL);
	#elif defined(OS_WINDOWS)
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&start_time);
	#endif
}

float SystemModule::getRandomNumber(void) const {
	return static_cast<float>(std::rand()) / RAND_MAX;
}

float SystemModule::getTimeFromStartInS(void) const {
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

void SystemModule::trace(float number) const {
	std::cout << std::fixed << number;
}

void SystemModule::trace(const std::string& string) const {
	std::cout << string;
}
