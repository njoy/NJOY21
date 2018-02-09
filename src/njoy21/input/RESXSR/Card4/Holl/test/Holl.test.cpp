#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "RESXSR card4 holl",
          "[Card4], [Holl]"){

  GIVEN( "valid title values" ){
    std::vector<std::string> validValues{
      "",
      "1",
      "123456",
      "1234567890123456",
      "123456789012345678901234567890123456789012345678901234567890123456789012" };

    THEN( "the holl value is correctly read and returned" ){
      for( auto holl : validValues ){
        iRecordStream<char> issHoll( std::istringstream( "'" + holl + "'" ) );

        REQUIRE( holl == argument::extract< RESXSR::Card4::Holl >(
                         issHoll ).value);
      }
    }
  }

  GIVEN( "invalid values" ){
    THEN( "an exception is thrown" ){
      iRecordStream<char> issHoll( std::istringstream( 
      " '1234567890123456789012345678901234567890123456789012345678901234567890123' " ) );

      REQUIRE_THROWS( argument::extract< RESXSR::Card4::Holl >( issHoll ) );
    }
  }
}
