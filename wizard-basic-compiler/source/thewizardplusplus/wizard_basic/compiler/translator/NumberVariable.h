#ifndef NUMBERVARIABLE_H
#define NUMBERVARIABLE_H

#include "Variable.h"

namespace thewizardplusplus {
namespace wizard_basic {
namespace compiler {
namespace translator {

class NumberVariable : public Variable {
public:
	NumberVariable(const std::string& name);
	virtual std::string getCppDefinition(void) const;
};

}
}
}
}
#endif
