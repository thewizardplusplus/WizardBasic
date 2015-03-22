#ifndef CONVERTER_H
#define CONVERTER_H

#include <sstream>

namespace thewizardplusplus {
namespace wizard_basic_2 {
namespace framework {
namespace utils {

class Converter {
public:
	template<typename Type>
	static std::string toString(Type value);
};

template<typename Type>
std::string Converter::toString(Type value) {
	std::ostringstream out;
	out << value;

	return out.str();
}

}
}
}
}
#endif
