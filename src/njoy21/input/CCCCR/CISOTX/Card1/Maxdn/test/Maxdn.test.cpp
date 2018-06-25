#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "CCCCR, CISOTX, Card1, Maxdn",
          "[CCCCR] [CISOTX] [Card1] [Maxdn]" ){
  const int ngroup = 12;
  GIVEN( "valid inputs" ){
    for( auto i = 0; i < ngroup+1; i++ ){
      std::string situ( "valid input " + std::to_string(i) + " is provided." );
      WHEN( situ.c_str() ){
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

    for( auto i : {-1, ngroup+1} ){
      std::string situ( "invalid input " + std::to_string(i) + " is provided.");
      WHEN( situ.c_str() ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( argument::extract< CCCCR::CISOTX::Card1::Maxdn >(
                                                                iss, ngroup ) );
        }
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
