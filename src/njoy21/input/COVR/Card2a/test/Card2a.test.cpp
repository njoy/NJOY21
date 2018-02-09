#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "COVR card2a values",
  "[COVR], [Card2a]"){

  GIVEN( "valid card2a input given" ){
    WHEN( "card2a input value is provided" ){
      THEN( "the returned class has the correct tape value" ){
        for( auto& epmin : {0.0, 1.0, 2.0} ){
          iRecordStream<char> iss(
            std::istringstream( std::to_string( epmin ) ) );
	  COVR::Card2a card2a( iss );
	  REQUIRE( epmin*dimwits::electronVolt == card2a.epmin.value );
        }
      } // THEN
    } // WHEN

    WHEN( "no card2a value given " ){
      THEN( "default card2a value is substituted in" ){
        iRecordStream<char> iss( std::istringstream( "  /" ) );
	COVR::Card2a card2a( iss );
	REQUIRE( 0.0*dimwits::electronVolt == card2a.epmin.value );
      } // THEN
    } // WHEN
  } // GIVEN
  GIVEN( "invlaid card2a input value" ){ 
    WHEN( "card2a value is out of range" ){
      THEN( "an exception is thrown" ){
        for( auto& epmin : {-1.0, -0.1} ){
          iRecordStream<char> iss(
            std::istringstream( std::to_string( epmin ) ) );
	  REQUIRE_THROWS( COVR::Card2a( iss ) );
        }
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO

