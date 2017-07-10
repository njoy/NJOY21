#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Verifying GROUPR Card4 input", "[GROUPR], [Card4]" ){

  Argument< GROUPR::Card2::Ntemp > ntemp;
  ntemp.value = 3;

  GIVEN( "valid temp" ){
    iRecordStream< char> issTemps( std::istringstream( " 293.6 600 1200" ) );

    THEN( "the temperatures can be extracted and verified" ){
      std::vector< dimwits::Quantity< dimwits::Kelvin > > refTemps{
        293.6*dimwits::kelvin,
        600*dimwits::kelvin,
        1200*dimwits::kelvin};

      GROUPR::Card4 card4( issTemps, ntemp );
      REQUIRE( refTemps == card4.temp.value );
    }
  }
  GIVEN( "invalid temp---not enough temperatures" ){
    iRecordStream< char> issTemps( std::istringstream( " 293.6 600 " ) );

    THEN( "an exception is thrown" ){
      REQUIRE_THROWS( GROUPR::Card4( issTemps, ntemp ) );
    }
  }
  GIVEN( "invalid temp---too many temperatures" ){
    iRecordStream< char> issTemps( std::istringstream( " 293.6 600 900 1200" ) );

    THEN( "an exception is thrown" ){
      REQUIRE_THROWS( GROUPR::Card4( issTemps, ntemp ) );
    }
  }
} // SCENARIO
