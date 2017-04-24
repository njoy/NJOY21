#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Verifying ACER Card6 input", 
         "[ACER], [Card6]" ){

  Argument< ACER::Card1::Ngend > ngend;
  ngend.value = 22;

  GIVEN( "both entries" ){

    THEN( "the appropriate values are returned" ){
      iRecordStream<char> issCard6( std::istringstream( " 0 0 /" ) );
      ACER::Card6 card6( issCard6, ngend );

      REQUIRE( 0 == card6.newfor.value );
      REQUIRE( 0 == card6.iopp.value );
    }
  }
  GIVEN( "only the newfor entry" ){

    THEN( "the the appropriate values are returned" ){
      iRecordStream<char> issCard6( std::istringstream( " 0 /" ) );
      ACER::Card6 card6( issCard6, ngend );

      REQUIRE( 0 == card6.newfor.value );
      REQUIRE( 1 == card6.iopp.value );
    }
  }
  GIVEN( "no entries---default" ){

    THEN( "the default values are returned" ){
      iRecordStream<char> issCard6( std::istringstream( "/" ) );
      ACER::Card6 card6( issCard6, ngend );

      REQUIRE( 1 == card6.newfor.value );
      REQUIRE( 1 == card6.iopp.value );
    }
  }
  GIVEN( "invalid entries" ){
      iRecordStream<char> issCard6( std::istringstream( " 2 2 /" ) );
      REQUIRE_THROWS( ACER::Card6( issCard6, ngend ) );
  }
} // SCENARIO
          
