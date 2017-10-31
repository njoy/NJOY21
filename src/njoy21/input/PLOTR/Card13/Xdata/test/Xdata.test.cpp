#define CATCH_CONFIG_MAIN

#include <numeric>

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Xdata output values", "[PLOTR],[Card13], [Xdata]"){

  GIVEN( "valid Xdata parameters" ){
    std::vector<double> validValues{-2.0,-1.0,0.0,0.1,0.5,0.8,1.0,2.0,80.0};

    THEN( "the returned class has the correct value" ){
      for( auto xdata : validValues ){
        iRecordStream<char> issXdata( 
            std::istringstream( std::to_string( xdata ) ) );

        REQUIRE( xdata == argument::extract< PLOTR::Card13::Xdata >( 
                          issXdata ).value );
      }
    }
  } // GIVEN

  GIVEN( "no parameter" ){
    iRecordStream<char> issXdata( std::istringstream( " /" ) );
    THEN( "a default nullopt is returned" ){
      REQUIRE( std::nullopt == argument::extract< PLOTR::Card13::Xdata >(
                               issXdata ).value );
    }
  } // GIVEN

} // SCENARIO
