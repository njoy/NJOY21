#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "ERRORR, Rest, Card2, Ign",
          "[ERRORR] [Rest] [Card2] [Ign]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid values are provided" ){
      for( auto i : {1, 10, 19} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "the value can be verified" ){
          REQUIRE( i ==
                   argument::extract< ERRORR::Rest::Card2::Ign >( iss ).value );
        }
      }
    } // WHEN

    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "the default value can be verified" ){
        REQUIRE( 1 ==
                   argument::extract< ERRORR::Rest::Card2::Ign >( iss ).value );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "invalid values are provided" ){
      for( auto i : {0, 20} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( argument::extract< ERRORR::Rest::Card2::Ign >( iss ));
        }
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
