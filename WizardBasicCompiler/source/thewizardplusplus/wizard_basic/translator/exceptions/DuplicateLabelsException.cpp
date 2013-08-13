#include "DuplicateLabelsException.h"
#include <boost/format.hpp>

using namespace thewizardplusplus::wizard_basic::translator::exceptions;
using namespace thewizardplusplus::wizard_basic::exceptions;
using namespace boost;

const std::string DuplicateLabelsException::MESSAGE = "duplicate labels %1%";

DuplicateLabelsException::DuplicateLabelsException(size_t label) :
	WizardBasicException((format(MESSAGE) % label).str())
{}
