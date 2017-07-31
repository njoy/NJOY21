#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "LEAPR Card20 input",
  "[LEAPR], [Card20]"){

  GIVEN( "valid (short) comment entry" ){
    THEN( "the returned class has the correct value" ){
      iRecordStream<char> iss( std::istringstream( "'h'" ) );
      LEAPR::Card20 card20( iss );
      REQUIRE( "h" == *( card20.comment.value ) );
    } // THEN
  } // GIVEN

  GIVEN( "valid (medium) comment entry" ){
    THEN( "the returned class has the correct value" ){
      iRecordStream<char> iss( std::istringstream( 
        "'123456789 123456789 123456789 123456789 123456789"
	" 123456789 123456789 123456789'" ) );
      REQUIRE( "123456789 123456789 123456789 123456789 123456789" 
	       " 123456789 123456789 123456789" ==
        *(argument::extract< LEAPR::Card20::Comment >( iss ).value ) );
    } // THEN
  } // GIVEN

  GIVEN( "invalid (long) comment values" ){
    THEN( "an exception is thrown" ){
      iRecordStream<char> iss( std::istringstream( 
        "'123456789 123456789 123456789 123456789 123456789"
        " 123456789 123456789 123456789 0'" ) );
      REQUIRE_THROWS( argument::extract< 
        LEAPR::Card20::Comment >( iss ) );
    } // THEN
  } // GIVEN
  
  GIVEN( "no comment value provided" ){
    THEN( "nullopt value used" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );
      REQUIRE( not argument::extract<
        LEAPR::Card20::Comment >( iss ).value );
    } // THEN
  } // GIVEN
} // SCENARIO
