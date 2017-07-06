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

      THEN( "the Hollerith names can be extracted correctly" ){
        std::vector<std::string > refHolNames{ "pheat1", "edits", "dtfr" };
        REQUIRE( refHolNames == argument::extract< 
          DTFR::Card4::HollerithNames >( iss, iptotl.value - 3 ).value );
      } // THEN
    } // WHEN

    WHEN( "a name is too long (over 6 characters)" ){
      iRecordStream< char> iss( std::istringstream("longword edits dtfr") );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< 
        DTFR::Card4::HollerithNames >( iss, iptotl.value - 3 ) );
      } // THEN
    } // WHEN

    WHEN( "commas are used to separate values" ){
      iRecordStream< char> iss( std::istringstream("pheat1, edits, dtfr") );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< 
          DTFR::Card4::HollerithNames >( iss, iptotl.value - 3 ) );
      } // THEN
    } // WHEN
  } // GIVEN

  GIVEN( "an incorrect number of names" ){
    WHEN( "there are too many names" ){
      iRecordStream< char> iss( std::istringstream(" 1.0 2.0 3.0 4.0") );
      THEN( "an exception is not thrown" ){
        REQUIRE_NOTHROW( argument::extract< 
          DTFR::Card4::HollerithNames >( iss, iptotl.value - 3 ) );
      } // THEN
    } // WHEN

    WHEN( "there are not enough names" ){
      iRecordStream< char> iss( std::istringstream(" 1.0 2.0") );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< 
          DTFR::Card4::HollerithNames >( iss, iptotl.value - 3 ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
