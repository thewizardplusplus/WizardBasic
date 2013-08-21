#include "Program.h"
#include "exceptions/DuplicateLabelsException.h"
#include "exceptions/IncorrectOrderOfLabelsException.h"
#include "NumberVariable.h"
#include "ArrayVariable.h"
#include "StringVariable.h"
#include "exceptions/IllegalAssignOperationException.h"
#include "../utils/assert.h"
#include "ArrayAccessExpression.h"
#include "exceptions/IllegalConditionOperationException.h"
#include "IndexVariable.h"
#include "FunctionCallExpression.h"
#include "exceptions/JumpsToNonexsistentLabelsExceptions.h"
#include <boost/format.hpp>
#include <boost/algorithm/string.hpp>
#include <typeinfo>
#include <set>

using namespace thewizardplusplus::wizard_basic::translator;
using namespace thewizardplusplus::wizard_basic::translator::exceptions;
using namespace boost;

const VariableList& Program::getVariables(void) const {
	return variables;
}

void Program::addLabel(size_t label) {
	if (std::find(labels.begin(), labels.end(), label) != labels.end()) {
		throw DuplicateLabelsException();
	}
	if (labels.size() != 0 && label < labels.back()) {
		throw IncorrectOrderOfLabelsException();
	}
	labels.push_back(label);

	cpp_code += (format("label%1%:\n") % label).str();
}

void Program::addVariable(const shared_ptr<Variable>& variable) {
	variables.addVariable(variable);
}

void Program::addAssign(const std::string& variable_name, const shared_ptr<
	Expression>& expression)
{
	shared_ptr<Variable> variable = variables.getVariableByName(variable_name);
	ValueType::Types variable_type = ValueType::UNKNOWN_TYPE;
	if (variable) {
		if (typeid(*variable) == typeid(NumberVariable)) {
			variable_type = ValueType::NUMBER;
		} else if (typeid(*variable) == typeid(ArrayVariable) || typeid(
			*variable) == typeid(StringVariable))
		{
			variable_type = ValueType::ARRAY;
		}
	} else {
		variables.addVariable(shared_ptr<Variable>(new NumberVariable(
			variable_name)));
		variable_type = ValueType::NUMBER;
	}
	if (variable_type != expression->getType()) {
		throw IllegalAssignOperationException(variable_type, expression->
			getType());
	}

	cpp_code += (format("\t%1% = %2%;\n") % variable_name % expression->
		getCppCode()).str();
}

void Program::addAssign(const shared_ptr<Expression>& array_access, const boost
	::shared_ptr<Expression>& expression)
{
	ASSERT(typeid(*array_access) == typeid(ArrayAccessExpression), "Wizard "
		"BASIC: translating error - invalid expression type; expected "
		"ArrayAccessExpression.");

	if (array_access->getType() != expression->getType()) {
		throw IllegalAssignOperationException(array_access->getType(),
			expression->getType());
	}

	cpp_code += (format("\t%1% = %2%;\n") % array_access->getCppCode() %
		expression->getCppCode()).str();
}

void Program::addJump(size_t label) {
	jumps.push_back(label);
	cpp_code += (format("\tgoto label%1%;\n") % label).str();
}

void Program::addCondition(ConditionType::Types condition_type, const
	shared_ptr<Expression>& left_expression, const shared_ptr<Expression>&
	right_expression, size_t label)
{
	if (left_expression->getType() != right_expression->getType() ||
		(left_expression->getType() != ValueType::NUMBER && left_expression->
		getType() != ValueType::ARRAY))
	{
		throw IllegalConditionOperationException(left_expression->getType(),
			right_expression->getType());
	}

	jumps.push_back(label);
	cpp_code += (format(
		"\tif (%1% %2% %3%) {\n"
		"\t\tgoto label%4%;\n"
		"\t}\n"
	) % left_expression->getCppCode() % ConditionType::convertToCppCode(
		condition_type) % right_expression->getCppCode() % label).str();
}

std::string Program::addTestArrayBounds(const shared_ptr<Variable>& variable,
	const shared_ptr<Expression>& index)
{
	ASSERT(typeid(*variable) == typeid(ArrayVariable), "Wizard BASIC: "
		"translating error - invalid variable type; expected ArrayVariable.");
	ASSERT(index->getType() == ValueType::NUMBER, "Wizard BASIC: translating "
		"error - invalid expression value type; expected NUMBER.");

	shared_ptr<Variable> index_variable(new IndexVariable());
	addVariable(index_variable);

	cpp_code += (format(
		"\t%1% = (size_t)floor(%2% + 0.5f);\n"
		"\tif (%1% >= %3%_SIZE) {\n"
		"\t\tfputs(\"Wizard BASIC: runtime error - out of bounds of array "
			"\\\"%4%\\\".\", stderr);\n"
		"\t}\n"
	) % index_variable->getName() % index->getCppCode() % to_upper_copy(
		variable->getName()) % variable->getName()).str();

	return index_variable->getName();
}

void Program::addFunctionCallAsSatetement(const boost::shared_ptr<Expression>&
	function_call)
{
	ASSERT(typeid(*function_call) == typeid(FunctionCallExpression), "Wizard "
		"BASIC: translating error - invalid expression type; expected "
		"FunctionCallExpression.");

	cpp_code += (format("\t%1%;\n") % function_call->getCppCode()).str();
}

std::string Program::getCppCode(void) const {
	testJumps();

	std::string code = cpp_code;
	LabelVector unused_labels = findUnusedLabels();
	LabelVector::const_iterator i = unused_labels.begin();
	for (; i != unused_labels.end(); ++i) {
		erase_all(code, (format("label%1%:\n") % *i).str());
	}

	if (!variables.hasArrays()) {
		return (format(
			"#include <stdlib.h>\n"
			"\n"
			"int main(void) {\n"
			"%1%"
			"%2%\n"
			"\treturn EXIT_SUCCESS;\n"
			"}\n"
		) % variables.getCppDefinitionOfVariables() % code).str();
	} else {
		return (format(
			"#include <math.h>\n"
			"#include <stdio.h>\n"
			"#include <stdlib.h>\n"
			"\n"
			"%1%"
			"int main(void) {\n"
			"%2%"
			"%3%\n"
			"\treturn EXIT_SUCCESS;\n"
			"}\n"
		) % variables.getCppDefinitionOfArraySizes() % variables.
			getCppDefinitionOfVariables() % code).str();
	}
}

void Program::testJumps(void) const {
	std::set<size_t> jumps(this->jumps.begin(), this->jumps.end());
	std::set<size_t> labels(this->labels.begin(), this->labels.end());
	LabelVector result(jumps.size());
	LabelVector::const_iterator end = std::set_difference(jumps.begin(), jumps.
		end(), labels.begin(), labels.end(), result.begin());
	result.resize(end - result.begin());
	if (!result.empty()) {
		throw JumpsToNonexsistentLabelsExceptions(result);
	}
}

Program::LabelVector Program::findUnusedLabels(void) const {
	std::set<size_t> labels(this->labels.begin(), this->labels.end());
	std::set<size_t> jumps(this->jumps.begin(), this->jumps.end());
	LabelVector result(labels.size());
	LabelVector::const_iterator end = std::set_difference(labels.begin(), labels
		.end(), jumps.begin(), jumps.end(), result.begin());
	result.resize(end - result.begin());
	return result;
}
