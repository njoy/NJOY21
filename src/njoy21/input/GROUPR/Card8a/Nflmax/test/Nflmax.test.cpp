#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Nflmax  output values", "[GROUPR],[Card8a], [Nflmax]"){
  GIVEN( "valid nflmax values" ){
    std::vector<int> validValues{10, 20, 100};

    THEN( "the returned class has the correct value" ){
      for( auto& nflmax : validValues ){
        iRecordStream<char> iss(
            std::istringstream( std::to_string(nflmax) ) );

        REQUIRE( 
            nflmax == argument::extract< GROUPR::Card8a::Nflmax >( iss ).value );
      }
    }
  }
  GIVEN( "invalid nflmax values" ){
    std::vector<int> invalidValues{-1, 0};

    THEN( "an exception is thrown" ){
      for( auto& nflmax : invalidValues ){
        iRecordStream<char> iss(
            std::istringstream( std::to_string(nflmax) ) );

        REQUIRE_THROWS( argument::extract< GROUPR::Card8a::Nflmax >( iss ) );
      }
    }
  }
}
