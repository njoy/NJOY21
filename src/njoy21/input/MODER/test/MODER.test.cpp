#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "bugless" ){
  {
    iRecordStream<char> iss( std::istringstream( "21 -22" ) );
    MODER moder( iss );
    REQUIRE( moder.card1.nin.value == 21 );
    REQUIRE( moder.card1.nout.value == -22 );
    REQUIRE( not moder.card2 );
    REQUIRE( not moder.card3List );
  }{
    iRecordStream<char> iss( std::istringstream(
      "1 -22 \n"
      "'my simple pendf tape'\n"
      "21 125\n"
      "0/"
      ) );
    MODER moder( iss );
    REQUIRE( moder.card1.nin.value == 1 );
    REQUIRE( moder.card1.nout.value == -22 );
    REQUIRE( moder.card2 );
    REQUIRE( moder.card2->tapeid.value == "my simple pendf tape" );
    REQUIRE( moder.card3List );
    REQUIRE( moder.card3List->size() == 1 );
    REQUIRE( moder.card3List->front().nin.value == 21 );
    REQUIRE( moder.card3List->front().matd.value == 125 );
  }{
    iRecordStream<char> iss( std::istringstream(
      "1 -22 \n"
      "'my simple pendf tape'\n"
      "23 122\n"
      "21 124\n"
      "0/"
      ) );
    MODER moder( iss );
    REQUIRE( moder.card1.nin.value == 1 );
    REQUIRE( moder.card1.nout.value == -22 );
    REQUIRE( moder.card2 );
    REQUIRE( moder.card2->tapeid.value == "my simple pendf tape" );
    REQUIRE( moder.card3List );
    REQUIRE( moder.card3List->size() == 2 );
    REQUIRE( moder.card3List->at(0).nin.value == 23 );
    REQUIRE( moder.card3List->at(0).matd.value == 122 );
    REQUIRE( moder.card3List->at(1).nin.value == 21 );
    REQUIRE( moder.card3List->at(1).matd.value == 124 );
  }

}

SCENARIO( "bugged" ){
  {
    iRecordStream<char> iss( std::istringstream( "21 -21" ) );
    REQUIRE_THROWS( MODER( iss ) );
  }{
    iRecordStream<char> iss( std::istringstream(
      "1 -22 \n"
      "'my simple pendf tape'\n"
      "0 /"
      ) );
    REQUIRE_THROWS( MODER( iss ) );
  }{
    iRecordStream<char> iss( std::istringstream(
      "1 -22 \n"
      "'my simple pendf tape'\n"
      "21 124\n"
      "23 122\n"
      "0/"
      ) );
    REQUIRE_THROWS( MODER( iss ) );
  }
}
