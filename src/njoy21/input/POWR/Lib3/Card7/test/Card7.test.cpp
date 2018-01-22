#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "POWR, Lib3, Card7",
          "[POWR] [Lib3] [Card7]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid values are provided" ){
      iRecordStream<char> iss( std::istringstream( " -100 0 100 9999 /" ) );

      THEN( "the values can be verified" ){
        POWR::Lib3::Card7 card7( iss, 4 );

        REQUIRE( -100 == card7.identb.value.at(0) );
        REQUIRE( 0 == card7.identb.value.at(1) );
        REQUIRE( 100 == card7.identb.value.at(2) );
        REQUIRE( 9999 == card7.identb.value.at(3) );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "invalid values are provided" ){
      iRecordStream<char> iss( std::istringstream( " -101 0 100 9999 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( POWR::Lib3::Card7( iss, 4 ) );
      }
    } // WHEN

    WHEN( "too many values are provided" ){
      iRecordStream<char> iss( std::istringstream( " -100 0 100 9999 1 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( POWR::Lib3::Card7( iss, 4 ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
