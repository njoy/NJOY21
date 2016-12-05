#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "bugless" ){
  {
    std::istringstream iss("   20 21 22\n");
    long lineNumber = 1;
    BROADR::Card1 card1( iss, lineNumber );
    REQUIRE( card1.nendf.value == 20 );
    REQUIRE( card1.nin.value == 21 );
    REQUIRE( card1.nout.value == 22 );
    REQUIRE( lineNumber == 2 );
  }{
    std::istringstream iss("   -20 21 22\n");
    long lineNumber = 1;
    BROADR::Card1 card1( iss, lineNumber );
    REQUIRE( card1.nendf.value == -20 );
    REQUIRE( card1.nin.value == 21 );
    REQUIRE( card1.nout.value == 22 );
    REQUIRE( lineNumber == 2 );
  }
}

SCENARIO( "bugged" ){
  {
    std::istringstream iss("   20 20 21\n");
    long lineNumber = 1;
    REQUIRE_THROWS( BROADR::Card1( iss, lineNumber ) );
  }{
    std::istringstream iss("   20 21 20\n");
    long lineNumber = 1;
    REQUIRE_THROWS( BROADR::Card1( iss, lineNumber ) );
  }{
    std::istringstream iss("   20 21 21\n");
    long lineNumber = 1;
    REQUIRE_THROWS( BROADR::Card1( iss, lineNumber ) );
  }{
    std::istringstream iss("   20 -21 22\n");
    long lineNumber = 1;
    REQUIRE_THROWS( BROADR::Card1( iss, lineNumber ) );
  }
}
