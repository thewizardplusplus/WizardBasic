#include "IncorrectOrderOfLabelsException.h"

using namespace thewizardplusplus::wizard_basic::compiler::translator::
	exceptions;

IncorrectOrderOfLabelsException::IncorrectOrderOfLabelsException(void) :
	TranslateException("incorrect label order")
{}
