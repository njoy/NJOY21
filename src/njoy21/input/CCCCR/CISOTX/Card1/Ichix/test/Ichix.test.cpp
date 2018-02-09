#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "CCCCR, CISOTX, Card1, Ichix",
          "[CCCCR] [CISOTX] [Card1] [Ichix]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      for( auto i = -1; i < 6; i++ ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "the value can be verified" ){
          REQUIRE( i == argument::extract< CCCCR::CISOTX::Card1::Ichix >(
                                                                  iss ).value );
        }
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS(argument::extract< CCCCR::CISOTX::Card1::Ichix >( iss ));
      }
    } // WHEN

    WHEN( "invalid values are provided" ){
      iRecordStream<char> iss( std::istringstream( " -2 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS(argument::extract< CCCCR::CISOTX::Card1::Ichix >( iss ));
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
