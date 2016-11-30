#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input::argument;

struct DefaultZero {
  using Value_t = int;
  static std::string name(){ return "defaultZero"; }
  static Value_t defaultValue(){ return 0; }
  static std::string description(){
    return
      "defaultZero is my super cool example policy class.\n"
      "\n"
      "It defaults to zero when the value cannot be read";
  }
};

SCENARIO
( "Argument is present and valid for field with default when extracted" ){
  std::istringstream iss("   101");
  long lineNumber = 1;
  auto defaultor = extract<DefaultZero>( iss, lineNumber );
  REQUIRE( defaultor.value == 101 );
  REQUIRE( defaultor.defaulted == false );
}

SCENARIO( "Argument has wrong type when extracted" ){
  long lineNumber = 1;
  std::istringstream iss("  alphabet");
  REQUIRE_THROWS( extract<DefaultZero>( iss, lineNumber ) );
}
