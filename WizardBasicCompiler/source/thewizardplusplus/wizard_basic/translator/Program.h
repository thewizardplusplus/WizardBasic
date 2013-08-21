#ifndef PROGRAM_H
#define PROGRAM_H

#include "Expression.h"
#include "ConditionType.h"
#include "VariableList.h"
#include <string>
#include <vector>

namespace thewizardplusplus {
namespace wizard_basic {
namespace translator {

class Program {
public:
	const VariableList& getVariables(void) const;
	void addLabel(size_t label);
	void addVariable(const boost::shared_ptr<Variable>& variable);
	void addAssign(const std::string& variable_name, const boost::shared_ptr<
		Expression>& expression);
	void addAssign(const boost::shared_ptr<Expression>& array_access, const
		boost::shared_ptr<Expression>& expression);
	void addJump(size_t label);
	void addCondition(ConditionType::Types condition_type, const boost::
		shared_ptr<Expression>& left_expression, const boost::shared_ptr<
		Expression>& right_expression, size_t label);
	std::string addTestArrayBounds(const boost::shared_ptr<Variable>& variable,
		const boost::shared_ptr<Expression>& index);
	void addFunctionCallAsSatetement(const boost::shared_ptr<Expression>&
		function_call);
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
