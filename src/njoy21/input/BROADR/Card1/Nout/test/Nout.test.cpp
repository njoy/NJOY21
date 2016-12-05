#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "value range" ){
  Argument< BROADR::Card1::Nendf > nendf; nendf.value = 21;
  Argument< BROADR::Card1::Nin > nin;
  {
    std::istringstream iss("   19");
    long lineNumber = 1;
    nin.value = 22;
    REQUIRE_THROWS( argument::extract< BROADR::Card1::Nout >
		    ( iss, lineNumber, nendf, nin ) );
  }{
    std::istringstream iss("   -19");
    long lineNumber = 1;
    nin.value = -22;
    REQUIRE_THROWS( argument::extract< BROADR::Card1::Nout >
		    ( iss, lineNumber, nendf, nin ) );
  }{
    std::istringstream iss("   -20");
    long lineNumber = 1;
    nin.value = 22;
    REQUIRE_THROWS( argument::extract< BROADR::Card1::Nout >
		    ( iss, lineNumber, nendf, nin ) );
  }{
    std::istringstream iss("   20");
    long lineNumber = 1;
    nin.value = 22;
    REQUIRE( argument::extract< BROADR::Card1::Nout >
	     ( iss, lineNumber, nendf, nin ).value == 20 );
  }{
    std::istringstream iss("   -20");
    long lineNumber = 1;
    nin.value = -22;
    REQUIRE( argument::extract< BROADR::Card1::Nout >
	     ( iss, lineNumber, nendf, nin ).value == -20 );
  }{
    std::istringstream iss("   50");
    long lineNumber = 1;
    nin.value = 22;
    REQUIRE( argument::extract< BROADR::Card1::Nout >
	     ( iss, lineNumber, nendf, nin ).value == 50 );
  }{
    std::istringstream iss("   -50");
    long lineNumber = 1;
    nin.value = -22;
    REQUIRE( argument::extract< BROADR::Card1::Nout >
	     ( iss, lineNumber, nendf, nin ).value == -50 );
  }{
    std::istringstream iss("   99");
    long lineNumber = 1;
    nin.value = 22;
    REQUIRE( argument::extract< BROADR::Card1::Nout >
	     ( iss, lineNumber, nendf, nin ).value == 99 );
  }{
    std::istringstream iss("   -99");
    long lineNumber = 1;
    nin.value = -22;
    REQUIRE( argument::extract< BROADR::Card1::Nout >
	     ( iss, lineNumber, nendf, nin ).value == -99 );
  }{
    std::istringstream iss("   100");
    long lineNumber = 1;
    nin.value = 22;
    REQUIRE_THROWS( argument::extract< BROADR::Card1::Nout >
		    ( iss, lineNumber, nendf, nin ) );
  }{
    std::istringstream iss("   -100");
    nin.value = -22;
    long lineNumber = 1;
    REQUIRE_THROWS( argument::extract< BROADR::Card1::Nout >
		    ( iss, lineNumber, nendf, nin ) );
  }{
    std::istringstream iss("   ");
    nin.value = 22;
    long lineNumber = 1;
    REQUIRE_THROWS( argument::extract< BROADR::Card1::Nout >
		    ( iss, lineNumber, nendf, nin ) );
  }
}
