#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "POWR, Lib3, Card8",
          "[POWR] [Lib3] [Card8]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid values are provided" ){
      iRecordStream<char> iss(std::istringstream( " 1 1.1 2.1 2.2 2.3 2.4 /" ));

      THEN( "the values can be verified" ){
        POWR::Lib3::Card8 card8( iss, 2 );

        REQUIRE( 1 == card8.identa.value );
        REQUIRE( Approx( 1.1 ) == card8.decay.value );
        REQUIRE( Approx( 2.1 ) == card8.yield.value.at(0) );
        REQUIRE( Approx( 2.2 ) == card8.yield.value.at(1) );
        REQUIRE( Approx( 2.3 ) == card8.yield.value.at(2) );
        REQUIRE( Approx( 2.4 ) == card8.yield.value.at(3) );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "an invalid value is provided" ){
      iRecordStream<char> iss(std::istringstream( " 1 -0.1 2.1 2.2 2.3 2.4 /" ));

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( POWR::Lib3::Card8( iss, 2 ) );
      }
    } // WHEN

    WHEN( "too many values are provided" ){
      iRecordStream<char> iss(std::istringstream( " 1 1.1 2.1 2.2 2.3 2.4 /" ));

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( POWR::Lib3::Card8( iss, 1 ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
