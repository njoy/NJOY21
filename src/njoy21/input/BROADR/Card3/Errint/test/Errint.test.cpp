#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "value range" ){
  Argument< BROADR::Card3::Errthn > errthn; errthn.value = 1.0;
  {
    std::istringstream iss("   -1.0");
    long lineNumber = 1;
    REQUIRE_THROWS( argument::extract
		    < BROADR::Card3::Errint >( iss, lineNumber, errthn ) );
  }{
    std::istringstream iss("   0.0");
    long lineNumber = 1;
    REQUIRE_THROWS( argument::extract
		    < BROADR::Card3::Errint >( iss, lineNumber, errthn ) );
  }{
    std::istringstream iss("   1.0");
    long lineNumber = 1;
    REQUIRE( argument::extract
	     < BROADR::Card3::Errint >( iss, lineNumber, errthn ).value
	     == 1.0 * dimwits::barns );
  }{
    std::istringstream iss("   ");
    long lineNumber = 1;
    REQUIRE( argument::extract
	     < BROADR::Card3::Errint >( iss, lineNumber, errthn ).value
	     == 1.0 * dimwits::barn * ( errthn.value / 2.0E4 ) );
  }
}
