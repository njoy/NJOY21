#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "MIXR Card description" ){
  GIVEN( "description of valid (zero) length" ){
    std::string des("");
    iRecordStream<char> iss( std::istringstream( "'" + des + "'" ) );
    REQUIRE( des == argument::extract< MIXR::Card6::Des >( iss ).value );
  }
  GIVEN( "description of valid (nonzero) length" ){
    std::string des(
      "012345678901234567890123456789012345678901234567890123456789012345");
    iRecordStream<char> iss( std::istringstream( "'" + des + "'" ) );
    REQUIRE( des == argument::extract< MIXR::Card6::Des >( iss ).value );
  }
  GIVEN( "description of invalid length" ){
    std::string des(
      "0123456789012345678901234567890123456789012345678901234567890123456");
    iRecordStream<char> iss( std::istringstream( "'" + des + "'" ) );
    REQUIRE_THROWS( argument::extract< MIXR::Card6::Des >( iss ) );
  }
}
