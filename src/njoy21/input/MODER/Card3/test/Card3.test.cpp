#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "bugless" ){
  Argument< MODER::Card1::Nout > nout; nout.value = 22;
  {
    std::istringstream iss( "0 /" );
    long lineNumber = 1;
    MODER::Card3 card3( iss, lineNumber, nout );
    REQUIRE( card3.nin.value == 0 );
    REQUIRE( card3.matd.value == 0 );
    REQUIRE( card3.matd.defaulted == true );
  }{
    std::istringstream iss( "21 125" );
    long lineNumber = 1;
    MODER::Card3 card3( iss, lineNumber, nout );
    REQUIRE( card3.nin.value == 21 );
    REQUIRE( card3.matd.value == 125 );
    REQUIRE( card3.matd.defaulted == false );
  }
}

SCENARIO( "bugged" ){
  Argument< MODER::Card1::Nout > nout; nout.value = 21;
  {
    std::istringstream iss( "0 125" );
    long lineNumber = 1;
    REQUIRE_THROWS( MODER::Card3( iss, lineNumber, nout ) );
  }{
    std::istringstream iss( "24 /" );
    long lineNumber = 1;
    REQUIRE_THROWS( MODER::Card3( iss, lineNumber, nout ) );
  }{
    std::istringstream iss( "21 125" );
    long lineNumber = 1;
    REQUIRE_THROWS( MODER::Card3( iss, lineNumber, nout ) );
  }
}
