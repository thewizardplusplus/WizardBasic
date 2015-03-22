#include "JumpsToNonexsistentLabelsExceptions.h"
#include <boost/format.hpp>
#include <boost/lexical_cast.hpp>

using namespace thewizardplusplus::wizard_basic_2::compiler::translator::
	exceptions;
using namespace boost;

JumpsToNonexsistentLabelsExceptions::JumpsToNonexsistentLabelsExceptions(const
	std::vector<size_t>& nonexistent_labels)
:
	TranslateException(constructMessage(nonexistent_labels))
{}

std::string JumpsToNonexsistentLabelsExceptions::constructMessage(const std::
	vector<size_t>& nonexistent_labels) const
{
	std::string result;
	std::vector<size_t>::const_iterator i = nonexistent_labels.begin();
	for (; i != nonexistent_labels.end(); ++i) {
		if (i != nonexistent_labels.begin()) {
			result += ", ";
		}
		result += lexical_cast<std::string>(*i);
	}

	return (format("jumps to nonexsistent labels %1%") % result).str();
}
