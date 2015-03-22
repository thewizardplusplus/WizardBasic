#include "Array.h"
#include "exceptions/OutOfBoundsException.h"
#include <cmath>

using namespace thewizardplusplus::wizard_basic_2::framework::base;
using namespace thewizardplusplus::wizard_basic_2::framework::base::exceptions;

Array::Array(size_t size, const std::string& name) :
	array(size),
	name(name)
{}

Array::Array(const std::string& string, const std::string& name) :
	array(string.length()),
	name(name)
{
	for (size_t i = 0; i < string.length(); i++) {
		array[i] = static_cast<float>(string[i]);
	}
}

float Array::operator[](float index) const {
	return array[processIndex(index)];
}

float& Array::operator[](float index) {
	return array[processIndex(index)];
}

Array::operator std::string(void) const {
	std::string result;
	NumberVector::const_iterator i = array.begin();
	for (; i != array.end(); ++i) {
		result += static_cast<char>(*i);
	}

	return result;
}

size_t Array::getSize(void) const {
	return array.size();
}

std::string Array::toString(void) const {
	return *this;
}

size_t Array::processIndex(float index) const {
	float rounded_index = std::floor(index + 0.5f);
	if (rounded_index < 0 || rounded_index >= array.size()) {
		throw OutOfBoundsException(name, array.size(), rounded_index);
	}

	return static_cast<size_t>(rounded_index);
}
