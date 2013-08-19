#include "ParsingException.h"
#include <boost/format.hpp>

using namespace thewizardplusplus::wizard_basic::parser::exceptions;
using namespace thewizardplusplus::wizard_basic::exceptions;
using namespace boost;

ParsingException::ParsingException(const CodePosition& code_position) :
	WizardBasicException((format("parsing error on line %1% in column %2%") %
		code_position.getLine() % code_position.getColumn()).str())
{}
