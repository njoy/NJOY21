namespace parser {

#include "njoy21/input/argument/parser/src/validate.hpp"
#include "njoy21/input/argument/parser/FortranString.hpp"
#include "njoy21/input/argument/parser/src/rightShift.hpp"
#include "njoy21/input/argument/parser/src/read.hpp"

#include "njoy21/input/argument/parser/Base.hpp"
#include "njoy21/input/argument/parser/Required.hpp"
#include "njoy21/input/argument/parser/Optional.hpp"
#include "njoy21/input/argument/parser/Discriminating.hpp"
#include "njoy21/input/argument/parser/Defaulted.hpp"
#include "njoy21/input/argument/parser/Composition.hpp"

template< typename Policy,
	  bool defaults = argument::policy::hasDefault< Policy >,
	  bool verifies = argument::policy::requiresVerification<Policy> >
using Type = typename Composition< Policy, defaults, verifies >::type;

}
