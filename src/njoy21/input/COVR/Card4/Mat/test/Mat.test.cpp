#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Card4 mat input values",
  "[COVR], [Card4], [Mat]" ){
  GIVEN( "mat tape values are valid" ){
    std::vector<int> validValues{1, 125, 9998, 9999};
    THEN( "the returned class has the correct tape value" ){
      for( auto mat : validValues ){
        iRecordStream<char> iss(
          std::istringstream( std::to_string( mat ) ) );
        REQUIRE( mat == argument::extract< 
          COVR::Card4::Mat >( iss ).value );
      }
    } // THEN
  } // GIVEN

  GIVEN( "mat tape values are invalid" ){
    std::vector<int> invalidValues{-20, -1, 0, 10000, 10001};
    THEN( "an exception is thrown" ){
      for( auto mat : invalidValues ){
        iRecordStream<char> iss(
          std::istringstream( std::to_string( mat ) ) );
        REQUIRE_THROWS( argument::extract< 
          COVR::Card4::Mat >( iss ) );
      }
    } // THEN
  } // GIVEN
} // SCENARIO
