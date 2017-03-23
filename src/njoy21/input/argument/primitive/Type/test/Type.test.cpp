#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input::argument::primitive;

template< typename Char >
using iRecordStream = njoy::njoy21::input::iRecordStream<Char>;

struct MyArg{ int value; };

SCENARIO( "simple case" ){
  int sink = 0;
  iRecordStream<char> iss( std::istringstream("   101") );
  REQUIRE( Type<int>::read( iss, sink ) );
  REQUIRE( sink == 101 );
}

SCENARIO( "simple failing case" ){
  double sink = 0.0;
  iRecordStream<char> iss( std::istringstream("   100.abc") );
  Type<double>::read( iss, sink );
  REQUIRE( iss.fail() );
}

SCENARIO( "string" ){
  SECTION("with quotes"){
    std::string sink = "";
    iRecordStream<char> iss( std::istringstream("   'Lorem Ipsum'") );
    REQUIRE( Type<std::string>::read( iss, sink ) );
    REQUIRE( sink == "Lorem Ipsum" );
  }

  SECTION("without quotes"){
    std::string sink = "";
    iRecordStream<char> iss( std::istringstream("   Lorem Ipsum ") );
    REQUIRE( Type<std::string>::read( iss, sink ) );
    REQUIRE( sink == "Lorem" );
    REQUIRE( not iss.fail() );
  }

  SECTION("without quotes"){
    std::string sink = "";
    iRecordStream<char> iss( std::istringstream("   Lorem Ipsum ") );
    REQUIRE( Type<std::string>::read( iss, sink ) );
    REQUIRE( sink == "Lorem" );
    REQUIRE( not iss.fail() );
    std::getline( iss, sink );
    REQUIRE( sink == " Ipsum " );
  }
  
  SECTION("incomplete quotes"){
    std::string sink = "";
    iRecordStream<char> iss( std::istringstream("   'Lorem Ipsum ") );
    REQUIRE( Type<std::string>::read( iss, sink ) );
    REQUIRE( iss.fail() );
  }

  SECTION("trailing slash"){
    std::string sink = "";
    iRecordStream<char> iss( std::istringstream(" hello/world ") );
    REQUIRE( Type<std::string>::read( iss, sink ) );
    REQUIRE( sink == "hello" );
    REQUIRE( not iss.fail() );
    std::getline( iss, sink );
    REQUIRE( sink == "/world " );
  }
}

SCENARIO( "Quantity" ){
  dimwits::Quantity< dimwits::Meter > sink = 0 * dimwits::meter;
  iRecordStream<char> iss( std::istringstream("   10 ") );
  REQUIRE( Type< dimwits::Quantity
	         < dimwits::Meter > >::read( iss, sink ) );
  REQUIRE( sink == 10 * dimwits::meter );
}

SCENARIO( "Pair" ){
  using MyPair = std::pair< int, double >;
  MyPair sink{0, 1.0};
  iRecordStream<char> iss( std::istringstream("   10  100.0") );
  REQUIRE( Type< MyPair >::read( iss, sink ) );
  REQUIRE( sink.first == 10 );
  REQUIRE( sink.second == 100. );
}

SCENARIO( "Vector" ){
  std::vector< int > sink;
  std::vector< int > reference{10, 20, 30};
  MyArg arg{3};
  SECTION( "correct number of entries" ){
    iRecordStream<char> iss( std::istringstream("   10 20 30") );
    REQUIRE( Type< std::vector< int > >::read( iss, sink, arg ) );
    REQUIRE( sink == reference );
  }
  SECTION( "Incorrect number of entries" ){
    iRecordStream<char> iss( std::istringstream("   10 20") );
    REQUIRE( Type< std::vector< int > >::read( iss, sink, arg ) );
    REQUIRE( iss.fail() );
  }
}

SCENARIO( "Vector of Quanitities" ){
  std::vector< dimwits::Quantity< dimwits::Meter > > lengths;
  std::vector< dimwits::Quantity< dimwits::Meter > > reflengths
  { 10*dimwits::meter, 20*dimwits::meter, 30*dimwits::meter };

  iRecordStream<char> iss( std::istringstream("   10 20 30") );
  MyArg arg{3};

  REQUIRE( Type< std::vector< dimwits::Quantity< dimwits::Meter > > >::read( 
	     iss, lengths, arg ) );
  REQUIRE( lengths == reflengths );

}
