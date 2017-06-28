#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Jsigz  output values", "[GROUPR],[Card8a], [Jsigz]"){
  GIVEN( "valid jsigz values" ){
    std::vector<int> validValues{0, 10, 20, 100};

    THEN( "the returned class has the correct value" ){
      for( auto& jsigz : validValues ){
        iRecordStream<char> iss(
            std::istringstream( std::to_string(jsigz) ) );

        REQUIRE( 
            jsigz == argument::extract< GROUPR::Card8a::Jsigz >( iss ).value );
      }
    }
  }
  GIVEN( "no jsigz value" ){
    THEN( "the default value is returned" ){
      iRecordStream<char> iss( std::istringstream( "/") );
      REQUIRE( 0 == argument::extract< GROUPR::Card8a::Jsigz >( iss ).value );
    }
  }
  GIVEN( "invalid jsigz values" ){
    std::vector<int> invalidValues{-2, -1};

    THEN( "an exception is thrown" ){
      for( auto& jsigz : invalidValues ){
        iRecordStream<char> iss(
            std::istringstream( std::to_string(jsigz) ) );

        REQUIRE_THROWS( argument::extract< GROUPR::Card8a::Jsigz >( iss ) );
      }
    }
  }
}
