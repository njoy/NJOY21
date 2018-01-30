#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "WIMSR, Card4, Inorf",
          "[WIMSR] [Card4] [Inorf]" ){
  GIVEN( "valid values" ){
    WHEN( "valid values are provided" ){
      for( auto i : {0,1} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "the value can be verified" ){
          REQUIRE( i == argument::extract< WIMSR::Card4::Inorf >( iss ).value );
        }
      }
    }

    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "the default value is returned" ){
        REQUIRE( 0 == argument::extract< WIMSR::Card4::Inorf >( iss ).value );
      }
    }
  } // GIVEN

  GIVEN( "invalid values" ){
    WHEN( "invalid values are provided" ){
      for( auto i : {-1, 2} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( argument::extract< WIMSR::Card4::Inorf >( iss ) );
        }
      }
    }
  } // GIVEN
} // SCENARIO
