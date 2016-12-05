#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "mat input values",
         "[Card3], [mat]"){

  RECONR::Card3::Mat mat;
  REQUIRE( mat.verify(0) );
  REQUIRE( mat.verify(1) );
  REQUIRE( mat.verify(9999) );
  REQUIRE( not mat.verify(-1) );
  REQUIRE( not mat.verify(10000) );

  REQUIRE( "mat" == mat.name() );
}
