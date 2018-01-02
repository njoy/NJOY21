#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "RESXSR card5 unit",
          "[Card5], [Unit]" ){

  GIVEN( "valid input" ){
    WHEN( "valid inputs are provided" ){
      for( auto unit : {-99, -54, -20, 20, 45, 99} ){
        iRecordStream<char> issUnit( std::istringstream( std::to_string( unit ) ) );

        THEN( "the value can be verified" ){
          REQUIRE( unit ==
                   argument::extract< RESXSR::Card5::Unit >( issUnit ).value );
        }
      }
    }
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "invalid values are provided" ){
      for( auto unit : {-100, -19, 0, 19, 100} ){
        iRecordStream<char> issUnit( std::istringstream( std::to_string( unit ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( argument::extract< RESXSR::Card5::Unit >( issUnit ) );
        }
      }
    }

    WHEN( "no value is provided" ){
      iRecordStream<char> issUnit( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< RESXSR::Card5::Unit >( issUnit ) );
      }
    }
  } // GIVEN
} // SCENARIO
