#ifndef FUNCTION_H
#define FUNCTION_H

#include "ValueType.h"
#include "FunctionParameter.h"
#include "FunctionStringFormat.h"
#include <list>

namespace thewizardplusplus {
namespace wizard_basic_2 {
namespace compiler {
namespace translator {

class Function {
public:
	typedef std::list<FunctionParameter> ParameterList;

	Function(const std::string& name);
	Function(ValueType::Types result_type, const std::string& name, const std::
		string& cpp_name, const ParameterList& parameters = ParameterList());
	bool operator==(const Function& function) const;
	ValueType::Types getResultType(void) const;
	std::string getName(void) const;
	std::string getCppName(void) const;
	const ParameterList& getParameters(void) const;
	ParameterList& getParameters(void);
	std::string getDescription(void) const;
	std::string getCppCode(void) const;

private:
	ValueType::Types result_type;
	std::string      name;
	std::string      cpp_name;
	ParameterList    parameters;

	std::string toString(FunctionStringFormat::Types string_format) const;
};

}
}
}
}
#endif
