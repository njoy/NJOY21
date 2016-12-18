#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "mat input values", "[Card3], [mat]"){
  std::vector<int> validMat{ 0, 1, 5000, 9999 };
  for( auto mat : validMat ){
    iRecordStream<char> iss( std::istringstream( std::to_string( mat ) ) );
    REQUIRE( argument::extract< RECONR::Card3::Mat >(iss).value == mat );
  }
  std::vector<int> invalidMat{ -1, 10000 };
  for( auto mat : invalidMat ){
    iRecordStream<char> iss( std::istringstream( std::to_string( mat ) ) );
    REQUIRE_THROWS( argument::extract< RECONR::Card3::Mat >(iss) );
  }
}
