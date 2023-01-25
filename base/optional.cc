#include "base/optional.h"

namespace base {

// Specification:
// http://en.cppreference.com/w/cpp/utility/optional/in_place
/*const*/ in_place_t in_place = {};

// Specification:
// http://en.cppreference.com/w/cpp/utility/optional/nullopt
/*const*/ nullopt_t nullopt(0);

}