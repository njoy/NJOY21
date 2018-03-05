#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "MATXSR Card3 ntype",
          "[MATXSR], [Card3], [Ntype]" ){
  GIVEN( "valid inputs" ){
    for( int i : {0,1,2,3,4,5,6,7,8,9} ){
      std::string situ( "valid input " + std::to_string(i) + " is provided." );
      WHEN( situ.c_str() ){
        iRecordStream<char> iss( std::istringstream( std::to_string(i) ) );

        THEN( "the value can be verified" ){
          REQUIRE( i == argument::extract< MATXSR::Card3::Ntype >( iss ).value );
        }
      }
    }
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< MATXSR::Card3::Ntype >( iss ) );
      }
    }

    WHEN( "invalid values are provided" ){
      iRecordStream<char> iss( std::istringstream( std::to_string( -1 ) ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< MATXSR::Card3::Ntype >( iss ) );
      }
    }
  } // GIVEN
} // SCENARIO
