#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Verifying THERMR Card3 input", "[THERMR], [Card3]" ){

  GIVEN( "a valid value for ntemp" ){
    Argument< THERMR::Card2::Ntemp > ntemp; ntemp.value = 3;
    WHEN( "Card3 input is valid" ){
      iRecordStream< char> iss( std::istringstream( "293.6 600 1200" ) );
      THEN( "the tempreratures can be extracted and verified" ){
        std::vector< dimwits::Quantity< dimwits::Kelvin > > refTemprs{
          293.6*dimwits::kelvin,
          600*dimwits::kelvin,
          1200*dimwits::kelvin};
        THERMR::Card3 card3( iss, ntemp );
        REQUIRE( refTemprs == card3.tempr.value );
      } // THEN
    } // WHEN
    WHEN( "not enough tempreratures provided" ){
      iRecordStream< char> iss( std::istringstream( "293.6 600 " ) );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( THERMR::Card3( iss, ntemp ) );
      } // THEN
    } // WHEN
    WHEN( "too many tempreratures provided" ){
      iRecordStream< char> iss( std::istringstream( "293.6 600 900 1200" ) );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( THERMR::Card3( iss, ntemp ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
