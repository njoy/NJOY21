#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "WIMSR, Card3, Nfid",
          "[WIMSR] [Card3] [Nfid]" ){
  GIVEN( "valid inputs" ){
    WHEN( "any input is provided" ){
      for( auto i : {-10, 0, 1, 10} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "it doesn't really matter, but the value is returned" ){
          REQUIRE( i == argument::extract< WIMSR::Card3::Nfid >( iss ).value );
        }
      }
    }

    WHEN( "no input is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "the default value is returned" ){
        REQUIRE( 0 == argument::extract< WIMSR::Card3::Nfid >( iss ).value );
      }
    }
  } // GIVEN
} // SCENARIO
