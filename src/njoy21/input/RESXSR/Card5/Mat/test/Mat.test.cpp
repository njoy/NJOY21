#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "RESXSR card5 mat",
          "[Card5], [Hmat]" ){

  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      for( auto mat : {0,1,10,100,9999} ){
        iRecordStream<char> issMat( std::istringstream( std::to_string( mat ) ) );

        THEN( "the value can be verified" ){
          REQUIRE( mat ==
                   argument::extract< RESXSR::Card5::Mat >( issMat ).value );
        }
      }
    }
  }

  GIVEN( "invalid inputs" ){
    WHEN( "invalid values are used" ){
      for( auto mat : {-1,10000} ){
        iRecordStream<char> issMat( std::istringstream( std::to_string( mat ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( argument::extract< RESXSR::Card5::Mat >( issMat ) );
        }
      }
    }

    WHEN( "no value is provided" ){
      iRecordStream<char> issMat( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< RESXSR::Card5::Mat >( issMat ) );
      }
    }
  } // GIVEN
} // SCENARIO
