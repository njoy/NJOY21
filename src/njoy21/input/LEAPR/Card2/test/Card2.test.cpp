#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "LEAPR card2",
  "[LEAPR], [Card2]"){
  GIVEN( "valid card2 inputs" ){
    std::vector< std::string > validValues{ 
      "",
      "This is a test descriptive string.",
      "123456789012345678901234567890123456789012345678901234567890123456",
      "1234567890123456789012345678901234567890123456789012345678901234567890"
    };
    THEN( "card2 is correctly read and returned" ){
      for( auto& title : validValues ){
        iRecordStream<char> iss( std::istringstream( "'" + title + "'" ) );

        LEAPR::Card2 card2( iss );
        REQUIRE( card2.title.value == title );
      } 
    } // THEN
  } // GIVEN
  GIVEN( "invalid card2 input" ){
    THEN( "an exception is thrown" ){
      std::string value(
          "123456789 123456789 123456789 123456789 123456789 123456789" 
          "123456789 123456789 12");
      iRecordStream<char> iss(
          std::istringstream( "'" + value + "'" ) );

      REQUIRE_THROWS( LEAPR::Card2( iss ) );
    } // THEN
  } // GIVEN
} // SCENARIO
