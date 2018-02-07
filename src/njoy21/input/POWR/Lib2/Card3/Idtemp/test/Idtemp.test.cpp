#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "POWR, Lib2, Card3, Idtemp",
          "[POWR] [Lib2] [Card3] [Idtemp]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      for( double d : {0.0, 10.0, 1000.0} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( d ) ) );

        THEN( "the value can be verified" ){
          REQUIRE( d*dimwits::kelvin == argument::extract<
                                     POWR::Lib2::Card3::Idtemp >( iss ).value );
        }
      }
    } // WHEN

    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "the default value can be verified" ){
        REQUIRE( 300.0*dimwits::kelvin == argument::extract<
                                    POWR::Lib2::Card3::Idtemp >( iss ) .value );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "invalid inputs are provided" ){
      for( double d : {-10.0, -1.0, -0.1} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( d ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( argument::extract< POWR::Lib2::Card3::Idtemp
                                                                     >( iss ) );
        }
      }
    }
  } // GIVEN
} // SCENARIO
