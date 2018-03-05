#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Ismooth  output values",
         "[ACER],[Card6], [Ismooth]"){

  long ln{0};
  GIVEN( "valid ismooth values" ){
    std::vector<int> validValues{0, 1};

    THEN( "the returned class has the correct value" ){
      for( auto& ismooth : validValues ){
        iRecordStream<char> iss(
            std::istringstream( std::to_string(ismooth) ) );

        REQUIRE( 
          ismooth == argument::extract< ACER::Card6::Ismooth >( iss ).value );
      }
    }
  }
  GIVEN( "no ismooth values" ){
    THEN( "the default value is returned" ){
      iRecordStream<char> iss(
          std::istringstream( "/") );
      REQUIRE( 1 == argument::extract< ACER::Card6::Ismooth >( iss ).value );
    }
  }
  
  GIVEN( "invalid ismooth values" ){
    std::vector<int> invalidValues{-1, 2};

    THEN( "an exception is thrown" ){
      for( auto& ismooth : invalidValues ){
        iRecordStream<char> iss(
            std::istringstream( std::to_string(ismooth) ) );

        REQUIRE_THROWS( argument::extract< ACER::Card6::Ismooth >( iss ) );
      }
    }
  }

} // SCENARIO
