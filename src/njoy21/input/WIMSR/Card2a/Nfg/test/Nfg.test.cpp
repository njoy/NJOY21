#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "WIMSR, Card2a, Nfg",
          "[WIMSR] [Card2a] [Nfg]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      const int ngnd = 100;
      for( auto i : {1, 10, 100} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "the value is verified" ){
          REQUIRE( i == argument::extract< WIMSR::Card2a::Nfg >(
                                           iss, ngnd ).value );
        }
      }
    }
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "an invalid value is provided" ){
      const int ngnd = 10;
      iRecordStream<char> iss( std::istringstream( " -1 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< WIMSR::Card2a::Nfg >( iss, ngnd ) );
      }
    }

    WHEN( "no value is provided" ){
      const int ngnd = 10;
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< WIMSR::Card2a::Nfg >( iss, ngnd ) );
      }
    }

    WHEN( "the provided value is greater than ngnd" ){
      const int ngnd = 10;
      iRecordStream<char> iss( std::istringstream( " 12 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< WIMSR::Card2a::Nfg >( iss, ngnd ) );
      }
    }
  } // GIVEN
} // SCENARIO
