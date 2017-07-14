#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Verifying HEATR Card4 input", 
  "[HEATR], [Card4]" ){
  GIVEN( "a card2 nqa input value" ){
    Argument< HEATR::Card2::Nqa > nqa; nqa.value = 3;
    WHEN( "Card4 input is valid" ){
      iRecordStream<char> iss( std::istringstream( "1 303 999" ) );
      THEN( "the mt values can be extracted correctly" ){
        std::vector<int> refMts{ 1, 303, 999 };
	HEATR::Card4 card4( iss, nqa );
	REQUIRE( refMts == card4.mta.value );
      } // THEN
    } // WHEN
    WHEN( "a Card4 input value is out of range" ){
      iRecordStream<char> iss1( std::istringstream( "0 303 999" ) );
      iRecordStream<char> iss2( std::istringstream( "1 303 1000" ) );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( HEATR::Card4( iss1, nqa ) );
        REQUIRE_THROWS( HEATR::Card4( iss2, nqa ) );
      } // THEN
    } // WHEN
    WHEN( "too few Card4 inputs are provided" ){
      iRecordStream<char> iss( std::istringstream( "301 450" ) );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( HEATR::Card4( iss, nqa ) );
      } // THEN
    } // WHEN
    WHEN( "too many Card4 inputs are provided" ){
      iRecordStream<char> iss( std::istringstream( "301 400 449 450" ) );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( HEATR::Card4( iss, nqa ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
