#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "expected successes" ){
  {
    iRecordStream<char> iss( std::istringstream("  1") );
    REQUIRE( argument::extract
                  < GAMINR::Card2::Iwt >( iss ).value  == 1 );
  }{
    iRecordStream<char> iss( std::istringstream("  2") );
    REQUIRE( argument::extract
                  < GAMINR::Card2::Iwt >( iss ).value  == 2 );
  }{
    iRecordStream<char> iss( std::istringstream("  3") );
    REQUIRE( argument::extract
                  < GAMINR::Card2::Iwt >( iss ).value == 3 );
  }
}

SCENARIO( "expected failures" ){
  {
    iRecordStream<char> iss( std::istringstream("  0") );
    REQUIRE_THROWS( argument::extract
                         <GAMINR::Card2::Iwt >( iss ) );
  }{
    iRecordStream<char> iss( std::istringstream(" -1") );
    REQUIRE_THROWS( argument::extract
                         <GAMINR::Card2::Iwt >( iss ) );
  }{
    iRecordStream<char> iss( std::istringstream("  4") );
    REQUIRE_THROWS( argument::extract
                         <GAMINR::Card2::Iwt >( iss ) );
  }{
    iRecordStream<char> iss( std::istringstream(" cat") );
    REQUIRE_THROWS( argument::extract
                         <GAMINR::Card2::Iwt >( iss ) );
  }{
    iRecordStream<char> iss( std::istringstream("    ") );
    REQUIRE_THROWS( argument::extract
                         <GAMINR::Card2::Iwt >( iss ) );
  }
}
