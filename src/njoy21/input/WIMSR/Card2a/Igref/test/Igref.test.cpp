#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "WIMSR, Card2a, Igref",
          "[WIMSR] [Card2a] [Igref]" ){
  const int nfg = 10;
  const int ngnd = 21;
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      for( auto i : {1, 5, 10, 20} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "the values can be verified" ){
          REQUIRE( i == argument::extract< WIMSR::Card2a::Igref >(
                        iss, nfg, ngnd ).value );
        }
      }
    }

    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "the default value is returned" ){
        REQUIRE( nfg == argument::extract< WIMSR::Card2a::Igref >(
                        iss, nfg, ngnd ).value );
      }
    }
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "invalid inputs are provided" ){
      for( auto i : {-1, 0, 21} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "the values can be verified" ){
          REQUIRE_THROWS( argument::extract< WIMSR::Card2a::Igref >(
                          iss, nfg, ngnd ) );
        }
      }
    }
  } // GIVEN
} // SCENARIO
