#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "HEATR input", 
  "[HEATR]" ){
  GIVEN( "valid HEATR cards" ){
    WHEN( "all entries are provided" ){
      iRecordStream<char> iss( std::istringstream( 
        "-21 -22 -24/\n"
        "1306 1/\n"
        "444\n"
        ) );
      HEATR heatr( iss );
      THEN( "all cards should have the correct values" ){
        REQUIRE( heatr.card1.nendf.value == -21 );
        REQUIRE( heatr.card1.nin.value   == -22 );
        REQUIRE( heatr.card1.nout.value  == -24 );
        REQUIRE( heatr.card1.nplot.value  == 0 );
/*
        REQUIRE( heatr.card2.matde.value  == 0 );
        REQUIRE( heatr.card2.matdp.value  == 1306 );
        REQUIRE( heatr.card2.nbin.value   == 8 );
        REQUIRE( heatr.card2.ntemp.value  == 2 );
        REQUIRE( heatr.card2.iin.value    == 1 );
        REQUIRE( heatr.card2.icoh.value   == 0 );
        REQUIRE( heatr.card2.iform.value  == 0 );
        REQUIRE( heatr.card2.natom.value  == 1 );
        REQUIRE( heatr.card2.mtref.value  == 221 );
        REQUIRE( heatr.card2.iprint.value == 2 );
	
        REQUIRE( heatr.card3.tempr.value[0] == 350.0 * dimwits::kelvin );
        REQUIRE( heatr.card3.tempr.value[1] == 450.0 * dimwits::kelvin );

        REQUIRE( heatr.card4.tol.value  == 0.05 );
        REQUIRE( heatr.card4.emax.value == 1.2  );
*/      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO

