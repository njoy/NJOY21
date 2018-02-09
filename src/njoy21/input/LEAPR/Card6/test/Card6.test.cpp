#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "LEAPR Card6 input values",
  "[LEAPR], [Card6]" ){
  GIVEN( "valid card6 inputs" ){
    WHEN( "secondary scatterer available (nss = 1)" ){
      iRecordStream<char> is( std::istringstream( "1 1 15.87 3.84 1" ) );
      THEN( "all card6 inputs are provided and returned correctly" ){
        LEAPR::Card6 card6( is );
        REQUIRE( card6.nss.value   == 1    );
        auto ct = *( card6.controlTuple );
        REQUIRE( ct.b7.value == 1 );
        REQUIRE( ct.aws.value == 15.87 );
        REQUIRE( ct.sps.value == 3.84*dimwits::barns  );
        REQUIRE( ct.mss.value == 1 );
      } // THEN
    } // WHEN
    WHEN( "secondary scatterer not available (nss = 0)" ){
      iRecordStream<char> is( std::istringstream( "0/" ) );
      THEN( "last four card6 inputs are not provided" ){
        LEAPR::Card6 card6( is );
        REQUIRE( card6.nss.value == 0 );
      } // THEN
    } // WHEN
  } // GIVEN
  GIVEN( "invalid card6 inputs" ){
    WHEN( "card6 input value is out of range" ){
      iRecordStream<char> is1( std::istringstream( "2 1 15.87 3.84 1" ) );
      iRecordStream<char> is2( std::istringstream( "1 3 15.87 3.84 1" ) );
      iRecordStream<char> is3( std::istringstream( "1 1 0.000 3.84 1" ) );
      iRecordStream<char> is4( std::istringstream( "1 1 15.87 0.00 1" ) );
      iRecordStream<char> is5( std::istringstream( "1 1 15.87 3.84 0" ) );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( LEAPR::Card6( is1 ) );
        REQUIRE_THROWS( LEAPR::Card6( is2 ) );
        REQUIRE_THROWS( LEAPR::Card6( is3 ) );
        REQUIRE_THROWS( LEAPR::Card6( is4 ) );
        REQUIRE_THROWS( LEAPR::Card6( is5 ) );
      } // THEN
    } // WHEN
    WHEN( "nss input conflicts with subsequent entries" ){
      iRecordStream<char> is1( std::istringstream( "0 1 15.87 3.84 1" ) );
      iRecordStream<char> is2( std::istringstream( "1/" ) );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( LEAPR::Card6( is1 ) );
        REQUIRE_THROWS( LEAPR::Card6( is2 ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO

