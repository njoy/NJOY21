#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "ERRORR, Rest, Card7, Ifissp",
          "[ERRORR] [Rest] [Card7] [Ifissp]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      const int mfcov = 35;
      for( auto i : {-1, 1, 10, 100} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "the value can be verified" ){
          REQUIRE( i ==
         argument::extract< ERRORR::Rest::Card7::Ifissp >( iss, mfcov ).value );
        }
      }
    } // WHEN

    WHEN( "no value is provided" ){
      const int mfcov = 35;
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "the default value can be verified" ){
        REQUIRE( -1 ==
         argument::extract< ERRORR::Rest::Card7::Ifissp >( iss, mfcov ).value );
      }
    } // WHEN

    WHEN( "mfcov != 35" ){
      for( auto i : {31, 33, 34, 40} ){
        for( auto j : {-10, 0} ){
          iRecordStream<char> iss( std::istringstream( std::to_string( j ) ) );

          THEN( "the value doesn't matter, but can be verified" ){
            REQUIRE( j == argument::extract< ERRORR::Rest::Card7::Ifissp >(
                                                               iss, i ).value );
          }
        }
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "invalid values are provided" ){
      const int mfcov = 35;
      for( auto i : {-2, 0} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS(
               argument::extract< ERRORR::Rest::Card7::Ifissp >( iss, mfcov ) );
        }
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
