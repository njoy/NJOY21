#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "bugless" ){
  std::string value("012345678901234567890123456789012345678901234567890123456789012345");
  std::istringstream iss( "'" + value + "'" );
  long lineNumber = 1;
  RECONR::Card5 card5( iss, lineNumber );
  REQUIRE( card5.cards.value == value );
}

SCENARIO( "bugged" ){
  std::string value("'0123456789012345678901234567890123456789012345678901234567890123456'");
  std::istringstream iss(value);
  long lineNumber = 1;
  REQUIRE_THROWS( RECONR::Card5( iss, lineNumber ) );
}

