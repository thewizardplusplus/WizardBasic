#ifndef ASSERT_H
#define ASSERT_H

#include <boost/assert.hpp>

#define ASSERT(expression, message) BOOST_ASSERT((expression) && message)
#endif
