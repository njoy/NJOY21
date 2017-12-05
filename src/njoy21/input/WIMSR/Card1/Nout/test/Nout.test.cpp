#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "WIMSR, Card1, Nout",
          "[WIMSR] [Card1] [Nout]" ){
  int ngendf = -24;
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      for( auto nout : {20, 42, 99} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( nout ) ) );

        THEN( "the value can be validated" ){
          REQUIRE( nout == argument::extract< WIMSR::Card1::Nout >( iss ) );
        }
      }
    }
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< WIMSR::Card1::Nout >( iss ) );
      }
    }

    WHEN( "invalid values are provided" ){
      for( auto nout : {-99,-55,-20,0,19,100} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( nout ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( argument::extract< WIMSR::Card1::Nout >( iss ) );
        }
      }
    }
  } // GIVEN
} // SCENARIO
