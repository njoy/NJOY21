#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "bugless" ){
  {
    iRecordStream<char> iss( std::istringstream("   1 21\n") );
    MODER::Card1 card1( iss );
    REQUIRE( card1.nin.value == 1 );
    REQUIRE( card1.nout.value == 21 );
  }{
    iRecordStream<char> iss( std::istringstream("   20 21\n") );
    MODER::Card1 card1( iss );
    REQUIRE( card1.nin.value == 20 );
    REQUIRE( card1.nout.value == 21 );
  }{
    iRecordStream<char> iss( std::istringstream("   20 -21\n") );
    MODER::Card1 card1( iss );
    REQUIRE( card1.nin.value == 20 );
    REQUIRE( card1.nout.value == -21 );
  }
}

SCENARIO( "bugged" ){
  {
    iRecordStream<char> iss( std::istringstream("   0 21\n") );
    REQUIRE_THROWS( MODER::Card1 card1( iss ) );
  }{
    iRecordStream<char> iss( std::istringstream("   20 10\n") );
    REQUIRE_THROWS( MODER::Card1 card1( iss ) );
  }{
    iRecordStream<char> iss( std::istringstream("   20 21 30\n") );
    REQUIRE_THROWS( MODER::Card1 card1( iss ) );
  }
}
