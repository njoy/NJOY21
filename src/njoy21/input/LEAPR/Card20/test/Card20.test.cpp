#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "LEAPR Card20 input",
  "[LEAPR], [Card20]"){

  GIVEN( "valid (short) card20 entry" ){
    THEN( "the returned class has the correct value" ){
      iRecordStream<char> iss( std::istringstream( "'h'" ) );
      LEAPR::Card20 card20( iss );
      REQUIRE( "h" == *( card20.comment.value ) );
    } // THEN
  } // GIVEN

  GIVEN( "valid (medium) card20 entry" ){
    THEN( "the returned class has the correct value" ){
      iRecordStream<char> iss( std::istringstream( 
        "'123456789 123456789 123456789 123456789 123456789 123456789 123456'" )
       );
      LEAPR::Card20 card20( iss );
      REQUIRE( 
        "123456789 123456789 123456789 123456789 123456789 123456789 123456" 
         == *(card20.comment.value) );
    } // THEN
  } // GIVEN

  GIVEN( "invalid (long) card20 entry" ){
    THEN( "an exception is thrown" ){
      iRecordStream<char> iss( std::istringstream( 
        "'123456789 123456789 123456789 123456789 123456789 123456789 1234567'")
      );
      REQUIRE_THROWS( LEAPR::Card20( iss ) ); 
    } // THEN
  } // GIVEN
} // SCENARIO
