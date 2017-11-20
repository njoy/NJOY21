#define CATCH_CONFIG_MAIN

#include <numeric>

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Nform output values", "[PLOTR],[Card12], [Nform]"){

  GIVEN( "valid Nform parameters" ){
    std::vector<int> validValues{0,1,2,3,4,5,6,7,8};

    THEN( "the returned class has the correct value" ){
      for( auto nform : validValues ){
        iRecordStream<char> issNform( 
            std::istringstream( std::to_string( nform ) ) );

        REQUIRE( nform == argument::extract< PLOTR::Card12::Nform >( 
                          issNform ).value );
      }
    }
  } // GIVEN
  GIVEN( "invalid Nform parameters" ){
    std::vector<int> invalidValues{ -2, -1 };

    THEN( "the returned class has the correct value" ){
      for( auto nform : invalidValues ){
        iRecordStream<char> issNform( 
            std::istringstream( std::to_string( nform ) ) );

        REQUIRE_THROWS( argument::extract< PLOTR::Card12::Nform >( issNform ) );
      }
    }
  } // GIVEN
} // SCENARIO
