#ifndef NJOY21
#define NJOY21

#include <experimental/optional>
#include <sstream>

#include "dimwits.hpp"
#include "Log.hpp"
#include "utility.hpp"

namespace njoy{

namespace njoy21{

template< typename T >
using optional = std::experimental::optional< T >;

using namespace dimwits;

struct CommandLine;

#include "njoy21/input.hpp"

}
}

// #include "njoy21/CommandLine.hpp"

#endif
