#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "nendf input values" ){
  long ln = 1;
  GIVEN( "valid nendf tape values" ){
    std::vector<int> validValues{-20, 20, 42, 99, -99};

    THEN( "the returned class has the correct tape value" ){
      for( auto nendf : validValues ){
        std::istringstream issNendf(std::to_string(nendf));
        REQUIRE(nendf == argument::extract< 
                         ACER::Card1::Nendf >( issNendf, ln ).value );
      }
    }
  } // GIVEN

  GIVEN( "invalid nendf tape values" ){
    std::vector<int> invalidValues{-19, 19, 100, -100};
    THEN( "an exception is thrown" ){

      for( auto nendf : invalidValues ){
        std::istringstream issNendf(std::to_string(nendf));
        REQUIRE_THROWS(argument::extract<ACER::Card1::Nendf>(issNendf, ln));
      }
    }
  } // GIVEN
} // SCENARIO

