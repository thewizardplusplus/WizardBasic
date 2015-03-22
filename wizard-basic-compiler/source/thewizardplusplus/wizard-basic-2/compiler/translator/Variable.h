#ifndef VARIABLE_H
#define VARIABLE_H

#include <boost/shared_ptr.hpp>
#include <string>

namespace thewizardplusplus {
namespace wizard_basic_2 {
namespace compiler {
namespace translator {

class Variable {
public:
	typedef boost::shared_ptr<Variable> Pointer;

	Variable(const std::string& name);
	virtual ~Variable(void);
	std::string getName(void) const;
	virtual std::string getCppDefinition(void) const = 0;

protected:
	std::string name;
};

}
}
}
}
#endif
