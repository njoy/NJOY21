#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "bugless" ){
  {
    std::istringstream iss("   1 21\n");
    long lineNumber = 1;
    MODER::Card1 card1( iss, lineNumber );
    REQUIRE( card1.nin.value == 1 );
    REQUIRE( card1.nout.value == 21 );
    REQUIRE( lineNumber == 2 );
  }{
    std::istringstream iss("   20 21\n");
    long lineNumber = 1;
    MODER::Card1 card1( iss, lineNumber );
    REQUIRE( card1.nin.value == 20 );
    REQUIRE( card1.nout.value == 21 );
    REQUIRE( lineNumber == 2 );
  }{
    std::istringstream iss("   20 -21\n");
    long lineNumber = 1;
    MODER::Card1 card1( iss, lineNumber );
    REQUIRE( card1.nin.value == 20 );
    REQUIRE( card1.nout.value == -21 );
    REQUIRE( lineNumber == 2 );
  }
}

SCENARIO( "bugged" ){
  {
    std::istringstream iss("   0 21\n");
    long lineNumber = 1;
    REQUIRE_THROWS( MODER::Card1( iss, lineNumber ) );
  }{
    std::istringstream iss("   20 10\n");
    long lineNumber = 1;
    REQUIRE_THROWS( MODER::Card1( iss, lineNumber ) );
  }
}

