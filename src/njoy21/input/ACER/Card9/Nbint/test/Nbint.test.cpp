#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Verifying ACER Card9 input", "[ACER], [Card9]" ){
  GIVEN( "valid nbint values" ){
    std::vector<int> validNbint{1, 16, 25};
    THEN( "the returned class has the correct value" ){
      for( auto nbint : validNbint ){
        iRecordStream<char> issNbint( 
            std::istringstream( std::to_string(nbint) ) );
        auto nbintArg = argument::extract< ACER::Card9::Nbint >(issNbint );
        REQUIRE( nbint == nbintArg.value );
      }
    }
  }
  GIVEN( "no Nbint value" ){
    THEN( "the default value is returned" ){
      iRecordStream<char> iss( std::istringstream( "/") );
      REQUIRE( ACER::Card9::Nbint::defaultValue() == 
                argument::extract< ACER::Card9::Nbint >( iss ).value );
    }
  }
  GIVEN( "invalid nbint values" ){
    std::vector<int> invalidNbint{-1, 0};
    THEN( "an exception is thrown" ){
      for( auto& nbint : invalidNbint ){
        iRecordStream< char> issNbint( std::stringstream( std::to_string(nbint) ) );
        REQUIRE_THROWS( argument::extract< ACER::Card9::Nbint >( issNbint ) );
      }
    }
  }
}

