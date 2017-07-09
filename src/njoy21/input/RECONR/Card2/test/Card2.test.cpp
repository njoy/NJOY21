#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "bugless" ){
  std::string value("012345678901234567890123456789012345678901234567890123456789012345");
  iRecordStream<char> iss( std::istringstream( "'" + value + "'" ) );
  RECONR::Card2 card2( iss );
  REQUIRE( card2.tlabel.value == value );
}

SCENARIO( "bugged" ){
  std::string value("'0123456789012345678901234567890123456789012345678901234567890123456'");
  iRecordStream<char> iss( (std::istringstream(value)) );
  REQUIRE_THROWS( RECONR::Card2( iss ) );
}
