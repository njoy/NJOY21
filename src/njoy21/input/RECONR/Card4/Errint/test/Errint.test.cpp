#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "errint input values",
         "[Card4], [Errmax]"){

  RECONR::Card4::Errint errint;
  REQUIRE( errint.verify(0.1*barn) );
  REQUIRE( errint.verify(1.0*barn) );
  REQUIRE( errint.verify(1E6*barn) );
  REQUIRE( not errint.verify(0.0*barn) );
}

