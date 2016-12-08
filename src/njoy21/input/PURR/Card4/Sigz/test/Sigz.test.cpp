#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Sigz input values",
         "[Card4], [Sigz]" ){
  GIVEN( "a value for nsigz (number of temperatures)" ){
    Argument< PURR::Card2::Nsigz > nsigz;
    nsigz.value = 3;

    WHEN( "there are the correct number of temperatures and they are valid" ){
      std::istringstream issPoints(" 1.0 2.0 3.0");

      THEN( "the grid points can be extracted correctly" ){
        long ln(0);
        auto sigz = argument::extract< 
                    PURR::Card4::Sigz >(issPoints, ln, nsigz);
        std::vector< dimwits::Quantity< dimwits::Barn > > refSigzs{
                      1.0*dimwits::barn, 
                      2.0*dimwits::barn, 
                      3.0*dimwits::barn};
        REQUIRE( refSigzs == sigz.value );
      }
    }

    WHEN( "the grid points are invalid" ){
      std::istringstream issPoints(" 1.0 -2.0 3.0");

      THEN( "an exception is thrown" ){
        long ln(0);
        REQUIRE_THROWS(
            argument::extract< PURR::Card4::Sigz >(issPoints, ln, nsigz) );
      }
    }

    WHEN( "commas are used to separate values" ){
      std::istringstream issPoints(" 1.0, 2.0, 3.0");

      THEN( "an exception is thrown" ){
        long ln(0);
        REQUIRE_THROWS(
            argument::extract< PURR::Card4::Sigz >(issPoints, ln, nsigz) );
      }
    }

    WHEN( "there are too many grid points" ){
      std::istringstream issPoints(" 1.0 2.0 3.0 4.0");

      THEN( "an exception is thrown" ){
        long ln(0);
        REQUIRE_THROWS(
            argument::extract< PURR::Card4::Sigz >(issPoints, ln, nsigz) );
      }
    }

    WHEN( "there are not enough many grid points" ){
      std::istringstream issPoints(" 1.0 2.0");

      THEN( "an exception is thrown" ){
        long ln(0);
        REQUIRE_THROWS(
            argument::extract< PURR::Card4::Sigz >(issPoints, ln, nsigz) );
      }
    }
  }
} // SCENARIO

