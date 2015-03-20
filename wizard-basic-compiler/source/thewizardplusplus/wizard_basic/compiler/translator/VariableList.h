#ifndef VARIABLELIST_H
#define VARIABLELIST_H

#include "Variable.h"
#include <boost/optional.hpp>
#include <boost/shared_ptr.hpp>
#include <list>

namespace thewizardplusplus {
namespace wizard_basic {
namespace compiler {
namespace translator {

class VariableList {
public:
	Variable::Pointer getVariableByName(const std::string& variable_name) const;
	bool hasArrays(void) const;
	void addVariable(const Variable::Pointer& variable);
	std::string getCppDefinition(void) const;

private:
	typedef std::list<Variable::Pointer > VariableInnerList;

	VariableInnerList variables;
};

}
}
}
}
#endif
