#define CATCH_CONFIG_MAIN

#include <numeric>

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Ydata output values", "[PLOTR],[Card13], [Ydata]"){

  GIVEN( "valid Ydata parameters" ){
    std::vector<double> validValues{-2.0,-1.0,0.0,0.1,0.5,0.8,1.0,2.0,80.0};

    THEN( "the returned class has the correct value" ){
      for( auto ydata : validValues ){
        iRecordStream<char> issYdata( 
            std::istringstream( std::to_string( ydata ) ) );

        REQUIRE( ydata == argument::extract< PLOTR::Card13::Ydata >( 
                          issYdata ).value );
      }
    }
  } // GIVEN

  GIVEN( "no parameter" ){
    iRecordStream<char> issYdata( std::istringstream( " /" ) );
    THEN( "the default nullopt is returned" ){
      REQUIRE( std::nullopt == argument::extract< PLOTR::Card13::Ydata >(
                               issYdata ).value );
    }
  } // GIVEN

} // SCENARIO
