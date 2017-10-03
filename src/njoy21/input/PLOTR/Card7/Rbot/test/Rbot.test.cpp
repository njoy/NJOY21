#define CATCH_CONFIG_MAIN

#include <numeric>

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Rbot output values", "[PLOTR],[Card7], [Rbot]"){

  GIVEN( "valid Rbot parameters" ){
    std::vector<float> validValues{0.0,0.1,0.5,0.8,1.0,2.0,80.0};

    THEN( "the returned class has the correct value" ){
      for( auto rbot : validValues ){
        iRecordStream<char> issRbot( 
            std::istringstream( std::to_string( rbot ) ) );

        REQUIRE( rbot == argument::extract< PLOTR::Card7::Rbot >( 
                          issRbot ).value );
      }
    }
  } // GIVEN

  GIVEN( "default value" ){
    iRecordStream<char> issRbot( std::istringstream( " /" ) );

    THEN( "default value is returned" ){
      REQUIRE( APPROX( 0.0 ) == argument::extract< PLOTR::Card7::Rbot >(
                          issRbot ).value );
    }
  }//GIVEN

  GIVEN( "invalid Rbot parameters" ){
    std::vector<float> invalidValues{ -2.0, -1.1 };

    THEN( "the class throws an exception" ){
      for( auto rbot : invalidValues ){
        iRecordStream<char> issRbot( 
            std::istringstream( std::to_string( rbot ) ) );

        REQUIRE_THROWS( argument::extract< PLOTR::Card7::Rbot >( issRbot ) );
      }
    }
  } // GIVEN
} // SCENARIO
