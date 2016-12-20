#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Ngrid input values" ){
  std::vector<int> validNgrid{ 0, 1, 100 };
  for( auto ngrid : validNgrid ){
    iRecordStream<char> iss( std::istringstream( std::to_string( ngrid ) ) );
    REQUIRE( argument::extract< RECONR::Card3::Ngrid >(iss).value == ngrid );
  }
  std::vector<int> invalidNgrid{ -1 };
  for( auto ngrid : invalidNgrid ){
    iRecordStream<char> iss( std::istringstream( std::to_string( ngrid ) ) );
    REQUIRE_THROWS( argument::extract< RECONR::Card3::Ngrid >(iss) );
  }
}



