#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "value range" ){
  Argument< BROADR::Card1::Nendf > nendf; nendf.value = 22;
  {
    std::istringstream iss("   19");
    long lineNumber = 1;
    REQUIRE_THROWS( argument::extract< BROADR::Card1::Nin >
		    ( iss, lineNumber, nendf ) );
  }{
    std::istringstream iss("   -19");
    long lineNumber = 1;
    REQUIRE_THROWS( argument::extract< BROADR::Card1::Nin >
		    ( iss, lineNumber, nendf ) );
  }{
    std::istringstream iss("   22");
    long lineNumber = 1;
    REQUIRE_THROWS( argument::extract< BROADR::Card1::Nin >
		    ( iss, lineNumber, nendf ) );
  }{
    std::istringstream iss("   -22");
    long lineNumber = 1;
    REQUIRE_THROWS( argument::extract< BROADR::Card1::Nin >
		    ( iss, lineNumber, nendf ) );
  }{
    std::istringstream iss("   20");
    long lineNumber = 1;
    REQUIRE( argument::extract
	     < BROADR::Card1::Nin >( iss, lineNumber, nendf ).value == 20 );
  }{
    std::istringstream iss("   -20");
    long lineNumber = 1;
    REQUIRE( argument::extract
	     < BROADR::Card1::Nin >( iss, lineNumber, nendf ).value == -20 );
  }{
    std::istringstream iss("   50");
    long lineNumber = 1;
    REQUIRE( argument::extract
	     < BROADR::Card1::Nin >( iss, lineNumber, nendf ).value == 50 );
  }{
    std::istringstream iss("   -50");
    long lineNumber = 1;
    REQUIRE( argument::extract
	     < BROADR::Card1::Nin >( iss, lineNumber, nendf ).value == -50 );
  }{
    std::istringstream iss("   99");
    long lineNumber = 1;
    REQUIRE( argument::extract
	     < BROADR::Card1::Nin >( iss, lineNumber, nendf ).value == 99 );
  }{
    std::istringstream iss("   -99");
    long lineNumber = 1;
    REQUIRE( argument::extract
	     < BROADR::Card1::Nin >( iss, lineNumber, nendf ).value == -99 );
  }{
    std::istringstream iss("   100");
    long lineNumber = 1;
    REQUIRE_THROWS( argument::extract< BROADR::Card1::Nin >
		    ( iss, lineNumber, nendf ) );
  }{
    std::istringstream iss("   -100");
    long lineNumber = 1;
    REQUIRE_THROWS( argument::extract< BROADR::Card1::Nin >
		    ( iss, lineNumber, nendf ) );
  }{
    std::istringstream iss("   ");
    long lineNumber = 1;
    REQUIRE_THROWS( argument::extract< BROADR::Card1::Nin >
		    ( iss, lineNumber, nendf ) );
  }
}
