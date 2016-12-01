#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Tempr input values",
         "[Card4], [Tempr]"){
  RECONR::Card4::Tempr tempr;

  REQUIRE( tempr.verify(0*dimwits::kelvin) );
  REQUIRE( tempr.verify(293.6*dimwits::kelvin) );
  REQUIRE( not tempr.verify(-1.0*dimwits::kelvin) );

  REQUIRE( "tempr" == tempr.name() );
}

