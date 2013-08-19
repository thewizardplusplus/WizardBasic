#ifndef JUMPSTONONEXSISTENTLABELSEXCEPTIONS_H
#define JUMPSTONONEXSISTENTLABELSEXCEPTIONS_H

#include "TranslateException.h"
#include <vector>

namespace thewizardplusplus {
namespace wizard_basic {
namespace translator {
namespace exceptions {

class JumpsToNonexsistentLabelsExceptions : public TranslateException {
public:
	JumpsToNonexsistentLabelsExceptions(const std::vector<size_t>&
		nonexistent_labels);

private:
	std::string constructMessage(const std::vector<size_t>& nonexistent_labels)
		const;
};

}
}
}
}
#endif
