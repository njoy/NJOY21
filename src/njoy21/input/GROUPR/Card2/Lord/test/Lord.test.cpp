#define CATCH_CONFIG_MAIN

#include <numeric>

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Lord output values", "[GROUPR],[Card2], [Lord]"){

  long ln{0};
  GIVEN( "valid Lord parameters" ){
    std::vector<int> validValues(10);
    std::iota( validValues.begin(), validValues.end(), 1);

    THEN( "the returned class has the correct value" ){
      for( auto lord : validValues ){
        iRecordStream<char> issLord( 
            std::istringstream( std::to_string( lord ) ) );

        REQUIRE( lord == argument::extract< GROUPR::Card2::Lord >( 
                          issLord ).value );
      }
    }
  } // GIVEN
  GIVEN( "invalid Lord parameters" ){
    std::vector<int> invalidValues{ -1, 0 };

    THEN( "the returned class has the correct value" ){
      for( auto lord : invalidValues ){
        iRecordStream<char> issLord( 
            std::istringstream( std::to_string( lord ) ) );

        REQUIRE_THROWS( argument::extract< GROUPR::Card2::Lord >( issLord ) );
      }
    }
  } // GIVEN
} // SCENARIO



