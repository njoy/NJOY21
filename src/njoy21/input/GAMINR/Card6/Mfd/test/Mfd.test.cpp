#define CATCH_CONFIG_MAIN

#include <numeric>

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Mfd output values", "[GROUPR],[Card9], [Mfd]"){

  GIVEN( "valid Mfd parameters" ){
    std::vector<int> validValues{ 0, 3, 5, 6, 8, 12, 13, 16, 17, 18, 
      21, 22, 23, 24, 25, 26, 31, 32, 33, 34, 35, 36, 10000000 };

    THEN( "the returned class has the correct value" ){
      for( auto mfd : validValues ){
        njoy::Log::debug( "Valid mfd={}", mfd);
        iRecordStream<char> issMfd( 
            std::istringstream( std::to_string( mfd ) ) );

        REQUIRE( mfd == argument::extract< GROUPR::Card9::Mfd >( 
                          issMfd ).value );
      }
    }
  } // GIVEN
  GIVEN( "invalid Mfd parameters" ){
    std::vector<int> invalidValues{ -2, -1, 1, 2, 4, 7, 9, 11, 14, 15, 19, 20,
      27, 28, 29, 30, 37, 9999999};

    THEN( "the returned class has the correct value" ){
      for( auto mfd : invalidValues ){
        njoy::Log::debug( "Invalid mfd={}", mfd);
        iRecordStream<char> issMfd( 
            std::istringstream( std::to_string( mfd ) ) );

        REQUIRE_THROWS( argument::extract< GROUPR::Card9::Mfd >( issMfd ) );
      }
    }
  } // GIVEN
} // SCENARIO
