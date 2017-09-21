#define CATCH_CONFIG_MAIN

#include <numeric>

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Ipcol output values", "[PLOTR],[Card1], [Ipcol]"){

  GIVEN( "valid Ipcol parameters" ){
    std::vector<int> validValues{0,1,2,3,4,5,6,7};

    THEN( "the returned class has the correct value" ){
      for( auto ipcol : validValues ){
        iRecordStream<char> issIpcol( 
            std::istringstream( std::to_string( ipcol ) ) );

        REQUIRE( ipcol == argument::extract< PLOTR::Card1::Ipcol >( 
                          issIpcol ).value );
      }
    }
  } // GIVEN
  GIVEN( "invalid Ipcol parameters" ){
    std::vector<int> invalidValues{ -2, -1, 8, 9 };

    THEN( "the returned class has the correct value" ){
      for( auto ipcol : invalidValues ){
        iRecordStream<char> issIpcol( 
            std::istringstream( std::to_string( ipcol ) ) );

        REQUIRE_THROWS( argument::extract< PLOTR::Card1::Ipcol >( issIpcol ) );
      }
    }
  } // GIVEN
} // SCENARIO
