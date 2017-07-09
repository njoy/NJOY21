#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Validating card9 inputs", "[GROUPR], [Card9]" ){
  GIVEN( "all values are given" ){
    iRecordStream<char> issCard9( std::istringstream( 
            "3 18 'MF3 MT18' /" ) );

    GROUPR::Card9 card9( issCard9 );

    THEN( "the card9 values can be verified" ){
      REQUIRE( 3 == card9.mfd.value );
      REQUIRE( 18 == card9.mtd.value );
      REQUIRE( "MF3 MT18" == card9.mtname.value );
    }
  }
  GIVEN( "mfd=0" ){
    iRecordStream<char> issCard9( std::istringstream( 
            "0 /" ) );

    GROUPR::Card9 card9( issCard9 );

    THEN( "the card9 values can be verified" ){
      REQUIRE( 0 == card9.mfd.value );
      REQUIRE( 0 == card9.mtd.value );
      REQUIRE( "" == card9.mtname.value );
    }
  }
} // SCENARIO

