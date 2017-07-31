#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;
SCENARIO( "LEAPR Card17 input values",
  "[LEAPR], [Card17]" ){
  GIVEN( "valid card17 entry" ){
    iRecordStream<char> iss( std::istringstream( "1 .001" ) );
    THEN( "the returned values are correct" ){
      LEAPR::Card17 card17( iss );
      REQUIRE( card17.nka.value == 1 );
      REQUIRE( card17.dka.value == 0.001 * 
        dimwits::pow( 1.0 * dimwits::angstrom, dimwits::Ratio<-1> ) );
    } // THEN
  } // GIVEN

  GIVEN( "invalid card17 values" ){
    iRecordStream<char> iss1( std::istringstream( " 1 .00"  ) );
    iRecordStream<char> iss2( std::istringstream( "-1 .001" ) );
    THEN( "an exception is thrown" ){
      REQUIRE_THROWS( LEAPR::Card17( iss1 ) );
      REQUIRE_THROWS( LEAPR::Card17( iss2 ) );
    } // THEN
  } // GIVEN
} // SCENARIO

