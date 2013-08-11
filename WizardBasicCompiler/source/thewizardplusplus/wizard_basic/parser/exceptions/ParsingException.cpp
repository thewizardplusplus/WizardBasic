#include "ParsingException.h"
#include <boost/format.hpp>

using namespace thewizardplusplus::wizard_basic::parser::exceptions;
using namespace thewizardplusplus::wizard_basic::exceptions;
using namespace boost;

const std::string ParsingException::MESSAGE = "parsing error on line %1% in "
	"column %2%";

ParsingException::ParsingException(const CodePosition& code_position) :
	WizardBasicException((format(MESSAGE) % code_position.getLine() %
		code_position.getColumn()).str())
{}
