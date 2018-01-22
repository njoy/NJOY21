#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "POWR, Lib3, Card9",
          "[POWR] [Lib3] [Card9]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      iRecordStream<char> iss( std::istringstream( " 0.1 1.1 1 /" ) );

      THEN( "the values can be verified" ){
        POWR::Lib3::Card9 card9( iss );

        REQUIRE( Approx( 0.1 ) == card9.aw.value );
        REQUIRE( Approx( 1.1 ) == card9.indfis.value );
        REQUIRE( 1 == card9.ntemp.value );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "an invalid input is provided" ){
      iRecordStream<char> iss( std::istringstream( " 0.0 1.1 1 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( POWR::Lib3::Card9( iss ) );
      }
    } // WHEN

    WHEN( "too few values are given" ){
      iRecordStream<char> iss( std::istringstream( " 0.1 1.1 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( POWR::Lib3::Card9( iss ) );
      }
    } // WHEN

    WHEN( "too many values are given" ){
      iRecordStream<char> iss( std::istringstream( " 0.1 1.1 1 1 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( POWR::Lib3::Card9( iss ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
