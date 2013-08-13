#include "Program.h"
#include "exceptions/DuplicateLabelsException.h"
#include "exceptions/IncorrectOrderOfLabelsException.h"
#include <boost/format.hpp>

using namespace thewizardplusplus::wizard_basic::translator;
using namespace thewizardplusplus::wizard_basic::translator::exceptions;
using namespace boost;

Program::Program(void) {
	reset();
}

void Program::addLabel(size_t label) {
	if (std::find(labels.begin(), labels.end(), label) != labels.end()) {
		throw DuplicateLabelsException(label);
	}
	if (labels.size() != 0 && label <= labels.back()) {
		throw IncorrectOrderOfLabelsException(label);
	}
	labels.push_back(label);

	cpp_code += (format("\tlabel%1%:\n") % label).str();
}

std::string Program::getCppCode(void) const {
	return (format(
		"#include \"stdlib.h\"\n"
		"\n"
		"int main(void) {\n"
		"%1%\n"
		"\treturn EXIT_SUCCESS;\n"
		"}\n") % cpp_code).str();
}

void Program::reset(void) {
	cpp_code.clear();
	labels.clear();
}
