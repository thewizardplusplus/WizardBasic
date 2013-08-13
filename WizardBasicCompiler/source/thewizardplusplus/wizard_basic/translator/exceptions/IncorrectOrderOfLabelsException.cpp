#include "IncorrectOrderOfLabelsException.h"
#include <boost/format.hpp>

using namespace thewizardplusplus::wizard_basic::translator::exceptions;
using namespace thewizardplusplus::wizard_basic::exceptions;
using namespace boost;

const std::string IncorrectOrderOfLabelsException::MESSAGE = "incorrect order "
	"of labels with label %1%";

IncorrectOrderOfLabelsException::IncorrectOrderOfLabelsException(size_t label) :
	WizardBasicException((format(MESSAGE) % label).str())
{}
