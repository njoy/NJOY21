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
    }
  }
} // SCENARIO
