#include "Array.h"
#include "exceptions/OutOfBoundsException.h"
#include <cmath>

using namespace thewizardplusplus::wizard_basic::framework::base;
using namespace thewizardplusplus::wizard_basic::framework::base::exceptions;

Array::Array(const std::string& name, size_t size) :
	name(name),
	array(size)
{}

Array::Array(const std::string& name, const std::string& string) :
	name(name),
	array(string.length())
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
	return toString();
}

size_t Array::getSize(void) const {
	return array.size();
}

std::string Array::toString(void) const {
	std::string result;
	NumberVector::const_iterator i = array.begin();
	for (; i != array.end(); ++i) {
		result += static_cast<char>(*i);
	}

	return result;
}

size_t Array::processIndex(float index) const {
	float rounded_index = std::floor(index + 0.5f);
	if (rounded_index < 0 || rounded_index >= array.size()) {
		throw OutOfBoundsException(name, array.size(), rounded_index);
	}

	return static_cast<size_t>(rounded_index);
}
