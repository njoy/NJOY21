#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Verifying ACER Card8 input", "[ACER], [Card8]" ){
  GIVEN( "all arguments" ){
    iRecordStream<char> issCard9( std::istringstream(
            " 1 80 231 0 1 10.1 2 /" ) );
    THEN( "the arguments can be extracted and verified" ){
      ACER::Card9 card9( issCard9 );
      REQUIRE( 1    == card9.mti.value );
      REQUIRE( 80   == card9.nbint.value );
      REQUIRE( 231  == card9.mte.value );
      REQUIRE( 0    == card9.ielas.value );
      REQUIRE( 1    == card9.nmix.value );
      REQUIRE( 10.1 == card9.emax.value );
      REQUIRE( 2    == card9.iwt.value );
    }
  }
  GIVEN( "only required arguments" ){
    iRecordStream<char> issCard9( std::istringstream( " 1 /" ) );
    THEN( "the arguments can be extracted and verified" ){
      ACER::Card9 card9( issCard9 );
      REQUIRE( 1    == card9.mti.value );
      REQUIRE( 16   == card9.nbint.value );
      REQUIRE( 0    == card9.mte.value );
      REQUIRE( 0    == card9.ielas.value );
      REQUIRE( 1    == card9.nmix.value );
      REQUIRE( 1000 == card9.emax.value );
      REQUIRE( 0    == card9.iwt.value );
    }
  }
  GIVEN( "invalid Card9 input" ){
  }
}
