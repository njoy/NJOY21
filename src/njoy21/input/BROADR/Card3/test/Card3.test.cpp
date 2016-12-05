#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "bugless" ){
  {
    std::istringstream iss("   1.0E-3");
    long lineNumber = 1;
    BROADR::Card3 card3( iss, lineNumber );
    REQUIRE( card3.errthn.value == 1.0E-3 );
    REQUIRE( card3.thnmax.value == 1.0 * dimwits::mega( dimwits::electronVolts ) );
    REQUIRE( card3.errmax.value == 10 * card3.errthn.value );
    REQUIRE( card3.errint.value == 1.0 * dimwits::barns * ( card3.errthn.value / 2.0E4 ) );
  }{
    std::istringstream iss("   1.0E-3 500.0 1.0E-3 1.0E-20");
    long lineNumber = 1;
    BROADR::Card3 card3( iss, lineNumber );
    REQUIRE( card3.errthn.value == 1.0E-3 );
    REQUIRE( card3.thnmax.value == 500.0 * dimwits::electronVolts );
    REQUIRE( card3.errmax.value == 1.0E-3 );
    REQUIRE( card3.errint.value == 1.0E-20 * dimwits::barns );
  }
}

SCENARIO( "bugged" ){
  std::istringstream iss("   0.0");
  long lineNumber = 1;
  REQUIRE_THROWS( BROADR::Card3( iss, lineNumber ) );
}
