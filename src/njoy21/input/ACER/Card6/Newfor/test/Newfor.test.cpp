#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Newfor  output values",
         "[ACER],[Card6], [Newfor]"){

  long ln{0};
  GIVEN( "valid newfor values" ){
    std::vector<int> validValues{0, 1};

    THEN( "the returned class has the correct value" ){
      for( auto& newfor : validValues ){
        iRecordStream<char> iss(
            std::istringstream( std::to_string(newfor) ) );

        REQUIRE( 
          newfor == argument::extract< ACER::Card6::Newfor >( iss ).value );
      }
    }
  }
  GIVEN( "no newfor values" ){
    THEN( "the default value is returned" ){
      iRecordStream<char> iss(
          std::istringstream( "/") );
      REQUIRE( ACER::Card6::Newfor::defaultValue() == 
                argument::extract< ACER::Card6::Newfor >( iss ).value );
    }
  }
  
  GIVEN( "invalid newfor values" ){
    std::vector<int> invalidValues{-1, 2};

    THEN( "an exception is thrown" ){
      for( auto& newfor : invalidValues ){
        iRecordStream<char> iss(
            std::istringstream( std::to_string(newfor) ) );

        REQUIRE_THROWS( argument::extract< ACER::Card6::Newfor >( iss ) );
      }
    }
  }

} // SCENARIO
