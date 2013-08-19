#include "Program.h"
#include "exceptions/DuplicateLabelsException.h"
#include "exceptions/IncorrectOrderOfLabelsException.h"
#include "NumberVariable.h"
#include "exceptions/JumpsToNonexsistentLabelsExceptions.h"
#include <boost/format.hpp>
#include <boost/algorithm/string.hpp>
#include <set>

using namespace thewizardplusplus::wizard_basic::translator;
using namespace thewizardplusplus::wizard_basic::translator::exceptions;
using namespace boost;

void Program::addLabel(size_t label) {
	if (std::find(labels.begin(), labels.end(), label) != labels.end()) {
		throw DuplicateLabelsException();
	}
	if (labels.size() != 0 && label < labels.back()) {
		throw IncorrectOrderOfLabelsException();
	}
	labels.push_back(label);

	cpp_code += (format("\tlabel%1%:\n") % label).str();
}

void Program::addVariable(const boost::shared_ptr<Variable>& variable) {
	variables.addVariable(variable);
}

void Program::addAssign(const std::string& identifier, const std::string&
	expression)
{
	if (!variables.hasVariable(identifier)) {
		variables.addVariable(shared_ptr<Variable>(new NumberVariable(
			identifier)));
	}
	cpp_code += (format("\t%1% = %2%;\n") % identifier % expression).str();
}

void Program::addAssign(const std::string& identifier, const std::string&
	index_expression, const std::string& expression)
{
	cpp_code += (format("\t%1%[%2%] = %3%;\n") % identifier % index_expression %
		expression).str();
}

void Program::addJump(size_t label) {
	jumps.push_back(label);
	cpp_code += (format("\tgoto %1%;\n") % label).str();
}

std::string Program::getCppCode(void) const {
	testJumps();

	std::string code = cpp_code;
	LabelVector unused_labels = findUnusedLabels();
	LabelVector::const_iterator i = unused_labels.begin();
	for (; i != unused_labels.end(); ++i) {
		erase_all(code, (format("\tlabel%1%:\n") % *i).str());
	}

	return (format(
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
