#include "SystemModule.h"
#include "exceptions/InvalidOpenFileModeException.h"
#include "exceptions/OpenFileException.h"
#include "SystemModulePrivate.h"
#include "exceptions/InvalidFileIdException.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace thewizardplusplus::wizard_basic_2::framework::system;
using namespace thewizardplusplus::wizard_basic_2::framework::system::exceptions;
using namespace thewizardplusplus::wizard_basic_2::framework::base;

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
	return static_cast<float>(std::rand()) / RAND_MAX;
}

float SystemModule::getTimeFromStartInS(void) const {
	return private_realization->getTimeFromStartInS();
}

float SystemModule::fileOpen(const base::Array& filename, float mode) {
	std::string mode_string;
	if (mode == 0.0f) {
		mode_string = "r";
	} else if (mode == 1.0f) {
		mode_string = "w";
	} else if (mode == 2.0f) {
		mode_string = "a";
	} else {
		throw InvalidOpenFileModeException(mode);
	}

	FILE* file = std::fopen(filename.toString().c_str(), mode_string.c_str());
	if (file == NULL) {
		throw OpenFileException(filename);
	}
	files.push_back(file);

	return files.size() - 1;
}

float SystemModule::fileInput(float file_id) const {
	int symbol = std::fgetc(getFileById(file_id));
	if (symbol != EOF) {
		return static_cast<unsigned>(symbol);
	} else {
		return -1.0f;
	}
}

void SystemModule::fileOutput(float file_id, float number) const {
	std::fputc(number, getFileById(file_id));
}

void SystemModule::fileOutput(float file_id, const base::Array& string) const {
	std::fputs(string.toString().c_str(), getFileById(file_id));
}

void SystemModule::fileClose(float file_id) {
	std::fclose(getFileById(file_id));

	FileList::iterator iterator = files.begin();
	std::advance(iterator, std::floor(file_id));
	*iterator = NULL;
}

SystemModule::SystemModule(void) {
	std::srand(std::time(NULL));
	private_realization.reset(new SystemModulePrivate());
}

FILE* SystemModule::getFileById(float file_id) const {
	if (file_id < 0 || file_id >= files.size()) {
		throw InvalidFileIdException(file_id);
	}

	FileList::const_iterator iterator = files.begin();
	std::advance(iterator, std::floor(file_id));
	FILE* file = *iterator;
	if (file == NULL) {
		throw InvalidFileIdException(file_id);
	}

	return file;
}
