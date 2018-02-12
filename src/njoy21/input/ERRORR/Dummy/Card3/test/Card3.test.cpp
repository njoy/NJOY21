#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "ERRORR, Dummy, Card3",
          "[ERRORR] [Dummy] [Card3]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      for( auto i : {0, 1, 2, 102, 600} ){
        std::string inp( " " + std::to_string( i ) + " /" );
        iRecordStream<char> iss{ std::istringstream{ inp } };

        THEN( "the values can be verified" ){
          ERRORR::Dummy::Card3 card3( iss );

          REQUIRE( i == card3.mt.value );
        }
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( ERRORR::Dummy::Card3( iss ) );
      }
    } // WHEN

    WHEN( "too many values are provided" ){
      iRecordStream<char> iss( std::istringstream( " 22 403 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( ERRORR::Dummy::Card3( iss ) );
      }
    } // WHEN

    WHEN( "an invalid material number is provided" ){
      iRecordStream<char> iss( std::istringstream( " -19 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( ERRORR::Dummy::Card3( iss ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
