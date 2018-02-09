#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "COVR, Card4, Mat1",
          "[COVR] [Card4] [Mat1]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      for( int i : {-9999, -1000, 0, 1000, 9999} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "the value can be verified" ){
          REQUIRE( i == argument::extract< COVR::Card4::Mat1 >( iss ).value );
        }
      }
    } // WHEN

    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "the default value can be verified" ){
        REQUIRE( 0 == argument::extract< COVR::Card4::Mat1 >( iss ).value );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "invalid inputs are provided" ){
      for( int i : {-10000, 10000} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( argument::extract< COVR::Card4::Mat1 >( iss ) );
        }
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
