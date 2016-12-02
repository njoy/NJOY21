#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "bugless" ){
  std::string value("123456789 123456789 123456789 123456789 123456789 123456789 123456");
  std::istringstream iss( "'" + value + "'" );
  long lineNumber = 1;
  RECONR::Card5 card5( iss, lineNumber );
  REQUIRE( value == card5.cards.value );
}

SCENARIO( "bugged" ){
  std::string value("'123456789 123456789 123456789 123456789 123456789 123456789 1234567'");
  std::istringstream iss(value);
  long lineNumber = 1;
  REQUIRE_THROWS( RECONR::Card5( iss, lineNumber ) );
}

