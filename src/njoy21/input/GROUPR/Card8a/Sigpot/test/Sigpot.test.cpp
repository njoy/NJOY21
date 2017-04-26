#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Sigpot  output values", "[GROUPR],[Card8a], [Sigpot]"){
  GIVEN( "valid sigpot values" ){
    std::vector<double> validValues{1.0, 1E3, 1E5};

    THEN( "the returned class has the correct value" ){
      for( auto& sigpot : validValues ){
        iRecordStream<char> iss(
            std::istringstream( std::to_string(sigpot) ) );

        REQUIRE( sigpot*dimwits::barn == 
                argument::extract< GROUPR::Card8a::Sigpot >( iss ).value );
      }
    }
  }
  GIVEN( "invalid sigpot values" ){
    std::vector<double> invalidValues{-1.0, 0};

    THEN( "an exception is thrown" ){
      for( auto& sigpot : invalidValues ){
        iRecordStream<char> iss(
            std::istringstream( std::to_string(sigpot) ) );

        REQUIRE_THROWS( argument::extract< GROUPR::Card8a::Sigpot >( iss ) );
      }
    }
  }
}
