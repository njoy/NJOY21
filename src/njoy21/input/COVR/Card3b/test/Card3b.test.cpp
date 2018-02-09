#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "COVR Card3b",
          "[COVR], [Card3b]"){

  GIVEN( "valid inputs" ){
    WHEN( "the returned class has the correct value" ){
      iRecordStream<char> iss( std::istringstream( "h" ) );

      THEN( "the value can be verified" ){
        COVR::Card3b card3b( iss );

        REQUIRE( "h" == card3b.hlibid.value );
      } // THEN
    } // WHEN

    WHEN( "the returned class has the correct value" ){
      iRecordStream<char> iss( std::istringstream( "hlibid" ) );

      THEN( "the value can be verified" ){
        COVR::Card3b card3b( iss );

        REQUIRE( "hlibid" == card3b.hlibid.value );
      } // THEN
    } // WHEN
  } // GIVEN

  GIVEN( "invalid (long) card3b entry" ){
    WHEN( "an invalid entry is provided" ){
      iRecordStream<char> iss( std::istringstream( "toolong"  ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( COVR::Card3b( iss ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
