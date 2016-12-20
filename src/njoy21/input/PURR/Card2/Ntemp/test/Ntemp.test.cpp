#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "value range" ){
  {
    iRecordStream< char> iss( std::istringstream("   0") );
    REQUIRE_THROWS( argument::extract< PURR::Card2::Ntemp >( iss ) );
  }{
    iRecordStream< char> iss( std::istringstream("   1") );
    REQUIRE( argument::extract< PURR::Card2::Ntemp >( iss ).value == 1 );
  }{
    iRecordStream< char> iss( std::istringstream("   5000") );
    REQUIRE( argument::extract< PURR::Card2::Ntemp >( iss ).value == 5000 );
  }{
    iRecordStream< char> iss( std::istringstream("   /") );
    REQUIRE( argument::extract< PURR::Card2::Ntemp >( iss ).value == 1 );
  }
}
