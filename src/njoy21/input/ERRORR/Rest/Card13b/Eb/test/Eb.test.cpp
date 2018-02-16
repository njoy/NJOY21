#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "ERRORR, Rest, Card13b, Eb",
          "[ERRORR] [Rest] [Card13b] [Eb]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid values are provided" ){
      for( double d : {0.0, 0.1, 1.0, 10.0} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( d ) ) );

        THEN( "the value can be verified" ){
          REQUIRE( d*dimwits::electronVolt == argument::extract<
                                     ERRORR::Rest::Card13b::Eb >( iss ).value );
        }
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< ERRORR::Rest::Card13b::Eb >( iss ) );
      }
    } // WHEN

    WHEN( "an invalid value is provided" ){
      iRecordStream<char> iss( std::istringstream( " -1.0 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< ERRORR::Rest::Card13b::Eb >( iss ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
