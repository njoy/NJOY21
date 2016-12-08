#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Temp input values",
         "[Card3], [Temp]" ){
  GIVEN( "a value for ntemp (number of temperatures)" ){
    Argument< PURR::Card2::Ntemp > ntemp;
    ntemp.value = 3;

    WHEN( "there are the correct number of temperatures and they are valid" ){
      std::istringstream issPoints(" 1.0 2.0 3.0");

      THEN( "the grid points can be extracted correctly" ){
        long ln(0);
        auto temps = argument::extract< 
                    PURR::Card3::Temp >(issPoints, ln, ntemp);
        std::vector< dimwits::Quantity< dimwits::Kelvin > > refTemps{
                      1.0*dimwits::kelvin, 
                      2.0*dimwits::kelvin, 
                      3.0*dimwits::kelvin};
        REQUIRE( refTemps == temps.value );
      }
    }

    WHEN( "the grid points are invalid" ){
      std::istringstream issPoints(" 1.0 -2.0 3.0");

      THEN( "an exception is thrown" ){
        long ln(0);
        REQUIRE_THROWS(
            argument::extract< PURR::Card3::Temp >(issPoints, ln, ntemp) );
      }
    }

    WHEN( "commas are used to separate values" ){
      std::istringstream issPoints(" 1.0, 2.0, 3.0");

      THEN( "an exception is thrown" ){
        long ln(0);
        REQUIRE_THROWS(
            argument::extract< PURR::Card3::Temp >(issPoints, ln, ntemp) );
      }
    }

    WHEN( "there are too many grid points" ){
      std::istringstream issPoints(" 1.0 2.0 3.0 4.0");

      THEN( "an exception is thrown" ){
        long ln(0);
        REQUIRE_THROWS(
            argument::extract< PURR::Card3::Temp >(issPoints, ln, ntemp) );
      }
    }

    WHEN( "there are not enough many grid points" ){
      std::istringstream issPoints(" 1.0 2.0");

      THEN( "an exception is thrown" ){
        long ln(0);
        REQUIRE_THROWS(
            argument::extract< PURR::Card3::Temp >(issPoints, ln, ntemp) );
      }
    }
  }
} // SCENARIO
