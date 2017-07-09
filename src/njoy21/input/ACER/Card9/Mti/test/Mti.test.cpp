#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Verifying ACER Card9 input", "[ACER], [Card9]" ){
  GIVEN( "valid mti values" ){
    std::vector<int> validMti{222, 241, 245};
    THEN( "the returned class has the correct value" ){
      for( auto mti : validMti ){
        iRecordStream<char> issMti( 
            std::istringstream( std::to_string(mti) ) );
        auto mtiArg = argument::extract< ACER::Card9::Mti >(issMti );
        REQUIRE( mti == mtiArg.value );
      }
    }
  }
  GIVEN( "invalid mti values" ){
    std::vector<int> invalidMti{-222, -241, -245, 0, 1000};
    THEN( "an exception is thrown" ){
      for( auto& mti : invalidMti ){
        iRecordStream< char> issMti( std::stringstream( std::to_string(mti) ) );
        REQUIRE_THROWS( argument::extract< ACER::Card9::Mti >( issMti ) );
      }
    }
  }
}
