#define CATCH_CONFIG_MAIN

#include <numeric>

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Size output values", "[PLOTR],[Card1], [Size]"){

  GIVEN( "valid Size parameters" ){
    std::vector<double> validValues{-1.0,-0.5,-0.1,0.1,0.5,0.8,1.0};

    THEN( "the returned class has the correct value" ){
      for( auto size : validValues ){
        iRecordStream<char> issSize( 
            std::istringstream( std::to_string( size ) ) );

        REQUIRE( size == argument::extract< PLOTR::Card1::Size >( 
                          issSize ).value );
      }
    }
  } // GIVEN

  GIVEN( "no Size parameter provided" ){
    THEN( "the default value is returned" ){
      iRecordStream<char> issSize( std::istringstream( " /" ) );
      REQUIRE( Approx( 0.3 ) == argument::extract< PLOTR::Card1::Size >( 
                         issSize ).value );
    }
  } //GIVEN

  GIVEN( "invalid Size parameters" ){
    std::vector<double> invalidValues{ -2.0, -1.1, 0.0, 2.0, 3.0 };

    THEN( "an exception is thrown" ){
      for( auto size : invalidValues ){
        iRecordStream<char> issSize( 
            std::istringstream( std::to_string( size ) ) );

        REQUIRE_THROWS( argument::extract< PLOTR::Card1::Size >( issSize ) );
      }
    }
  } // GIVEN
} // SCENARIO
