#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "MATXSR Card3 npart",
          "[MATXSR], [Card3], [Npart]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      for( int i : {1,2,3,4,5,6,7,8,9} ){
        iRecordStream<char> iss( std::istringstream( std::to_string(i) ) );

        THEN( "the value can be verified" ){
          REQUIRE( i == argument::extract< MATXSR::Card3::Npart >( iss ).value );
        }
      }
    }
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< MATXSR::Card3::Npart >( iss ) );
      }
    }

    WHEN( "invalid values are provided" ){
      for( int i : {-1,0,10} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( argument::extract< MATXSR::Card3::Npart >( iss ) );
        }
      }
    }
  } // GIVEN
} // SCENARIO
