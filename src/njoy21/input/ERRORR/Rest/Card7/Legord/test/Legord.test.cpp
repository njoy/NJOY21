#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "ERRORR, Rest, Card7, Legord",
          "[ERRORR] [Rest] [Card7] [Legord]" ){
  GIVEN( "valid inputs" ){
    WHEN( "a valid input is provided" ){
      iRecordStream<char> iss( std::istringstream( " 1 /" ) );

      THEN( "the value can be verified" ){
        REQUIRE( 1 ==
                argument::extract< ERRORR::Rest::Card7::Legord >( iss ).value );
      }
    } // WHEN

    WHEN( "no input is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "the default value is provided" ){
        REQUIRE( 1 ==
                argument::extract< ERRORR::Rest::Card7::Legord >( iss ).value );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "invalid values are provided" ){
      for( auto i : {0, 2} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS(
                      argument::extract< ERRORR::Rest::Card7::Legord >( iss ) );
        }
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
