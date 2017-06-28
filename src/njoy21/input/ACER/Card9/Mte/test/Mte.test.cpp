#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Verifying ACER Card9 input", "[ACER], [Card9]" ){
  GIVEN( "valid mte values" ){
    std::vector<int> validMte{0, 222, 241, 245};
    THEN( "the returned class has the correct value" ){
      for( auto mte : validMte ){
        iRecordStream<char> issMte( 
            std::istringstream( std::to_string(mte) ) );
        auto mteArg = argument::extract< ACER::Card9::Mte >(issMte );
        REQUIRE( mte == mteArg.value );
      }
    }
  }
  GIVEN( "no mte value" ){
    THEN( "the default value is returned" ){
      iRecordStream<char> iss( std::istringstream( "/") );
      REQUIRE( 0 == argument::extract< ACER::Card9::Mte >( iss ).value );
    }
  }
  GIVEN( "invalid mte values" ){
    std::vector<int> invalidMte{-222, -241, -245};
    THEN( "an exception is thrown" ){
      for( auto& mte : invalidMte ){
        iRecordStream< char> issMte( std::stringstream( std::to_string(mte) ) );
        REQUIRE_THROWS( argument::extract< ACER::Card9::Mte >( issMte ) );
      }
    }
  }
}
