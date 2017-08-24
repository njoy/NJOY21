#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "expected successes" ){
  {
    iRecordStream<char> iss( std::istringstream("  20") );
    REQUIRE( argument::extract
                  < GAMINR::Card1::Nendf >( iss ).value  == 20 );
  }{
    iRecordStream<char> iss( std::istringstream(" -20") );
    REQUIRE( argument::extract
                  < GAMINR::Card1::Nendf >( iss ).value  == -20 );
  }{
    iRecordStream<char> iss( std::istringstream("  99") );
    REQUIRE( argument::extract
                  < GAMINR::Card1::Nendf >( iss ).value == 99 );
  }{
    iRecordStream<char> iss( std::istringstream(" -99") );
    REQUIRE( argument::extract
                  < GAMINR::Card1::Nendf >( iss ).value == -99 );
  }{
    iRecordStream<char> iss( std::istringstream("  59") );
    REQUIRE( argument::extract
                  < GAMINR::Card1::Nendf >( iss ).value == 59 );
  }{
    iRecordStream<char> iss( std::istringstream(" -59") );
    REQUIRE( argument::extract
                  < GAMINR::Card1::Nendf >( iss ).value == -59 );
  }
}

SCENARIO( "expected failures" ){
  {
    iRecordStream<char> iss( std::istringstream("  19") );
    REQUIRE_THROWS( argument::extract
                         <GAMINR::Card1::Nendf >( iss ) );
  }{
    iRecordStream<char> iss( std::istringstream(" -19") );
    REQUIRE_THROWS( argument::extract
                         <GAMINR::Card1::Nendf >( iss ) );
  }{
    iRecordStream<char> iss( std::istringstream("  100") );
    REQUIRE_THROWS( argument::extract
                         <GAMINR::Card1::Nendf >( iss ) );
  }{
    iRecordStream<char> iss( std::istringstream(" -100") );
    REQUIRE_THROWS( argument::extract
                         <GAMINR::Card1::Nendf >( iss ) );
  }{
    iRecordStream<char> iss( std::istringstream("  0") );
    REQUIRE_THROWS( argument::extract
                         <GAMINR::Card1::Nendf >( iss ) );
  }{
    iRecordStream<char> iss( std::istringstream(" cat") );
    REQUIRE_THROWS( argument::extract
                         <GAMINR::Card1::Nendf >( iss ) );
  }{
    iRecordStream<char> iss( std::istringstream("    ") );
    REQUIRE_THROWS( argument::extract
                         <GAMINR::Card1::Nendf >( iss ) );
  }
}
