#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "LEAPR Card4 mat values",
  "[LEAPR], [Card4], [Mat]"){

  GIVEN( "valid mat values" ){
    std::vector<int> validValues{1, 2, 99, 100, 101, 9999};
    THEN( "the returned class has the correct value" ){
      for( auto& mat : validValues ){
        iRecordStream<char> iss( 
          std::istringstream( std::to_string( mat ) ) );
        REQUIRE( mat == argument::extract< 
          LEAPR::Card4::Mat >( iss ).value );
      }
    } // THEN
  } // GIVEN

  GIVEN( "invalid mat values" ){
    std::vector<int> invalidValues{-1, 0, 10000};
    THEN( "an exception is thrown" ){
      for( auto& mat : invalidValues ){
        iRecordStream<char> iss( 
          std::istringstream( std::to_string( mat ) ) );
        REQUIRE_THROWS( argument::extract< 
          LEAPR::Card4::Mat >( iss ) );
      }
    } // THEN
  } // GIVEN
} // SCENARIO
