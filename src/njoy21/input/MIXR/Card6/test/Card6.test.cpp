#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Card6 has valid input" ){
  std::string cardInput(
    "012345678901234567890123456789012345678901234567890123456789012345");
  iRecordStream<char> iss( std::istringstream( "'" + cardInput + "'" ) );
  MIXR::Card6 card6( iss );
  REQUIRE( card6.des.value == cardInput );
}
SCENARIO( "Card6 has invalid input" ){
  std::string cardInput(
    "0123456789012345678901234567890123456789012345678901234567890123456");
  iRecordStream<char> iss( std::istringstream( "'" + cardInput + "'" ) );
  REQUIRE_THROWS( MIXR::Card6( iss ) );
}
