#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "ERRORR, Rest, Card7, Mfcov",
          "[ERRORR] [Rest] [Card7] [Mfcov]" ){
  GIVEN( "valid inputs" ){
    const int ngout = 35;
    WHEN( "valid inputs are provided" ){
      for( auto i : {-33, 31, 33, 34, 35, 40, 333} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "the value can be verified" ){
          REQUIRE( i ==
          argument::extract< ERRORR::Rest::Card7::Mfcov >( iss, ngout ).value );
        }
      }
    } // WHEN

    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "the default value can be provided" ){
        REQUIRE( 33 == argument::extract< ERRORR::Rest::Card7::Mfcov >(
                                                           iss, ngout ).value );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "valid values are provided but ngout can't equal zero" ){
      const int ngout = 0;
      for( auto i : {31, 35, 40} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( argument::extract< ERRORR::Rest::Card7::Mfcov >(
                                                                 iss, ngout ) );
        }
      }
    } // WHEN

    WHEN( "invalid values are provided" ){
      const int ngout = 35;
      for( auto i : {30, 32, 36, 39, 41} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( argument::extract< ERRORR::Rest::Card7::Mfcov >(
                                                                 iss, ngout ) );
        }
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
