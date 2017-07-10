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

struct DefaultPositiveInt : public PositiveInt {
  using Value_t = int;
  static Value_t defaultValue(){ return 10; }  
};

using Descriminator = parser::Type< PositiveInt >;
using Defaultor = parser::Type< DefaultPositiveInt >;

template< typename Char >
using iRecordStream = njoy::njoy21::input::iRecordStream<Char>;

template< typename T >
struct foo;

SCENARIO( "Argument is defaulted" ){
  iRecordStream<char> iss( std::istringstream("   /") );
  auto sink = extract<DefaultPositiveInt>( iss );
  //foo<decltype(sink)>();
  REQUIRE( sink.defaulted );
  REQUIRE( sink.value == 10 );
}

SCENARIO( "Argument is present and valid" ){
  int sink = 0;
  iRecordStream<char> iss( std::istringstream("   101") );
  REQUIRE( Descriminator::read( iss, sink ) );
  REQUIRE( sink == 101 );
}

SCENARIO( "Argument is present but invalid" ){
  int sink = 0;
  iRecordStream<char> iss( std::istringstream("   -101") );
  REQUIRE_THROWS( Descriminator::read( iss, sink ) );
}

SCENARIO( "Argument is wrong type" ){
  int sink = 0;
  iRecordStream<char> iss( std::istringstream("   alphabet") );
  REQUIRE_THROWS( Descriminator::read( iss, sink ) );
}

SCENARIO( "Argument is missing" ){
  int sink;
  iRecordStream<char> iss( std::istringstream("   ") );
  REQUIRE_THROWS( Descriminator::read( iss, sink ) );
}
