#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "ERRORR, Normal, Card7, Ifissp",
          "[ERRORR] [Normal] [Card7] [Ifissp]" ){
  GIVEN( "valid inputs" ){
    for( auto i : {-1, 1, 10, 100} ){
      std::string situ( "valid input " + std::to_string(i) + " is provided." );
      WHEN( situ.c_str() ){
        const int mfcov = 35;
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "the value can be verified" ){
          REQUIRE( i == argument::extract< ERRORR::Normal::Card7::Ifissp >(
                                                           iss, mfcov ).value );
        }
      } // WHEN
    }

    WHEN( "no value is provided" ){
      const int mfcov = 35;
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "the default value can be verified" ){
        REQUIRE( -1 == argument::extract< ERRORR::Normal::Card7::Ifissp >(
                                                           iss, mfcov ).value );
      }
    } // WHEN

    for( auto i : {31, 33, 34, 40} ){
      for( auto j : {-10, 0} ){
        std::string situ( " mfcov == " + std::to_string(i) + " and ifissp == " +
                          std::to_string(j) );
        WHEN( situ.c_str() ){
          iRecordStream<char> iss( std::istringstream( std::to_string( j ) ) );

          THEN( "the value doesn't matter, but can be verified" ){
            REQUIRE( j == argument::extract< ERRORR::Normal::Card7::Ifissp >(
                                                               iss, i ).value );
          }
        } // WHEN
      }
    }
  } // GIVEN

  GIVEN( "invalid inputs" ){
    for( auto i : {-2, 0} ){
      std::string situ( "invalid value " + std::to_string(i) + " is provided.");
      WHEN( situ.c_str() ){
        const int mfcov = 35;
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS(
             argument::extract< ERRORR::Normal::Card7::Ifissp >( iss, mfcov ) );
        }
      } // WHEN
    }
  } // GIVEN
} // SCENARIO
