#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "WIMSR, Card4, Sigp",
          "[WIMSR] [Card4] [Sigp]" ){
  GIVEN( "valid inputs" ){
    for( double d : {0.0, 1.0, 10.0, 100.0} ){
      std::string situ( "valid input " + std::to_string(d) + " is provided." );
      WHEN( situ.c_str() ){
        iRecordStream<char> iss( std::istringstream( std::to_string( d ) ) );

        THEN( "the value can be verified" ){
          REQUIRE( d == argument::extract< WIMSR::Card4::Sigp >( iss ).value );
        }
      }
    }
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< WIMSR::Card4::Sigp >( iss ) );
      }
    }

    WHEN( "an invalid value is provided" ){
      iRecordStream<char> iss( std::istringstream( "-1.0" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< WIMSR::Card4::Sigp >( iss ) );
      }
    }
  } // GIVEN
} // SCENARIO
