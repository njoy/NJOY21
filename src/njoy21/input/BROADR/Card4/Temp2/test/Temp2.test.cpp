#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "value range" ){
  Argument< BROADR::Card2::Ntemp2 > ntemp2; ntemp2.value = 1;
  Argument< BROADR::Card2::Istrap > istrap; istrap.value = 1;
  Argument< BROADR::Card2::Temp1 > temp1; temp1.value = 10.0 * dimwits::kelvin;
  {
    std::istringstream iss("   9.0");
    long lineNumber = 1;
    REQUIRE_THROWS( argument::extract< BROADR::Card4::Temp2 >
		    ( iss, lineNumber, ntemp2, istrap, temp1 ) );
  }{
    std::istringstream iss("   10.0");
    long lineNumber = 1;
    REQUIRE( argument::extract< BROADR::Card4::Temp2 >
	     ( iss, lineNumber, ntemp2, istrap, temp1 ).value.front()
	     == 10.0 * dimwits::kelvin );
  }{
    std::istringstream iss("   11.0");
    long lineNumber = 1;
    REQUIRE( argument::extract< BROADR::Card4::Temp2 >
	     ( iss, lineNumber, ntemp2, istrap, temp1 ).value.front()
	     == 11.0 * dimwits::kelvin );
  }{
    std::istringstream iss("   ");
    long lineNumber = 1;
    REQUIRE_THROWS( argument::extract< BROADR::Card4::Temp2 >
		    ( iss, lineNumber, ntemp2, istrap, temp1 ) );
  }{
    std::istringstream iss("   100 200");
    long lineNumber = 1;
    REQUIRE_THROWS( argument::extract< BROADR::Card4::Temp2 >
		    ( iss, lineNumber, ntemp2, istrap, temp1 ) );
  }{
    ntemp2.value = 2;
    std::istringstream iss("   100.0 200.0");
    long lineNumber = 1;
    auto temp2 = argument::extract< BROADR::Card4::Temp2 >
                 ( iss, lineNumber, ntemp2, istrap, temp1 );
    REQUIRE( temp2.value.front() == 100.0 * dimwits::kelvin );
    REQUIRE( temp2.value.back() == 200.0 * dimwits::kelvin );
  }{
    ntemp2.value = 2;
    std::istringstream iss("   300.0 200.0");
    long lineNumber = 1;
    REQUIRE_THROWS( argument::extract< BROADR::Card4::Temp2 >
		    ( iss, lineNumber, ntemp2, istrap, temp1 ) );
  }
}
