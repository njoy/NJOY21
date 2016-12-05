#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "value range" ){
  Argument< BROADR::Card2::Ntemp2 > ntemp2; ntemp2.value = 1;
  Argument< BROADR::Card2::Istrap > istrap; istrap.value = 1;
  Argument< BROADR::Card2::Temp1 > temp1; temp1.value = 10.0 * dimwits::kelvin;
  {
    std::istringstream iss("   9.0\n");
    long lineNumber = 1;
    REQUIRE_THROWS( BROADR::Card4( iss, lineNumber, ntemp2, istrap, temp1 ) );
  }{
    std::istringstream iss("   10.0\n");
    long lineNumber = 1;
    REQUIRE( BROADR::Card4( iss, lineNumber, ntemp2, istrap, temp1 ).temp2.value.front()
	     == 10.0 * dimwits::kelvin );
  }{
    std::istringstream iss("   11.0\n");
    long lineNumber = 1;
    REQUIRE( BROADR::Card4( iss, lineNumber, ntemp2, istrap, temp1 ).temp2.value.front()
	     == 11.0 * dimwits::kelvin );
  }{
    std::istringstream iss("   \n");
    long lineNumber = 1;
    REQUIRE_THROWS( BROADR::Card4( iss, lineNumber, ntemp2, istrap, temp1 ) );
  }{
    std::istringstream iss("  20.0 30.0 40.0 \n");
    ntemp2.value = 3;
    long lineNumber = 1;
    BROADR::Card4 card4( iss, lineNumber, ntemp2, istrap, temp1 );
    REQUIRE( card4.temp2.value.front() == 20.0 * dimwits::kelvin );
    REQUIRE( card4.temp2.value.at(1) == 30.0 * dimwits::kelvin );
    REQUIRE( card4.temp2.value.back() == 40.0 * dimwits::kelvin );
  }
}
