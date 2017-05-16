#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input::argument::parser;

struct positiveInt{ static bool verify( int i ){ return i > 0; } };
using Discriminator = Discriminating< Base<int>, positiveInt >;

template< typename Char >
using iRecordStream = njoy::njoy21::input::iRecordStream<Char>;

SCENARIO( "Discriminating" ){
  SECTION( "Argument is valid" ){
    int sink = 0;
    iRecordStream<char> iss( std::istringstream("   101") );
    REQUIRE( Discriminator::read( iss, sink ) );
    REQUIRE( sink == 101 );
  }

  SECTION( "Argument is not valid" ){
    int sink = 0;
    iRecordStream<char> iss( std::istringstream("   -101") );
    REQUIRE_THROWS( Discriminator::read( iss, sink ) );
  }
}
