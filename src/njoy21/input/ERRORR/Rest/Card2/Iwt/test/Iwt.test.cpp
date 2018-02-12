#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "ERRORR, Rest, Card2, Iwt",
          "[ERRORR] [Rest] [Card2] [Iwt]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      for( auto i : {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "the value can be verified" ){
          REQUIRE( i ==
                   argument::extract< ERRORR::Rest::Card2::Iwt >( iss ).value );
        }
      }
    } // WHEN

    WHEN( "no input is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) ) ;

      THEN( "the default value can be verified" ){
        REQUIRE( 6 ==
                   argument::extract< ERRORR::Rest::Card2::Iwt >( iss ).value );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "invalid inputs are provided" ){
      for( auto i : {0, 13} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( argument::extract< ERRORR::Rest::Card2::Iwt >( iss ));
        }
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
