#define CATCH_CONFIG_MAIN

#include <numeric>

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Istyle output values", "[PLOTR],[Card1], [Istyle]"){

  GIVEN( "valid Istyle parameters" ){
    std::vector<int> validValues{1,2};

    THEN( "the returned class has the correct value" ){
      for( auto istyle : validValues ){
        iRecordStream<char> issIstyle( 
            std::istringstream( std::to_string( istyle ) ) );

        REQUIRE( istyle == argument::extract< PLOTR::Card1::Istyle >( 
                          issIstyle ).value );
      }
    }
  } // GIVEN
  GIVEN( "invalid Istyle parameters" ){
    std::vector<int> invalidValues{ -2, -1, 0, 3, 4 };

    THEN( "the returned class has the correct value" ){
      for( auto istyle : invalidValues ){
        iRecordStream<char> issIstyle( 
            std::istringstream( std::to_string( istyle ) ) );

        REQUIRE_THROWS( argument::extract< PLOTR::Card1::Istyle >( issIstyle ) );
      }
    }
  } // GIVEN
} // SCENARIO
