#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "MATXSR Card2 ivers",
          "[MATXSR], [Card2], [Ivers]" ){

  GIVEN( "valid inputs" ){
    for( unsigned int i : { 0, 1, 301 } ){
      std::string situ( "valid input " + std::to_string(i) + " is provided." );
      WHEN( situ.c_str() ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "the value can be verified" ){
          REQUIRE( i == argument::extract< MATXSR::Card2::Ivers >( iss ).value );
        }
      }
    }

    WHEN( "no input is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "the default value is returned" ){
        REQUIRE( 0 == argument::extract< MATXSR::Card2::Ivers >( iss ).value );
      }
    }
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "an invalid input is provided" ){
      iRecordStream<char> iss( std::istringstream( " -1 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< MATXSR::Card2::Ivers >( iss ) );
      }
    }
  } // GIVEN
} // SCENARIO
