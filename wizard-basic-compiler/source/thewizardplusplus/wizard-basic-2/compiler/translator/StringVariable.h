#ifndef STRINGVARIABLE_H
#define STRINGVARIABLE_H

#include "ArrayVariable.h"

namespace thewizardplusplus {
namespace wizard_basic_2 {
namespace compiler {
namespace translator {

class StringVariable : public ArrayVariable {
public:
	StringVariable(const std::string& name, const std::string& string);
	virtual std::string getCppDefinition(void) const;

private:
	std::string string;
};

}
}
}
}
#endif
