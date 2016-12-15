#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input::argument::primitive;

template< typename Char >
using iRecordStream = njoy::njoy21::input::iRecordStream<Char>;

SCENARIO( "Argument is present" ){
  int sink = 0;
  iRecordStream<char> iss( std::istringstream("   101") );
  REQUIRE( Required< Type<int> >::read( iss, sink ) );
  REQUIRE( sink == 101 );
}

SCENARIO( "Argument is not present" ){
  int sink = 0;
  iRecordStream<char> iss( std::istringstream("") );
  REQUIRE_THROWS( Required< Type<int> >::read( iss, sink ) );
}

SCENARIO( "Argument is wrong type" ){
  int sink = 0;
  iRecordStream<char> iss( std::istringstream(" alphabet ") );
  REQUIRE_THROWS( Required< Type<int> >::read( iss, sink ) );
}
