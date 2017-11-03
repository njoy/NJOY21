#define CATCH_CONFIG_MAIN

#include <numeric>

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Ithick output values", "[PLOTR],[Card9], [Ithick]"){

  GIVEN( "valid Ithick parameters" ){
    std::vector<int> validValues{0,1,10,100,1000};

    THEN( "the returned class has the correct value" ){
      for( auto ithick : validValues ){
        iRecordStream<char> issIthick( 
            std::istringstream( std::to_string( ithick ) ) );

        REQUIRE( ithick == argument::extract< PLOTR::Card9::Ithick >( 
                          issIthick ).value );
      }
    }
  } // GIVEN
  GIVEN( "invalid Ithick parameters" ){
    std::vector<int> invalidValues{ -2, -1};

    THEN( "the returned class has the correct value" ){
      for( auto ithick : invalidValues ){
        iRecordStream<char> issIthick( 
            std::istringstream( std::to_string( ithick ) ) );

        REQUIRE_THROWS( argument::extract< PLOTR::Card9::Ithick >( issIthick ) );
      }
    }
  } // GIVEN
} // SCENARIO
