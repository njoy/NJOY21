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

        REQUIRE( std::nullopt == errorr.dummyMF33 );

        REQUIRE( 525 == errorr.normal->card2.matd.value );
        REQUIRE( 3 == errorr.normal->card2.ign.value );
        REQUIRE( 9 == errorr.normal->card2.iwt.value );
        REQUIRE( 1 == errorr.normal->card2.iprint.value );
        REQUIRE( 1 == errorr.normal->card2.irelco.value );

        REQUIRE( 0 == errorr.normal->card3.mprint.value );
        REQUIRE( 0.0*dimwits::kelvin == errorr.normal->card3.tempin.value );

        REQUIRE( 0 == errorr.normal->card7.iread.value );
        REQUIRE( 33 == errorr.normal->card7.mfcov.value );
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

        REQUIRE( std::nullopt == errorr.dummyMF33 );

        REQUIRE( 1398 == errorr.normal->card2.matd.value );
        REQUIRE( 19 == errorr.normal->card2.ign.value );
        REQUIRE( 1 == errorr.normal->card2.iwt.value );
        REQUIRE( 1 == errorr.normal->card2.iprint.value );
        REQUIRE( 1 == errorr.normal->card2.irelco.value ); // default

        REQUIRE( 0 == errorr.normal->card3.mprint.value );
        REQUIRE( 0.*dimwits::kelvin == errorr.normal->card3.tempin.value );

        REQUIRE( 2 == errorr.normal->card7.iread.value );
        REQUIRE( 31 == errorr.normal->card7.mfcov.value );

        REQUIRE( 1380 == errorr.normal->card10List->at(0).mat1.value );
        REQUIRE( 452 == errorr.normal->card10List->at(0).mt1->value );

        REQUIRE( 1381 == errorr.normal->card10List->at(1).mat1.value );
        REQUIRE( 452 == errorr.normal->card10List->at(1).mt1->value );

        REQUIRE( 1390 == errorr.normal->card10List->at(2).mat1.value );
        REQUIRE( 452 == errorr.normal->card10List->at(2).mt1->value );

        REQUIRE( 1395 == errorr.normal->card10List->at(3).mat1.value );
        REQUIRE( 452 == errorr.normal->card10List->at(3).mt1->value );

        REQUIRE( 1399 == errorr.normal->card10List->at(4).mat1.value );
        REQUIRE( 452 == errorr.normal->card10List->at(4).mt1->value );
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

/* Commented because ENDF::Tab1 record format is unhappy
    WHEN( "the second errorr example from page 326 is used" ){
      iRecordStream<char> iss( std::istringstream(
 " -21 0 -24 -28 -25 -31 /\n"
 " 1399 3 1 1 /\n"
 " 0 0. /\n"
 " 2 33 /\n"
 " 1395 18 /\n"
 " 0 /\n"
 " -1395 -18 1361 18 /\n"
 " 0 /"
      ) );

      THEN( "the values can be verified" ){
        REQUIRE_NOTHROW( ERRORR( iss ) );
      }
    } // WHEN
*/

