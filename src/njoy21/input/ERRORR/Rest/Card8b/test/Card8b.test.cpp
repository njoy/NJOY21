#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "ERRORR, Rest, Card8b",
          "[ERRORR] [Rest] [Card8b]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid values are provided" ){
      iRecordStream<char> iss( std::istringstream(
                                               " 0.2 2.0 2.0e1 2.0e2 /" ) );

      THEN( "the values can be verified" ){
        ERRORR::Rest::Card8b card8b( iss, 3 );

        REQUIRE( 4 == card8b.ek.value.size() );

        REQUIRE( 0.2*dimwits::electronVolt == card8b.ek.value.at(0) );
        REQUIRE( 2.0*dimwits::electronVolt == card8b.ek.value.at(1) );
        REQUIRE( 20.0*dimwits::electronVolt == card8b.ek.value.at(2) );
        REQUIRE( 200.0*dimwits::electronVolt == card8b.ek.value.at(3) );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "too many values are provided" ){
      iRecordStream<char> iss( std::istringstream( " 0.2 2.0 2.0e1 2.0e2 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( ERRORR::Rest::Card8b( iss, 2 ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
