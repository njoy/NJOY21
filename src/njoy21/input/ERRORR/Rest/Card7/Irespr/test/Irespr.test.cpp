#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "ERRORR, Rest, Card7, Irespr",
          "[ERRORR] [Rest] [Card7] [Irespr]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      const int mfcov = 33;
      for( auto i : {0, 1} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "the value can be verified" ){
          REQUIRE( i == argument::extract< ERRORR::Rest::Card7::Irespr >(
                                                           iss, mfcov ).value );
        }
      }
    } // WHEN

    WHEN( "no value is provided" ){
      const int mfcov = 33;
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "the default value can be verified" ){
        REQUIRE( 1 == argument::extract< ERRORR::Rest::Card7::Irespr >(
                                                           iss, mfcov ).value );
      }
    } // WHEN

    WHEN( "mfcov != 33, the input value is ignored" ){
      for( auto i : {31, 34, 35, 40} ){
        for( auto j : {-2, -1, 0, 1, 2, 3} ){
          iRecordStream<char> iss( std::istringstream( std::to_string( j ) ) );

          THEN( "the value doesn't matter, but can be verified" ){
            REQUIRE( j == argument::extract< ERRORR::Rest::Card7::Irespr >(
                                                               iss, i ).value );
          }
        }
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "invalid values are provided" ){
      const int mfcov = 33;
      for( auto i : {-1, 2} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS(
               argument::extract< ERRORR::Rest::Card7::Irespr >( iss, mfcov ) );
        }
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
