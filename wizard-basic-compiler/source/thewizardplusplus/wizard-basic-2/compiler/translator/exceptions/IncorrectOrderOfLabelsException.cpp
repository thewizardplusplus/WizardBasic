#include "IncorrectOrderOfLabelsException.h"

using namespace thewizardplusplus::wizard_basic_2::compiler::translator::
	exceptions;

IncorrectOrderOfLabelsException::IncorrectOrderOfLabelsException(void) :
	TranslateException("incorrect label order")
{}
