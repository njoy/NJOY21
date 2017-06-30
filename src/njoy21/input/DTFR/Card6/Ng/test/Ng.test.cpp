#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "DTFR ng values",
         "[DTFR],[Card6], [Ng]"){

  GIVEN( "valid ng values" ){
    std::vector<int> validValues{1, 2};
    THEN( "the returned class has the correct value" ){
      for( auto& ng : validValues ){
        iRecordStream<char> iss(
            std::istringstream( std::to_string(ng) ) );
        REQUIRE( ng == argument::extract< 
          DTFR::Card6::Ng >( iss ).value );
      }
    } // THEN
  } // GIVEN

  GIVEN( "invalid ng values" ){
    std::vector<int> invalidValues{0, -1};
    THEN( "an exception is thrown" ){
      for( auto& ng : invalidValues ){
        iRecordStream<char> iss( 
          std::istringstream( std::to_string(ng) ) );
        REQUIRE_THROWS( argument::extract< 
          DTFR::Card6::Ng >( iss ) );
      }
    } // THEN
  } // GIVEN

  GIVEN( "no input ng value" ){
    THEN( "default value is used" ){
      iRecordStream<char> iss(
        std::istringstream( " /" ) );
      REQUIRE( 30 == argument::extract< 
        DTFR::Card6::Ng >( iss ).value );
    } // THEN
  } // GIVEN
} // SCENARIO
