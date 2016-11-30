#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Screamcase label" ){
  long lineNumber = 1;
  std::istringstream iss("MODER");
  REQUIRE( "MODER" == Label::extract( iss, lineNumber ) );
  REQUIRE( lineNumber == 2 );
}

SCENARIO( "lowercase label" ){
  long lineNumber = 1;
  std::istringstream iss("moder");
  REQUIRE( "MODER" == Label::extract( iss, lineNumber ) );
  REQUIRE( lineNumber == 2 );
}

SCENARIO( "mixed-case label" ){
  long lineNumber = 1;
  std::istringstream iss("MoDEr");
  REQUIRE( "MODER" == Label::extract( iss, lineNumber ) );
  REQUIRE( lineNumber == 2 );
}

SCENARIO( "with whitespace" ){
  long lineNumber = 1;
  std::istringstream iss("  MODER  ");
  REQUIRE( "MODER" == Label::extract( iss, lineNumber ) );
  REQUIRE( lineNumber == 2 );
}

SCENARIO( "label with comments" ){
  long lineNumber = 1;
  std::istringstream iss(
    "-- This a comment line\n"
    "-- This another comment line\n"
    "MoDEr");
  REQUIRE( "MODER" == Label::extract( iss, lineNumber ) );
  REQUIRE( lineNumber == 4 );
}

SCENARIO( "missing label" ){
  {
    long lineNumber = 1;
    std::istringstream iss("");
    iss.exceptions( std::ios_base::failbit | std::ios_base::badbit );
    REQUIRE_THROWS( Label::extract( iss, lineNumber ) );
  }
  {
    long lineNumber = 1;
    std::istringstream iss(
      "-- This a comment line\n"
      "-- This another comment line\n" );
    REQUIRE_THROWS( Label::extract( iss, lineNumber ) );
  }
}
