#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "errint input values",
         "[Card4], [Errint]"){

  GIVEN( "valid errint values" ){
    std::vector<double> validErrint{0.1, 1.0, 1E6};

    THEN( "the returned class has the correct tape value" ){
      for( auto errint : validErrint ){
        long ln(0);
        std::istringstream issErrint(std::to_string(errint));
        REQUIRE( errint*dimwits::barn == argument::extract<
                           RECONR::Card4::Errint >(issErrint, ln).value );
      }
    }
  }
//RECONR::Card4::Errint errint;
//REQUIRE( errint.verify(0.1*dimwits::barn) );
//REQUIRE( errint.verify(1.0*dimwits::barn) );
//REQUIRE( errint.verify(1E6*dimwits::barn) );
//REQUIRE( not errint.verify(0.0*dimwits::barn) );
}

