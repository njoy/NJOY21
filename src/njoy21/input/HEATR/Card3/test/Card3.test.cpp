#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Verifying HEATR Card3 input", 
  "[HEATR], [Card3]" ){
  GIVEN( "a card2 npk input value" ){
    Argument< HEATR::Card2::Npk > npk; npk.value = 3;
    WHEN( "Card3 input is valid" ){
      iRecordStream<char> iss( std::istringstream( "302 303 450" ) );
      THEN( "the mt values can be extracted correctly" ){
        std::vector<int> refMts{ 302, 303, 450 };
	HEATR::Card3 card3( iss, npk );
	REQUIRE( refMts == card3.mtk.value );
      } // THEN
    } // WHEN
    WHEN( "a Card3 input value is out of range" ){
      iRecordStream<char> iss( std::istringstream( "301 303 450" ) );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( HEATR::Card3( iss, npk ) );
      } // THEN
    } // WHEN
    WHEN( "too few Card3 inputs are provided" ){
      iRecordStream<char> iss( std::istringstream( "301 450" ) );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( HEATR::Card3( iss, npk ) );
      } // THEN
    } // WHEN
    WHEN( "too many Card3 inputs are provided" ){
      iRecordStream<char> iss( std::istringstream( "301 400 449 450" ) );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( HEATR::Card3( iss, npk ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
