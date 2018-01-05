#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "WIMSR, Card4, Sgref",
          "[WIMSR] [Card4] [Sgref]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid values are provided" ){
      for( auto i : {0.0, 1.0, 10.0, 100.0} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "the value can be verified" ){
          REQUIRE( i == argument::extract< WIMSR::Card4::Sgref >( iss ).value );
        }
      }
    }
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< WIMSR::Card4::Sgref >( iss ) );
      }
    }

    WHEN( "an invalid input is provided" ){
      iRecordStream<char> iss( std::istringstream( "-1.0" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< WIMSR::Card4::Sgref >( iss ) );
      }
    }
  } // GIVEN
} // SCENARIO
