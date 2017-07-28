#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "LEAPR Card5 ncold input values", 
  "[LEAPR], [Card5], [Ncold]"){
  GIVEN( "valid ncold input values" ){
    WHEN( "ncold input provided" ){
      std::vector<int> validValues{0, 1, 3, 4};
      THEN( "the returned class has the correct value" ){
        for( auto& ncold : validValues ){
          iRecordStream<char> iss(
            std::istringstream( std::to_string( ncold ) ) );
          REQUIRE( ncold == argument::extract< 
            LEAPR::Card5::Ncold >( iss ).value );
        }
      } // THEN
    } // WHEN
    WHEN( "no ncoldd input provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );
      THEN( "default value is used" ){
        REQUIRE( 0 == argument::extract< LEAPR::Card5::Ncold >( iss ).value );
      } // THEN
    } // WHEN
  } // GIVEN
  GIVEN( "invalid ncold values" ){
    std::vector<int> invalidValues{-1, 5};
    THEN( "an exception is thrown" ){
      for( auto& ncold : invalidValues ){
        iRecordStream<char> iss(
          std::istringstream( std::to_string( ncold ) ) );
        REQUIRE_THROWS( argument::extract< LEAPR::Card5::Ncold >( iss ) );
      }
    } // THEN
  } // GIVEN
} // SCENARIO
