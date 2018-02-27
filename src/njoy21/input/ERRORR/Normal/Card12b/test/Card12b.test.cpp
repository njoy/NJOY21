#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "ERRORR, Normal, Card12b",
          "[ERRORR] [Normal] [Card12b]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      iRecordStream<char> iss( std::istringstream( " 1e-6 5e-5 2e-2 1e1 /" ) );

      THEN( "the values can be verified" ){
        ERRORR::Normal::Card12b card12b( iss, 3 );

        REQUIRE( 4 == card12b.egn.value.size() );

        REQUIRE( 1e-6*dimwits::electronVolt == card12b.egn.value.at(0) );
        REQUIRE( 5e-5*dimwits::electronVolt == card12b.egn.value.at(1) );
        REQUIRE( 2e-2*dimwits::electronVolt == card12b.egn.value.at(2) );
        REQUIRE( 1e1*dimwits::electronVolt == card12b.egn.value.at(3) );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "too many values are provided" ){
      iRecordStream<char> iss( std::istringstream( " 1e-6 5e-5 2e-2 1e1 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( ERRORR::Normal::Card12b( iss, 2 ) );
      }
    } // WHEN

    WHEN( "invalid values are provided" ){
      iRecordStream<char> iss( std::istringstream( " 1e-6 2e-2 5e-5 1e1 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( ERRORR::Normal::Card12b( iss, 3 ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
