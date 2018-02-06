#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "MATXSR Card10 matno",
          "[MATXSR], [Card10], [Matno]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid values are provided" ){
      for( int i : {1,10,100,1000,9999} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "the value is verified" ){
          REQUIRE( i == argument::extract< MATXSR::Card10::Matno >( iss ).value );
        }
      }
    }
  } // GIVEN

  GIVEN( "invalid values" ){
    WHEN( "an invalid value is provided" ){
      for( int i : { 0, 10000 } ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( argument::extract< MATXSR::Card10::Matno >( iss ) );
        }
      }
    }

    WHEN( "no value is given" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< MATXSR::Card10::Matno >( iss ) );
      }
    }
  } // GIVEN
} // SCENARIO
