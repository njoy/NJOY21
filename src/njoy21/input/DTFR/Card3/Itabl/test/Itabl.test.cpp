#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "DTFR itabl values",
  "[DTFR],[Card3], [Itabl]"){

  GIVEN( "valid itabl values" ){
    std::vector<int> validValues{1, 2};
    THEN( "the returned class has the correct value" ){
      for( int itabl : validValues ){
        iRecordStream<char> iss( 
          std::istringstream( std::to_string(itabl) ) );
        REQUIRE( itabl == argument::extract< 
          DTFR::Card3::Itabl >(iss).value );
      }
    } // THEN
  } // GIVEN

  GIVEN( "invalid itabl values" ){
    std::vector<int> invalidValues{-1, 0};
    THEN( "an exception is thrown" ){
      for( int itabl : invalidValues ){
        iRecordStream<char> iss( 
          std::istringstream( std::to_string(itabl) ) );
        REQUIRE_THROWS( argument::extract< 
          DTFR::Card3::Itabl >( iss ) );
      }
    } // THEN
  } // GIVEN
} // SCENARIO
