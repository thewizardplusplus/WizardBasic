#ifndef FUNCTIONMANAGER_H
#define FUNCTIONMANAGER_H

#include "Function.h"
#include <list>

namespace thewizardplusplus {
namespace wizard_basic_2 {
namespace compiler {
namespace translator {

class FunctionList {
public:
	typedef std::list<Function> SimpleFunctionList;

	FunctionList(void);
	Function getFunctionBySample(const Function& sample_function) const;

private:
	SimpleFunctionList functions;
};

}
}
}
}
#endif
