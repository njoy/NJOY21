#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input::argument::parser;

struct positiveInt{
  using Value_t = int;
  static bool verify( int i ){ return i > 0; }
};

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

  SECTION( "unwrapping values" ){
    int i = 1;
    std::optional<int> oi = 1;
    bool works;
    works = std::is_same_type< decltype( Discriminator::unwrap(i) ), int& >::value;
    REQUIRE(works);
    works = std::is_same_type< decltype( Discriminator::unwrap(oi) ), int& >::value;
    REQUIRE(works);
  }
}
