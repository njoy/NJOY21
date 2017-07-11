#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "HollerithNames input values",
  "[Card4], [HollerithNames]" ){
  Argument< DTFR::Card3::Iptotl > iptotl;
  iptotl.value = 6 ;

 GIVEN( "the correct number of names" ){

    WHEN( "the names are of correct length" ){
      iRecordStream< char> iss( std::istringstream("pheat1 edits dtfr") );
      DTFR::Card4 card4( iss, iptotl );
      
      THEN( "the Hollerith names can be extracted correctly" ){
        std::vector<std::string > refHolNames{ "pheat1", "edits", "dtfr" };
        REQUIRE( refHolNames == card4.hollerithNames.value );
      } // THEN
    } // WHEN

    WHEN( "a name is too long (over 6 characters)" ){
      iRecordStream< char> iss( std::istringstream("longword edits dtfr") );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( DTFR::Card4( iss, iptotl ) );
      } // THEN
    } // WHEN

    WHEN( "commas are used to separate values" ){
      iRecordStream< char> iss( std::istringstream("pheat1, edits, dtfr") );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( DTFR::Card4( iss, iptotl ) );
      } // THEN
    } // WHEN
  } // GIVEN

  GIVEN( "an incorrect number of names" ){
    WHEN( "there are too many names" ){
      iRecordStream< char> iss( std::istringstream(" 1.0 2.0 3.0 4.0") );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( DTFR::Card4( iss, iptotl ) );
      } // THEN
    } // WHEN

    WHEN( "there are not enough names" ){
      iRecordStream< char> iss( std::istringstream(" 1.0 2.0") );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( DTFR::Card4( iss, iptotl ) );
      } // THEN
    } // WHE
  } // GIVEN
} // SCENARIO
