#ifndef NJOY21
#define NJOY21

#include <sstream>

#include "dimwits.hpp"
#include "Log.hpp"
#include "utility.hpp"

namespace njoy{

template< typename T >
using optional = std::experimental::optional< T >;

namespace njoy21{

struct CommandLine;

#include "njoy21/input.hpp"

}
}

// #include "njoy21/CommandLine.hpp"

#endif
