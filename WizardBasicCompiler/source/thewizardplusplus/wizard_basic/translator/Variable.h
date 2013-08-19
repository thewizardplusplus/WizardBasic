#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>

namespace thewizardplusplus {
namespace wizard_basic {
namespace translator {

class Variable {
public:
	Variable(const std::string& name);
	std::string getName(void) const;
	virtual std::string getCppDefinition(void) const = 0;

protected:
	std::string name;
};

}
}
}
#endif
