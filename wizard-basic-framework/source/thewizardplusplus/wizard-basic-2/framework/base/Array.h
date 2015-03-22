#ifndef ARRAY_H
#define ARRAY_H

#include <string>
#include <vector>

#define WIZARD_BASIC_ARRAY(name, size)    Array name(size, #name)
#define WIZARD_BASIC_STRING(name, string) Array name(string, #name)

namespace thewizardplusplus {
namespace wizard_basic_2 {
namespace framework {
namespace base {

class Array {
public:
	Array(size_t size, const std::string& name);
	Array(const std::string& string, const std::string& name);
	float operator[](float index) const;
	float& operator[](float index);
	operator std::string(void) const;
	size_t getSize(void) const;
	std::string toString(void) const;

private:
	typedef std::vector<float> NumberVector;

	NumberVector array;
	std::string  name;

	size_t processIndex(float index) const;
};

}
}
}
}
#endif
