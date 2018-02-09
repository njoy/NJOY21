#define CATCH_CONFIG_MAIN

#include <numeric>

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Mfd output values", "[PLOTR],[Card8], [Mfd]"){
  int iverf = 2;

  GIVEN( "valid Mfd parameters" ){
    std::vector<int> validValues{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 13, 14, 15,
                                  23, 26, 27, 28, 30, 31, 32, 33, 34, 35, 39,
                                  40 };

    THEN( "the returned class has the correct value" ){
      for( auto mfd : validValues ){
        njoy::Log::debug( "Valid mfd={}", mfd);
        iRecordStream<char> issMfd( 
            std::istringstream( std::to_string( mfd ) ) );

        REQUIRE( mfd == argument::extract< PLOTR::Card8::Mfd >( 
                          issMfd, iverf ).value );
      }
    }
  } // GIVEN
  GIVEN( "invalid Mfd parameters" ){
    std::vector<int> invalidValues{ -1, 0, 11, 16, 17, 18, 19, 20, 21, 22, 24,
                                    25, 29, 36, 37, 38, 41 };

    THEN( "an exception is thrown" ){
      for( auto mfd : invalidValues ){
        njoy::Log::debug( "Invalid mfd={}", mfd);
        iRecordStream<char> issMfd( 
            std::istringstream( std::to_string( mfd ) ) );

        REQUIRE_THROWS( argument::extract< PLOTR::Card8::Mfd >(
                                           issMfd, iverf ) );
      }
    }
  } // GIVEN
  GIVEN( "Iverf == 0" ){
    iverf = 0;
    THEN( "this value doesn't matter." ){
      for( int i = -2; i < 45; i++ ){
        iRecordStream<char> issMfd( std::istringstream(
                                    std::to_string( i ) ) );
        REQUIRE_NOTHROW( argument::extract< PLOTR::Card8::Mfd >(
                                            issMfd, iverf ) );
      }
    }
  }//GIVEN
} // SCENARIO
