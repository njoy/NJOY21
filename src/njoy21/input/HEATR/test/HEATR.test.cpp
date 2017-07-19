#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "HEATR input", 
  "[HEATR]" ){
  GIVEN( "valid HEATR input" ){
    WHEN( "Card3 is invoked" ){
      iRecordStream<char> iss( std::istringstream( 
        "-21 -22 -24 -25\n"
        "1325 1 0 1 1 2 30\n"
        "444\n"
        ) );
      HEATR heatr( iss );
      THEN( "all cards have the correct values" ){
        REQUIRE( heatr.card1.nendf.value == -21 );
        REQUIRE( heatr.card1.nin.value   == -22 );
        REQUIRE( heatr.card1.nout.value  == -24 );
        REQUIRE( heatr.card1.nplot.value == -25 );

        REQUIRE( heatr.card2.matd.value   == 1325 );
        REQUIRE( heatr.card2.npk.value    == 1 );
        REQUIRE( heatr.card2.nqa.value    == 0 );
        REQUIRE( heatr.card2.ntemp.value  == 1 );
        REQUIRE( heatr.card2.local.value  == 1 );
        REQUIRE( heatr.card2.iprint.value == 2 );
        REQUIRE( heatr.card2.ed.value     == 30 * dimwits::electronVolts );

        REQUIRE( heatr.card3->mtk.value.size() == 1 );
        REQUIRE( heatr.card3->mtk.value[0] == 444 );
      } // THEN
    } // WHEN

    WHEN( "Cards 4 and 5 are invoked, qa values < 99e6 eV" ){
      iRecordStream<char> iss( std::istringstream( 
        "-21 -22 -24 -25\n"
        "1325 0 1 0 0 2 27\n"
        "16\n"
	"55e6\n"
        ) );
      HEATR heatr( iss );
      THEN( "all cards have the correct values" ){
        REQUIRE( heatr.card1.nendf.value == -21 );
        REQUIRE( heatr.card1.nin.value   == -22 );
        REQUIRE( heatr.card1.nout.value  == -24 );
        REQUIRE( heatr.card1.nplot.value == -25 );

	REQUIRE( heatr.controlTuple );

        const auto& card4 = std::get<0>( *(heatr.controlTuple) );
	REQUIRE( card4.mta.value[0] == 16 );

        const auto& card5 = std::get<1>( *(heatr.controlTuple) );
	REQUIRE( card5.qa.value[0] == 55e6 * dimwits::electronVolts);
      } // THEN
    } // WHEN

    WHEN( "Cards 3, 4, and 5 are invoked, qa values < 99e6 eV" ){
      iRecordStream<char> iss( std::istringstream( 
        "-21 -22 -24 -25\n"
        "1325 2 2 0 0 2 27\n"
	"444 445\n"
        "16 18\n"
	"55e6 56e6\n"
        ) );
      HEATR heatr( iss );
      THEN( "all cards have the correct values, no card5a values" ){
        REQUIRE( heatr.card3->mtk.value.size() == 2 );
	REQUIRE( heatr.card3->mtk.value[0] == 444 );
	REQUIRE( heatr.card3->mtk.value[1] == 445 );
	
	REQUIRE( heatr.controlTuple );

	const auto& card4 = std::get<0>( *(heatr.controlTuple) );
	REQUIRE( card4.mta.value.size() == 2 );
	REQUIRE( card4.mta.value[0] == 16 );
	REQUIRE( card4.mta.value[1] == 18 );

	const auto& card5 = std::get<1>( *(heatr.controlTuple) );
	REQUIRE( card5.qa.value.size() == 2 );
	REQUIRE( card5.qa.value[0] == 55e6 * dimwits::electronVolts );
	REQUIRE( card5.qa.value[1] == 56e6 * dimwits::electronVolts );

        REQUIRE( std::get<2>( *(heatr.controlTuple) ).size() == 0 );
      } // THEN
    } // WHEN

    WHEN( "Cards 4 and 5 are invoked, qa value >= 99e6 eV (singular card5a)" ){
      iRecordStream<char> iss( std::istringstream( 
        "-21 -22 -24 -25\n"
        "1325 0 2 0 0 2 27\n"
        "16 18\n"
	"55e6 99e6\n"
	"0 0 0 0 1 3\n"
	"3 2\n"
	"8.9e6 -8.14e6 9.0e6 -8.14e6 1.1e7 -8.36e6\n"
        ) );
      HEATR heatr( iss );
      THEN( "all cards have the correct values, along with card5a values" ){

	REQUIRE( heatr.controlTuple );

	const auto& card4 = std::get<0>( *(heatr.controlTuple) );
	REQUIRE( card4.mta.value.size() == 2 );
	REQUIRE( card4.mta.value[0] == 16 );
	REQUIRE( card4.mta.value[1] == 18 );

	const auto& card5 = std::get<1>( *(heatr.controlTuple) );
	REQUIRE( card5.qa.value.size() == 2 );
	REQUIRE( card5.qa.value[0] == 55e6 * dimwits::electronVolts );
	REQUIRE( card5.qa.value[1] == 99e6 * dimwits::electronVolts );
	
	const auto& card5aList = std::get<2>( *(heatr.controlTuple) );
	REQUIRE( card5aList.size() == 1 );
	REQUIRE( card5aList[0].qbar.value.NR() == 1 );
	REQUIRE( card5aList[0].qbar.value.NP() == 3 );
	std::vector<double> x{8.9e6, 9.0e6, 1.1e7};
	std::vector<double> y{-8.14e6, -8.14e6, -8.36e6};
	REQUIRE( ranges::equal( x, card5aList[0].qbar.value.x() ) );
	REQUIRE( ranges::equal( y, card5aList[0].qbar.value.y() ) );
      } // THEN
    } // WHEN

    WHEN( "Cards 4 and 5 are invoked, qa value >= 99e6 eV (mult. card5a's)" ){
      iRecordStream<char> iss( std::istringstream( 
        "-21 -22 -24 -25\n"
        "1325 0 2 0 0 2 27\n"
        "16 18\n"
	"10e7 99e6\n"
        "0 0 0 0 1 3\n"
	"3 2\n"
	"8.9e6 -8.14e6 9.0e6 -8.14e6 1.1e7 -8.36e6\n"
        "0 0 0 0 2 6\n"
	"3 2 6 1\n"
	"8.9e6 8.14e6 9.0e6 8.14e6 1.1e7 8.36e6\n"
	"1.3e7 9.14e6 1.5e7 9.14e6 1.8e7 9.36e6\n"
        ) );
      HEATR heatr( iss );
      THEN( "all cards have the correct values, along with card5a values" ){

	REQUIRE( heatr.controlTuple );

	const auto& card4 = std::get<0>( *(heatr.controlTuple) );
	REQUIRE( card4.mta.value.size() == 2 );
	REQUIRE( card4.mta.value[0] == 16 );
	REQUIRE( card4.mta.value[1] == 18 );

	const auto& card5 = std::get<1>( *(heatr.controlTuple) );
	REQUIRE( card5.qa.value.size() == 2 );
	REQUIRE( card5.qa.value[0] == 10e7 * dimwits::electronVolts );
	REQUIRE( card5.qa.value[1] == 99e6 * dimwits::electronVolts );
	
	const auto& card5aList = std::get<2>( *(heatr.controlTuple) );
	REQUIRE( card5aList.size() == 2 );

	REQUIRE( card5aList[0].qbar.value.NR() == 1 );
	REQUIRE( card5aList[0].qbar.value.NP() == 3 );
	std::vector<double> x1{8.9e6, 9.0e6, 1.1e7};
	std::vector<double> y1{-8.14e6, -8.14e6, -8.36e6};
	REQUIRE( ranges::equal( x1, card5aList[0].qbar.value.x() ) );
	REQUIRE( ranges::equal( y1, card5aList[0].qbar.value.y() ) );

	REQUIRE( card5aList[1].qbar.value.NR() == 2 );
	REQUIRE( card5aList[1].qbar.value.NP() == 6 );
	std::vector<double> x2{8.9e6, 9.0e6, 1.1e7, 1.3e7, 1.5e7, 1.8e7};
	std::vector<double> y2{8.14e6, 8.14e6, 8.36e6, 9.14e6, 9.14e6, 9.36e6};
	REQUIRE( ranges::equal( x2, card5aList[1].qbar.value.x() ) );
	REQUIRE( ranges::equal( y2, card5aList[1].qbar.value.y() ) );

      } // THEN
    } // WHEN


    WHEN( "optional entries not provided (no card3 - card5a )" ){
      iRecordStream<char> iss( std::istringstream(
        "-21 -22 -24 /\n"
        "1325 /\n"
      ) );
      HEATR heatr( iss );
      THEN( "all cards have the correct values" ){
        REQUIRE( heatr.card1.nplot.value == 0 );
          
	REQUIRE( heatr.card2.npk.value    == 0 );
	REQUIRE( heatr.card2.nqa.value    == 0 );
	REQUIRE( heatr.card2.ntemp.value  == 0 );
	REQUIRE( heatr.card2.local.value  == 0 );
	REQUIRE( heatr.card2.iprint.value == 0 );
	REQUIRE( heatr.card2.ed.value     == 27 * dimwits::electronVolts );

      } // THEN
    } // WHEN
  } // GIVEN

  GIVEN( "invalid HEATR input" ){
    WHEN( "Value is out of range" ) {
      iRecordStream<char> iss1( std::istringstream( 
        "-21 -22 -24 -25\n"
        "1325 1 0 1 2 2 30\n"
        "444\n"
        ) );
      iRecordStream<char> iss2( std::istringstream( 
        "-21 -22 -24 -25\n"
        "1325 1 0 1 1 2 30\n"
        "650\n"
        ) );
      iRecordStream<char> iss3( std::istringstream( 
        "-19 -22 -24 -25\n"
        "1325 1 0 1 1 2 30\n"
        "444\n"
        ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( HEATR( iss1 ) );
        REQUIRE_THROWS( HEATR( iss2 ) );
        REQUIRE_THROWS( HEATR( iss3 ) );
      } // THEN
    } // WHEN

    WHEN( "Npk (Card2) disagrees with Mtk (Card3)" ){
      iRecordStream<char> iss1( std::istringstream( 
        "-21 -22 -24 -25\n"
        "1325 1 0 0 0 2 27\n"
	"445 446\n"
        ) );
      iRecordStream<char> iss2( std::istringstream( 
        "-21 -22 -24 -25\n"
        "1325 3 0 0 0 2 27\n"
	"445 446\n"
	) );
      THEN( "an exception is thrown" ){
	REQUIRE_THROWS( HEATR( iss1 ) );
	REQUIRE_THROWS( HEATR( iss2 ) );
      } // THEN
    } // WHEN

    WHEN( "Nqa (Card2) disagrees with Qa (Card3)" ){
      iRecordStream<char> iss1( std::istringstream( 
        "-21 -22 -24 -25\n"
        "1325 0 1 0 0 2 27\n"
	"16 18\n"
        ) );
      iRecordStream<char> iss2( std::istringstream( 
        "-21 -22 -24 -25\n"
        "1325 0 3 0 0 2 27\n"
	"16 18\n"
	) );
      THEN( "an exception is thrown" ){
	REQUIRE_THROWS( HEATR( iss1 ) );
	REQUIRE_THROWS( HEATR( iss2 ) );
      } // THEN
    } // WHEN

    WHEN( "iprint (Card2) disagrees with nplot (Card1)" ){
      iRecordStream<char> iss1( std::istringstream(
	"-21 -22 -24 -25\n"
	"1325 0 0 0 0 1 / \n"
	) );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( HEATR( iss1 ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO

