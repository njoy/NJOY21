#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "PLOTR card3 title",
         "[Card3], [Title]"){
  GIVEN( "valid title values" ){
    std::vector< std::string > validValues{ 
      "",
      "This is a test descriptive string.",
      "123456789012345678901234567890123456789012345678901234567890",
      "12345678901234567890123456789012345678901234567890"
    };

    THEN( "the title value is correctly read and returned" ){
      for( auto& title : validValues ){
        iRecordStream<char> iss( std::istringstream( "'" + title + "'" ) );

        REQUIRE( 
            title == argument::extract< PLOTR::Card3::T1 >( iss ).value );
      }
    }
  }
  GIVEN( "invalid titles" ){
    THEN( "an exception is thrown" ){
      std::string value(
          "123456789 123456789 123456789 123456789 123456789 123456789 1");
      iRecordStream<char> iss(
          std::istringstream( "'" + value + "'" ) );
      REQUIRE_THROWS( argument::extract< PLOTR::Card3::T1 >( iss ) );
    }
  }
} // SCENARIO
