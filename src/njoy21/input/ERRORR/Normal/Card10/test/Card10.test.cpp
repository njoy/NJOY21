#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "ERRORR, Normal, Card10",
          "[ERRORR] [Normal] [Card10]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      iRecordStream<char> iss( std::istringstream( " 100 20 /" ) );

      THEN( "the values can be verified" ){
        ERRORR::Normal::Card10 card10( iss );

        REQUIRE( 100 == card10.mat1.value );
        REQUIRE( 20 == card10.mt1->value );
      }
    } // WHEN

    WHEN( "a material number of zero is provided" ){
      iRecordStream<char> iss( std::istringstream( " 0 /" ) );

      THEN( "the mt value is not expected" ){
        ERRORR::Normal::Card10 card10( iss );

        REQUIRE( 0 == card10.mat1.value );
        REQUIRE( std::nullopt == card10.mt1 );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "no values are provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( ERRORR::Normal::Card10( iss ) );
      }
    } // WHEN

    WHEN( "no mt value is provided with a non-zero material" ){
      iRecordStream<char> iss( std::istringstream( " 100 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( ERRORR::Normal::Card10( iss ) );
      }
    } // WHEN

    WHEN( "an invalid value is provided" ){
      iRecordStream<char> iss( std::istringstream( " 100 1000 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( ERRORR::Normal::Card10( iss ) );
      }
    } // WHEN

    WHEN( "too many values are provided" ){
      iRecordStream<char> iss( std::istringstream( " 100 10 1 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( ERRORR::Normal::Card10( iss ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
