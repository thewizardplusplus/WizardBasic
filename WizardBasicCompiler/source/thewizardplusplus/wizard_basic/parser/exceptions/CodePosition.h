#ifndef CODEPOSITION_H
#define CODEPOSITION_H

#include <string>

namespace thewizardplusplus {
namespace wizard_basic {
namespace parser {
namespace exceptions {

class CodePosition {
public:
	CodePosition(const std::string& previous_code);
	size_t getLine(void) const;
	size_t getColumn(void) const;

private:
	size_t line;
	size_t column;
};

}
}
}
}
#endif
