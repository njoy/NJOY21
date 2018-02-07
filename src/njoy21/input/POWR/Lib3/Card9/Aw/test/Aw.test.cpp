#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "POWR, Card9, Lib3, Aw",
          "[POWR] [Card9] [Lib3] [Aw]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      for( double d : {0.1, 1.0, 10.0, 100.0} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( d ) ) );

        THEN( "the value can be verified" ){
          REQUIRE( Approx( d ) == argument::extract< POWR::Lib3::Card9::Aw >(
                                                                  iss ).value );
        }
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< POWR::Lib3::Card9::Aw >( iss ) );
      }
    } // WHEN

    WHEN( "invlid values are provided" ){
      for( double d : {-10.0, -1.0, -0.1, 0.0} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( d ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( argument::extract< POWR::Lib3::Card9::Aw >( iss ) );
        }
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
