#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "CCCCR, CBRKXS, Card1, Nzi",
          "[CCCCR] [CBRKXS] [Card1] [Nzi]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      for( auto i : { -20, -10, -1, 1, 10, 20 } ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "the value can be verified" ){
          REQUIRE( i ==
                  argument::extract< CCCCR::CBRKXS::Card1::Nzi >( iss ).value );
        }
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< CCCCR::CBRKXS::Card1::Nzi >( iss ) );
      }
    } // WHEN

    WHEN( "invalid values are provided" ){
      for( auto i : { -21, 0, 21 } ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( argument::extract< CCCCR::CBRKXS::Card1::Nzi >(iss) );
        }
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
