#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "WISMR, Card3, Rdfid",
          "[WIMSR] [Card3] [Rdfid]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      for( auto i : {0.1, 1.0, 10.0, 100.0, 9999.9} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "the value can be verified" ){
          REQUIRE( Approx( i ) == 
                argument::extract< WIMSR::Card3::Rdfid >( iss ).value );
        }
      }
    }
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< WIMSR::Card3::Rdfid >( iss ) );
      }
    }

    WHEN( "invalid values are provided" ){
      for( auto i : {-1.0, 0.0, 10000.0} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( argument::extract< WIMSR::Card3::Rdfid >( iss ) );
        }
      }
    }
  } // GIVEN
} // SCENARIO
