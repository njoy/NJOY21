#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Sam  output values", "[GROUPR],[Card8a], [Sam]"){
  GIVEN( "valid sam values" ){
    std::vector<double> validValues{0, 10, 20, 100};

    THEN( "the returned class has the correct value" ){
      for( auto& sam : validValues ){
        iRecordStream<char> iss(
            std::istringstream( std::to_string(sam) ) );

        REQUIRE( sam*dimwits::barn == 
                argument::extract< GROUPR::Card8a::Sam >( iss ).value );
      }
    }
  }
  GIVEN( "no sam value" ){
    THEN( "the default value is returned" ){
      iRecordStream<char> iss( std::istringstream( "/") );
      REQUIRE( GROUPR::Card8a::Sam::defaultValue() == 
                argument::extract< GROUPR::Card8a::Sam >( iss ).value );
    }
  }
  GIVEN( "invalid sam values" ){
    std::vector<double> invalidValues{-2, -1};

    THEN( "an exception is thrown" ){
      for( auto& sam : invalidValues ){
        iRecordStream<char> iss(
            std::istringstream( std::to_string(sam) ) );

        REQUIRE_THROWS( argument::extract< GROUPR::Card8a::Sam >( iss ) );
      }
    }
  }
}

