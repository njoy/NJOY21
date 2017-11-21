#define CATCH_CONFIG_MAIN

#include <numeric>

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Iccol output values", "[PLOTR],[Card9], [Iccol]"){

  GIVEN( "valid Iccol parameters" ){
    std::vector<int> validValues{0,1,2,3,4,5,6,7,8};

    THEN( "the returned class has the correct value" ){
      for( auto iccol : validValues ){
        iRecordStream<char> issIccol( 
            std::istringstream( std::to_string( iccol ) ) );

        REQUIRE( iccol == argument::extract< PLOTR::Card9::Iccol >( 
                          issIccol ).value );
      }
    }
  } // GIVEN
  GIVEN( "invalid Iccol parameters" ){
    std::vector<int> invalidValues{ -2, -1, 9, 10 };

    THEN( "an exception is thrown" ){
      for( auto iccol : invalidValues ){
        iRecordStream<char> issIccol( 
            std::istringstream( std::to_string( iccol ) ) );

        REQUIRE_THROWS( argument::extract< PLOTR::Card9::Iccol >( issIccol ) );
      }
    }
  } // GIVEN
} // SCENARIO
