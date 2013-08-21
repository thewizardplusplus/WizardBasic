#ifndef INDEXVARIABLE_H
#define INDEXVARIABLE_H

#include "Variable.h"

namespace thewizardplusplus {
namespace wizard_basic {
namespace translator {

class IndexVariable : public Variable {
public:
	IndexVariable(void);
	virtual std::string getCppDefinition(void) const;

private:
	static size_t id;
};

}
}
}
#endif
