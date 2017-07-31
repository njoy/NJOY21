#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "LEAPR Card5 spr input values", 
  "[LEAPR], [Card5], [Spr]"){
  GIVEN( "valid spr input values" ){
    std::vector<double> validValues{0.001, 23.0};
    THEN( "the returned class has the correct value" ){
      for( auto& spr : validValues ){
        iRecordStream<char> iss(
          std::istringstream( std::to_string( spr ) ) );
        REQUIRE( spr * dimwits::barns == argument::extract< 
          LEAPR::Card5::Spr >( iss ).value );
      }
    } // THEN
  } // GIVEN
  GIVEN( "invalid spr values" ){
    std::vector<double> invalidValues{0, -0.001};
    THEN( "an exception is thrown" ){
      for( auto& spr : invalidValues ){
        iRecordStream<char> iss(
          std::istringstream( std::to_string( spr ) ) );
        REQUIRE_THROWS( argument::extract< LEAPR::Card5::Spr >( iss ) );
      }
    } // THEN
  } // GIVEN
} // SCENARIO
