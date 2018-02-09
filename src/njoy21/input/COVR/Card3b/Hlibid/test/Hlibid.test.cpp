#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "COVR hlibid",
  "[COVR], [Card3b], [Hlibid]"){

  GIVEN( "valid inputs" ){
    THEN( "the returned class has the correct value" ){
      iRecordStream<char> iss( std::istringstream( "h" ) );
      REQUIRE( "h" == argument::extract< COVR::Card3b::Hlibid >( iss ).value);
    } // THEN

    THEN( "the returned class has the correct value" ){
      iRecordStream<char> iss( std::istringstream( "hlibid" ) );
      REQUIRE( "hlibid" == argument::extract< 
        COVR::Card3b::Hlibid >( iss ).value );
    } // THEN
  } // GIVEN

  GIVEN( "invalid (long) hlibid values" ){
    THEN( "an exception is thrown" ){
      iRecordStream<char> iss( std::istringstream( "toolong"  ) );
      REQUIRE_THROWS( argument::extract< COVR::Card3b::Hlibid >( iss ) );
    } // THEN
  } // GIVEN
} // SCENARIO
