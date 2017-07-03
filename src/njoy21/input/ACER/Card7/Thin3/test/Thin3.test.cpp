#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Thin3  output values",
         "[ACER],[Card7], [thin3]"){
  Argument< ACER::Card7::Thin1 > thin1;
  thin1.value = 3.0;
  GIVEN( "valid thin3 values" ){
    std::vector<int> validValues{2, 3, 60};

    THEN( "the returned class has the correct value" ){
      for( auto& thin3 : validValues ){
        iRecordStream<char> iss(
            std::istringstream( std::to_string(thin3) ) );

        REQUIRE( 
          thin3 == argument::extract< ACER::Card7::Thin3 >( iss, thin1 ).value );
      }
    }
  }
  GIVEN( "no thin3 value" ){
    THEN( "the default value is returned" ){
      iRecordStream<char> iss(
          std::istringstream( "/") );
      REQUIRE( 0.0 == 
               argument::extract< ACER::Card7::Thin3 >( iss, thin1 ).value );
    }
  }
  GIVEN( "invalid thin3 values" ){
    WHEN( "thin1 is positive" ){
      thin1.value = 3.0;
      std::vector<int> invalidValues{-1, -2, 1};

      THEN( "an exception is thrown" ){
        for( auto& thin3 : invalidValues ){
          iRecordStream<char> iss(
              std::istringstream( std::to_string(thin3) ) );

          REQUIRE_THROWS( argument::extract< ACER::Card7::Thin3 >( iss, thin1 ) );
        }
      }
      }
    WHEN( "thin1 is negative" ){
      thin1.value = -3.0;
      std::vector<int> invalidValues{-1, -2, 1};

      THEN( "no exception is thrown---thin3 doesn't matter" ){
        for( auto& thin3 : invalidValues ){
          iRecordStream<char> iss(
              std::istringstream( std::to_string(thin3) ) );

          REQUIRE_NOTHROW( 
              argument::extract< ACER::Card7::Thin3 >( iss, thin1 ) );
        }
      }
      }
  }
}
