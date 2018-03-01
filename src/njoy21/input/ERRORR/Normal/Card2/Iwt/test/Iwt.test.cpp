#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "ERRORR, Normal, Card2, Iwt",
          "[ERRORR] [Normal] [Card2] [Iwt]" ){
  GIVEN( "valid inputs" ){
    for( auto i : {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12} ){
      std::string situ( "valid input " + std::to_string(i) + " is provided." );
      WHEN( situ.c_str() ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "the value can be verified" ){
          REQUIRE( i ==
                 argument::extract< ERRORR::Normal::Card2::Iwt >( iss ).value );
        }
      } // WHEN
    }

    WHEN( "no input is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) ) ;

      THEN( "the default value can be verified" ){
        REQUIRE( 6 ==
                 argument::extract< ERRORR::Normal::Card2::Iwt >( iss ).value );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    for( auto i : {0, 13} ){
      std::string situ( "invalid input " + std::to_string(i) + " is provided.");
      WHEN( situ.c_str() ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS(
                       argument::extract< ERRORR::Normal::Card2::Iwt >( iss ) );
        }
      } // WHEN
    }
  } // GIVEN
} // SCENARIO
