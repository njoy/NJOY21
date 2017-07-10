#define CATCH_CONFIG_MAIN

#include <numeric>

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Ngg output values", "[GROUPR],[Card7a], [Ngg]"){

  GIVEN( "valid Ngg parameters" ){
    std::vector<int> validValues(10);
    std::iota( validValues.begin(), validValues.end(), 1);

    THEN( "the returned class has the correct value" ){
      for( auto ngg : validValues ){
        iRecordStream<char> issNgg( 
            std::istringstream( std::to_string( ngg ) ) );

        REQUIRE( ngg == argument::extract< GROUPR::Card7a::Ngg >( 
                          issNgg ).value );
      }
    }
  } // GIVEN
  GIVEN( "invalid Ngg parameters" ){
    std::vector<int> invalidValues{ -2, -1 };

    THEN( "the returned class has the correct value" ){
      for( auto ngg : invalidValues ){
        iRecordStream<char> issNgg( 
            std::istringstream( std::to_string( ngg ) ) );

        REQUIRE_THROWS( argument::extract< GROUPR::Card7a::Ngg >( issNgg ) );
      }
    }
  } // GIVEN
} // SCENARIO

