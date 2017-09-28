#define CATCH_CONFIG_MAIN

#include <numeric>

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Idash output values", "[PLOTR],[Card9], [Idash]"){

  GIVEN( "valid Idash parameters" ){
    std::vector<int> validValues{0,1,2,3,4};

    THEN( "the returned class has the correct value" ){
      for( auto idash : validValues ){
        iRecordStream<char> issIdash( 
            std::istringstream( std::to_string( idash ) ) );

        REQUIRE( idash == argument::extract< PLOTR::Card9::Idash >( 
                          issIdash ).value );
      }
    }
  } // GIVEN
  GIVEN( "invalid Idash parameters" ){
    std::vector<int> invalidValues{ -2, -1, 5, 6 };

    THEN( "the returned class has the correct value" ){
      for( auto idash : invalidValues ){
        iRecordStream<char> issIdash( 
            std::istringstream( std::to_string( idash ) ) );

        REQUIRE_THROWS( argument::extract< PLOTR::Card9::Idash >( issIdash ) );
      }
    }
  } // GIVEN
} // SCENARIO
