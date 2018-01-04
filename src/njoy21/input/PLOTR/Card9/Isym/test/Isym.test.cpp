#define CATCH_CONFIG_MAIN

#include <numeric>

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Isym output values", "[PLOTR],[Card9], [Isym]"){

  GIVEN( "valid Isym parameters" ){
    std::vector<int> validValues(19);
    std::iota(validValues.begin(), validValues.end(), 0);

    THEN( "the returned class has the correct value" ){
      for( auto isym : validValues ){
        iRecordStream<char> issIsym( 
            std::istringstream( std::to_string( isym ) ) );

        REQUIRE( isym == argument::extract< PLOTR::Card9::Isym >( 
                          issIsym ).value );
      }
    }
  } // GIVEN
  GIVEN( "invalid Isym parameters" ){
    std::vector<int> invalidValues{ -2, -1, 19, 20 };

    THEN( "the returned class has the correct value" ){
      for( auto isym : invalidValues ){
        iRecordStream<char> issIsym( 
            std::istringstream( std::to_string( isym ) ) );

        REQUIRE_THROWS( argument::extract< PLOTR::Card9::Isym >( issIsym ) );
      }
    }
  } // GIVEN
} // SCENARIO
