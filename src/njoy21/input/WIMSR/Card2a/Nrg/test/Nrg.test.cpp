#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "WIMSR, Card2a, Nrg",
          "[WIMSR] [Card2a] [Nrg]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      const int ngnd = 100;
      for( auto i : {1, 10, 100} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "the value can be verified" ){
          REQUIRE( i == argument::extract< WIMSR::Card2a::Nrg >(
                                           iss, ngnd ).value );
        }
      }
    }
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "an invalid input is provided" ){
      const int ngnd = 10;
      iRecordStream<char> iss( std::istringstream( "-1" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< WIMSR::Card2a::Nrg >( iss, ngnd ) );
      }
    }

    WHEN( "no value is provided" ){
      const int ngnd = 10;
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "the default value is returned" ){
        REQUIRE_THROWS( argument::extract< WIMSR::Card2a::Nrg >( iss, ngnd ) );
      }
    }

    WHEN( "the provided value is greater than ngnd" ){
      const int ngnd = 10;
      iRecordStream<char> iss( std::istringstream( " 20 /" ) );

      THEN( "the default value is returned" ){
        REQUIRE_THROWS( argument::extract< WIMSR::Card2a::Nrg >( iss, ngnd ) );
      }
    }
  } // GIVEN
} // SCENARIO
