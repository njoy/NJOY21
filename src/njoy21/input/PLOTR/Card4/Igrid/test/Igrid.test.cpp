#define CATCH_CONFIG_MAIN

#include <numeric>

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Igrid output values", "[PLOTR],[Card4], [Igrid]"){

  GIVEN( "valid Igrid parameters" ){
    std::vector<int> validValues{0,1,2,3};

    THEN( "the returned class has the correct value" ){
      for( auto igrid : validValues ){
        iRecordStream<char> issIgrid( 
            std::istringstream( std::to_string( igrid ) ) );

        REQUIRE( igrid == argument::extract< PLOTR::Card4::Igrid >( 
                          issIgrid ).value );
      }
    }
  } // GIVEN
  GIVEN( "no Igrid parameter" ){
    THEN( "the default is returned" ){
      iRecordStream<char> issIgrid(std::istringstream( " /" ) );
      REQUIRE( 2 == argument::extract< PLOTR::Card4::Igrid >( issIgrid ).value );
    }
  }//GIVEN
  GIVEN( "invalid Igrid parameters" ){
    std::vector<int> invalidValues{ -1,4 };

    THEN( "the returned class has the correct value" ){
      for( auto igrid : invalidValues ){
        iRecordStream<char> issIgrid( 
            std::istringstream( std::to_string( igrid ) ) );

        REQUIRE_THROWS( argument::extract< PLOTR::Card4::Igrid >( issIgrid ) );
      }
    }
  } // GIVEN
} // SCENARIO
