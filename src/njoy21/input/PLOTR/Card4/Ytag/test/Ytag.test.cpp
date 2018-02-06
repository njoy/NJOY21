#define CATCH_CONFIG_MAIN

#include <numeric>

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Ytag output values", "[PLOTR],[Card4], [Ytag]"){

  GIVEN( "valid Ytag parameters" ){
    std::vector<double> validValues{-2.0,-1.1,0.0,0.1,0.5,0.8,1.0,2.0,80.0};

    THEN( "the returned class has the correct value" ){
      for( auto ytag : validValues ){
        iRecordStream<char> issYtag( 
            std::istringstream( std::to_string( ytag ) ) );

        REQUIRE( ytag == argument::extract< PLOTR::Card4::Ytag >( 
                          issYtag ).value );
      }
    }
  } // GIVEN
} // SCENARIO
