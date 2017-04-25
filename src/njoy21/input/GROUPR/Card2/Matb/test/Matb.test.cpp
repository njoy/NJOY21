#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Matb  output values",
         "[GROUPR],[Card2], [Matb]"){
  GIVEN( "valid matb values" ){
    std::vector<int> validValues{1001, 1, 9238};

    THEN( "the returned class has the correct value" ){
      for( auto& matb : validValues ){
        iRecordStream<char> iss(
            std::istringstream( std::to_string(matb) ) );

        REQUIRE( 
          matb == argument::extract< GROUPR::Card2::Matb >( iss ).value );
      }
    }
  }
  GIVEN( "invalid matb values" ){
    std::vector<int> invalidValues{0};

    THEN( "an exception is thrown" ){
      for( auto& matb : invalidValues ){
        iRecordStream<char> iss(
            std::istringstream( std::to_string(matb) ) );

        REQUIRE_THROWS( argument::extract< GROUPR::Card2::Matb >( iss ) );
      }
    }
  }
}

