#define CATCH_CONFIG_MAIN

#include <numeric>

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Ign output values", "[GROUPR],[Card2], [Ign]"){

  long ln{0};
  GIVEN( "valid Ign parameters" ){
    std::vector<int> validValues(23);
    std::iota( validValues.begin(), validValues.end(), 1);

    THEN( "the returned class has the correct value" ){
      for( auto ign : validValues ){
        iRecordStream<char> issIgn( 
            std::istringstream( std::to_string( ign ) ) );

        REQUIRE( ign == argument::extract< GROUPR::Card2::Ign >( 
                          issIgn ).value );
      }
    }
  } // GIVEN
  GIVEN( "invalid Ign parameters" ){
    std::vector<int> invalidValues{ -1, 0, 24, 25 };

    THEN( "the returned class has the correct value" ){
      for( auto ign : invalidValues ){
        iRecordStream<char> issIgn( 
            std::istringstream( std::to_string( ign ) ) );

        REQUIRE_THROWS( argument::extract< GROUPR::Card2::Ign >( issIgn ) );
      }
    }
  } // GIVEN
} // SCENARIO


