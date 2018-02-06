#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "THERMR emax values",
  "[THERMR], [Card4], [Emax]"){

  GIVEN( "valid emax values" ){
    std::vector<double> validValues{0.001, 0.001, 0.09, 1.0, 1.5};
    THEN( "the returned class has the correct value" ){
      for( double emax : validValues ){
        iRecordStream<char> iss( 
          std::istringstream( std::to_string( emax ) ) );
        REQUIRE( emax * dimwits::electronVolts == argument::extract< 
          THERMR::Card4::Emax >( iss ).value );
      }
    } // THEN
  } // GIVEN

  GIVEN( "invalid emax values" ){
    std::vector<double> invalidValues{-0.05, 0.0};
    THEN( "an exception is thrown" ){
      for( double emax : invalidValues ){
        iRecordStream<char> iss( 
          std::istringstream( std::to_string( emax ) ) );
        REQUIRE_THROWS( argument::extract< 
          THERMR::Card4::Emax >( iss ) );
      }
    } // THEN
  } // GIVEN
} // SCENARIO
