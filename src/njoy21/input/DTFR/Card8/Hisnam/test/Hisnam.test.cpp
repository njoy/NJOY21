#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "DTFR hisnam",
  "[DTFR],[Card8], [Hisnam]"){

  GIVEN( "valid (short) hisnam entry" ){
    THEN( "the returned class has the correct value" ){
      iRecordStream<char> iss( std::istringstream( "h" ) );
      REQUIRE( "h" == *(argument::extract< 
        DTFR::Card8::Hisnam >( iss ).value) );
    } // THEN
  } // GIVEN

  GIVEN( "valid (medium) hisnam entry" ){
    THEN( "the returned class has the correct value" ){
      iRecordStream<char> iss( std::istringstream( "u235h1" ) );
      REQUIRE( "u235h1" == *(argument::extract< 
        DTFR::Card8::Hisnam >( iss ).value ) );
    } // THEN
  } // GIVEN

  GIVEN( "invalid (long) hisnam values" ){
    THEN( "an exception is thrown" ){
      iRecordStream<char> iss( std::istringstream( "u235u238"  ) );
      REQUIRE_THROWS( argument::extract< 
        DTFR::Card8::Hisnam >( iss ) );
    } // THEN
  } // GIVEN
  
  GIVEN( "no hisnam value provided" ){
    THEN( "nullopt value used" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );
      REQUIRE( not argument::extract<
        DTFR::Card8::Hisnam >( iss ).value );
    } // THEN
  } // GIVEN
} // SCENARIO
