#include "CodePosition.h"
#include <algorithm>

using namespace thewizardplusplus::wizard_basic_2::compiler::parser::exceptions;

CodePosition::CodePosition(const std::string& previous_code) :
	line(0),
	column(0)
{
	line = std::count(previous_code.begin(), previous_code.end(), '\n') + 1;

	size_t index = previous_code.find_last_of('\n');
	if (index != std::string::npos) {
		column = previous_code.substr(index + 1).length();
	} else {
		column = previous_code.length();
	}
	column++;
}

size_t CodePosition::getLine(void) const {
	return line;
}

size_t CodePosition::getColumn(void) const {
	return column;
}
