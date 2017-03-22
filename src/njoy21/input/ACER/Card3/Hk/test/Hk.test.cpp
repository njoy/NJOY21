#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "ACER card3 hk",
         "[Card3], [Hk]"){
  GIVEN( "valid hk values" ){
    std::vector< std::string > validValues{ 
      "",
      "This is a test descriptive string.",
      "123456789012345678901234567890123456789012345678901234567890123456"
    };

    THEN( "the tname value is correctly read and returned" ){
      for( auto& hk : validValues ){
        iRecordStream<char> iss( std::istringstream( "'" + hk + "'" ) );

        REQUIRE( 
            hk == argument::extract< ACER::Card3::Hk >( iss ).value );
      }
    }
  }
  GIVEN( "invalid hks" ){
    THEN( "an exception is thrown" ){
      std::string value(
          "1234567890123456789012345678901234567890"
          "1234567890123456789012345678901");
      iRecordStream<char> iss(
          std::istringstream( "'" + value + "'" ) );
      REQUIRE_THROWS( argument::extract< 
                     ACER::Card3::Hk >( iss ) );
    }
  }
} // SCENARIO

