#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Verifying ACER Card6 input", 
         "[ACER], [Card6]" ){

  GIVEN( "all entries" ){

    THEN( "the appropriate values are returned" ){
      iRecordStream<char> issCard6( std::istringstream( " 0 0 1 /" ) );
      ACER::Card6 card6( issCard6 );

      REQUIRE( 0 == card6.newfor.value );
      REQUIRE( 0 == card6.iopp.value );
    }
  }
  GIVEN( "only the newfor entry" ){

    THEN( "the the appropriate values are returned" ){
      iRecordStream<char> issCard6( std::istringstream( " 0 /" ) );
      ACER::Card6 card6( issCard6 );

      REQUIRE( 0 == card6.newfor.value );
      REQUIRE( 1 == card6.iopp.value );
      REQUIRE( 1 == card6.ismooth.value );
    }
  }
  GIVEN( "no entries---default" ){

    THEN( "the default values are returned" ){
      iRecordStream<char> issCard6( std::istringstream( "/" ) );
      ACER::Card6 card6( issCard6 );

      REQUIRE( 1 == card6.newfor.value );
      REQUIRE( 1 == card6.iopp.value );
      REQUIRE( 1 == card6.ismooth.value );
    }
  }
  GIVEN( "invalid entries" ){
      iRecordStream<char> issCard6( std::istringstream( " 2 2 2 /" ) );
      REQUIRE_THROWS( ACER::Card6( issCard6 ) );
  }
} // SCENARIO
          
