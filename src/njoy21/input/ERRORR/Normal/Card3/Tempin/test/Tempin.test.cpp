#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "ERRORR, Normal, Card3, Tempin",
          "[ERRORR] [Normal] [Card3] [Tempin]" ){
  GIVEN( "valid inputs" ){
    for( double d : {0.0, 1.0, 10.0, 100.0, 1000.0} ){
      std::string situ( "valid input " + std::to_string(d) + " is provided." );
      WHEN( situ.c_str() ){
        iRecordStream<char> iss( std::istringstream( std::to_string( d ) ) );

        THEN( "the values can be verified" ){
          REQUIRE( d*dimwits::kelvin ==
              argument::extract< ERRORR::Normal::Card3::Tempin >( iss ).value );
        }
      } // WHEN
    }

    WHEN( "no input is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "the default value can be verified" ){
        REQUIRE( 300.0*dimwits::kelvin ==
              argument::extract< ERRORR::Normal::Card3::Tempin >( iss ).value );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "an invalid value is provided" ){
      iRecordStream<char> iss( std::istringstream( std::to_string( -1.0 ) ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS(
                    argument::extract< ERRORR::Normal::Card3::Tempin >( iss ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
