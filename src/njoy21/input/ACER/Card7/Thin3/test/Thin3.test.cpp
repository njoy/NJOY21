#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Newfor  output values",
         "[ACER],[Card7], [thin3]"){
  GIVEN( "valid thin3 values" ){
    std::vector<int> validValues{1, 2, 3, 60};

    THEN( "the returned class has the correct value" ){
      for( auto& thin3 : validValues ){
        iRecordStream<char> iss(
            std::istringstream( std::to_string(thin3) ) );

        REQUIRE( 
          thin3 == argument::extract< ACER::Card7::Thin3 >( iss ).value );
      }
    }
  }
  GIVEN( "no thin3 value" ){
    THEN( "the default value is returned" ){
      iRecordStream<char> iss(
          std::istringstream( "/") );
      REQUIRE( ACER::Card7::Thin3::defaultValue() == 
                argument::extract< ACER::Card7::Thin3 >( iss ).value );
    }
  }
  GIVEN( "invalid thin3 values" ){
    std::vector<int> invalidValues{-1, -2};

    THEN( "an exception is thrown" ){
      for( auto& thin3 : invalidValues ){
        iRecordStream<char> iss(
            std::istringstream( std::to_string(thin3) ) );

        REQUIRE_THROWS( argument::extract< ACER::Card7::Thin3 >( iss ) );
      }
    }
  }
}
