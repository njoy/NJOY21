#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "MIXR, Card2, Mtn",
          "[MIXR] [Card2] [Mtc]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid values are provided" ){
      for( int i : {1, 10, 100, 999} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "the value can be verified" ){
          REQUIRE( i == argument::extract< MIXR::Card2::Mtn >( iss ).value );
        }
      }
    } // WHEN

    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "a predefined, unallowable value is provided" ){
        REQUIRE( 0 == argument::extract< MIXR::Card2::Mtn >( iss ).value );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "invalid values are provided" ){
      for( int i : {-1, 0, 1000} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( argument::extract< MIXR::Card2::Mtn >( iss ) );
        }
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
