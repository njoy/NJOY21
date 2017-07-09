#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Fehi  output values", "[GROUPR],[Card8a], [Fehi]"){
  GIVEN( "valid fehi values" ){
    std::vector<double> validValues{1.0, 1E3, 1E5};

    THEN( "the returned class has the correct value" ){
      for( auto& fehi : validValues ){
        iRecordStream<char> iss(
            std::istringstream( std::to_string(fehi) ) );

        REQUIRE( fehi*dimwits::electronVolt == 
                argument::extract< GROUPR::Card8a::Fehi >( iss ).value );
      }
    }
  }
  GIVEN( "invalid fehi values" ){
    std::vector<double> invalidValues{-1.0, 0};

    THEN( "an exception is thrown" ){
      for( auto& fehi : invalidValues ){
        iRecordStream<char> iss(
            std::istringstream( std::to_string(fehi) ) );

        REQUIRE_THROWS( argument::extract< GROUPR::Card8a::Fehi >( iss ) );
      }
    }
  }
}
