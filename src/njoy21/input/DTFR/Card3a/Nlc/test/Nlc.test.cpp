#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "DTFR nlc values",
  "[DTFR],[Card3a], [Nlc]"){

  GIVEN( "valid nlc values" ){
    std::vector<int> validValues{0, 1, 456, 999};

    THEN( "the returned class has the correct value" ){
      for( auto& nlc : validValues ){
        iRecordStream<char> iss(
          std::istringstream( std::to_string(nlc) ) );
        REQUIRE( nlc == argument::extract< 
          DTFR::Card3a::Nlc >( iss ).value );
      }
    } // THEN
  } // GIVEN

  GIVEN( "invalid nlc values" ){
    std::vector<int> invalidValues{-1, -2};

    THEN( "an exception is thrown" ){
      for( auto& nlc : invalidValues ){
        iRecordStream<char> iss(
          std::istringstream( std::to_string(nlc) ) );
        REQUIRE_THROWS( argument::extract< DTFR::Card3a::Nlc >( iss ) );
      }
    } // THEN
  } // GIVEN
  
  GIVEN( "no nlc value provided" ){
    THEN( "default value used" ){
      iRecordStream<char> iss( 
        std::istringstream( " /" ) );
      REQUIRE( 0 == argument::extract< 
        DTFR::Card3a::Nlc >( iss ).value );
    } // THEN
  } // GIVEN
} // SCENARIO
