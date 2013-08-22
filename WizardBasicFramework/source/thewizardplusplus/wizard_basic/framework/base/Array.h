#ifndef ARRAY_H
#define ARRAY_H

#include <string>
#include <vector>

namespace thewizardplusplus {
namespace wizard_basic {
namespace framework {
namespace base {

class Array {
public:
	Array(const std::string& name, size_t size);
	Array(const std::string& name, const std::string& string);
	float operator[](float index) const;
	float& operator[](float index);
	operator std::string(void) const;
	size_t getSize(void) const;
	std::string toString(void) const;

private:
	typedef std::vector<float> NumberVector;

	std::string  name;
	NumberVector array;

	size_t processIndex(float index) const;
};

}
}
}
}
#endif
