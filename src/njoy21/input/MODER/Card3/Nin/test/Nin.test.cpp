#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "special values" ){
  Argument< MODER::Card1::Nout > nout; nout.value = 21;
  std::istringstream iss("   0");
  long lineNumber = 1;
  REQUIRE( argument::extract< MODER::Card3::Nin >( iss, lineNumber, nout ).value == 0 );
}

SCENARIO( "typical values" ){
  Argument< MODER::Card1::Nout > nout; nout.value = 21;
  {
    std::istringstream iss("   19");
    long lineNumber = 1;
    REQUIRE_THROWS( argument::extract< MODER::Card3::Nin >( iss, lineNumber, nout ) );
  }{
    std::istringstream iss("   -19");
    long lineNumber = 1;
    REQUIRE_THROWS( argument::extract< MODER::Card3::Nin >( iss, lineNumber, nout ) );
  }{
    std::istringstream iss("   21");
    long lineNumber = 1;
    REQUIRE_THROWS( argument::extract< MODER::Card3::Nin >( iss, lineNumber, nout ) );
  }{
    std::istringstream iss("   -21");
    long lineNumber = 1;
    REQUIRE_THROWS( argument::extract< MODER::Card3::Nin >( iss, lineNumber, nout ) );
  }{
    std::istringstream iss("   20");
    long lineNumber = 1;
    REQUIRE( argument::extract
	     < MODER::Card3::Nin >( iss, lineNumber, nout ).value == 20 );
  }{
    std::istringstream iss("   -20");
    long lineNumber = 1;
    REQUIRE( argument::extract
	     < MODER::Card3::Nin >( iss, lineNumber, nout ).value == -20 );
  }{
    std::istringstream iss("   50");
    long lineNumber = 1;
    REQUIRE( argument::extract
	     < MODER::Card3::Nin >( iss, lineNumber, nout ).value == 50 );
  }{
    std::istringstream iss("   -50");
    long lineNumber = 1;
    REQUIRE( argument::extract
	     < MODER::Card3::Nin >( iss, lineNumber, nout ).value == -50 );
  }{
    std::istringstream iss("   99");
    long lineNumber = 1;
    REQUIRE( argument::extract
	     < MODER::Card3::Nin >( iss, lineNumber, nout ).value == 99 );
  }{
    std::istringstream iss("   -99");
    long lineNumber = 1;
    REQUIRE( argument::extract
	     < MODER::Card3::Nin >( iss, lineNumber, nout ).value == -99 );
  }{
    std::istringstream iss("   100");
    long lineNumber = 1;
    REQUIRE_THROWS( argument::extract< MODER::Card3::Nin >( iss, lineNumber, nout ) );
  }{
    std::istringstream iss("   -100");
    long lineNumber = 1;
    REQUIRE_THROWS( argument::extract< MODER::Card3::Nin >( iss, lineNumber, nout ) );
  }{
    std::istringstream iss("   ");
    long lineNumber = 1;
    REQUIRE_THROWS( argument::extract< MODER::Card3::Nin >( iss, lineNumber, nout ) );
  }
}
