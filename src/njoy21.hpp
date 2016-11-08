#ifndef NJOY21
#define NJOY21

#include <sstream>

#include "dimwits.hpp"
#include "Log.hpp"
#include "utility.hpp"

namespace njoy{
namespace njoy21{

template< typename T >
using optional = std::experimental::optional< T >;

#include "njoy21/argument.hpp"
#include "njoy21/input.hpp"

struct CommandLine;

}
}

#include "njoy21/CommandLine.hpp"

#endif
