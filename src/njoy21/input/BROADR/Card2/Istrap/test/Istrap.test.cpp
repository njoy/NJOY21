#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "value range" ){
  {
    std::istringstream iss("   -1");
    long lineNumber = 1;
    REQUIRE_THROWS( argument::extract< BROADR::Card2::Istrap >( iss, lineNumber ) );
  }{
    std::istringstream iss("   0");
    long lineNumber = 1;
    REQUIRE( argument::extract
	     < BROADR::Card2::Istrap >( iss, lineNumber ).value == 0 );
  }{
    std::istringstream iss("   1");
    long lineNumber = 1;
    REQUIRE( argument::extract
	     < BROADR::Card2::Istrap >( iss, lineNumber ).value == 1 );
  }{
    std::istringstream iss("   2");
    long lineNumber = 1;
    REQUIRE_THROWS( argument::extract< BROADR::Card2::Istrap >( iss, lineNumber ) );
  }{
    std::istringstream iss("   ");
    long lineNumber = 1;
    REQUIRE( argument::extract
	     < BROADR::Card2::Istrap >( iss, lineNumber ).value == 0 );
  }
}
