#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "CCCCR, Card4, Niso",
          "[CCCCR] [Card4] [Niso]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      for( auto i : {1, 10, 100, 200} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "the value can be verified" ){
          REQUIRE( i == argument::extract< CCCCR::Card4::Niso >( iss ).value );
        }
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< CCCCR::Card4::Niso >( iss ) );
      }
    } // WHEN

    WHEN( "an invalid value is provided" ){
      for( auto i : {0, 201} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );
  
        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( argument::extract< CCCCR::Card4::Niso >( iss ) );
        }
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
