#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "MATXSR Card10 Matgg",
          "[MATXSR], [Card10], [Matgg]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid values are provided" ){
      for( int i : { 1, 10, 100, 1000, 10000 } ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "the value can be verified" ){
          REQUIRE( i == argument::extract< MATXSR::Card10::Matgg >( iss, 1 ).value );
        }
      }
    }

    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "the default is returned based on the matno value" ){
        REQUIRE( 1000 == argument::extract< MATXSR::Card10::Matgg >( iss, 1000 ).value );
      }
    }
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "invalid inputs are provided ( zero )" ){
      iRecordStream<char> iss( std::istringstream( std::to_string( 0 ) ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< MATXSR::Card10::Matgg >( iss, 100 ) );
      }
    }
  } // GIVEN
} // SCENARIO
