#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Gamma  output values", "[GROUPR],[Card8a], [Gamma]"){
  GIVEN( "valid gamma values" ){
    std::vector<double> validValues{0, 10, 20, 100};

    THEN( "the returned class has the correct value" ){
      for( auto& gamma : validValues ){
        iRecordStream<char> iss(
            std::istringstream( std::to_string(gamma) ) );

        REQUIRE( 
            gamma == argument::extract< GROUPR::Card8a::Gamma >( iss ).value );
      }
    }
  }
  GIVEN( "no gamma value" ){
    THEN( "the default value is returned" ){
      iRecordStream<char> iss( std::istringstream( "/") );
      REQUIRE( GROUPR::Card8a::Gamma::defaultValue() == 
                argument::extract< GROUPR::Card8a::Gamma >( iss ).value );
    }
  }
  GIVEN( "invalid gamma values" ){
    std::vector<double> invalidValues{-2, -1};

    THEN( "an exception is thrown" ){
      for( auto& gamma : invalidValues ){
        iRecordStream<char> iss(
            std::istringstream( std::to_string(gamma) ) );

        REQUIRE_THROWS( argument::extract< GROUPR::Card8a::Gamma >( iss ) );
      }
    }
  }
}
