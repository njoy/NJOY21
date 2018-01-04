#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "RESXSR card3 huse",
          "[Card3], [Huse]"){

  GIVEN( "valid title values" ){
    std::vector<std::string> validValues{
      "",
      "1",
      "123456",
      "1234567890123456" };

    THEN( "the huse value is correctly read and returned" ){
      for( auto huse : validValues ){
        iRecordStream<char> issHuse( std::istringstream( "'" + huse + "'" ) );

        REQUIRE( huse == argument::extract< RESXSR::Card3::Huse >(
                         issHuse ).value);
      }
    }
  }

  GIVEN( "invalid values" ){
    THEN( "an exception is thrown" ){
      iRecordStream<char> issHuse( std::istringstream( 
                          " '12345678901234567' " ) );

      REQUIRE_THROWS( argument::extract< RESXSR::Card3::Huse >( issHuse ) );
    }
  }
}
