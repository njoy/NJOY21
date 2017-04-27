#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Alpha3  output values", "[GROUPR],[Card8a], [Alpha3]"){
  GIVEN( "valid alpha3 values" ){
    std::vector<double> validValues{0, 10, 20, 100};

    THEN( "the returned class has the correct value" ){
      for( auto& alpha3 : validValues ){
        iRecordStream<char> iss(
            std::istringstream( std::to_string(alpha3) ) );

        REQUIRE( 
            alpha3 == argument::extract< GROUPR::Card8a::Alpha3 >( iss ).value );
      }
    }
  }
  GIVEN( "no alpha3 value" ){
    THEN( "the default value is returned" ){
      iRecordStream<char> iss( std::istringstream( "/") );
      REQUIRE( GROUPR::Card8a::Alpha3::defaultValue() == 
                argument::extract< GROUPR::Card8a::Alpha3 >( iss ).value );
    }
  }
  GIVEN( "invalid alpha3 values" ){
    std::vector<double> invalidValues{-2, -1};

    THEN( "an exception is thrown" ){
      for( auto& alpha3 : invalidValues ){
        iRecordStream<char> iss(
            std::istringstream( std::to_string(alpha3) ) );

        REQUIRE_THROWS( argument::extract< GROUPR::Card8a::Alpha3 >( iss ) );
      }
    }
  }
}
