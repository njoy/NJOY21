#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "POWR, Lib3, Card4",
          "[POWR] [Lib3] [Card4]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      iRecordStream<char> iss( std::istringstream( " -99 100 101 /" ) );

      THEN( "the values can be verified" ){
        POWR::Lib3::Card4 card4( iss, 3 );

        REQUIRE( -99 == card4.mat.value.at(0) );
        REQUIRE( 100 == card4.mat.value.at(1) );
        REQUIRE( 101 == card4.mat.value.at(2) );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "too many values are provided" ){
      iRecordStream<char> iss( std::istringstream( " -99 100 101 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( POWR::Lib3::Card4( iss, 2 ) );
      }
    } // WHEN
  } // GIVEN
} //SCENARIO
