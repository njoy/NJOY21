#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "bugless" ){
  {
    std::istringstream iss( " 1 /" );
    long lineNumber = 1;
    BROADR::Card2 card2( iss, lineNumber );
    REQUIRE( card2.mat1.value == 1 );
    REQUIRE( card2.ntemp2.value == 1 );
    REQUIRE( card2.istart.value == 0 );
    REQUIRE( card2.istrap.value == 0 );
    REQUIRE( card2.temp1.value == 0.0 * dimwits::kelvin );
  }{
    std::istringstream iss( " 20 2 1 1 100" );
    long lineNumber = 1;
    BROADR::Card2 card2( iss, lineNumber );
    REQUIRE( card2.mat1.value == 20 );
    REQUIRE( card2.ntemp2.value == 2 );
    REQUIRE( card2.istart.value == 1 );
    REQUIRE( card2.istrap.value == 1 );
    REQUIRE( card2.temp1.value == 100.0 * dimwits::kelvin );
  }
}

SCENARIO( "bugged" ){
  std::istringstream iss( " 0 /" );
  long lineNumber = 1;
  REQUIRE_THROWS( BROADR::Card2( iss, lineNumber ) );
}
