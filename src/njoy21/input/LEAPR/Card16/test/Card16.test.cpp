#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "LEAPR Card16 ow input values",
  "[LEAPR], [Card16], [Ow]" ){
  GIVEN( "a small value for nd" ){
    Argument< LEAPR::Card14::Nd > nd;
    Argument< LEAPR::Card13::Twt > twt;
    Argument< LEAPR::Card13::Tbeta > tbeta;
    nd.value = 2;
    twt.value = 0.0192;
    tbeta.value = 0.4904;

    WHEN( "there are the correct number of ows and they are valid" ){
      iRecordStream< char> iss( std::istringstream("0.163467 0.326933") );
      THEN( "the ow values can be extracted correctly" ){
        std::vector< double > refOws{ 0.163467, 0.326933 };
        LEAPR::Card16 card16( iss, nd, twt, tbeta );
        REQUIRE( refOws == card16.ow.value );
      } // THEN
    } // WHEN
    WHEN( "the ow value is out of range" ){
      iRecordStream< char> iss( std::istringstream("-0.163467 0.326933") );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( LEAPR::Card16( iss, nd, twt, tbeta ) );
      } // THEN
    } // WHEN
    WHEN ("ow sum conflicts with card13's twt and tbeta values" ){
      iRecordStream< char> iss( std::istringstream("0.163467 0.326932") );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( LEAPR::Card16( iss, nd, twt, tbeta ) );
      } // THEN
    } // WHEN
    WHEN( "too few ow values are provided" ){
      iRecordStream< char> iss( std::istringstream("0.163467") );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( LEAPR::Card16( iss, nd, twt, tbeta ) );
      } // THEN
    } // WHEN
    WHEN( "too many ow values are provided" ){
      iRecordStream< char> iss( std::istringstream("0.163467 0.326933 4.0") );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( LEAPR::Card16( iss, nd, twt, tbeta ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO

