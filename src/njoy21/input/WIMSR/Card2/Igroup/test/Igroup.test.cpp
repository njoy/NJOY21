#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "WIMSR, Card2, Igroup",
          "[WIMSR] [Card2] [Igroup]" ){
  GIVEN( "valid inputs" ){
    for( auto i : {0, 9} ){
      std::string situ( "valid input " + std::to_string(i) + " is provided." );
      WHEN( situ.c_str() ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "the value can be validated" ){
          REQUIRE( i == argument::extract< WIMSR::Card2::Igroup >( iss ).value);
        }
      }
    }

    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "the default value is returned" ){
        REQUIRE( 0 == argument::extract< WIMSR::Card2::Igroup >( iss ).value );
      }
    }
  } // GIVEN

  GIVEN( "invalid inputs" ){
    for( auto i : {-1, 1, 8, 10} ){
      std::string situ( "invalid input " + std::to_string(i) + " is provided.");
      WHEN( situ.c_str() ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( argument::extract< WIMSR::Card2::Igroup >( iss ) );
        }
      }
    }
  } // GIVEN
} // SCENARIO
