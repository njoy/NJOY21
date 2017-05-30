#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input::argument::parser;

template< typename Char >
using iRecordStream = njoy::njoy21::input::iRecordStream<Char>;

SCENARIO( "Optional" ){
  SECTION( "Argument is present" ){
    int sink = 0;
    iRecordStream<char> iss( std::istringstream("   101") );
    REQUIRE( Optional< Base<int> >::read( iss, sink ) );
    REQUIRE( sink == 101 );
  }

  SECTION( "Slash" ){
    int sink = 0;
    iRecordStream<char> iss( std::istringstream("/") );
    REQUIRE( not Optional< Base<int> >::read( iss, sink ) );
    REQUIRE( sink == 0 );
  }

  SECTION( "Argument is wrong type" ){
    int sink = 0;
    iRecordStream<char> iss( std::istringstream(" alphabet") );
    REQUIRE_THROWS( Optional< Base<int> >::read( iss, sink ) );
  }
}
