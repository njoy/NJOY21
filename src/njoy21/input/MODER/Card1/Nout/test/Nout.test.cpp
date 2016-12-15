#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "moder card1 nout" ){
  Argument< MODER::Card1::Nin > nin; nin.value = 22;
  {
    iRecordStream<char> iss( std::istringstream(" 19") );
    REQUIRE_THROWS( argument::extract< MODER::Card1::Nout >( iss, nin ) );
  }{
    iRecordStream<char> iss( std::istringstream(" -19") );
    REQUIRE_THROWS( argument::extract< MODER::Card1::Nout >( iss, nin ) );
  }  {
    iRecordStream<char> iss( std::istringstream(" 22") );
    REQUIRE_THROWS( argument::extract< MODER::Card1::Nout >( iss, nin ) );
  }{
    iRecordStream<char> iss( std::istringstream(" -22") );
    REQUIRE_THROWS( argument::extract< MODER::Card1::Nout >( iss, nin ) );
  }{
    iRecordStream<char> iss( std::istringstream(" 20") );
    REQUIRE( 20 == argument::extract< MODER::Card1::Nout >( iss, nin ).value );
  }{
    iRecordStream<char> iss( std::istringstream(" -20") );
    REQUIRE( -20 == argument::extract< MODER::Card1::Nout >( iss, nin ).value );
  }{
    iRecordStream<char> iss( std::istringstream(" 50") );
    REQUIRE( 50 == argument::extract< MODER::Card1::Nout >( iss, nin ).value );
  }{
    iRecordStream<char> iss( std::istringstream(" -50") );
    REQUIRE( -50 == argument::extract< MODER::Card1::Nout >( iss, nin ).value );
  }{
    iRecordStream<char> iss( std::istringstream(" 99") );
    REQUIRE( 99 == argument::extract< MODER::Card1::Nout >( iss, nin ).value );
  }{
    iRecordStream<char> iss( std::istringstream(" -99") );
    REQUIRE( -99 == argument::extract< MODER::Card1::Nout >( iss, nin ).value );
  }{
    iRecordStream<char> iss( std::istringstream(" 100") );
    REQUIRE_THROWS( argument::extract< MODER::Card1::Nout >( iss, nin ) );
  }{
    iRecordStream<char> iss( std::istringstream(" -100") );
    REQUIRE_THROWS( argument::extract< MODER::Card1::Nout >( iss, nin ) );
  }
}
