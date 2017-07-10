#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Verifying ACER Card9 input", "[ACER], [Card9]" ){
  GIVEN( "valid iwt values" ){
    std::vector<int> validIwt{0, 1, 2};
    THEN( "the returned class has the correct value" ){
      for( auto iwt : validIwt ){
        iRecordStream<char> issIwt( 
            std::istringstream( std::to_string(iwt) ) );
        auto iwtArg = argument::extract< ACER::Card9::Iwt >(issIwt );
        REQUIRE( iwt == iwtArg.value );
      }
    }
  }
  GIVEN( "no iwt value" ){
    THEN( "the default value is returned" ){
      iRecordStream<char> iss( std::istringstream( "/") );
      REQUIRE( 0 == 
                argument::extract< ACER::Card9::Iwt >( iss ).value );
    }
  }
  GIVEN( "invalid iwt values" ){
    std::vector<int> invalidIwt{-1, 3};
    THEN( "an exception is thrown" ){
      for( auto& iwt : invalidIwt ){
        iRecordStream< char> issIwt( std::stringstream( std::to_string(iwt) ) );
        REQUIRE_THROWS( argument::extract< ACER::Card9::Iwt >( issIwt ) );
      }
    }
  }
}

