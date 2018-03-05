#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "MATXSR Card4 hsetid",
          "[MATXSR], [Card4], [hsetid]" ){
  GIVEN( "valid inputs" ){

    for( std::string i : { "", "12345678901234567",
"123456789012345678901234567890123456789012345678901234567890123456789012" } ){
      std::string situ( "valid input " + i + " is provided." );
      WHEN( situ.c_str() ){
        iRecordStream<char> iss( std::istringstream( "'" + i + "'" ) );

        THEN( "the value can be verified" ){
          REQUIRE( i == argument::extract< MATXSR::Card4::Hsetid >( iss ).value );
        }
      }
    }
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "no input" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< MATXSR::Card4::Hsetid >( iss ) );
      }
    }

    WHEN( "an input that is too long is provided" ){
      iRecordStream<char> iss( std::istringstream( 
"'1234567890123456789012345678901234567890123456789012345678901234567890123'" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< MATXSR::Card4::Hsetid >( iss ) );
      }
    }
  } // GIVEN
} // SCENARIO
