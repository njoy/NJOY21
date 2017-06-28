#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Thin2  output values",
         "[ACER],[Card7], [thin2]"){
  GIVEN( "valid thin2 values" ){
    std::vector<double> validValues{0.0, 0.001, 1E4, 1.0, 2};

    THEN( "the returned class has the correct value" ){
      for( auto& thin2 : validValues ){
        iRecordStream<char> iss(
            std::istringstream( std::to_string(thin2) ) );
        njoy::Log::info("Valid value {}", thin2);

        REQUIRE( 
          thin2 == argument::extract< ACER::Card7::Thin2 >( iss ).value );
      }
    }
  }
  GIVEN( "no thin2 value" ){
    THEN( "the default value is returned" ){
      iRecordStream<char> iss(
          std::istringstream( "/") );
      REQUIRE( 0.0 == argument::extract< ACER::Card7::Thin2 >( iss ).value );
    }
  }
  GIVEN( "invalid thin2 values" ){
    std::vector<double> invalidValues{-1};

    THEN( "an exception is thrown" ){
      for( auto& thin2 : invalidValues ){
        iRecordStream<char> iss(
            std::istringstream( std::to_string(thin2) ) );

        REQUIRE_THROWS( argument::extract< ACER::Card7::Thin2 >( iss ) );
      }
    }
  }
}
