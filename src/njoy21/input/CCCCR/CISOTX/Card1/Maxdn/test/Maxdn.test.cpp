#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "CCCCR, CISOTX, Card1, Maxdn",
          "[CCCCR] [CISOTX] [Card1] [Maxdn]" ){
  const int ngroup = 12;
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      for( auto i = 0; i < ngroup+1; i++ ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "the value can be verified" ){
          REQUIRE( i == argument::extract< CCCCR::CISOTX::Card1::Maxdn >(
                                                          iss, ngroup ).value );
        }
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< CCCCR::CISOTX::Card1::Maxdn >(
                                                                iss, ngroup ) );
      }
    } // WHEN

    WHEN( "invalid inputs are provided" ){
      for( auto i : {-1, ngroup+1} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( argument::extract< CCCCR::CISOTX::Card1::Maxdn >(
                                                                iss, ngroup ) );
        }
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
