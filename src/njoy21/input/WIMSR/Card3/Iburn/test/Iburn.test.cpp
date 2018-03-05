#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "WIMSR, Card3, Iburn",
          "[WIMSR] [Card3] [Iburn]" ){
  GIVEN( "valid inputs" ){
    for( auto i : {-1, 0, 1} ){
      std::string situ( "valid input " + std::to_string(i) + " is provided." );
      WHEN( situ.c_str() ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "the value can be verified" ){
          REQUIRE( i == argument::extract< WIMSR::Card3::Iburn >( iss ).value );
        }
      }
    }

    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "the default value is returned" ){
        REQUIRE( 0 == argument::extract< WIMSR::Card3::Iburn >( iss ).value );
      }
    }
  } // GIVEN

  GIVEN( "invalid values" ){
    for( auto i : {-2, 2} ){
      std::string situ( "invalid input " + std::to_string(i) + " is provided.");
      WHEN( situ.c_str() ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( argument::extract< WIMSR::Card3::Iburn >( iss ) );
        }
      }
    }
  } // GIVEN
} // SCENARIO
