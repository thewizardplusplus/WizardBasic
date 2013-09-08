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

	Function(ValueType::Types result_type, const std::string& name, const
		ParameterList& parameters = ParameterList());
	Function(ValueType::Types result_type, const std::string& alias, const std::
		string& name, const ParameterList& parameters = ParameterList());
	ValueType::Types getResultType(void) const;
	std::string getAlias(void) const;
	std::string getName(void) const;
	ParameterList& getParameters(void);
	std::string getCppCode(void) const;

private:
	ValueType::Types result_type;
	std::string      alias;
	std::string      name;
	ParameterList    parameters;
};

}
}
}
}
#endif
