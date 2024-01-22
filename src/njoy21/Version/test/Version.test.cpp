#define CATCH_CONFIG_MAIN

#include "catch.hpp"

namespace njoy21 {
#include "njoy21/Version.hpp"
} // namespace

// This was created in the hopes of avoiding to forget to change the Version
// number in releases.
// This is not a guarantee, but it should help.
SCENARIO( "Testing NJOY21 version" ){

  CHECK( "1.2.74" == njoy21::Version::version() );

} // SCENARIO
