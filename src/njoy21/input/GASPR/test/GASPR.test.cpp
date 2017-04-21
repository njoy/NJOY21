#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "bugless" ){
  {
    iRecordStream<char> iss( std::istringstream( "21 -22 -23" ) );
    GASPR gaspr( iss );
    REQUIRE( gaspr.card1.nendf.value == 21 );
    REQUIRE( gaspr.card1.nin.value == -22 );
    REQUIRE( gaspr.card1.nout.value == -23 );
  }{
    iRecordStream<char> iss( std::istringstream( "-21 -22 -23" ) );
    GASPR gaspr( iss );
    REQUIRE( gaspr.card1.nendf.value == -21 );
    REQUIRE( gaspr.card1.nin.value == -22 );
    REQUIRE( gaspr.card1.nout.value == -23 );
  }{
    iRecordStream<char> iss( std::istringstream( "-21 22 23" ) );
    GASPR gaspr( iss );
    REQUIRE( gaspr.card1.nendf.value == -21 );
    REQUIRE( gaspr.card1.nin.value == 22 );
    REQUIRE( gaspr.card1.nout.value == 23 );
  }{
    iRecordStream<char> iss( std::istringstream( "21 22 23" ) );
    GASPR gaspr( iss );
    REQUIRE( gaspr.card1.nendf.value == 21 );
    REQUIRE( gaspr.card1.nin.value == 22 );
    REQUIRE( gaspr.card1.nout.value == 23 );
  }
}

SCENARIO( "bugged" ){
  {
    iRecordStream<char> iss( std::istringstream( "21 -21 -22" ) );
    REQUIRE_THROWS( GASPR( iss ) );
  }{
    iRecordStream<char> iss( std::istringstream( "20 -21 -21" ) );
    REQUIRE_THROWS( GASPR( iss ) );
  }{
    iRecordStream<char> iss( std::istringstream( "20 -21 -20" ) );
    REQUIRE_THROWS( GASPR( iss ) );
  }{
    iRecordStream<char> iss( std::istringstream( "20 -21 22" ) );
    REQUIRE_THROWS( GASPR( iss ) );
  }
}
