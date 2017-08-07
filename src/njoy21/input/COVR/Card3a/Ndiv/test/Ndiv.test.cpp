#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "ndiv output values",
  "[COVR], [Card3a], [Ndiv]"){
  GIVEN( "valid inputs for ndiv" ){
    WHEN( "the ndiv value is provided" ){
      std::vector<int> validValues{1, 2, 5};
      THEN( "the returned class has the correct tape value" ){
        for( auto& ndiv : validValues ){
          iRecordStream<char> iss(
            std::istringstream( std::to_string( ndiv ) ) );
          REQUIRE( ndiv == argument::extract< 
            COVR::Card3a::Ndiv >( iss ).value );
        }
      } // THEN
    } // WHEN

    WHEN( "no ndiv value given " ){
      THEN( "default value is substituted in" ){
        iRecordStream<char> iss( std::istringstream( "  /" ) );
        REQUIRE( 1 == argument::extract<
          COVR::Card3a::Ndiv > ( iss ).value );
      } // THEN
    } // WHEN
  
    WHEN( "ndiv tapes are out of range" ){
      std::vector<int> invalidValues{0, -1, -2};
      THEN( "an exception is thrown" ){
        for( auto& ndiv : invalidValues ){
          iRecordStream<char> iss(
            std::istringstream( std::to_string( ndiv ) ) );
          REQUIRE_THROWS( argument::extract<
            COVR::Card3a::Ndiv>( iss ) );
        }
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO

