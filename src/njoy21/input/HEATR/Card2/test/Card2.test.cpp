#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Validating HEATR Card2 inputs",
  "[HEATR], [Card2]"){
  GIVEN( "a card1 nplot input value of zero" ){
    Argument< HEATR::Card1::Nplot > nplot; nplot.value = 0;
    WHEN( "all card2 inputs are provided and valid " ){
      iRecordStream<char> iss1( std::istringstream("125 5 6 1 1 2 40\n") );
      iRecordStream<char> iss2( std::istringstream("9228 5 3 1 1 2 40\n") );
      THEN( "the returned values are correct" ){
        {
          HEATR::Card2 card2( iss1, nplot );
          REQUIRE( card2.matd.value == 125 );
          REQUIRE( card2.npk.value == 5 );
          REQUIRE( card2.nqa.value == 6 );
          REQUIRE( card2.ntemp.value == 1 );
          REQUIRE( card2.local.value == 1 );
          REQUIRE( card2.iprint.value == 2 );
          REQUIRE( card2.ed.value == 40 * dimwits::electronVolts );
        } 
        {
          HEATR::Card2 card2( iss2, nplot );
          REQUIRE( card2.matd.value == 9228 );
          REQUIRE( card2.npk.value == 5 );
          REQUIRE( card2.nqa.value == 3 );
          REQUIRE( card2.ntemp.value == 1 );
          REQUIRE( card2.local.value == 1 );
          REQUIRE( card2.iprint.value == 2 );
          REQUIRE( card2.ed.value == 40 * dimwits::electronVolts );
        } 
      } // THEN
    } // WHEN
    WHEN( "optional inputs not provided" ){
      iRecordStream<char> iss1( std::istringstream("125 /\n") );
      THEN( "the returned values are correct" ){
        HEATR::Card2 card2( iss1, nplot );
        REQUIRE( card2.matd.value == 125 );
        REQUIRE( card2.npk.value == 0 );
        REQUIRE( card2.nqa.value == 0 );
        REQUIRE( card2.ntemp.value == 0 );
        REQUIRE( card2.local.value == 0 );
        REQUIRE( card2.iprint.value == 0 );
        REQUIRE( card2.ed.value == 25 * dimwits::electronVolts );
      } // THEN
    } // WHEN
    WHEN( "all card2 inputs are provided, but not valid" ){
      iRecordStream<char> iss1( std::istringstream("0 5 6 1 1 2 40\n") );
      iRecordStream<char> iss2( std::istringstream("125 -1 6 1 1 2 40\n") );
      iRecordStream<char> iss3( std::istringstream("125 5 -1 1 1 2 40\n") );
      iRecordStream<char> iss4( std::istringstream("125 5 6 -1 1 2 40\n") );
      iRecordStream<char> iss5( std::istringstream("125 5 6 1 2 2 40\n") );
      iRecordStream<char> iss6( std::istringstream("125 5 6 1 1 3 40\n") );
      iRecordStream<char> iss7( std::istringstream("125 5 6 1 1 2 -1\n") );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( HEATR::Card2( iss1, nplot ) );
        REQUIRE_THROWS( HEATR::Card2( iss2, nplot ) );
        REQUIRE_THROWS( HEATR::Card2( iss3, nplot ) );
        REQUIRE_THROWS( HEATR::Card2( iss4, nplot ) );
        REQUIRE_THROWS( HEATR::Card2( iss5, nplot ) );
        REQUIRE_THROWS( HEATR::Card2( iss6, nplot ) );
        REQUIRE_THROWS( HEATR::Card2( iss7, nplot ) );
      } // THEN
    } // WHEN
  } //GIVEN
  
  GIVEN( "a nonzero card1 nplot input value" ){
    Argument< HEATR::Card1::Nplot > nplot; nplot.value = 20;
    WHEN( "all card2 inputs are provided and valid" ){
      iRecordStream<char> iss1( std::istringstream("125 5 6 1 1 2 40\n") );
      THEN( "the returned values are correct" ){
        HEATR::Card2 card2( iss1, nplot );
        REQUIRE( card2.matd.value == 125 );
        REQUIRE( card2.npk.value == 5 );
        REQUIRE( card2.nqa.value == 6 );
        REQUIRE( card2.ntemp.value == 1 );
        REQUIRE( card2.local.value == 1 );
        REQUIRE( card2.iprint.value == 2 );
        REQUIRE( card2.ed.value == 40 * dimwits::electronVolts );
      } // THEN
    } // WHEN
    WHEN( "optional inputs not provided" ){
      iRecordStream<char> iss1( std::istringstream("125 /\n") );
      THEN( "the returned values are correct" ){
        HEATR::Card2 card2( iss1, nplot );
        REQUIRE( card2.matd.value == 125 );
        REQUIRE( card2.npk.value == 0 );
        REQUIRE( card2.nqa.value == 0 );
        REQUIRE( card2.ntemp.value == 0 );
        REQUIRE( card2.local.value == 0 );
        REQUIRE( card2.iprint.value == 0 );
        REQUIRE( card2.ed.value == 25 * dimwits::electronVolts );
      } // THEN
    } // WHEN
    WHEN( "there is a conflict between iprint and nplot" ){
      iRecordStream<char> iss0( std::istringstream("125 5 6 1 1 0 40\n") );
      iRecordStream<char> iss1( std::istringstream("125 5 6 1 1 1 40\n") );
      iRecordStream<char> iss3( std::istringstream("125 5 6 1 1 3 40\n") );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( HEATR::Card2( iss0, nplot ) );
        REQUIRE_THROWS( HEATR::Card2( iss1, nplot ) );
        REQUIRE_THROWS( HEATR::Card2( iss3, nplot ) );
      } // THEN
    } // WHEN
  } //GIVEN
} // SCENARIO
