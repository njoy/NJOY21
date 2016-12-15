#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input::argument;

template< typename Char >
using iRecordStream = njoy::njoy21::input::iRecordStream<Char>;

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

using Defaultor = Type< DefaultZero >;

SCENARIO( "Argument is present and valid for field with default" ){
  Defaultor defaultor;
  iRecordStream<char> iss( std::istringstream("   101") );
  REQUIRE_NOTHROW( read( iss, defaultor ) );
  REQUIRE( defaultor.value == 101 );
  REQUIRE( defaultor.defaulted == false );
}

SCENARIO( "Argument is missing for field with default" ){
  Defaultor defaultor;
  iRecordStream<char> iss( std::istringstream("  /") );
  REQUIRE_NOTHROW( read( iss, defaultor ) );
  REQUIRE( defaultor.value == 0 );
  REQUIRE( defaultor.defaulted == true );
}

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

SCENARIO( "Argument is present and valid for field without default" ){
  Descriminator descriminator;
  iRecordStream<char> iss( std::istringstream("   101") );
  REQUIRE_NOTHROW( read( iss, descriminator ) );
  REQUIRE( descriminator.value == 101 );
}

SCENARIO( "Argument is missing for field without default" ){
  Descriminator descriminator;
  iRecordStream<char> iss( std::istringstream("  /") );
  REQUIRE_THROWS( read( iss, descriminator ) );
}
