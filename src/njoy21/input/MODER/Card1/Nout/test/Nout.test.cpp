#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "moder card1 nout" ){
  Argument< MODER::Card1::Nin > nin; nin.value = 22;
  {
    std::istringstream iss(" 19");
    long lineNumber = 1;
    REQUIRE_THROWS( argument::extract< MODER::Card1::Nout >( iss, lineNumber, nin ) );
  }{
    std::istringstream iss(" -19");
    long lineNumber = 1;
    REQUIRE_THROWS( argument::extract< MODER::Card1::Nout >( iss, lineNumber, nin ) );
  }  {
    std::istringstream iss(" 22");
    long lineNumber = 1;
    REQUIRE_THROWS( argument::extract< MODER::Card1::Nout >( iss, lineNumber, nin ) );
  }{
    std::istringstream iss(" -22");
    long lineNumber = 1;
    REQUIRE_THROWS( argument::extract< MODER::Card1::Nout >( iss, lineNumber, nin ) );
  }{
    std::istringstream iss(" 20");
    long lineNumber = 1;
    REQUIRE( 20 == argument::extract< MODER::Card1::Nout >( iss, lineNumber, nin ).value );
  }{
    std::istringstream iss(" -20");
    long lineNumber = 1;
    REQUIRE( -20 == argument::extract< MODER::Card1::Nout >( iss, lineNumber, nin ).value );
  }{
    std::istringstream iss(" 50");
    long lineNumber = 1;
    REQUIRE( 50 == argument::extract< MODER::Card1::Nout >( iss, lineNumber, nin ).value );
  }{
    std::istringstream iss(" -50");
    long lineNumber = 1;
    REQUIRE( -50 == argument::extract< MODER::Card1::Nout >( iss, lineNumber, nin ).value );
  }{
    std::istringstream iss(" 99");
    long lineNumber = 1;
    REQUIRE( 99 == argument::extract< MODER::Card1::Nout >( iss, lineNumber, nin ).value );
  }{
    std::istringstream iss(" -99");
    long lineNumber = 1;
    REQUIRE( -99 == argument::extract< MODER::Card1::Nout >( iss, lineNumber, nin ).value );
  }{
    std::istringstream iss(" 100");
    long lineNumber = 1;
    REQUIRE_THROWS( argument::extract< MODER::Card1::Nout >( iss, lineNumber, nin ) );
  }{
    std::istringstream iss(" -100");
    long lineNumber = 1;
    REQUIRE_THROWS( argument::extract< MODER::Card1::Nout >( iss, lineNumber, nin ) );
  }
}
