#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "value range" ){
  Argument< BROADR::Card2::Temp1 > temp1; temp1.value = 10.0 * dimwits::kelvin;
  {
    std::istringstream iss("   9.0");
    long lineNumber = 1;
    REQUIRE_THROWS( argument::extract
		    < BROADR::Card4::Temp2 >( iss, lineNumber, temp1 ) );
  }{
    std::istringstream iss("   10.0");
    long lineNumber = 1;
    REQUIRE( argument::extract
	     < BROADR::Card4::Temp2 >( iss, lineNumber, temp1 ).value
	     == 10.0 * dimwits::kelvin );
  }{
    std::istringstream iss("   11.0");
    long lineNumber = 1;
    REQUIRE( argument::extract
	     < BROADR::Card4::Temp2 >( iss, lineNumber, temp1 ).value
	     == 11.0 * dimwits::kelvin );
  }{
    std::istringstream iss("   ");
    long lineNumber = 1;
    REQUIRE_THROWS( argument::extract
		    < BROADR::Card4::Temp2 >( iss, lineNumber, temp1 ) );
  }
}
