#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Alpha2  output values", "[GROUPR],[Card8a], [Alpha2]"){
  GIVEN( "valid alpha2 values" ){
    std::vector<double> validValues{0, 10, 20, 100};

    THEN( "the returned class has the correct value" ){
      for( auto& alpha2 : validValues ){
        iRecordStream<char> iss(
            std::istringstream( std::to_string(alpha2) ) );

        REQUIRE( 
            alpha2 == argument::extract< GROUPR::Card8a::Alpha2 >( iss ).value );
      }
    }
  }
  GIVEN( "no alpha2 value" ){
    THEN( "the default value is returned" ){
      iRecordStream<char> iss( std::istringstream( "/") );
      REQUIRE( GROUPR::Card8a::Alpha2::defaultValue() == 
                argument::extract< GROUPR::Card8a::Alpha2 >( iss ).value );
    }
  }
  GIVEN( "invalid alpha2 values" ){
    std::vector<double> invalidValues{-2, -1};

    THEN( "an exception is thrown" ){
      for( auto& alpha2 : invalidValues ){
        iRecordStream<char> iss(
            std::istringstream( std::to_string(alpha2) ) );

        REQUIRE_THROWS( argument::extract< GROUPR::Card8a::Alpha2 >( iss ) );
      }
    }
  }
}

