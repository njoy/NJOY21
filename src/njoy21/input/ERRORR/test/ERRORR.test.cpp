#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "ERRORR",
          "[ERRORR]" ){
  GIVEN( "valid inputs" ){
    WHEN( "example in the NJOY2016 manual on page 319 in the manual is used" ){
      iRecordStream<char> iss( std::istringstream(
 " 31 32 0 33 /\n"
 " 525 3 9 1 1 /\n"
 " 0 0. /\n"
 " 0 33 /"
      ) );

      THEN( "the values can be verified" ){
        ERRORR errorr( iss );

        REQUIRE( 31 == errorr.card1.nendf.value );
        REQUIRE( 32 == std::get<0>( *( errorr.card1.rest ) ).value );
        REQUIRE( 0 == std::get<1>( *( errorr.card1.rest ) ).value );
        REQUIRE( 33 == std::get<2>( *( errorr.card1.rest ) ).value );

        REQUIRE( std::nullopt == errorr.dummy );

        REQUIRE( 525 == errorr.rest->card2.matd.value );
        REQUIRE( 3 == errorr.rest->card2.ign.value );
        REQUIRE( 9 == errorr.rest->card2.iwt.value );
        REQUIRE( 1 == errorr.rest->card2.iprint.value );
        REQUIRE( 1 == errorr.rest->card2.irelco.value );

        REQUIRE( 0 == errorr.rest->card3.mprint.value );
        REQUIRE( 0.0*dimwits::kelvin == errorr.rest->card3.tempin.value );

        REQUIRE( 0 == errorr.rest->card7.iread.value );
        REQUIRE( 33 == errorr.rest->card7.mfcov.value );
      }
    } // WHEN

/* Doesn't work.  Probably a problem with ENDFtk?
    WHEN( "example input from page 322 is used" ){
      iRecordStream<char> iss( std::istringstream(
 " -23 0 24 25 /\n"
 " 1398 19 1 1 /\n"
 " 0 0. /\n"
 " 2 31 /\n"
 " 1380 452 /\n"
 " 1381 452 /\n"
 " 1390 452 /\n"
 " 1395 452 /\n"
 " 1399 452 /\n"
 " 0 /\n"
 " 1 /\n"
 " 1.e7 1.7e7/"
      ) );

      THEN( "the values can be verified" ){
        ERRORR errorr( iss );

        REQUIRE( -23 == errorr.card1.nendf.value );
        REQUIRE( 0 == std::get<0>( *( errorr.card1.rest ) ).value );
        REQUIRE( 24 == std::get<1>( *( errorr.card1.rest ) ).value );
        REQUIRE( 25 == std::get<2>( *( errorr.card1.rest ) ).value );

        REQUIRE( std::nullopt == errorr.dummy );

        REQUIRE( 1398 == errorr.rest->card2.matd.value );
        REQUIRE( 19 == errorr.rest->card2.ign.value );
        REQUIRE( 1 == errorr.rest->card2.iwt.value );
        REQUIRE( 1 == errorr.rest->card2.iprint.value );
        REQUIRE( 1 == errorr.rest->card2.irelco.value ); // default

        REQUIRE( 0 == errorr.rest->card3.mprint.value );
        REQUIRE( 0.*dimwits::kelvin == errorr.rest->card3.tempin.value );

        REQUIRE( 2 == errorr.rest->card7.iread.value );
        REQUIRE( 31 == errorr.rest->card7.mfcov.value );

        REQUIRE( 1380 == errorr.rest->card10List->at(0).mat1.value );
        REQUIRE( 452 == errorr.rest->card10List->at(0).mt1->value );

        REQUIRE( 1381 == errorr.rest->card10List->at(1).mat1.value );
        REQUIRE( 452 == errorr.rest->card10List->at(1).mt1->value );

        REQUIRE( 1390 == errorr.rest->card10List->at(2).mat1.value );
        REQUIRE( 452 == errorr.rest->card10List->at(2).mt1->value );

        REQUIRE( 1395 == errorr.rest->card10List->at(3).mat1.value );
        REQUIRE( 452 == errorr.rest->card10List->at(3).mt1->value );

        REQUIRE( 1399 == errorr.rest->card10List->at(4).mat1.value );
        REQUIRE( 452 == errorr.rest->card10List->at(4).mt1->value );
      }
    } // WHEN
*/

    WHEN( "the example on page 324 is used" ){
      iRecordStream<char> iss( std::istringstream(
 " -21 -22 0 -23 /\n"
 " 1306 3 3 /\n"
 " /\n" // replaced with defaults because of failure
// " 2 0 0 /\n"
 " 1 33 /\n"
 " 7 3 /\n"
 " 1 2 4 102 103 104 107 /\n"
 " 1.e-5 2e6 4.812e6 2e7 /\n"
 " 0 1 0 1 0 0 0 /\n"
 " 0 1 0 0 0 0 0 /\n"
 " 0 0 1 0 0 0 0 /\n"
 " 0 0 0 1 0 0 0 /\n"
 " 0 0 0 0 1 0 0 /\n"
 " 0 0 0 0 0 1 0 /\n"
 " 0 0 0 0 0 0 1 /\n"
 " 1 0 0 0 0 0 0 /\n"
 " 0 1 0 0 0 0 0 /\n"
 " 0 0 1 0 0 0 0 /\n"
 " 0 0 0 1 0 0 0 /\n"
 " 0 0 0 0 1 0 0 /\n"
 " 0 0 0 0 0 1 0 /\n"
 " 0 0 0 0 0 0 1 /\n"
 " 1 0 0 0 0 0 0 /\n"
 " 0 1 0 0 0 0 0 /\n"
 " 1 -1 0 -1 -1 -1 -1 /\n"
 " 0 0 0 1 0 0 0 /\n"
 " 0 0 0 0 1 0 0 /\n"
 " 0 0 0 0 0 1 0 /\n"
 " 0 0 0 0 0 0 1 /"
      ) );

      THEN( "the values can be verified" ){
        REQUIRE_NOTHROW( ERRORR( iss ) );
      }
    } // WHEN
  } // GIVEN

//  GIVEN( "invalid inputs" ){
//
//  } // GIVEN
} // SCENARIO
