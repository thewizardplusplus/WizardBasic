#include "DuplicateLabelsException.h"

using namespace thewizardplusplus::wizard_basic::compiler::translator::
	exceptions;

DuplicateLabelsException::DuplicateLabelsException(void) :
	TranslateException("duplicate labels")
{}
