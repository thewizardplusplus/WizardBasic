#ifndef VARIABLELIST_H
#define VARIABLELIST_H

#include "Variable.h"
#include <boost/shared_ptr.hpp>
#include <list>

namespace thewizardplusplus {
namespace wizard_basic {
namespace translator {

class VariableList {
public:
	bool hasVariable(const std::string& variable_name);
	void addVariable(const boost::shared_ptr<Variable>& variable);
	std::string getCppDefinitionOfArraySizes(void) const;
	std::string getCppDefinitionOfVariables(void) const;

private:
	typedef std::list<boost::shared_ptr<Variable> > VariableInnerList;

	VariableInnerList variables;
};

}
}
}
#endif
