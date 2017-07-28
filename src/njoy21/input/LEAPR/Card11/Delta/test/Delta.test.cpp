#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "LEAPR Card11 delta input values", 
  "[LEAPR], [Card11], [Delta]"){
  GIVEN( "valid delta input values" ){
    std::vector<double> validValues{0.001, 2.0};
    THEN( "the returned class has the correct value" ){
      for( auto& delta : validValues ){
        iRecordStream<char> iss(
          std::istringstream( std::to_string( delta ) ) );
        REQUIRE( delta * dimwits::electronVolts == argument::extract< 
          LEAPR::Card11::Delta >( iss ).value );
      }
    } // THEN
  } // GIVEN
  GIVEN( "invalid delta values" ){
    std::vector<double> invalidValues{0,-0.001};
    THEN( "an exception is thrown" ){
      for( auto& delta : invalidValues ){
        iRecordStream<char> iss(
          std::istringstream( std::to_string( delta ) ) );
        REQUIRE_THROWS( argument::extract< 
          LEAPR::Card11::Delta >( iss ) );
      }
    } // THEN
  } // GIVEN
} // SCENARIO
