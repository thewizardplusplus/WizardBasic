#include "DuplicateLabelsException.h"

using namespace thewizardplusplus::wizard_basic_2::compiler::translator::
	exceptions;

DuplicateLabelsException::DuplicateLabelsException(void) :
	TranslateException("duplicate labels")
{}
