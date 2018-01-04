#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

std::string sCard1( " 22 /" );
std::string sCard2( " 3 1 2 13.3 299.0 2.2 /" );
std::string sCard3( " '123456' 12 /" );
std::string sCard4List( " 'testing hollerith data line 1' /\n 'testing hollerith data line 2' /" );
std::string sCard5List( " 'name1' 3333 23 /\n 'name2' 4444 24 /\n 'name3' 5555 25 /" );

SCENARIO( "Parsing RESXSR input" ){
  GIVEN( "valid input" ){
    iRecordStream<char> issRESXSR( std::istringstream(
      sCard1 + '\n'
    + sCard2 + '\n'
    + sCard3 + '\n'
    + sCard4List + '\n'
    + sCard5List ) );

    RESXSR resxsr( issRESXSR );

    THEN( "the values can be verified" ){
      REQUIRE( 22 == resxsr.card1.nout.value );

      REQUIRE( 3 == resxsr.card2.nmat.value );
      REQUIRE( 1 == resxsr.card2.maxt.value );
      REQUIRE( 2 == resxsr.card2.nholl.value );
      REQUIRE( 13.3*dimwits::electronVolt == resxsr.card2.efirst.value );
      REQUIRE( 299.0*dimwits::electronVolt == resxsr.card2.elast.value );
      REQUIRE( Approx( 2.2 ) == resxsr.card2.eps.value );

      REQUIRE( "123456" == resxsr.card3.huse.value );
      REQUIRE( 12 == resxsr.card3.ivers.value );

      REQUIRE( "testing hollerith data line 1" ==
                 resxsr.card4List.at(0).holl.value );
      REQUIRE( "testing hollerith data line 2" ==
                 resxsr.card4List.at(1).holl.value );

      REQUIRE( "name1" == resxsr.card5List.at(0).hmat.value );
      REQUIRE( 3333 == resxsr.card5List.at(0).mat.value );
      REQUIRE( 23 == resxsr.card5List.at(0).unit.value );

      REQUIRE( "name2" == resxsr.card5List.at(1).hmat.value );
      REQUIRE( 4444 == resxsr.card5List.at(1).mat.value );
      REQUIRE( 24 == resxsr.card5List.at(1).unit.value );

      REQUIRE( "name3" == resxsr.card5List.at(2).hmat.value );
      REQUIRE( 5555 == resxsr.card5List.at(2).mat.value );
      REQUIRE( 25 == resxsr.card5List.at(2).unit.value );
    }
  } // GIVEN

  GIVEN( "invalid inputs" ){

    WHEN( "too few card4s are provided" ){

      iRecordStream<char> issRESXSR( std::istringstream(
        sCard1 + '\n'
      + sCard2 + '\n'
      + sCard3 + '\n'
      + "'testing hollerith data line 1' /\n"
      + sCard5List ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( RESXSR( issRESXSR ) );
      }
    }

    WHEN( "too many card4s are provided" ){

      iRecordStream<char> issRESXSR( std::istringstream(
        sCard1 + '\n'
      + sCard2 + '\n'
      + sCard3 + '\n'
      + sCard4List + '\n' + "'extra hollerith data' /" + '\n'
      + sCard5List ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( RESXSR( issRESXSR ) );
      }
    }

    WHEN( "too few card5s are provided" ){

      iRecordStream<char> issRESXSR( std::istringstream(
        sCard1 + '\n'
      + sCard2 + '\n'
      + sCard3 + '\n'
      + sCard4List + '\n'
      + " 'name1' 3333 23 /\n 'name2' 4444 24 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( RESXSR( issRESXSR ) );
      }
    }

// Unsure how to make this work... Commenting out for now.

    WHEN( "too many card5s are provided" ){

      iRecordStream<char> issRESXSR( std::istringstream(
        sCard1 + '\n'
      + sCard2 + '\n'
      + sCard3 + '\n'
      + sCard4List + '\n'
      + sCard5List + '\n' + " 'extra' 9999 29 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( RESXSR( issRESXSR ) );
      }
    }

  } // GIVEN
} // SCENARIO
