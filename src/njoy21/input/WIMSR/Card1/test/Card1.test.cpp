#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "WIMSR, Card1",
          "[WIMSR] [Card1]" ){
  GIVEN( "valid inputs" ){
    std::vector< std::string > validValues{
      " 20 21 /",
      " 98 99 /",
      " 20 99 /" };
    WHEN( "valid inputs are provided" ){
      for( std::string valid : validValues ){
        iRecordStream<char> iss( std::istringstream( valid.c_str() ) );

        WIMSR::Card1 card1( iss );
        THEN( "the values can be validated" ){
          REQUIRE( stoi( valid.substr( 1, 2 ) ) == card1.ngendf.value );
          REQUIRE( stoi( valid.substr( 4, 2 ) ) == card1.nout.value );
        }
      }
    }
  } // GIVEN

  GIVEN( "invalid values" ){
    WHEN( "too few values are provided" ){
      iRecordStream<char> iss( std::istringstream( " 20 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( WIMSR::Card1( iss ) );
      }
    } // WHEN

    WHEN( "too many values are provided" ){
      iRecordStream<char> iss( std::istringstream( " 20 21 22 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( WIMSR::Card1( iss ) );
      }
    } // WHEN

    WHEN( "the same value is given twice" ){
      iRecordStream<char> iss( std::istringstream( " 20 20 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( WIMSR::Card1( iss ) );
      }
    } // WHEN

    WHEN( "one value is invalid" ){
      iRecordStream<char> iss( std::istringstream( " 20 -21 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( WIMSR::Card1( iss ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
