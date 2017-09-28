#define CATCH_CONFIG_MAIN

#include <numeric>

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Ishade output values", "[PLOTR],[Card9], [Ishade]"){

  GIVEN( "valid Ishade parameters" ){
    std::vector<int> validValues(81);
    std::iota(validValues.begin(), validValues.end(), 0);

    THEN( "the returned class has the correct value" ){
      for( auto ishade : validValues ){
        iRecordStream<char> issIshade( 
            std::istringstream( std::to_string( ishade ) ) );

        REQUIRE( ishade == argument::extract< PLOTR::Card9::Ishade >( 
                          issIshade ).value );
      }
    }
  } // GIVEN
  GIVEN( "invalid Ishade parameters" ){
    std::vector<int> invalidValues{ -2, -1, 82, 90 };

    THEN( "the returned class has the correct value" ){
      for( auto ishade : invalidValues ){
        iRecordStream<char> issIshade( 
            std::istringstream( std::to_string( ishade ) ) );

        REQUIRE_THROWS( argument::extract< PLOTR::Card9::Ishade >( issIshade ) );
      }
    }
  } // GIVEN
} // SCENARIO
