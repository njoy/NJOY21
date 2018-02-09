#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "CCCCR, CISOTX, Card1, Nsblok",
          "[CCCCR] [CISOTX] [Card1] [Nsblok]" ){
  const int ngroup = 12;
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      for( auto i : {1, ngroup} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "the value can be verified" ){
          REQUIRE( i == argument::extract< CCCCR::CISOTX::Card1::Nsblok >(
                                                          iss, ngroup ).value );
        }
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< CCCCR::CISOTX::Card1::Nsblok >(
                                                                iss, ngroup ) );
      }
    } // WHEN

    WHEN( "invalid values are provided" ){
      for( auto i : {-1, 0, 10, 13} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( argument::extract< CCCCR::CISOTX::Card1::Nsblok >(
                                                                iss, ngroup ) );
        }
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
