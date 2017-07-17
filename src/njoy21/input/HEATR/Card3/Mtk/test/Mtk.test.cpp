#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "HEATR mtk values",
  "[HEATR], [Card3], [Mtk]"){
  GIVEN( "a card2 npk input value" ){
    Argument< HEATR::Card2::Npk > npk; npk.value = 5;
    WHEN( "mtk entries are valid" ){
      iRecordStream<char> iss( std::istringstream( "302 303 400 449 450" ) );
      THEN( "the mt values can be extracted correctly" ){
        auto mts = argument::extract< HEATR::Card3::Mtk >( iss, npk );
        std::vector<int> refMts{ 302, 303, 400, 449, 450 };
	REQUIRE( refMts == mts.value );
      } // THEN
    } // WHEN
    WHEN( "mtk entries are out of range" ){
      iRecordStream<char> iss1( std::istringstream( "301 303 400 449 450" ) );
      iRecordStream<char> iss2( std::istringstream( "302 300 400 449 450" ) );
      iRecordStream<char> iss4( std::istringstream( "302 303 400 451 450" ) );
      iRecordStream<char> iss3( std::istringstream( "302 303 400 449 452" ) );
      THEN( "an exception is thrown" ){ 
        REQUIRE_THROWS( argument::extract< HEATR::Card3::Mtk >( iss1, npk ) );
        REQUIRE_THROWS( argument::extract< HEATR::Card3::Mtk >( iss2, npk ) );
        REQUIRE_THROWS( argument::extract< HEATR::Card3::Mtk >( iss3, npk ) );
        REQUIRE_THROWS( argument::extract< HEATR::Card3::Mtk >( iss4, npk ) );
      } // THEN
    } // WHEN
    WHEN( "commas are used to separate values" ){
      iRecordStream<char>iss( std::istringstream( "302, 303, 400, 449, 450" ) );
      THEN( "an exception is thrown" ){ 
        REQUIRE_THROWS( argument::extract< HEATR::Card3::Mtk >( iss, npk ) );
      } // THEN
    } // WHEN
    WHEN( "there are not enough mt values" ){
      iRecordStream<char> iss( std::istringstream( "302 303 449 450" ) );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< HEATR::Card3::Mtk >( iss, npk ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
