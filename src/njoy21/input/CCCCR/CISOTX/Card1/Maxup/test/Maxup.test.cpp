#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "CCCCR, CISOTX, Card1, Maxup",
          "[CCCCR] [CISOTX] [Card1] [Maxup]" ){
  GIVEN( "valid inputs" ){
    WHEN( "the only value allowed is provided" ){
      iRecordStream<char> iss( std::istringstream( " 0 /" ) );

      THEN( "the value can be verified" ){
        REQUIRE( 0 == argument::extract< CCCCR::CISOTX::Card1::Maxup >(
                                                                  iss ).value );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS(argument::extract< CCCCR::CISOTX::Card1::Maxup >( iss ));
      }
    } // WHEN

    for( auto i : {-1, 1, 5} ){
      std::string situ( "invalid input " + std::to_string(i) + " is provided.");
      WHEN( situ.c_str() ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS(argument::extract< CCCCR::CISOTX::Card1::Maxup >(iss));
        }
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
