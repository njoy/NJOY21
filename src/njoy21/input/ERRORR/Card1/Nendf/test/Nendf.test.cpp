#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "ERRORR, Card1, Nendf",
          "[ERRORR] [Card1] [Nendf]" ){
  GIVEN( "valid inputs" ){
    for( auto i : {-99, -40, -20, 20, 49, 99, 999} ){
      std::string situ( "valid input " + std::to_string(i) + " is provided." );
      WHEN( situ.c_str() ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "the value can be verified" ){
          REQUIRE( i == argument::extract< ERRORR::Card1::Nendf >( iss ).value);
        }
      } // WHEN
    }
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "no input is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< ERRORR::Card1::Nendf >( iss ) );
      }
    } // WHEN

    for( auto i : {-999, -100, -19, 0, 19, 100} ){
      std::string situ( "invalid input " + std::to_string(i) + " is provided.");
      WHEN( "invalid values are provided" ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( argument::extract< ERRORR::Card1::Nendf >( iss ) );
        }
      } // WHEN
    }
  } // GIVEN
} // SCENARIO
