#define CATCH_CONFIG_MAIN
 
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "value range" ){
  {
    std::istringstream iss("  -1");
    long lineNumber = 1;
    REQUIRE_THROWS( argument::extract< BROADR::Card5::Mat1 >( iss, lineNumber ) );
  }{
    std::istringstream iss("   0");
    long lineNumber = 1;
    REQUIRE( argument::extract
	     < BROADR::Card5::Mat1 >( iss, lineNumber ).value == 0 );
  }{
    std::istringstream iss("   1");
    long lineNumber = 1;
    REQUIRE( argument::extract
	     < BROADR::Card5::Mat1 >( iss, lineNumber ).value == 1 );
  }{
    std::istringstream iss("   5000");
    long lineNumber = 1;
    REQUIRE( argument::extract
	     < BROADR::Card5::Mat1 >( iss, lineNumber ).value == 5000 );
  }{
    std::istringstream iss("   9999");
    long lineNumber = 1;
    REQUIRE( argument::extract
	     < BROADR::Card5::Mat1 >( iss, lineNumber ).value == 9999 );
  }{
    std::istringstream iss("   10000");
    long lineNumber = 1;
    REQUIRE_THROWS( argument::extract
		    < BROADR::Card5::Mat1 >( iss, lineNumber ) );
  }{
    std::istringstream iss("   ");
    long lineNumber = 1;
    REQUIRE_THROWS( argument::extract
		    < BROADR::Card5::Mat1 >( iss, lineNumber ) );
  }
}
