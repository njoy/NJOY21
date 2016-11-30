#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Ngrid input values" ){

  RECONR::Card3::Ngrid ngrid;

  REQUIRE( ngrid.verify(0) );
  REQUIRE( ngrid.verify(1) );
  REQUIRE( not ngrid.verify(-1) );

  REQUIRE( "ngrid" == ngrid.name() );
}


