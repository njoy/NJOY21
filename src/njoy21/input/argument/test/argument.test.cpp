#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Verifying material numbers" ){
  argument::common::Matd mat;

  REQUIRE( mat.verify(1) );
  REQUIRE( not mat.verify(0) );
  REQUIRE( not mat.verify(10000) );

}
