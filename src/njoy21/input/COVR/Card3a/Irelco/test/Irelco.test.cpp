#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "irelco output values",
  "[COVR], [Card3a], [Irelco]"){
  GIVEN( "valid inputs for irelco" ){
    WHEN( "the irelco value is provided" ){
      std::vector<int> validValues{0, 1};
      THEN( "the returned class has the correct tape value" ){
        for( auto& irelco : validValues ){
          iRecordStream<char> iss(
            std::istringstream( std::to_string( irelco ) ) );
          REQUIRE( irelco == argument::extract< 
            COVR::Card3a::Irelco >( iss ).value );
        }
      } // THEN
    } // WHEN

    WHEN( "no irelco value given " ){
      THEN( "default value is substituted in" ){
        iRecordStream<char> iss( std::istringstream( "  /" ) );
        REQUIRE( 1 == argument::extract<
          COVR::Card3a::Irelco > ( iss ).value );
      } // THEN
    } // WHEN
  
    WHEN( "irelco tapes are out of range" ){
      std::vector<int> invalidValues{-1, 2, 3};
      THEN( "an exception is thrown" ){
        for( auto& irelco : invalidValues ){
          iRecordStream<char> iss(
            std::istringstream( std::to_string( irelco ) ) );
          REQUIRE_THROWS( argument::extract<
            COVR::Card3a::Irelco>( iss ) );
        }
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO

