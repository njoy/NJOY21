#define CATCH_CONFIG_MAIN

#include <numeric>

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Ngn output values", "[GROUPR],[Card6a], [Ngn]"){

  GIVEN( "valid Ngn parameters" ){
    std::vector<int> validValues(10);
    std::iota( validValues.begin(), validValues.end(), 1);

    THEN( "the returned class has the correct value" ){
      for( auto ngn : validValues ){
        iRecordStream<char> issNgn( 
            std::istringstream( std::to_string( ngn ) ) );

        REQUIRE( ngn == argument::extract< GROUPR::Card6a::Ngn >( 
                          issNgn ).value );
      }
    }
  } // GIVEN
  GIVEN( "invalid Ngn parameters" ){
    std::vector<int> invalidValues{ -2, -1 };

    THEN( "the returned class has the correct value" ){
      for( auto ngn : invalidValues ){
        iRecordStream<char> issNgn( 
            std::istringstream( std::to_string( ngn ) ) );

        REQUIRE_THROWS( argument::extract< GROUPR::Card6a::Ngn >( issNgn ) );
      }
    }
  } // GIVEN
} // SCENARIO

