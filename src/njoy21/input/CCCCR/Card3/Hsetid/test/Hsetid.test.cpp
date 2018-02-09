#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "CCCCR, Card3, Hsetid",
          "[CCCCR] [Card3] [Hsetid]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      for( std::string s : {"1234","123456789012"} ){
        std::string inp( "'" + s + "'/" );
        iRecordStream<char> iss{ std::istringstream{ inp } };

        THEN( "the values can be verified" ){
          REQUIRE( s == argument::extract< CCCCR::Card3::Hsetid >( iss ).value);
        }
      }
    } // WHEN

    WHEN( "no input is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "the default can be verified" ){
        REQUIRE( "" == argument::extract< CCCCR::Card3::Hsetid >( iss ).value );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "an invalid inputs is provided" ){
      iRecordStream<char> iss( std::istringstream( "'1234567890123'/" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< CCCCR::Card3::Hsetid >( iss ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
