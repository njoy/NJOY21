#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "MATXSR Card10 hmat",
          "[MATXSR], [Card10], [Hmat]" ){
  GIVEN( "valid inputs" ){
    for( std::string i : { "", "12345", "12345678" } ){
      std::string situ( "valid input " + i + " is provided." );
      WHEN( situ.c_str() ){
        iRecordStream<char> iss( std::istringstream( "'" + i + "' /" ) );

        THEN( "the value can be verified" ){
          REQUIRE( i == argument::extract< MATXSR::Card10::Hmat >( iss ).value );
        }
      }
    }
  }  // GIVEN

  GIVEN( "invalid inputs"  ){
    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< MATXSR::Card10::Hmat >( iss ) );
      }
    }

    WHEN( "an invalid value is provided" ){
      iRecordStream<char> iss( std::istringstream( " '123456789' /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< MATXSR::Card10::Hmat >( iss ) );
      }
    }
  } // GIVEN
} // SCENARIO
