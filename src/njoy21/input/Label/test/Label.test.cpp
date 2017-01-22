#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Screamcase label" ){
  iRecordStream<char> iss( std::istringstream("MODER") );
  REQUIRE( "MODER" == Label::extract( iss ) );
}

SCENARIO( "lowercase label" ){
  iRecordStream<char> iss( std::istringstream("moder") );
  REQUIRE( "MODER" == Label::extract( iss ) );
}

SCENARIO( "mixed-case label" ){
  iRecordStream<char> iss( std::istringstream("MoDEr") );
  REQUIRE( "MODER" == Label::extract( iss ) );
}

SCENARIO( "with whitespace" ){
  iRecordStream<char> iss( std::istringstream("  MODER  ") );
  REQUIRE( "MODER" == Label::extract( iss ) );
}

SCENARIO( "label with comments" ){
  iRecordStream<char> iss( std::istringstream(
    "-- This a comment line\n"
    "-- This another comment line\n"
    "MoDEr") );
  REQUIRE( "MODER" == Label::extract( iss ) );
}

SCENARIO( "missing label" ){
  {
    iRecordStream<char> iss( std::istringstream("") );
    REQUIRE_THROWS( Label::extract( iss ) );
  }
  {
    iRecordStream<char> iss( std::istringstream(
      "-- This a comment line\n"
      "-- This another comment line\n" ) );
    REQUIRE_THROWS( Label::extract( iss ) );
  }
}
