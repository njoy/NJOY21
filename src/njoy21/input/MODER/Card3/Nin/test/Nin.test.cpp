#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "special values" ){
  Argument< MODER::Card1::Nout > nout; nout.value = 21;
  iRecordStream<char> iss( std::istringstream("   0") );
  REQUIRE( argument::extract< MODER::Card3::Nin >( iss, nout ).value == 0 );
}

SCENARIO( "typical values" ){
  Argument< MODER::Card1::Nout > nout; nout.value = 21;
  {
    iRecordStream<char> iss( std::istringstream("   19") );
    REQUIRE_THROWS( argument::extract< MODER::Card3::Nin >( iss, nout ) );
  }{
    iRecordStream<char> iss( std::istringstream("   -19") );
    REQUIRE_THROWS( argument::extract< MODER::Card3::Nin >( iss, nout ) );
  }{
    iRecordStream<char> iss( std::istringstream("   21") );
    REQUIRE_THROWS( argument::extract< MODER::Card3::Nin >( iss, nout ) );
  }{
    iRecordStream<char> iss( std::istringstream("   -21") );
    REQUIRE_THROWS( argument::extract< MODER::Card3::Nin >( iss, nout ) );
  }{
    iRecordStream<char> iss( std::istringstream("   20") );
    REQUIRE( argument::extract
	     < MODER::Card3::Nin >( iss, nout ).value == 20 );
  }{
    iRecordStream<char> iss( std::istringstream("   -20") );
    REQUIRE( argument::extract
	     < MODER::Card3::Nin >( iss, nout ).value == -20 );
  }{
    iRecordStream<char> iss( std::istringstream("   50") );
    REQUIRE( argument::extract
	     < MODER::Card3::Nin >( iss, nout ).value == 50 );
  }{
    iRecordStream<char> iss( std::istringstream("   -50") );
    REQUIRE( argument::extract
	     < MODER::Card3::Nin >( iss, nout ).value == -50 );
  }{
    iRecordStream<char> iss( std::istringstream("   99") );
    REQUIRE( argument::extract
	     < MODER::Card3::Nin >( iss, nout ).value == 99 );
  }{
    iRecordStream<char> iss( std::istringstream("   -99") );
    REQUIRE( argument::extract
	     < MODER::Card3::Nin >( iss, nout ).value == -99 );
  }{
    iRecordStream<char> iss( std::istringstream("   100") );
    REQUIRE_THROWS( argument::extract< MODER::Card3::Nin >( iss, nout ) );
  }{
    iRecordStream<char> iss( std::istringstream("   -100") );
    REQUIRE_THROWS( argument::extract< MODER::Card3::Nin >( iss, nout ) );
  }{
    iRecordStream<char> iss( std::istringstream("   ") );
    REQUIRE_THROWS( argument::extract< MODER::Card3::Nin >( iss, nout ) );
  }
}
