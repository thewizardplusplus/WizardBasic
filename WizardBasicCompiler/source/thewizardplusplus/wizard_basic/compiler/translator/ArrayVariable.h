#ifndef ARRAYVARIABLE_H
#define ARRAYVARIABLE_H

#include "Variable.h"

namespace thewizardplusplus {
namespace wizard_basic {
namespace compiler {
namespace translator {

class ArrayVariable : public Variable {
public:
	ArrayVariable(const std::string& name, size_t size);
	virtual std::string getCppDefinition(void) const;

private:
	size_t size;
};

}
}
}
}
#endif
