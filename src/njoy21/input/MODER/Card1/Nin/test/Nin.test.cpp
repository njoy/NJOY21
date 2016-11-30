#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "special values" ){
  {
    std::istringstream iss("   0");
    long lineNumber = 1;
    REQUIRE_THROWS( argument::extract< MODER::Card1::Nin >( iss, lineNumber ) );
  }{
    std::istringstream iss("   1");
    long lineNumber = 1;
    REQUIRE( argument::extract
	     < MODER::Card1::Nin >( iss, lineNumber ).value == 1 );
  }{
    std::istringstream iss("   2");
    long lineNumber = 1;
    REQUIRE( argument::extract
	     < MODER::Card1::Nin >( iss, lineNumber ).value == 2 );
  }{
    std::istringstream iss("   3");
    long lineNumber = 1;
    REQUIRE( argument::extract
	     < MODER::Card1::Nin >( iss, lineNumber ).value == 3 );
  }{
    std::istringstream iss("   4");
    long lineNumber = 1;
    REQUIRE_THROWS( argument::extract< MODER::Card1::Nin >( iss, lineNumber ) );
  }
}

SCENARIO( "typical values" ){
  {
    std::istringstream iss("   19");
    long lineNumber = 1;
    REQUIRE_THROWS( argument::extract< MODER::Card1::Nin >( iss, lineNumber ) );
  }{
    std::istringstream iss("   -19");
    long lineNumber = 1;
    REQUIRE_THROWS( argument::extract< MODER::Card1::Nin >( iss, lineNumber ) );
  }{
    std::istringstream iss("   20");
    long lineNumber = 1;
    REQUIRE( argument::extract
	     < MODER::Card1::Nin >( iss, lineNumber ).value == 20 );
  }{
    std::istringstream iss("   -20");
    long lineNumber = 1;
    REQUIRE( argument::extract
	     < MODER::Card1::Nin >( iss, lineNumber ).value == -20 );
  }{
    std::istringstream iss("   50");
    long lineNumber = 1;
    REQUIRE( argument::extract
	     < MODER::Card1::Nin >( iss, lineNumber ).value == 50 );
  }{
    std::istringstream iss("   -50");
    long lineNumber = 1;
    REQUIRE( argument::extract
	     < MODER::Card1::Nin >( iss, lineNumber ).value == -50 );
  }{
    std::istringstream iss("   99");
    long lineNumber = 1;
    REQUIRE( argument::extract
	     < MODER::Card1::Nin >( iss, lineNumber ).value == 99 );
  }{
    std::istringstream iss("   -99");
    long lineNumber = 1;
    REQUIRE( argument::extract
	     < MODER::Card1::Nin >( iss, lineNumber ).value == -99 );
  }{
    std::istringstream iss("   100");
    long lineNumber = 1;
    REQUIRE_THROWS( argument::extract< MODER::Card1::Nin >( iss, lineNumber ) );
  }{
    std::istringstream iss("   -100");
    long lineNumber = 1;
    REQUIRE_THROWS( argument::extract< MODER::Card1::Nin >( iss, lineNumber ) );
  }{
    std::istringstream iss("   ");
    long lineNumber = 1;
    REQUIRE_THROWS( argument::extract< MODER::Card1::Nin >( iss, lineNumber ) );
  }
}
