#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Enode input values",
         "[Card6], [Enode]" ){
  GIVEN( "a value for ngrid (number of grid points)" ){
    Argument< RECONR::Card3::Ngrid > ngrid;
    ngrid.value = 3;

    WHEN( "there are the correct number of grid points and they are valid" ){
      std::istringstream issPoints(" 1.0 2.0 3.0");

      THEN( "the grid points can be extracted correctly" ){
        long ln(0);
        auto grid = argument::extract< 
                    RECONR::Card6::Enode >(issPoints, ln, ngrid);
        std::vector< dimwits::Quantity< dimwits::ElectronVolt > > refGrid{
                      1.0*dimwits::electronVolt, 
                      2.0*dimwits::electronVolt, 
                      3.0*dimwits::electronVolt};
        REQUIRE( refGrid == grid.value );
      }
    }

    WHEN( "the grid points are invalid" ){
      std::istringstream issPoints(" 1.0 -2.0 3.0");

      THEN( "an exception is thrown" ){
        long ln(0);
        REQUIRE_THROWS(
            argument::extract< RECONR::Card6::Enode >(issPoints, ln, ngrid) );
      }
    }

    WHEN( "commas are used to separate values" ){
      std::istringstream issPoints(" 1.0, 2.0, 3.0");

      THEN( "an exception is thrown" ){
        long ln(0);
        REQUIRE_THROWS(
            argument::extract< RECONR::Card6::Enode >(issPoints, ln, ngrid) );
      }
    }

    WHEN( "there are too many grid points" ){
      std::istringstream issPoints(" 1.0 2.0 3.0 4.0");

      THEN( "an exception is thrown" ){
        long ln(0);
        REQUIRE_THROWS(
            argument::extract< RECONR::Card6::Enode >(issPoints, ln, ngrid) );
      }
    }

    WHEN( "there are not enough many grid points" ){
      std::istringstream issPoints(" 1.0 2.0");

      THEN( "an exception is thrown" ){
        long ln(0);
        REQUIRE_THROWS(
            argument::extract< RECONR::Card6::Enode >(issPoints, ln, ngrid) );
      }
    }

  } // GIVEN
} // SCENARIO
