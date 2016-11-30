#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input::argument;

struct PositiveInt{
  using Value_t = int;
  static std::string name(){ return "positiveInt"; }
  static bool verify( int i ){ return i > 0; }
  static std::string description(){
    return
      "positiveInt is my super cool example policy class.\n"
      "\n"
      "It requires an integer value greater than zero";
  }
};

using Descriminator = Type< PositiveInt >;

SCENARIO( "Argument is present and valid" ){
  int sink = 0;
  std::istringstream iss("   101");
  REQUIRE( Descriminator::read( iss, sink ) );
  REQUIRE( sink == 101 );
}

SCENARIO( "Argument is present but invalid" ){
  int sink = 0;
  std::istringstream iss("   -101");
  REQUIRE_THROWS( Descriminator::read( iss, sink ) );
}

SCENARIO( "Argument is wrong type" ){
  int sink = 0;
  std::istringstream iss("   alphabet");
  REQUIRE_THROWS( Descriminator::read( iss, sink ) );
}

SCENARIO( "Argument is missing" ){
  int sink;
  std::istringstream iss("   ");
  REQUIRE_THROWS( Descriminator::read( iss, sink ) );
}
