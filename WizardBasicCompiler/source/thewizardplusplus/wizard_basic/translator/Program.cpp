#include "Program.h"
#include "exceptions/DuplicateLabelsException.h"
#include "exceptions/IncorrectOrderOfLabelsException.h"
#include "NumberVariable.h"
#include <boost/format.hpp>

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

std::string Program::getCppCode(void) const {
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
		getCppDefinitionOfVariables() % cpp_code).str();
}
