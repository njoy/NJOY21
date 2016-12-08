#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Verifying PURR Card3 input",
          "[PURR], [Card3]" ){

  Argument< PURR::Card2::Ntemp > ntemp;
  ntemp.value = 3;

  GIVEN( "valid temp" ){
    std::istringstream issTemps( " 293.6 600 1200" );
    long ln(0);

    THEN( "the temperatures can be extracted and verified" ){
      std::vector< dimwits::Quantity< dimwits::Kelvin > > refTemps{
        293.6*dimwits::kelvin,
        600*dimwits::kelvin,
        1200*dimwits::kelvin};

      PURR::Card3 card3( issTemps, ln, ntemp );
      REQUIRE( refTemps == card3.temp.value );
    }
  }
  GIVEN( "invalid temp---not enough temperatures" ){
    std::istringstream issTemps( " 293.6 600 " );
    long ln(0);

    THEN( "an exception is thrown" ){
      REQUIRE_THROWS( PURR::Card3 card3( issTemps, ln, ntemp ) );
    }
  }
  GIVEN( "invalid temp---too many temperatures" ){
    std::istringstream issTemps( " 293.6 600 900 1200" );
    long ln(0);

    THEN( "an exception is thrown" ){
      REQUIRE_THROWS( PURR::Card3 card3( issTemps, ln, ntemp ) );
    }
  }
} // SCENARIO
