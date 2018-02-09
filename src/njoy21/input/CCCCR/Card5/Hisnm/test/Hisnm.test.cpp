#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "CCCCR, Card5, Hisnm",
          "[CCCCR] [Card5] [Hisnm]" ){
  GIVEN( "valid inputs" ){
    WHEN( "a valid input is provided" ){
      iRecordStream<char> iss( std::istringstream( " '123456'/ " ) );

      THEN( "the value can be verified" ){
        REQUIRE( "123456" == argument::extract< CCCCR::Card5::Hisnm >(
                                                                  iss ).value );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< CCCCR::Card5::Hisnm >( iss ) );
      }
    } // WHEN

    WHEN( "an invalid value is provided" ){
      iRecordStream<char> iss( std::istringstream( " '1234567'/ " ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< CCCCR::Card5::Hisnm >( iss ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
