#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "ERRORR, Rest, Card7, Dap",
          "[ERRORR] [Rest] [Card7] [Dap]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      const int mfcov = 33;
      for( double d : {0.0, 0.01, 0.1, 0.5, 1.0} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( d ) ) );

        THEN( "the value can be verified" ){
          REQUIRE( Approx( d ) == argument::extract< ERRORR::Rest::Card7::Dap >(
                                                           iss, mfcov ).value );
        }
      }
    } // WHEN

    WHEN( "no value is provided" ){
      const int mfcov = 33;
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "the default value can be verified" ){
        REQUIRE( Approx( 0.0 ) == argument::extract< ERRORR::Rest::Card7::Dap >(
                                                           iss, mfcov ).value );
      }
    } // WHEN

    WHEN( "mfcov != 33" ){
      for( auto i : {31, 34, 35, 40} ){
        for( double d : {-1.0, 2.0} ){
          iRecordStream<char> iss( std::istringstream( std::to_string( d ) ) );

          THEN( "the value doesn't matter, but can be verified" ){
            REQUIRE( Approx( d ) == argument::extract< ERRORR::Rest::Card7::Dap
                                                            >( iss, i ).value );
          }
        }
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "invalid values are provided" ){
      const int mfcov = 33;
      for( double d : {-0.01, 1.01} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( d ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( argument::extract< ERRORR::Rest::Card7::Dap >(
                                                                 iss, mfcov ) );
        }
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
