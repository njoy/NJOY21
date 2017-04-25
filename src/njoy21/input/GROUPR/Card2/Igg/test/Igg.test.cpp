#define CATCH_CONFIG_MAIN

#include <numeric>

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Igg output values", "[GROUPR],[Card2], [Igg]"){

  long ln{0};
  GIVEN( "valid Igg parameters" ){
    std::vector<int> validValues(11);
    std::iota( validValues.begin(), validValues.end(), 0);

    THEN( "the returned class has the correct value" ){
      for( auto igg : validValues ){
        njoy::Log::info("igg: {}", igg);
        iRecordStream<char> issIgg( 
            std::istringstream( std::to_string( igg ) ) );

        REQUIRE( igg == argument::extract< GROUPR::Card2::Igg >( 
                          issIgg ).value );
      }
    }
  } // GIVEN
  GIVEN( "invalid Igg parameters" ){
    std::vector<int> invalidValues{ -2, -1, 11, 12};

    THEN( "the returned class has the correct value" ){
      for( auto igg : invalidValues ){
        iRecordStream<char> issIgg( 
            std::istringstream( std::to_string( igg ) ) );

        REQUIRE_THROWS( argument::extract< GROUPR::Card2::Igg >( issIgg ) );
      }
    }
  } // GIVEN
} // SCENARIO


