#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "POWR, Lib3, Card12c, Scat",
          "[POWR] [Lib3] [Card12c] [Scat]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      iRecordStream<char> iss( std::istringstream( " 0.1 0.2 0.3 0.4 /" ) );

      THEN( "the values can be provided" ){
        auto test = argument::extract< POWR::Lib3::Card12c::Scat >(iss,4).value;

        REQUIRE( 4 == test.size() );

        REQUIRE( Approx( 0.1 ) == test.at(0) );
        REQUIRE( Approx( 0.2 ) == test.at(1) );
        REQUIRE( Approx( 0.3 ) == test.at(2) );
        REQUIRE( Approx( 0.4 ) == test.at(3) );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "no input is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< POWR::Lib3::Card12c::Scat >(
                                                                    iss, 12 ) );
      }
    } // WHEN

    WHEN( "an invalid value is provided" ){
      iRecordStream<char> iss( std::istringstream( " 0.1 0.2 0.3 -0.4 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< POWR::Lib3::Card12c::Scat >(
                                                                     iss, 4 ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
