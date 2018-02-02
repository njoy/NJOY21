#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "LEAPR Card13 tbeta values",
  "[LEAPR], [Card13], [Tbeta]"){

  GIVEN( "valid tbeta values" ){
    std::vector<double> validValues{0.1, 1.0};
    THEN( "the returned class has the correct value" ){
      for( double tbeta : validValues ){
        iRecordStream<char> iss( 
          std::istringstream( std::to_string( tbeta ) ) );
        REQUIRE( tbeta == argument::extract< 
          LEAPR::Card13::Tbeta >( iss ).value );
      }
    } // THEN
  } // GIVEN

  GIVEN( "invalid tbeta values" ){
    std::vector<double> invalidValues{0.0 -0.1};
    THEN( "an exception is thrown" ){
      for( double tbeta : invalidValues ){
        iRecordStream<char> iss( 
          std::istringstream( std::to_string( tbeta ) ) );
        REQUIRE_THROWS( argument::extract< 
          LEAPR::Card13::Tbeta >( iss ) );
      }
    } // THEN
  } // GIVEN
} // SCENARIO
