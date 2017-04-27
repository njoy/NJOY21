#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Beta  output values", "[GROUPR],[Card8a], [Beta]"){
  GIVEN( "valid beta values" ){
    std::vector<double> validValues{0, 10, 20, 100};

    THEN( "the returned class has the correct value" ){
      for( auto& beta : validValues ){
        iRecordStream<char> iss(
            std::istringstream( std::to_string(beta) ) );

        REQUIRE( 
            beta == argument::extract< GROUPR::Card8a::Beta >( iss ).value );
      }
    }
  }
  GIVEN( "no beta value" ){
    THEN( "the default value is returned" ){
      iRecordStream<char> iss( std::istringstream( "/") );
      REQUIRE( GROUPR::Card8a::Beta::defaultValue() == 
                argument::extract< GROUPR::Card8a::Beta >( iss ).value );
    }
  }
  GIVEN( "invalid beta values" ){
    std::vector<double> invalidValues{-2, -1};

    THEN( "an exception is thrown" ){
      for( auto& beta : invalidValues ){
        iRecordStream<char> iss(
            std::istringstream( std::to_string(beta) ) );

        REQUIRE_THROWS( argument::extract< GROUPR::Card8a::Beta >( iss ) );
      }
    }
  }
}
