#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "ValueType.h"

namespace thewizardplusplus {
namespace wizard_basic {
namespace translator {

class Expression {
public:
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
#endif
