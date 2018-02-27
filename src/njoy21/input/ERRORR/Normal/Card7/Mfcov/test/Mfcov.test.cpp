#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "ERRORR, Normal, Card7, Mfcov",
          "[ERRORR] [Normal] [Card7] [Mfcov]" ){
  GIVEN( "valid inputs" ){
    const int ngout = 35;
    for( auto i : {-33, 31, 33, 34, 35, 40, 333} ){
      std::string situ( "valid input " + std::to_string(i) + " is provided." );
      WHEN( situ.c_str() ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "the value can be verified" ){
          REQUIRE( i == argument::extract< ERRORR::Normal::Card7::Mfcov >(
                                                           iss, ngout ).value );
        }
      } // WHEN
    }

    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "the default value can be provided" ){
        REQUIRE( 33 == argument::extract< ERRORR::Normal::Card7::Mfcov >(
                                                           iss, ngout ).value );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    for( auto i : {31, 35, 40} ){
      std::string situ( "valid value " + std::to_string(i) +
                                                "but ngout can't equal zero." );
      WHEN( situ.c_str() ){
        const int ngout = 0;
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( argument::extract< ERRORR::Normal::Card7::Mfcov >(
                                                                 iss, ngout ) );
        }
      } // WHEN
    }

    for( auto i : {30, 32, 36, 39, 41} ){
      std::string situ( "invalid value " + std::to_string(i) + " is provided.");
      WHEN( situ.c_str() ){
        const int ngout = 35;
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( argument::extract< ERRORR::Normal::Card7::Mfcov >(
                                                                 iss, ngout ) );
        }
      } // WHEN
    }
  } // GIVEN
} // SCENARIO
