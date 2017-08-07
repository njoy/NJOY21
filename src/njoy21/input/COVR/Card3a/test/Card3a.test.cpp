#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "COVR card3a values",
  "[COVR], [Card3a]"){

  GIVEN( "valid input for card3a" ){
    WHEN( "all card3a inputs are provided" ){
      iRecordStream<char> iss( 
        std::istringstream( "0 2 1 0 2" ) );
      THEN( "the returned class has the correct tape value" ){
          COVR::Card3a card3a( iss );
          REQUIRE( card3a.irelco.value == 0 );
          REQUIRE( card3a.ncase.value  == 2 );
          REQUIRE( card3a.noleg.value  == 1 );
          REQUIRE( card3a.nstart.value == 0 );
          REQUIRE( card3a.ndiv.value   == 2 );
      } // THEN
    } // WHEN

    WHEN( "optional card3a input values omitted" ){
      THEN( "default values are substituted in" ){
        iRecordStream<char> iss( std::istringstream( " /" ) );
        COVR::Card3a card3a( iss );
        REQUIRE( card3a.irelco.value == 1 );
        REQUIRE( card3a.ncase.value  == 1 );
        REQUIRE( card3a.noleg.value  == 0 );
        REQUIRE( card3a.nstart.value == 1 );
        REQUIRE( card3a.ndiv.value   == 1 );
      } // THEN
    } // WHEN
  } // GIVEN
  GIVEN( "invalid input for card3a" ){
    iRecordStream<char> iss1( std::istringstream( "2 2 1 0 2"  ) );
    iRecordStream<char> iss2( std::istringstream( "0 0 1 0 2"  ) );
    iRecordStream<char> iss3( std::istringstream( "0 2 2 0 2"  ) );
    iRecordStream<char> iss4( std::istringstream( "0 2 1 -1 2" ) );
    iRecordStream<char> iss5( std::istringstream( "0 2 1 0 0"  ) );
    THEN( "an exception is thrown" ){ 
      REQUIRE_THROWS( COVR::Card3a( iss1 ) );
      REQUIRE_THROWS( COVR::Card3a( iss2 ) );
      REQUIRE_THROWS( COVR::Card3a( iss3 ) );
      REQUIRE_THROWS( COVR::Card3a( iss4 ) );
      REQUIRE_THROWS( COVR::Card3a( iss5 ) );
    } // THEN
  } // GIVEN
} // SCENARIO

