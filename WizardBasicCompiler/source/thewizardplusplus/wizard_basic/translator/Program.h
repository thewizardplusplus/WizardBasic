#ifndef PROGRAM_H
#define PROGRAM_H

#include "VariableList.h"
#include <string>
#include <vector>

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
	void addJump(size_t label);
	std::string getCppCode(void) const;

private:
	typedef std::list<size_t>   LabelList;
	typedef std::vector<size_t> LabelVector;

	std::string  cpp_code;
	LabelList    labels;
	LabelList    jumps;
	VariableList variables;

	void testJumps(void) const;
	LabelVector findUnusedLabels(void) const;
};

}
}
}
#endif
