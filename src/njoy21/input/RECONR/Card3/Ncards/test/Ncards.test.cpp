#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Ncards input values" ){
  std::vector<int> validNcards{ 0, 1, 100 };
  for( auto ncards : validNcards ){
    iRecordStream<char> iss( std::istringstream( std::to_string( ncards ) ) );
    REQUIRE( argument::extract< RECONR::Card3::Ncards >(iss).value == ncards );
  }
  std::vector<int> invalidNcards{ -1 };
  for( auto ncards : invalidNcards ){
    iRecordStream<char> iss( std::istringstream( std::to_string( ncards ) ) );
    REQUIRE_THROWS( argument::extract< RECONR::Card3::Ncards >(iss) );
  }
}
