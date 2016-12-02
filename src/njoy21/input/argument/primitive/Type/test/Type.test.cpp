#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input::argument::primitive;

SCENARIO( "simple case" ){
  int sink = 0;
  std::istringstream iss("   101");
  REQUIRE( Type<int>::read( iss, sink ) );
  REQUIRE( sink == 101 );
}

SCENARIO( "string" ){
  SECTION("with quotes"){
    std::string sink = "";
    std::istringstream iss("   'Lorem Ipsum' ");
    REQUIRE( Type<std::string>::read( iss, sink ) );
    REQUIRE( sink == "Lorem Ipsum" );
  }

  SECTION("without quotes"){
    std::string sink = "";
    std::istringstream iss("   Lorem Ipsum ");
    REQUIRE( Type<std::string>::read( iss, sink ) );
    REQUIRE( sink == "Lorem" );
  }
}

SCENARIO( "Quantity" ){
  dimwits::Quantity< dimwits::Meter > sink = 0 * dimwits::meter;
  std::istringstream iss("   10 ");
  REQUIRE( Type< dimwits::Quantity
	         < dimwits::Meter > >::read( iss, sink ) );
  REQUIRE( sink == 10 * dimwits::meter );
}

SCENARIO( "Vector" ){
  std::vector< int > sink;
  std::vector< int > reference{10, 20, 30};
  std::istringstream iss("   10 20 30");
  REQUIRE( Type< std::vector< int > >::read( iss, sink ) );
  REQUIRE( sink == reference );
}

SCENARIO( "Vector of Quanitities" ){
  std::vector< dimwits::Quantity< dimwits::Meter > > lengths;
  std::vector< dimwits::Quantity< dimwits::Meter > > reflengths{ 
    10*dimwits::meter, 20*dimwits::meter, 30*dimwits::meter};

  std::istringstream iss("   10 20 30");
  REQUIRE( Type< std::vector< dimwits::Quantity< dimwits::Meter > > >::read( 
          iss, lengths ) );
  REQUIRE( lengths == reflengths );

}
