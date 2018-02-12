#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "ERRORR, Dummy, Card3, Mt",
          "[ERRORR] [Dummy] [Card3] [Mt]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      for( auto i : {0, 1, 10, 100, 1000, 9999} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "the value can be verified" ){
          REQUIRE( i ==
                   argument::extract< ERRORR::Dummy::Card3::Mt >( iss ).value );
        }
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< ERRORR::Dummy::Card3::Mt >( iss ) );
      }
    } // WHEN

    WHEN( "invalid values are provided" ){
      for( auto i : {-1, 10000} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( argument::extract< ERRORR::Dummy::Card3::Mt >( iss ));
        }
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
