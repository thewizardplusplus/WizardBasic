#ifndef NUMBERVARIABLE_H
#define NUMBERVARIABLE_H

#include "Variable.h"

namespace thewizardplusplus {
namespace wizard_basic {
namespace translator {

class NumberVariable : public Variable {
public:
	NumberVariable(const std::string& name);
	NumberVariable(const std::string& name, float initial_value);
	virtual std::string getCppDefinition(void) const;

private:
	bool  use_initial_value;
	float initial_value;
};

}
}
}
#endif
