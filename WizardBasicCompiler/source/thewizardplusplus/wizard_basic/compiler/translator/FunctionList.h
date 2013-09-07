#ifndef FUNCTIONMANAGER_H
#define FUNCTIONMANAGER_H

#include "Function.h"
#include <list>

namespace thewizardplusplus {
namespace wizard_basic {
namespace compiler {
namespace translator {

class FunctionList {
public:
	FunctionList(void);
	Function getFunctionByName(const std::string& name) const;

private:
	typedef std::list<Function> FunctionInnerList;

	FunctionInnerList functions;
};

}
}
}
}
#endif
