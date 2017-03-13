#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "value range" ){
  Argument< GASPR::Card1::Nendf > nendf; nendf.value = 21;
  Argument< GASPR::Card1::Nin > nin;
  {
    iRecordStream<char> iss( std::istringstream("   19") );
    nin.value = 22;
    REQUIRE_THROWS( argument::extract< GASPR::Card1::Nout >( iss, nendf, nin ) );
  }{
    iRecordStream<char> iss( std::istringstream("   -19") );
    nin.value = -22;
    REQUIRE_THROWS( argument::extract< GASPR::Card1::Nout >
		    ( iss, nendf, nin ) );
  }{
    iRecordStream<char> iss( std::istringstream("   -20") );
    nin.value = 22;
    REQUIRE_THROWS( argument::extract< GASPR::Card1::Nout >
		    ( iss, nendf, nin ) );
  }{
    iRecordStream<char> iss( std::istringstream("   20") );
    nin.value = 22;
    REQUIRE( argument::extract< GASPR::Card1::Nout >
	     ( iss, nendf, nin ).value == 20 );
  }{
    iRecordStream<char> iss( std::istringstream("   -20") );
    nin.value = -22;
    REQUIRE( argument::extract< GASPR::Card1::Nout >
	     ( iss, nendf, nin ).value == -20 );
  }{
    iRecordStream<char> iss( std::istringstream("   50") );
    nin.value = 22;
    REQUIRE( argument::extract< GASPR::Card1::Nout >
	     ( iss, nendf, nin ).value == 50 );
  }{
    iRecordStream<char> iss( std::istringstream("   -50") );
    nin.value = -22;
    REQUIRE( argument::extract< GASPR::Card1::Nout >
	     ( iss, nendf, nin ).value == -50 );
  }{
    iRecordStream<char> iss( std::istringstream("   99") );
    nin.value = 22;
    REQUIRE( argument::extract< GASPR::Card1::Nout >
	     ( iss, nendf, nin ).value == 99 );
  }{
    iRecordStream<char> iss( std::istringstream("   -99") );
    nin.value = -22;
    REQUIRE( argument::extract< GASPR::Card1::Nout >
	     ( iss, nendf, nin ).value == -99 );
  }{
    iRecordStream<char> iss( std::istringstream("   100") );
    nin.value = 22;
    REQUIRE_THROWS( argument::extract< GASPR::Card1::Nout >( iss, nendf, nin ) );
  }{
    iRecordStream<char> iss( std::istringstream("   -100") );
    nin.value = -22;
    REQUIRE_THROWS( argument::extract< GASPR::Card1::Nout >( iss, nendf, nin ) );
  }{
    iRecordStream<char> iss( std::istringstream("   ") );
    nin.value = 22;
    REQUIRE_THROWS( argument::extract< GASPR::Card1::Nout >( iss, nendf, nin ) );
  }
}
