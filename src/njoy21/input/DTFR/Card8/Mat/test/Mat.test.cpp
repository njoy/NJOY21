#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Card8 mat input values",
  "[DTFR], [Card8], [Mat]" ){
  GIVEN( "valid mat tape values" ){
    std::vector<int> validValues{1, 2, 125, 9998, 9999};

    THEN( "the returned class has the correct tape value" ){
      for( auto mat : validValues ){
        iRecordStream<char> iss(
          std::istringstream( std::to_string( mat )) );
        REQUIRE( mat == argument::extract< 
          DTFR::Card8::Mat >( iss ).value );
      }
    } // THEN
  } // GIVEN

  GIVEN( "invalid mat tape values" ){
    std::vector<int> invalidValues{-20, 0, 10000, 10001};

    THEN( "an exception is thrown" ){
      for( auto mat : invalidValues ){
        iRecordStream<char> iss(
          std::istringstream( std::to_string( mat ) ) );
        REQUIRE_THROWS( argument::extract< 
          DTFR::Card8::Mat >( iss ) );
      }
    } // THEN
  } // GIVEN

  GIVEN( "no mat tape value" ){
    THEN( "default value is used" ){
      iRecordStream<char> iss(
        std::istringstream( " /" ) );
      REQUIRE( 0 == argument::extract< 
        DTFR::Card8::Mat >( iss ).value );
    } // THEN
  } // GIVEN
} // SCENARIO
