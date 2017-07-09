#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Matd  output values", "[GROUPR],[Card10], [Matd]"){
  GIVEN( "valid matd values" ){
    std::vector<int> validValues{0, 1001, 1, 9238, 9999};

    THEN( "the returned class has the correct value" ){
      for( auto& matd : validValues ){
        iRecordStream<char> iss(
            std::istringstream( std::to_string(matd) ) );

        REQUIRE( 
          matd == argument::extract< GROUPR::Card10::Matd >( iss ).value );
      }
    }
  }
  GIVEN( "invalid matd values" ){
    std::vector<int> invalidValues{-1, -2, 10000};

    THEN( "an exception is thrown" ){
      for( auto& matd : invalidValues ){
        iRecordStream<char> iss(
            std::istringstream( std::to_string(matd) ) );

        REQUIRE_THROWS( argument::extract< GROUPR::Card10::Matd >( iss ) );
      }
    }
  }
}
