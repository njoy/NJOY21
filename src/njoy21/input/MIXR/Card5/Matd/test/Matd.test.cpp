#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Matd output values", 
  "[MIXR], [Card5], [Matd]" ){
  GIVEN( "Valid matd values" ){
    std::vector<int> validValues{1,125,9228,9936};
    THEN( "the returned class has the correct value" ){
      for( auto& matd : validValues ){
        iRecordStream<char> iss( std::istringstream(
          std::to_string( matd ) ) );
        REQUIRE( matd == argument::extract< MIXR::Card5::Matd >( iss ).value );
      }
    }
  }
  GIVEN( "Invalid matd values" ){
    std::vector<int> invalidValues{-125,0,10000};
    THEN( "an exception is thrown" ){
      for( auto& matd : invalidValues ){
        iRecordStream<char> iss( std::istringstream(
          std::to_string( matd ) ) );
        REQUIRE_THROWS( argument::extract< MIXR::Card5::Matd >( iss ) );
      }
    }
  }
}
