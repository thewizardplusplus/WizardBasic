#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "ValueType.h"
#include <boost/shared_ptr.hpp>

namespace thewizardplusplus {
namespace wizard_basic {
namespace compiler {
namespace translator {

class Expression {
public:
	typedef boost::shared_ptr<Expression> Pointer;

	Expression(ValueType::Types type = ValueType::UNKNOWN_TYPE);
	virtual ~Expression(void);
	ValueType::Types getType(void) const;
	virtual std::string getCppCode(void) const = 0;

protected:
	ValueType::Types type;
};

}
}
}
}
#endif
