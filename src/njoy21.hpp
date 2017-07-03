#ifndef NJOY21
#define NJOY21

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wunused-parameter"
#endif
#include <variant>
#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif


#ifdef USING_CPP17
  #include <optional>
#else 
  #include <experimental/optional>

  namespace std {
    using namespace std::experimental;
  }
#endif


#include <sstream>
#include <unordered_set>
#include <queue>
#include <iomanip>

#include "dimwits.hpp"
#include "Log.hpp"
#include "utility.hpp"

#include "njoy_c.h"

namespace njoy{
namespace njoy21{

using namespace std::experimental;
using namespace dimwits;

namespace legacy{ class Sequence; }
namespace modern{ class Sequence; }

struct CommandLine;

#include "njoy21/banner.hpp"
#include "njoy21/input.hpp"
#include "njoy21/io.hpp"
#include "njoy21/interface.hpp"
#include "njoy21/legacy.hpp"

}
}

#include "njoy21/CommandLine.hpp"

namespace njoy{
namespace njoy21{

#include "njoy21/Driver.hpp"

}
}

#endif
