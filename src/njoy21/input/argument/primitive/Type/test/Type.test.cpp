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
