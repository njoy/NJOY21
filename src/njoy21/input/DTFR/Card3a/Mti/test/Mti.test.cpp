#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "DTFR mti values",
  "[DTFR],[Card3a], [Mti]"){
  GIVEN( "valid mti values" ){
    std::vector<int> validValues{0, 1, 456, 999};
    THEN( "the returned class has the correct value" ){
      for( int mti : validValues ){
        iRecordStream<char> iss( std::istringstream( std::to_string( mti ) ) );
        REQUIRE( mti == argument::extract< DTFR::Card3a::Mti >( iss ).value );
      }
    } // THEN
  } // GIVEN

  GIVEN( "invalid mti values" ){
    std::vector<int> invalidValues{-1, 1000};
    THEN( "an exception is thrown" ){
      for( int mti : invalidValues ){
        iRecordStream<char> iss( std::istringstream( std::to_string( mti ) ) );
        REQUIRE_THROWS( argument::extract< DTFR::Card3a::Mti >( iss ) );
      }
    } // THEN
  } // GIVEN
} // SCENARIO
