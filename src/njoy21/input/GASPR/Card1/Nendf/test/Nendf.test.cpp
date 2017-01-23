#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "value range" ){
  {
    iRecordStream<char> iss( std::istringstream("   19") );
    REQUIRE_THROWS( argument::extract< GASPR::Card1::Nendf >( iss ) );
  }{
    iRecordStream<char> iss( std::istringstream("   -19") );
    REQUIRE_THROWS( argument::extract< GASPR::Card1::Nendf >( iss ) );
  }{
    iRecordStream<char> iss( std::istringstream("   20") );
    REQUIRE( argument::extract< GASPR::Card1::Nendf >( iss ).value == 20 );
  }{
    iRecordStream<char> iss( std::istringstream("   -20") );
    REQUIRE( argument::extract< GASPR::Card1::Nendf >( iss ).value == -20 );
  }{
    iRecordStream<char> iss( std::istringstream("   50") );
    REQUIRE( argument::extract< GASPR::Card1::Nendf >( iss ).value == 50 );
  }{
    iRecordStream<char> iss( std::istringstream("   -50") );
    REQUIRE( argument::extract< GASPR::Card1::Nendf >( iss ).value == -50 );
  }{
    iRecordStream<char> iss( std::istringstream("   99") );
    REQUIRE( argument::extract< GASPR::Card1::Nendf >( iss ).value == 99 );
  }{
    iRecordStream<char> iss( std::istringstream("   -99") );
    REQUIRE( argument::extract< GASPR::Card1::Nendf >( iss ).value == -99 );
  }{
    iRecordStream<char> iss( std::istringstream("   100") );
    REQUIRE_THROWS( argument::extract< GASPR::Card1::Nendf >( iss ) );
  }{
    iRecordStream<char> iss( std::istringstream("   -100") );
    REQUIRE_THROWS( argument::extract< GASPR::Card1::Nendf >( iss ) );
  }{
    iRecordStream<char> iss( std::istringstream("   /") );
    REQUIRE_THROWS( argument::extract< GASPR::Card1::Nendf >( iss ) );
  }
}
