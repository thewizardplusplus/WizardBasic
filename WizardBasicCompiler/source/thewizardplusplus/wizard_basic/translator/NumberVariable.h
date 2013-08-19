#ifndef NUMBERVARIABLE_H
#define NUMBERVARIABLE_H

#include "Variable.h"

namespace thewizardplusplus {
namespace wizard_basic {
namespace translator {

class NumberVariable : public Variable {
public:
	NumberVariable(const std::string& name, float initial_value = 0.0f);
	virtual std::string getCppDefinition(void) const;

private:
	float initial_value;
};

}
}
}
#endif
