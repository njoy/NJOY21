#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "COVR card2 values",
  "[COVR], [Card2]"){

  GIVEN( "valid input for icolor" ){
    WHEN( "the icolor value is provided" ){
      THEN( "the returned class has the correct tape value" ){
        for( auto& icolor : {0, 1, 2} ){
          iRecordStream<char> iss(
            std::istringstream( std::to_string( icolor ) ) );
	  COVR::Card2 card2( iss );
	  REQUIRE( card2.icolor.value == icolor );
        }
      } // THEN
    } // WHEN

    WHEN( "no icolor value given " ){
      THEN( "default value is substituted in" ){
        iRecordStream<char> iss( std::istringstream( "  /" ) );
	COVR::Card2 card2( iss );
	REQUIRE( 0 == card2.icolor.value );
      } // THEN
    } // WHEN
  
    WHEN( "icolor tapes are out of range" ){
      THEN( "an exception is thrown" ){
        for( auto& icolor : {-1, 3, 4} ){
          iRecordStream<char> iss(
            std::istringstream( std::to_string( icolor ) ) );
	  REQUIRE_THROWS( COVR::Card2( iss ) );
        }
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO

