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

        std::string situ( "the value " + std::to_string( unit ) +
                                                          " can be verified." );
        THEN( situ.c_str() ){
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

        std::string situ( "an exception is thrown for invalid value " +
                                                       std::to_string( unit ) );
        THEN( situ.c_str() ){
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
