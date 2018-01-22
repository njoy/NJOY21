#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "POWR, Lib1, Card3, Izref",
          "[POWR] [Lib1] [Card3] [Izref]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid values are provided" ){
      for( double d : {0.0, 1.0, 10.0, 100.0, 1000.0} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( d ) ) );

        THEN( "the values can be verified" ){
          REQUIRE( Approx( d ) == argument::extract< POWR::Lib1::Card3::Izref >(
                                                                  iss ).value );
        }
      }
    } // WHEN

    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "the default value is provided" ){
        REQUIRE( Approx( 1.0 ) == argument::extract< POWR::Lib1::Card3::Izref >(
                                                                  iss ).value );
      }
    }
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "invalid inputs are provided" ){
      for( double d : {-100.0, -10.0, -1.0} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( d ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( argument::extract< POWR::Lib1::Card3::Izref >( iss ));
        }
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
