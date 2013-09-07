#ifndef FUNCTION_H
#define FUNCTION_H

#include "ValueType.h"
#include "FunctionParameter.h"
#include <list>

namespace thewizardplusplus {
namespace wizard_basic {
namespace compiler {
namespace translator {

class Function {
public:
	typedef std::list<FunctionParameter> ParameterList;

	Function(ValueType::Types result_type, const std::string& name, const std::
		string& alias = "", const ParameterList& parameters = ParameterList());
	ValueType::Types getResultType(void) const;
	std::string getName(void) const;
	std::string getAlias(void) const;
	ParameterList getParameters(void);
	std::string getCppCode(void) const;

private:
	ValueType::Types result_type;
	std::string      name;
	std::string      alias;
	ParameterList    parameters;
};

}
}
}
}
#endif
