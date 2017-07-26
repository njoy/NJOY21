#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "bugless" ){
  std::string value(
      "123456789 123456789 123456789 123456789 123456789 123456789 123456");
  iRecordStream<char> iss{ std::istringstream( "'" + value + "'" ) };
  LEAPR::Card2 card2( iss );
  REQUIRE( card2.title.value == value );
}

SCENARIO( "bugged" ){
  GIVEN( "a string that's too long" ){
    std::string value(
      "123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 12");
    iRecordStream<char> iss{ std::istringstream( "'" + value + "'" ) };
    REQUIRE_THROWS( LEAPR::Card2( iss ) );
  }
}
