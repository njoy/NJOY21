#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "ERRORR, Normal, Card2, Ign",
          "[ERRORR] [Normal] [Card2] [Ign]" ){
  GIVEN( "valid inputs" ){
    for( int i = 1; i < 20; i++ ){
      std::string situ( "valid input " + std::to_string(i) + " is provided." );
      WHEN( situ.c_str() ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "the value can be verified" ){
          REQUIRE( i ==
                 argument::extract< ERRORR::Normal::Card2::Ign >( iss ).value );
        }
      } // WHEN
    }

    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "the default value can be verified" ){
        REQUIRE( 1 ==
                 argument::extract< ERRORR::Normal::Card2::Ign >( iss ).value );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    for( auto i : {0, 20} ){
      std::string situ( "invalid input " + std::to_string(i) + " is provided.");
      WHEN( situ.c_str() ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS(
                       argument::extract< ERRORR::Normal::Card2::Ign >( iss ) );
        }
      } // WHEN
    }
  } // GIVEN
} // SCENARIO
