#define CATCH_CONFIG_MAIN

#include <numeric>

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Xpoint output values", "[PLOTR],[Card10a], [Xpoint]"){

  GIVEN( "valid Xpoint parameters" ){
    std::vector<float> validValues{-10.0,-0.3,0.0,0.1,0.5,0.8,1.0,2.0,80.0};

    THEN( "the returned class has the correct value" ){
      for( auto xpoint : validValues ){
        iRecordStream<char> issXpoint( 
            std::istringstream( std::to_string( xpoint ) ) );

        REQUIRE( xpoint == argument::extract< PLOTR::Card10a::Xpoint >( 
                          issXpoint ).value );
      }
    }
  } // GIVEN
} // SCENARIO
