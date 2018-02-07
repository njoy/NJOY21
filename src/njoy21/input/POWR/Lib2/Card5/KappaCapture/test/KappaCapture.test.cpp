#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "POWR, Lib2, Card5, KappaCapture",
          "[POWR] [Lib2] [Card5] [KappaCapture]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid values are provided" ){
      for( double d : {0.1, 1.0, 10.0} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( d ) ) );

        THEN( "the value can be verified" ){
          REQUIRE( Approx( d ) == argument::extract<
                               POWR::Lib2::Card5::KappaCapture >( iss ).value );
        }
      }
    } // WHEN

    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "the default value can be verified" ){
        REQUIRE( Approx( 0.0 ) == argument::extract<
                               POWR::Lib2::Card5::KappaCapture >( iss ).value );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "invalid values are provided" ){
      iRecordStream<char> iss( std::istringstream( " -0.1 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< POWR::Lib2::Card5::KappaCapture >(
                                                                  iss ).value );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
