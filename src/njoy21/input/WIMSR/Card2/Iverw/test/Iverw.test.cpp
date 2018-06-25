#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "WIMSR, Card2, Iverw",
          "[WIMSR] [Card2] [Iverw]" ){
  GIVEN( "valid values" ){
    for( auto i : {4, 5} ){
      std::string situ( "valid input " + std::to_string(i) + " is provided." );
      WHEN( situ.c_str() ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "the value can be verified" ){
          REQUIRE( i == argument::extract< WIMSR::Card2::Iverw >( iss ).value );
        }
      }
    }

    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "the default value is returned" ){
        REQUIRE( 4 == argument::extract< WIMSR::Card2::Iverw >( iss ).value );
      }
    }
  } // GIVEN

  GIVEN( "invalid inputs" ){
    for( auto i : {3, 6} ){
      std::string situ( "invalid input " + std::to_string(i) + " is provided.");
      WHEN( situ.c_str() ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( argument::extract< WIMSR::Card2::Iverw >( iss ) );
        }
      }
    }
  } // GIVEN
} // SCENARIO
