#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "LEAPR Card19 input values", 
  "[LEAPR], [Card19]"){
  GIVEN( "valid card19 input values" ){
    iRecordStream<char> is0( std::istringstream( "0.0" ) );
    iRecordStream<char> is1( std::istringstream( "0.1" ) );
    iRecordStream<char> is2( std::istringstream( "0.9" ) );
    iRecordStream<char> is3( std::istringstream( "1.0" ) );
    THEN( "the returned class has the correct value" ){
      { LEAPR::Card19 card19( is0 );
        REQUIRE( card19.cfrac.value == 0.0 );
      }
      { LEAPR::Card19 card19( is1 );
        REQUIRE( card19.cfrac.value == 0.1 );
      }
      { LEAPR::Card19 card19( is2 );
        REQUIRE( card19.cfrac.value == 0.9 );
      }
      { LEAPR::Card19 card19( is3 );
        REQUIRE( card19.cfrac.value == 1.0 );
      }
    } // THEN
  } // GIVEN
  GIVEN( "invalid card19 input values" ){
    iRecordStream<char> is1( std::istringstream( "-0.1" ) );
    iRecordStream<char> is2( std::istringstream( "1.1" ) );
    
    THEN( "an exception is thrown" ){
      REQUIRE_THROWS( LEAPR::Card19( is1 ) );
      REQUIRE_THROWS( LEAPR::Card19( is2 ) );
    } // THEN
  } // GIVEN
} // SCENARIO

