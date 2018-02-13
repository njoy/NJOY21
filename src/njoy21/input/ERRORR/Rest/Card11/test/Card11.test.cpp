#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "ERRORR, Rest, Card11",
          "[ERRORR] [Rest] [Card11]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      iRecordStream<char> iss( std::istringstream( " 100 10 200 20 /" ) );

      THEN( "the values can be verified" ){
        ERRORR::Rest::Card11 card11( iss );

        REQUIRE( 100 == card11.matb.value );
        REQUIRE( 10 == std::get<0>( *( card11.rest ) ).value );
        REQUIRE( 200 == std::get<1>( *( card11.rest ) ).value );
        REQUIRE( 20 == std::get<2>( *( card11.rest ) ).value );
      }
    } // WHEN

    WHEN( "a material value of zero is provided" ){
      iRecordStream<char> iss( std::istringstream( " 0 /" ) );

      THEN( "the values can be verified" ){
        ERRORR::Rest::Card11 card11( iss );

        REQUIRE( 0 == card11.matb.value );
        REQUIRE( std::nullopt == card11.rest );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "too few values are provided" ){
      iRecordStream<char> iss( std::istringstream( " 100 10 200 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( ERRORR::Rest::Card11( iss ) );
      }
    } // WHEN

    WHEN( "too many values are provided" ){
      iRecordStream<char> iss( std::istringstream( " 100 10 200 20 300 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( ERRORR::Rest::Card11( iss ) );
      }
    } // WHEN

    WHEN( "an invalid value is provided" ){
      iRecordStream<char> iss( std::istringstream( " 100 10 200 -1 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( ERRORR::Rest::Card11( iss ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
