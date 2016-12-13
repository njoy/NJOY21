#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "bugless" ){
  std::string value(
      "123456789 123456789 123456789 123456789 123456789 123456789 123456");
  std::istringstream iss( "'" + value + "'" );
  long lineNumber = 1;
  ACER::Card3 card3( iss, lineNumber );
  REQUIRE( card3.hk.value == value );
}

SCENARIO( "bugged" ){
  GIVEN( "a string that's too long" ){
    std::string value("'123456789 123456789 123456789 123456789 123456789 123456789 123456789 1'");
    std::istringstream iss(value);
    long lineNumber = 1;
    REQUIRE_THROWS( ACER::Card3( iss, lineNumber ) );
  }
}

