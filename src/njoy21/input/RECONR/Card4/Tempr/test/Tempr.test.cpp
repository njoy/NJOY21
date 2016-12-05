#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Tempr input values",
         "[Card4], [Tempr]"){

  GIVEN( "valid tempr values" ){
    std::vector<double> validTempr{0.0, 293.6};

    THEN( "the returned class has the correct value" ){
      for( auto tempr : validTempr ){
        long ln(0);
        std::istringstream issTempr( std::to_string(tempr) );
        auto temprArg = argument::extract<RECONR::Card4::Tempr>(issTempr, ln);
        REQUIRE( tempr*dimwits::kelvin == temprArg.value );
      }
    }

  }
  GIVEN( "invalid tempr values" ){
    double tempr(-0.01);
    THEN( "an exception is thrown" ){
      long ln(0);
      std::istringstream issTempr( std::to_string(tempr) );
      REQUIRE_THROWS(argument::extract<RECONR::Card4::Tempr>(issTempr, ln) );
    }
  }
  RECONR::Card4::Tempr tempr;

  REQUIRE( tempr.verify(0*dimwits::kelvin) );
  REQUIRE( tempr.verify(293.6*dimwits::kelvin) );
  REQUIRE( not tempr.verify(-1.0*dimwits::kelvin) );

  REQUIRE( "tempr" == tempr.name() );
}

