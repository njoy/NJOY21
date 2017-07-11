#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Validating card7 inputs",
  "[DFTR], [Card7]" ){
  GIVEN( "valid DTFR card7 inputs" ){
    WHEN( "all DTFR inputs provided" ){
      iRecordStream<char> iss( std::istringstream( "5 12" ) );
      DTFR::Card7 card7( iss );
      THEN( "the cards should correspond to correct values" ){
        REQUIRE( 5  == card7.nptabl.value );
        REQUIRE( 12 == card7.ngp.value );
      } // THEN
    } // WHEN
    WHEN( "Ntabl and Npg not provided" ){
      iRecordStream<char> iss( std::istringstream( " / ") );
      DTFR::Card7 card7( iss );
      THEN( "default values for ntabl and ngp used" ){
        REQUIRE( 0 == card7.nptabl.value );
        REQUIRE( 0 == card7.ngp.value );
      } // THEN
    } // WHEN
  } // GIVEN
  GIVEN( "invalid DTFR card7 inputs" ){
    WHEN( "all DTFR inputs provided" ){
      iRecordStream<char> iss( std::istringstream( "-1 3" ) );
      THEN( "an exception is raised" ){
        REQUIRE_THROWS( DTFR::Card7( iss ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