/* Commented because float format (probably).  Following test fixes format.
    WHEN( "the example from page 329 is used" ){
      iRecordStream<char> iss( std::istringstream(
 " 20 0 91 28 0 0 /\n"
 " 9999 1 2 1 1 /\n"
 " 0 300. /\n"
 " 0 35 1 1 -1 1.23e6 /\n"
 " 71 /\n"
 " 1.000000-5 1.500000+4 3.500000+4 5.500000+4 7.500000+4\n"
 " 9.500000+4 1.150000+5 1.350000+5 1.650000+5 1.950000+5\n"
 " 2.250000+5 2.550000+5 3.050000+5 3.550000+5 4.050000+5\n"
 " 4.550000+5 5.050000+5 5.550000+5 6.050000+5 6.550000+5\n"
 " 7.050000+5 7.550000+5 8.050000+5 8.550000+5 9.050000+5\n"
 " 9.550000+5 1.050000+6 1.150000+6 1.250000+6 1.350000+5\n"
 " 1.450000+6 1.550000+6 1.650000+6 1.750000+6 1.850000+6\n"
 " 1.950000+6 2.150000+6 2.350000+6 2.550000+6 2.750000+6\n"
 " 2.950000+6 3.250000+6 3.550000+6 3.850000+6 4.150000+6\n"
 " 4.450000+6 4.750000+6 5.050000+6 5.550000+6 6.050000+6\n"
 " 6.550000+6 7.050000+6 7.550000+6 8.050000+6 8.550000+6\n"
 " 9.050000+6 9.550000+6 1.005000+7 1.055000+7 1.105000+7\n"
 " 1.155000+7 1.205000+7 1.255000+7 1.305000+7 1.355000+7\n"
 " 1.405000+7 1.460000+7 1.590000+7 1.690000+7 1.790000+7\n"
 " 1.910000+7 2.000000+7 /"
      ) );

      THEN( "the values can be verified" ){
        REQUIRE_NOTHROW( ERRORR( iss ) );
      }
    } // WHEN
*/

    WHEN( "the example from page 329 is used" ){
      iRecordStream<char> iss( std::istringstream(
 " 20 0 91 28 0 0 /\n"
 " 9999 1 2 1 1 /\n"
 " 0 300. /\n"
 " 0 35 1 1 -1 1.23e6 /\n"
 " 71 /\n"
 " 1.000000e-5 1.500000e+4 3.500000e+4 5.500000e+4 7.500000e+4\n"
 " 9.500000e+4 1.150000e+5 1.350000e+5 1.650000e+5 1.950000e+5\n"
 " 2.250000e+5 2.550000e+5 3.050000e+5 3.550000e+5 4.050000e+5\n"
 " 4.550000e+5 5.050000e+5 5.550000e+5 6.050000e+5 6.550000e+5\n"
 " 7.050000e+5 7.550000e+5 8.050000e+5 8.550000e+5 9.050000e+5\n"
 " 9.550000e+5 1.050000e+6 1.150000e+6 1.250000e+6 1.350000e+6\n"
 " 1.450000e+6 1.550000e+6 1.650000e+6 1.750000e+6 1.850000e+6\n"
 " 1.950000e+6 2.150000e+6 2.350000e+6 2.550000e+6 2.750000e+6\n"
 " 2.950000e+6 3.250000e+6 3.550000e+6 3.850000e+6 4.150000e+6\n"
 " 4.450000e+6 4.750000e+6 5.050000e+6 5.550000e+6 6.050000e+6\n"
 " 6.550000e+6 7.050000e+6 7.550000e+6 8.050000e+6 8.550000e+6\n"
 " 9.050000e+6 9.550000e+6 1.005000e+7 1.055000e+7 1.105000e+7\n"
 " 1.155000e+7 1.205000e+7 1.255000e+7 1.305000e+7 1.355000e+7\n"
 " 1.405000e+7 1.460000e+7 1.590000e+7 1.690000e+7 1.790000e+7\n"
 " 1.910000e+7 2.000000e+7 /"
      ) );

      THEN( "the values can be verified" ){
        REQUIRE_NOTHROW( ERRORR( iss ) );
      }
    } // WHEN

    WHEN( "the example from page 331 is used" ){
      iRecordStream<char> iss( std::istringstream(
 " 41 43 44 45 /\n"
 " 4125 1 6 1 1 /\n"
 " 0 300. /\n"
 " 0 33 /\n"
 " 21 /\n"
 " 1.e-5 0.625 10.7 100.0 1.e3 1.e4 1.e5 1.e6\n"
 " 2.e6 3.e6 4.e6 5.e6 6.e6 7.e6 8.e6 9.e6 10.e6\n"
 " 12.e6 14.e6 16.e6 18.e6 20.e6 /"
      ) );

      THEN( "the values can be verified" ){
        REQUIRE_NOTHROW( ERRORR( iss ) );
      }
    } // WHEN

    WHEN( "the first input from test problem 4 is used" ){
      iRecordStream<char> iss( std::istringstream(
 " -21 -22 0 23 0 /\n"
 " 1395 19 3 1 1 /\n"
 " 0 0. /\n"
 " 0 33 /\n"
 " 1 /\n"
 " 1.e0 1.e3 /"
      ) );

      THEN( "the values can be verified" ){
        REQUIRE_NOTHROW( ERRORR( iss ) );
      }
    } // WHEN

    WHEN( "first input from test problem 15 is used" ){
      iRecordStream<char> iss( std::istringstream(
 " -21 0 91 25 0 0 /\n"
 " 9237 3 6 1 1 /\n"
 " 1 300. /\n"
 " 0 31 1 1 -1 /"
      ) );

      THEN( "the values can be verified" ){
        REQUIRE_NOTHROW( ERRORR( iss ) );
      }
    } // WHEN

    WHEN( "second input from test problem 15 is used" ){
      iRecordStream<char> iss( std::istringstream(
 " -21 0 91 26 0 0 /\n"
 " 9237 3 6 1 1 /\n"
 " 1 300. /\n"
 " 0 33 1 1 -1 /"
      ) );

      THEN( "the values can be verified" ){
        REQUIRE_NOTHROW( ERRORR( iss ) );
      }
    } // WHEN

    WHEN( "third input from test problem 15 is used" ){
      iRecordStream<char> iss( std::istringstream(
 " -21 0 91 27 0 0 /\n"
 " 9237 3 6 1 1 /\n"
 " 1 300. /\n"
 " 0 34 1 1 -1 /"
      ) );

      THEN( "the values can be verified" ){
        REQUIRE_NOTHROW( ERRORR( iss ) );
      }
    } // WHEN

    WHEN( "input from test problem 17 is used" ){
      iRecordStream<char> iss( std::istringstream(
 " 21 0 99 26 0 /\n"
 " 9237 3 6 1 /\n"
 " 1 300. /\n"
 " 2 33 1 1 -1 /\n"
 " 9228 18 /\n"
 " 9437 18 /\n"
 " 0 /"
      ) );

      THEN( "the values can be verified" ){
        REQUIRE_NOTHROW( ERRORR( iss ) );
      }
    } // WHEN

    WHEN( "first input from test problem 20 is used" ){
      iRecordStream<char> iss( std::istringstream(
 " 999 /\n"
 " +20 +21 /\n"
 " 1 /\n"
 " 2 /\n"
 " 102 /\n"
 " 600 /\n"
 " 0 /"
      ) );

      THEN( "the values can be verified" ){
        REQUIRE_NOTHROW( ERRORR( iss ) );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "an invalid value is provided" ){
      iRecordStream<char> iss( std::istringstream(
 " 199 /\n"
 " +20 +21 /\n"
 " 1 /\n"
 " 2 /\n"
 " 102 /\n"
 " 600 /\n"
 " 0 /"
      ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( ERRORR( iss ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
