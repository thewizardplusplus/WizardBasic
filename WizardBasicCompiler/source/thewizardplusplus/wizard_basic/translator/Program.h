#ifndef PROGRAM_H
#define PROGRAM_H

#include "VariableList.h"
#include <string>

namespace thewizardplusplus {
namespace wizard_basic {
namespace translator {

class Program {
public:
	void addLabel(size_t label);
	void addVariable(const boost::shared_ptr<Variable>& variable);
	void addAssign(const std::string& identifier, const std::string&
		expression);
	void addAssign(const std::string& identifier, const std::string&
		index_expression, const std::string& expression);
	std::string getCppCode(void) const;

private:
	typedef std::list<size_t> LabelList;

	std::string  cpp_code;
	LabelList    labels;
	VariableList variables;
};

}
}
}
#endif
