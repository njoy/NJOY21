#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Verifying PURR Card4 input",
          "[PURR], [Card4]" ){

  Argument< PURR::Card2::Nsigz > nsigz;
  nsigz.value = 3;

  GIVEN( "valid sigzs" ){
    std::istringstream issSigzs( " 1 2 3" );
    long ln(0);

    THEN( "the sigma zero cross section values can be extracted and verified" ){
      std::vector< dimwits::Quantity< dimwits::Barn > > refSigzs{
        1*dimwits::barn,
        2*dimwits::barn,
        3*dimwits::barn};

      PURR::Card4 card4( issSigzs, ln, nsigz );
      REQUIRE( refSigzs == card4.sigz.value );
    }
  }
  GIVEN( "invalid sigz---not enough sigma zero values" ){
    std::istringstream issTemps( " 1 2 " );
    long ln(0);

    THEN( "an exception is thrown" ){
      REQUIRE_THROWS( PURR::Card4 card4( issTemps, ln, nsigz ) );
    }
  }
  GIVEN( "invalid sigz---too many sigma zero values" ){
    std::istringstream issTemps( " 1 2 3 4 " );
    long ln(0);

    THEN( "an exception is thrown" ){
      REQUIRE_THROWS( PURR::Card4 card4( issTemps, ln, nsigz ) );
    }
  }
} // SCENARIO

