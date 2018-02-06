#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "LEAPR Card19 cfrac input values", 
  "[LEAPR], [Card19], [Cfrac]"){
  GIVEN( "valid cfrac input values" ){
    std::vector<double> validValues{0.0, 0.1, 0.99, 1.0};
    THEN( "the returned class has the correct value" ){
      for( auto& cfrac : validValues ){
        iRecordStream<char> iss(
          std::istringstream( std::to_string( cfrac ) ) );
        REQUIRE( cfrac == argument::extract< 
          LEAPR::Card19::Cfrac >( iss ).value );
      }
    } // THEN
  } // GIVEN
  GIVEN( "invalid cfrac values" ){
    std::vector<double> invalidValues{-0.1, 1.1};
    THEN( "an exception is thrown" ){
      for( auto& cfrac : invalidValues ){
        iRecordStream<char> iss(
          std::istringstream( std::to_string( cfrac ) ) );
        REQUIRE_THROWS( argument::extract< 
          LEAPR::Card19::Cfrac >( iss ) );
      }
    } // THEN
  } // GIVEN
} // SCENARIO
