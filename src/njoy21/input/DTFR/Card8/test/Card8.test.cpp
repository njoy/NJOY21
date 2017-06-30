#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Validating card8 inputs",
  "[DFTR], [Card8]" ){
  GIVEN( "valid DTFR card8 inputs" ){
    WHEN( "all DTFR inputs provided" ){
      iRecordStream<char> iss( std::istringstream( "hisnam 125 1 300" ) );
      DTFR::Card8 card8( iss );
      THEN( "the cards should correspond to correct values" ){
        REQUIRE( "hisnam" == card8.hisnam.value );
        REQUIRE( 125 == card8.mat.value );
        REQUIRE( 1   == card8.jsigz.value );
        REQUIRE( 300 * dimwits::kelvin == card8.dtemp.value );
      } // THEN
    } // WHEN
 
    WHEN( "Mat, Jsigz, and Dtemp are not provided" ){
      iRecordStream<char> iss( std::istringstream( "hisnam / ") );
      DTFR::Card8 card8( iss );
      THEN( "default values for ntabl and ngp used" ){
        REQUIRE( 0 == card8.mat.value );
        REQUIRE( 1 == card8.jsigz.value );
        REQUIRE( 300 * dimwits::kelvin == card8.dtemp.value );
      } // THEN
    } // WHEN
  } // GIVEN
  GIVEN( "invalid DTFR card8 inputs" ){
    WHEN( "all DTFR inputs provided" ){
      iRecordStream<char> iss( std::istringstream( "longname -1 3 250" ) );
      THEN( "an exception is raised" ){
        REQUIRE_THROWS( DTFR::Card8( iss ) );
      } // THEN
    } // WHEN
   
  } // GIVEN
} // SCENARIO
