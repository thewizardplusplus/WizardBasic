#include "TranslateException.h"
#include <boost/format.hpp>

using namespace thewizardplusplus::wizard_basic::translator::exceptions;
using namespace thewizardplusplus::wizard_basic::exceptions;
using namespace boost;

TranslateException::TranslateException(const std::string& message) :
	WizardBasicException((format("translating error - %1%") % message).str()),
	translate_message(message)
{}

TranslateException::~TranslateException(void) throw() {}

void TranslateException::setLineLabel(size_t line_label) {
	message = (format("translating error on line with label %1% - %2%") %
		line_label % translate_message).str();
}
