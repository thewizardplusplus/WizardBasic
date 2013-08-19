#ifndef ASSERT_H
#define ASSERT_H

#include <cassert>

#define ASSERT(expression, message) assert((expression) && message)
#endif
