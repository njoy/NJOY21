#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "bugless" ){
  Argument< MODER::Card1::Nout > nout; nout.value = 22;
  {
    iRecordStream<char> iss( std::istringstream( "0 /" ) );
    MODER::Card3 card3( iss, nout );
    REQUIRE( card3.nin.value == 0 );
    REQUIRE( card3.matd.value == 0 );
    REQUIRE( card3.matd.defaulted == true );
  }{
    iRecordStream<char> iss( std::istringstream( "21 125" ) );
    MODER::Card3 card3( iss, nout );
    REQUIRE( card3.nin.value == 21 );
    REQUIRE( card3.matd.value == 125 );
    REQUIRE( card3.matd.defaulted == false );
  }
}

SCENARIO( "bugged" ){
  Argument< MODER::Card1::Nout > nout; nout.value = 21;
  {
    iRecordStream<char> iss( std::istringstream( "0 125" ) );
    REQUIRE_THROWS( MODER::Card3( iss, nout ) );
  }{
    iRecordStream<char> iss( std::istringstream( "24 /" ) );
    REQUIRE_THROWS( MODER::Card3( iss, nout ) );
  }{
    iRecordStream<char> iss( std::istringstream( "21 125" ) );
    REQUIRE_THROWS( MODER::Card3( iss, nout ) );
  }
}
