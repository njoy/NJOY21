#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "errint input values",
         "[Card4], [Errint]"){

  Argument< RECONR::Card4::Err > err;
  err.value = 0.01;
  GIVEN( "valid errint values" ){
    std::vector<double> validErrint{0.1, 1.0, 1E6};

    THEN( "the returned class has the correct value" ){
      for( auto errint : validErrint ){
        long ln(0);
        std::istringstream issErrint(std::to_string(errint));
        REQUIRE( errint*dimwits::barn == argument::extract<
                           RECONR::Card4::Errint >(issErrint, ln, err).value );
      }
    }
  }

  GIVEN( "invalid errint values:" ){
    THEN( "an exception is thrown" ){
      long ln(0);
      double errint(0.0);
      std::istringstream issErrint(std::to_string(errint));
      REQUIRE_THROWS( argument::extract<
                         RECONR::Card4::Errint >(issErrint, ln, err) );
    }
  }
}

