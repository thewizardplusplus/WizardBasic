#include "Program.h"
#include "exceptions/DuplicateLabelsException.h"
#include "exceptions/IncorrectOrderOfLabelsException.h"
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
