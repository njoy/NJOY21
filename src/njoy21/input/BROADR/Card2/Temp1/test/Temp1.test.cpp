#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "value range" ){
  {
    std::istringstream iss("   -1.0");
    long lineNumber = 1;
    REQUIRE_THROWS( argument::extract< BROADR::Card2::Temp1 >( iss, lineNumber ) );
  }{
    std::istringstream iss("   0.0");
    long lineNumber = 1;
    REQUIRE( argument::extract
	     < BROADR::Card2::Temp1 >( iss, lineNumber ).value == 0.0 * dimwits::kelvin );
  }{
    std::istringstream iss("   1.0");
    long lineNumber = 1;
    REQUIRE( argument::extract
	     < BROADR::Card2::Temp1 >( iss, lineNumber ).value == 1.0 * dimwits::kelvin );
  }{
    std::istringstream iss("   ");
    long lineNumber = 1;
    REQUIRE( argument::extract
	     < BROADR::Card2::Temp1 >( iss, lineNumber ).value == 0.0 * dimwits::kelvin );
  }
}
