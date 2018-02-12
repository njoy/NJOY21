#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "ERRORR, Card1, Nendf",
          "[ERRORR] [Card1] [Nendf]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      for( auto i : {-99, -40, -20, 20, 49, 99, 999} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "the value can be verified" ){
          REQUIRE( i == argument::extract< ERRORR::Card1::Nendf >( iss ).value);
        }
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "no input is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< ERRORR::Card1::Nendf >( iss ) );
      }
    } // WHEN

    WHEN( "invalid values are provided" ){
      for( auto i : {-999, -100, -19, 0, 19, 100} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( argument::extract< ERRORR::Card1::Nendf >( iss ) );
        }
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
