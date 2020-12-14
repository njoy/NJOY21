#ifndef NJOY21
#define NJOY21

#include <variant>
#include <map>


#include <optional>
#include <sstream>
#include <unordered_set>
#include <queue>
#include <iomanip>
#include <regex>
#include <cstdlib>

#include "ENDFtk.hpp"
#include "dimwits.hpp"
#include "Log.hpp"
#include "utility.hpp"


#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
#include "lipservice.hpp"
#pragma GCC diagnostic pop

#include "njoy_c.h"

namespace njoy{
namespace njoy21{

using namespace dimwits;

namespace legacy{ class Sequence; }
namespace modern{ class Sequence; }

struct CommandLine;

#include "njoy21/banner.hpp"
#include "njoy21/io.hpp"
#include "njoy21/interface.hpp"
#include "njoy21/legacy.hpp"
#include "njoy21/Version.hpp"

}
}

#include "njoy21/CommandLine.hpp"

namespace njoy{
namespace njoy21{

#include "njoy21/Driver.hpp"

}
}

#endif
