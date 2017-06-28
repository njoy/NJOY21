#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Verifying ACER Card9 input", "[ACER], [Card9]" ){
  GIVEN( "valid ielas values" ){
    std::vector<int> validIelas{0, 1};
    THEN( "the returned class has the correct value" ){
      for( auto ielas : validIelas ){
        iRecordStream<char> issIelas( 
            std::istringstream( std::to_string(ielas) ) );
        auto ielasArg = argument::extract< ACER::Card9::Ielas >(issIelas );
        REQUIRE( ielas == ielasArg.value );
      }
    }
  }
  GIVEN( "no ielas value" ){
    THEN( "the default value is returned" ){
      iRecordStream<char> iss( std::istringstream( "/") );
      REQUIRE( 0 == argument::extract< ACER::Card9::Ielas >( iss ).value );
    }
  }
  GIVEN( "invalid ielas values" ){
    std::vector<int> invalidIelas{-1, 2};
    THEN( "an exception is thrown" ){
      for( auto& ielas : invalidIelas ){
        iRecordStream< char> issIelas( std::stringstream( std::to_string(ielas) ) );
        REQUIRE_THROWS( argument::extract< ACER::Card9::Ielas >( issIelas ) );
      }
    }
  }
}

