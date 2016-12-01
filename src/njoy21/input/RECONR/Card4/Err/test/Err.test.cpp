#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "err input values",
         "[Card4], [Err]"){
  RECONR::Card4::Err err;

  REQUIRE( err.verify(0.1) );
  REQUIRE( err.verify(1.0) );
  REQUIRE( err.verify(1E6) );
  REQUIRE( not err.verify(0.0) );

  REQUIRE( "err" == err.name() );
} 
