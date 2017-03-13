#ifndef NJOY21
#define NJOY21

#include <experimental/optional>
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
