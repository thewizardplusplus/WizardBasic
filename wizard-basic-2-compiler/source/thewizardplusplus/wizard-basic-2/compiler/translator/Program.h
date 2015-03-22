#ifndef PROGRAM_H
#define PROGRAM_H

#include "Expression.h"
#include "ConditionType.h"
#include "VariableList.h"
#include "FunctionList.h"
#include <string>
#include <vector>
#include <set>

namespace thewizardplusplus {
namespace wizard_basic_2 {
namespace compiler {
namespace translator {

class Program {
public:
	const VariableList& getVariables(void) const;
	FunctionList& getFunctions(void);
	void addLabel(size_t label);
	void addVariable(const Variable::Pointer& variable);
	void addAssign(const std::string& variable_name, const Expression::Pointer&
		expression);
	void addAssign(const Expression::Pointer& array_access, const Expression::
		Pointer& expression);
	void addJump(size_t label);
	void addCondition(const Expression::Pointer& left_expression, ConditionType
		::Types condition_type, const Expression::Pointer& right_expression,
		size_t label);
	void addFunctionCallAsStatement(const Expression::Pointer& function_call);
	std::string getCppCode(void) const;

private:
	typedef std::list<size_t>   LabelList;
	typedef std::vector<size_t> LabelVector;
	typedef std::set<size_t>    LabelSet;

	std::string  cpp_code;
	LabelList    labels;
	LabelList    jumps;
	VariableList variables;
	FunctionList functions;

	void testJumps(void) const;
	LabelVector findUnusedLabels(void) const;
};

}
}
}
}
#endif
