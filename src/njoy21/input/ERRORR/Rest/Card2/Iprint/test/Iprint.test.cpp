#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "ERRORR, Rest, Card2, Iprint",
          "[ERRORR] [Rest] [Card2] [Iprint]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid values are provided" ){
      for( auto i : {0, 1} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "the value can be verified" ){
          REQUIRE( i ==
                argument::extract< ERRORR::Rest::Card2::Iprint >( iss ).value );
        }
      }
    } // WHEN

    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "the default value can be verified" ){
        REQUIRE( 1 ==
                argument::extract< ERRORR::Rest::Card2::Iprint >( iss ).value );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "invalid inputs are provided" ){
      for( auto i : {-1, 2} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS(
                      argument::extract< ERRORR::Rest::Card2::Iprint >( iss ) );
        }
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
