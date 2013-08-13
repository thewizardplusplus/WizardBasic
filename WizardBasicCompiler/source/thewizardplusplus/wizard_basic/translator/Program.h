#ifndef PROGRAM_H
#define PROGRAM_H

#include <string>
#include <list>

namespace thewizardplusplus {
namespace wizard_basic {
namespace translator {

class Program {
public:
	Program(void);
	void addLabel(size_t label);
	std::string getCppCode(void) const;
	void reset(void);

private:
	typedef std::list<size_t> LabelList;

	std::string cpp_code;
	LabelList   labels;
};

}
}
}
#endif
