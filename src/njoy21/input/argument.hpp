namespace argument{

#include "njoy21/input/argument/policy.hpp"
#include "njoy21/input/argument/Type.hpp"
#include "njoy21/input/argument/parser.hpp"
#include "njoy21/input/argument/common.hpp"

#include "njoy21/input/argument/src/echoLine.hpp"
#include "njoy21/input/argument/src/construct.hpp"
#include "njoy21/input/argument/src/extract.hpp"
#include "njoy21/input/argument/src/domainError.hpp"

}

template< typename Policy >
using Argument = argument::Type< Policy >;
