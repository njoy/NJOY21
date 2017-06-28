#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Iza02 input values", "[ACER], [Card8a], [Iza02]" ){
  GIVEN( "valid iza02 values" ){
    std::vector<int> validIza02{ 1001, 92235 };

    THEN( "the returned class has the correct value" ){
      for( auto iza02 : validIza02 ){
        iRecordStream<char> issIza02( 
            std::istringstream( std::to_string(iza02) ) );
        auto iza02Arg = argument::extract< ACER::Card8a::Iza02 >(issIza02 );
        REQUIRE( iza02 == iza02Arg.value );
      }
    }
  }
  GIVEN( "no iza02 value" ){
    THEN( "the default value is returned" ){
      iRecordStream<char> iss( std::istringstream( "/") );
      REQUIRE( 0 == argument::extract< ACER::Card8a::Iza02 >( iss ).value );
    }
  }
  GIVEN( "invalid iza02 values" ){
    int iza02(-1001);
    THEN( "an exception is thrown" ){
      iRecordStream<char> issIza02( std::istringstream( std::to_string(iza02) ) );
      REQUIRE_THROWS( argument::extract< ACER::Card8a::Iza02 >(issIza02) );
    }
  }
}

