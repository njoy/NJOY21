#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Validating card2 inputs", 
  "[DTFR], [Card2]" ){
  GIVEN( "valid DTFR card2 inputs" ){
    iRecordStream<char> iss( std::istringstream( "1 1 0" ) );
    DTFR::Card2 card2( iss );

    THEN( "the cards should correspond to correct values" ){
      REQUIRE( 1 == card2.iprint.value );
      REQUIRE( 1 == card2.ifilm.value );
      REQUIRE( 0 == card2.iedit.value );
    } // THEN
  } // GIVEN

  GIVEN( "no optional inputs" ){
    iRecordStream<char> iss( std::istringstream( "1  /" ) );
    DTFR::Card2 card2( iss );

    THEN( "the default values are substituted in " ){
      REQUIRE( 1 == card2.iprint.value );
      REQUIRE( 0 == card2.ifilm.value );
      REQUIRE( 0 == card2.iedit.value );
    } // THEN
  } // GIVEN
  
  GIVEN( "invalid DTFR card2 inputs" ){
    iRecordStream<char> iss( std::istringstream( "2 1 1" ) );
    THEN( "an exception is thrown" ){
      REQUIRE_THROWS( DTFR::Card2( iss ) );
    } // THEN
  } // GIVEN
} // SCENARIO

