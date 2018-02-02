#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "LEAPR nss input values", 
  "[LEAPR], [Card6], [Nss]"){
  GIVEN( "valid nss input values" ){
    std::vector<int> validValues{0, 1};
    THEN( "the returned class has the correct value" ){
      for( auto& nss : validValues ){
        iRecordStream<char> iss(
          std::istringstream( std::to_string( nss ) ) );
        REQUIRE( nss == argument::extract< LEAPR::Card6::Nss >( iss ).value );
      }
    } // THEN
  } // GIVEN
  GIVEN( "invalid nss values" ){
    std::vector<int> invalidValues{-1, 2};
    THEN( "an exception is thrown" ){
      for( auto& nss : invalidValues ){
        iRecordStream<char> iss(
          std::istringstream( std::to_string( nss ) ) );
        REQUIRE_THROWS( argument::extract< LEAPR::Card6::Nss >( iss ) );
      }
    } // THEN
  } // GIVEN
} // SCENARIO
