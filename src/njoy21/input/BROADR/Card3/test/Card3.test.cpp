#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "bugless" ){
  {
    iRecordStream<char> iss( std::istringstream("   1.0E-3 /") );
    BROADR::Card3 card3( iss );
    REQUIRE( card3.errthn.value == 1.0E-3 );
    REQUIRE( card3.thnmax.value
	     == 1.0 * dimwits::mega( dimwits::electronVolts ) );
    REQUIRE( card3.errmax.value
	     == 10 * card3.errthn.value );
    REQUIRE( card3.errint.value.value
	     == Approx( 1.0 * ( card3.errthn.value / 2.0E4 ) ) );
  }{
    iRecordStream<char> iss( std::istringstream("   1.0E-3 500.0 1.0E-3 1.0E-20") );
    BROADR::Card3 card3( iss );
    REQUIRE( card3.errthn.value == Approx(1.0E-3) );
    REQUIRE( card3.thnmax.value.value == Approx(500.0)  );
    REQUIRE( card3.errmax.value == 1.0E-3 );
    REQUIRE( card3.errint.value.value == Approx(1.0E-20) );
  }
}

SCENARIO( "bugged" ){
  iRecordStream<char> iss( std::istringstream("   0.0") );
  REQUIRE_THROWS( BROADR::Card3( iss ) );
}
