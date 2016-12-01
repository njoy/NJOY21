#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "errmax input values",
         "[Card4], [Errmax]"){

  GIVEN( "valid err values" ){
    Argument< RECONR::Card4::Err > err;
    err.value = 0.01;
    RECONR::Card4::Errmax errmax;

    WHEN( "the errmax values are valid" ){
      REQUIRE( errmax.verify( 0.01, err ) );
      REQUIRE( errmax.verify( 0.2, err ) );
    }
    WHEN( "the errmax values are invalid" ){
      REQUIRE( not errmax.verify( 0.002, err ) );
    }
  }
}
