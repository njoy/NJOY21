#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "value range" ){
  Argument< HEATR::Card1::Nendf > nendf; nendf.value = 21;
  Argument< HEATR::Card1::Nin > nin;
  Argument< HEATR::Card1::Nout > nout;
  {
    iRecordStream<char> iss( std::istringstream("   19") );
    nin.value = 22;
    nout.value = 23;
    REQUIRE_THROWS( argument::extract< HEATR::Card1::Nplot >
		    ( iss, nendf, nin, nout ) );
  }{
    iRecordStream<char> iss( std::istringstream("   -19") );
    nin.value = -22;
    nout.value = -23;
    REQUIRE_THROWS( argument::extract< HEATR::Card1::Nplot >
		    ( iss, nendf, nin, nout ) );
  }{
    iRecordStream<char> iss( std::istringstream("   -21") );
    nin.value = 22;
    nout.value = 23;
    REQUIRE_THROWS( argument::extract< HEATR::Card1::Nplot >
		    ( iss, nendf, nin, nout ) );
  }{
    iRecordStream<char> iss( std::istringstream("   -22") );
    nin.value = 22;
    nout.value = 23;
    REQUIRE_THROWS( argument::extract< HEATR::Card1::Nplot >
		    ( iss, nendf, nin, nout ) );
  }{
    iRecordStream<char> iss( std::istringstream("   -23") );
    nin.value = 22;
    nout.value = 23;
    REQUIRE_THROWS( argument::extract< HEATR::Card1::Nplot >
		    ( iss, nendf, nin, nout ) );
  }{
    iRecordStream<char> iss( std::istringstream("   20") );
    nin.value = 22;
    nout.value = 23;
    REQUIRE( argument::extract< HEATR::Card1::Nplot >
	     ( iss, nendf, nin, nout ).value == 20 );
  }{
    iRecordStream<char> iss( std::istringstream("   -20") );
    nin.value = -22;
    nout.value = -23;
    REQUIRE( argument::extract< HEATR::Card1::Nplot >
	     ( iss, nendf, nin, nout ).value == -20 );
  }{
    iRecordStream<char> iss( std::istringstream("   50") );
    nin.value = 22;
    nout.value = 23;
    REQUIRE( argument::extract< HEATR::Card1::Nplot >
	     ( iss, nendf, nin, nout ).value == 50 );
  }{
    iRecordStream<char> iss( std::istringstream("   -50") );
    nin.value = 22;
    nout.value = 23;
    REQUIRE( argument::extract< HEATR::Card1::Nplot >
	     ( iss, nendf, nin, nout ).value == -50 );
  }{
    iRecordStream<char> iss( std::istringstream("   -50") );
    nin.value = -22;
    nout.value = -23;
    REQUIRE( argument::extract< HEATR::Card1::Nplot >
	     ( iss, nendf, nin, nout ).value == -50 );
  }{
    iRecordStream<char> iss( std::istringstream("   99") );
    nin.value = 22;
    nout.value = 23;
    REQUIRE( argument::extract< HEATR::Card1::Nplot >
	     ( iss, nendf, nin, nout ).value == 99 );
  }{
    iRecordStream<char> iss( std::istringstream("   -99") );
    nin.value = -22;
    nout.value = -23;
    REQUIRE( argument::extract< HEATR::Card1::Nplot >
	     ( iss, nendf, nin, nout ).value == -99 );
  }{
    iRecordStream<char> iss( std::istringstream("   /") );
    nin.value = 22;
    nout.value = 23;
    REQUIRE( argument::extract< HEATR::Card1::Nplot >
	     ( iss, nendf, nin, nout ).value == 0 );
  }{
    iRecordStream<char> iss( std::istringstream("   100") );
    nin.value = 22;
    nout.value = 23;
    REQUIRE_THROWS( argument::extract< HEATR::Card1::Nplot >
		    ( iss, nendf, nin, nout ) );
  }{
    iRecordStream<char> iss( std::istringstream("   -100") );
    nin.value = -22;
    nout.value = -23;
    REQUIRE_THROWS( argument::extract< HEATR::Card1::Nplot >
		    ( iss, nendf, nin, nout ) );
  }
}
