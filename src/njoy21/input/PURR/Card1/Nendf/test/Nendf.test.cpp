#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "value range" ){
  {
    std::istringstream iss("   19");
    long lineNumber = 1;
    REQUIRE_THROWS( argument::extract
                    < PURR::Card1::Nendf >( iss, lineNumber ) );
  }{
    std::istringstream iss("   -19");
    long lineNumber = 1;
    REQUIRE_THROWS( argument::extract
                   < PURR::Card1::Nendf >( iss, lineNumber ) );
  }{
    std::istringstream iss("   20");
    long lineNumber = 1;
    REQUIRE( argument::extract
             < PURR::Card1::Nendf >( iss, lineNumber ).value == 20 );
  }{
    std::istringstream iss("   -20");
    long lineNumber = 1;
    REQUIRE( argument::extract
             < PURR::Card1::Nendf >( iss, lineNumber ).value == -20 );
  }{
    std::istringstream iss("   50");
    long lineNumber = 1;
    REQUIRE( argument::extract
             < PURR::Card1::Nendf >( iss, lineNumber ).value == 50 );
  }{
    std::istringstream iss("   -50");
    long lineNumber = 1;
    REQUIRE( argument::extract
             < PURR::Card1::Nendf >( iss, lineNumber ).value == -50 );
  }{
    std::istringstream iss("   99");
    long lineNumber = 1;
    REQUIRE( argument::extract
             < PURR::Card1::Nendf >( iss, lineNumber ).value == 99 );
  }{
    std::istringstream iss("   -99");
    long lineNumber = 1;
    REQUIRE( argument::extract
             < PURR::Card1::Nendf >( iss, lineNumber ).value == -99 );
  }{
    std::istringstream iss("   100");
    long lineNumber = 1;
    REQUIRE_THROWS( argument::extract
                    < PURR::Card1::Nendf >( iss, lineNumber ) );
  }{
    std::istringstream iss("   -100");
    long lineNumber = 1;
    REQUIRE_THROWS( argument::extract
                    < PURR::Card1::Nendf >( iss, lineNumber ) );
  }{
    std::istringstream iss("   ");
    long lineNumber = 1;
    REQUIRE_THROWS( argument::extract
                    < PURR::Card1::Nendf >( iss, lineNumber ) );
  }
}
