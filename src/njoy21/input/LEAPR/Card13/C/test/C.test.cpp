#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "LEAPR Card13 c input values", 
  "[LEAPR], [Card13], [C]"){
  GIVEN( "valid c input values" ){
    std::vector<double> validValues{0.0, 0.5, 0.1};
    THEN( "the returned class has the correct value" ){
      for( auto& c : validValues ){
        iRecordStream<char> iss(
          std::istringstream( std::to_string( c ) ) );
        REQUIRE( c == argument::extract< 
          LEAPR::Card13::C >( iss ).value );
      }
    } // THEN
  } // GIVEN
  GIVEN( "invalid c values" ){
    std::vector<double> invalidValues{-0.1,-1.0};
    THEN( "an exception is thrown" ){
      for( auto& c : invalidValues ){
        iRecordStream<char> iss(
          std::istringstream( std::to_string( c ) ) );
        REQUIRE_THROWS( argument::extract< 
          LEAPR::Card13::C >( iss ) );
      }
    } // THEN
  } // GIVEN
} // SCENARIO
