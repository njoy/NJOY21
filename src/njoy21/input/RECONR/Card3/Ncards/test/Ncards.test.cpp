#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Ncards input values" ){

  RECONR::Card3::Ncards ncards;

  REQUIRE( ncards.verify(0) );
  REQUIRE( ncards.verify(1) );
  REQUIRE( not ncards.verify(-1) );

  REQUIRE( "ncards" == ncards.name() );
}

