#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "COVR card2b values",
  "[COVR], [Card2b]"){

  GIVEN( "valid input for card2b" ){
    WHEN( "all card2b inputs are provided" ){
      iRecordStream<char> iss( 
        std::istringstream( "4 2" ) );
      THEN( "the returned class has the correct tape value" ){
          COVR::Card2b card2b( iss );
          REQUIRE( card2b.matype.value == 4 );
          REQUIRE( card2b.ncase.value  == 2 );
      } // THEN
    } // WHEN

    WHEN( "optional card2b input values omitted" ){
      THEN( "default values are substituted in" ){
        iRecordStream<char> iss( std::istringstream( " /" ) );
        COVR::Card2b card2b( iss );
        REQUIRE( card2b.matype.value == 3 );
        REQUIRE( card2b.ncase.value  == 1 );
      } // THEN
    } // WHEN
  } // GIVEN
  GIVEN( "invalid input for card2b" ){
    iRecordStream<char> iss1( std::istringstream( "2 2" ) );
    iRecordStream<char> iss2( std::istringstream( "3 0" ) );
    iRecordStream<char> iss3( std::istringstream( "5 2" ) );
    iRecordStream<char> iss4( std::istringstream( "4 61" ) );
    THEN( "an exception is thrown" ){ 
      REQUIRE_THROWS( COVR::Card2b( iss1 ) );
      REQUIRE_THROWS( COVR::Card2b( iss2 ) );
      REQUIRE_THROWS( COVR::Card2b( iss3 ) );
      REQUIRE_THROWS( COVR::Card2b( iss4 ) );
    } // THEN
  } // GIVEN
} // SCENARIO

