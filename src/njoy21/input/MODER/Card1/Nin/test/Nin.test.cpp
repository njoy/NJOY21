#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "special values" ){
  {
    iRecordStream<char> iss( std::istringstream("   0") );
    REQUIRE_THROWS( argument::extract< MODER::Card1::Nin >( iss ) );
  }{
    iRecordStream<char> iss( std::istringstream("   1") );
    REQUIRE( argument::extract
	     < MODER::Card1::Nin >( iss ).value == 1 );
  }{
    iRecordStream<char> iss( std::istringstream("   2") );
    REQUIRE( argument::extract
	     < MODER::Card1::Nin >( iss ).value == 2 );
  }{
    iRecordStream<char> iss( std::istringstream("   3") );
    REQUIRE( argument::extract
	     < MODER::Card1::Nin >( iss ).value == 3 );
  }{
    iRecordStream<char> iss( std::istringstream("   4") );
    REQUIRE_THROWS( argument::extract< MODER::Card1::Nin >( iss ) );
  }
}

SCENARIO( "typical values" ){
  {
    iRecordStream<char> iss( std::istringstream("   19") );
    REQUIRE_THROWS( argument::extract< MODER::Card1::Nin >( iss ) );
  }{
    iRecordStream<char> iss( std::istringstream("   -19") );
    REQUIRE_THROWS( argument::extract< MODER::Card1::Nin >( iss ) );
  }{
    iRecordStream<char> iss( std::istringstream("   20") );
    REQUIRE( argument::extract
	     < MODER::Card1::Nin >( iss ).value == 20 );
  }{
    iRecordStream<char> iss( std::istringstream("   -20") );
    REQUIRE( argument::extract
	     < MODER::Card1::Nin >( iss ).value == -20 );
  }{
    iRecordStream<char> iss( std::istringstream("   50") );
    REQUIRE( argument::extract
	     < MODER::Card1::Nin >( iss ).value == 50 );
  }{
    iRecordStream<char> iss( std::istringstream("   -50") );
    REQUIRE( argument::extract
	     < MODER::Card1::Nin >( iss ).value == -50 );
  }{
    iRecordStream<char> iss( std::istringstream("   99") );
    REQUIRE( argument::extract
	     < MODER::Card1::Nin >( iss ).value == 99 );
  }{
    iRecordStream<char> iss( std::istringstream("   -99") );
    REQUIRE( argument::extract
	     < MODER::Card1::Nin >( iss ).value == -99 );
  }{
    iRecordStream<char> iss( std::istringstream("   100") );
    REQUIRE_THROWS( argument::extract< MODER::Card1::Nin >( iss ) );
  }{
    iRecordStream<char> iss( std::istringstream("   -100") );
    REQUIRE_THROWS( argument::extract< MODER::Card1::Nin >( iss ) );
  }{
    iRecordStream<char> iss( std::istringstream("   ") );
    REQUIRE_THROWS( argument::extract< MODER::Card1::Nin >( iss ) );
  }
}
