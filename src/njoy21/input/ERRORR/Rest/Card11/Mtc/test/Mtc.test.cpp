#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "ERRORR, Rest, Card11, Mtc",
          "[ERRORR] [Rest] [Card11] [Mtc]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      for( auto i : {1, 10, 100, 999} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "the value can be verified" ){
          REQUIRE( i == argument::extract< ERRORR::Rest::Card11::Mtc >(
                                                                  iss ).value );
        }
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< ERRORR::Rest::Card11::Mtc >( iss ) );
      }
    } // WHEN

    WHEN( "invalid values are provided" ){
      for( auto i : {-1, 0, 1000} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( argument::extract< ERRORR::Rest::Card11::Mtc >(iss) );
        }
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
