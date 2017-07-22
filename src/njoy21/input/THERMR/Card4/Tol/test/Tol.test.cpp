#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "THERMR tol values",
  "[THERMR],[Card4], [Tol]"){

  GIVEN( "valid tol values" ){
    std::vector<double> validValues{2.e-6, 0.001, 0.001, 0.09, 1.0, 1.5};
    THEN( "the returned class has the correct value" ){
      for( double tol : validValues ){
        iRecordStream<char> iss( 
          std::istringstream( std::to_string( tol ) ) );
        REQUIRE( tol == argument::extract< 
          THERMR::Card4::Tol >( iss ).value );
      }
    } // THEN
  } // GIVEN

  GIVEN( "invalid tol values" ){
    std::vector<double> invalidValues{-0.05, 0.0, 1.e-6};
    THEN( "an exception is thrown" ){
      for( double tol : invalidValues ){
        iRecordStream<char> iss( 
          std::istringstream( std::to_string( tol ) ) );
        REQUIRE_THROWS( argument::extract< 
          THERMR::Card4::Tol >( iss ) );
      }
    } // THEN
  } // GIVEN
} // SCENARIO
