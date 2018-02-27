#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "ERRORR, Normal, Card8, Nek",
          "[ERRORR] [Normal] [Card8] [Nek]" ){
  GIVEN( "valid inputs" ){
    for( auto i : {0, 1, 10, 50} ){
    std::string situ( "valid input " + std::to_string(i) + " is provided." );
      WHEN( situ.c_str() ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "the value can be verified" ){
          REQUIRE( i ==
                 argument::extract< ERRORR::Normal::Card8::Nek >( iss ).value );
        }
      } // WHEN
    }
  } // GIVEN

  GIVEN( "invalid values" ){
    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< ERRORR::Normal::Card8::Nek >( iss ));
      }
    } // WHEN

    for( auto i : {-1, 51} ){
      std::string situ( "invalid value " + std::to_string(i) + " is provided.");
      WHEN( situ.c_str() ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( argument::extract< ERRORR::Normal::Card8::Nek >(
                                                                        iss ) );
        }
      } // WHEN
    }
  } // GIVEN
} // SCENARIO
