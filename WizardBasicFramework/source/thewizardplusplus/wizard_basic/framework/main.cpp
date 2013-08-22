#include "base/Array.h"
#include <boost/lexical_cast.hpp>
#include <iostream>

using namespace thewizardplusplus::wizard_basic::framework::base;
using namespace boost;

void ShowArray(const Array& array) {
	std::string result = "[";
	for (size_t i = 0; i < array.getSize(); i++) {
		if (i != 0) {
			result += ", ";
		}
		result += lexical_cast<std::string>(array[i]);
	}
	result += "]";

	std::cout << result << std::endl;
}

int main(void) {
	Array array1("array1", 10);
	ShowArray(array1);

	std::srand(std::time(NULL));
	for (size_t i = 0; i < array1.getSize(); i++) {
		array1[i] = static_cast<float>(std::rand()) / RAND_MAX;
	}
	ShowArray(array1);

	Array array2("array2", "Test.");
	std::cout << array2.toString() << std::endl;
}
