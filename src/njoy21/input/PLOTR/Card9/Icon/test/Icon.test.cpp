#define CATCH_CONFIG_MAIN

#include <numeric>

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Icon output values", "[PLOTR],[Card9], [Icon]"){

  GIVEN( "valid Icon parameters" ){
    std::vector<int> validValues{-99, -40, -1, 0, 1, 25, 82};

    THEN( "the returned class has the correct value" ){
      for( auto icon : validValues ){
        iRecordStream<char> issIcon( 
            std::istringstream( std::to_string( icon ) ) );

        REQUIRE( icon == argument::extract< PLOTR::Card9::Icon >( 
                          issIcon ).value );
      }
    }
  } // GIVEN
  GIVEN( "no Icon parameter" ){
    THEN( "the default is returned" ){
      iRecordStream<char> issIcon(std::istringstream( " /" ) );
      REQUIRE( 0 == argument::extract< PLOTR::Card9::Icon >( issIcon ).value );
    }
  }//GIVEN
} // SCENARIO
