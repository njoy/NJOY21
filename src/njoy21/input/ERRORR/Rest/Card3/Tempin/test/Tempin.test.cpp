#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "ERRORR, Rest, Card3, Tempin",
          "[ERRORR] [Rest] [Card3] [Tempin]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      for( double d : {0.0, 1.0, 10.0, 100.0, 1000.0} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( d ) ) );

        THEN( "the values can be verified" ){
          REQUIRE( d*dimwits::kelvin ==
                argument::extract< ERRORR::Rest::Card3::Tempin >( iss ).value );
        }
      }
    } // WHEN

    WHEN( "no input is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "the default value can be verified" ){
        REQUIRE( 300.0*dimwits::kelvin ==
                argument::extract< ERRORR::Rest::Card3::Tempin >( iss ).value );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "an invalid value is provided" ){
      iRecordStream<char> iss( std::istringstream( std::to_string( -1.0 ) ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS(argument::extract< ERRORR::Rest::Card3::Tempin >( iss ));
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
