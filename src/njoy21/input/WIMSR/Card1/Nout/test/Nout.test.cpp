#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "WIMSR, Card1, Nout",
          "[WIMSR] [Card1] [Nout]" ){
  int ngendf = -24;
  GIVEN( "valid inputs" ){
    for( auto nout : {20, 42, 99} ){
      std::string situ( "valid input " + std::to_string( nout ) +
                                                              " is provided." );
      WHEN( situ.c_str() ){
        iRecordStream<char> iss( std::istringstream( std::to_string( nout ) ) );

        THEN( "the value can be validated" ){
          REQUIRE( nout == argument::extract< WIMSR::Card1::Nout >(
                           iss, ngendf ).value );
        }
      }
    }
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< WIMSR::Card1::Nout >( iss, ngendf ));
      }
    }

    for( auto nout : {-99,-55,-20,0,19,100} ){
      std::string situ( "invalid input " + std::to_string( nout ) +
                                                              " is provided." );
      WHEN( situ.c_str() ){
        iRecordStream<char> iss( std::istringstream( std::to_string( nout ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( argument::extract< WIMSR::Card1::Nout >(iss, ngendf));
        }
      }
    }
  } // GIVEN
} // SCENARIO
