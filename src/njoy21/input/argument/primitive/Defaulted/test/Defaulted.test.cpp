#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input::argument::primitive;

struct defaultZero{ static int defaultValue(){ return 0; } };
using Defaultor = Defaulted< Type<int>, defaultZero >;

SCENARIO( "Argument is present" ){
  int sink = 0;
  std::istringstream iss("   101");
  REQUIRE( Defaultor::read( iss, sink ) );
  REQUIRE( sink == 101 );
}

SCENARIO( "Argument is missing" ){
  int sink = 101;
  std::istringstream iss("   ");
  REQUIRE( not Defaultor::read( iss, sink ) );
  REQUIRE( sink == 0 );
}
