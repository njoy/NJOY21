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
      for( auto valid : validValues ){
        iRecordStream<char> iss( std::istringstream( valid ) );

        Card1 card1( is );
        THEN( "the values can be validated" ){
          REQUIRE( stoi( valid.substr( 1, 2 ) ) == card1.ngendf.value );
          REQUIRE( stoi( valid.substr( 4, 2 ) ) == card1.nout.value );
        }
      }
    }
  } // GIVEN

  GIVEN( "invalid values" ){
    WHEN( 
  } // GIVEN
} // SCENARIO
