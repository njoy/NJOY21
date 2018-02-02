#define CATCH_CONFIG_MAIN

#include <numeric>

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Lori output values", "[PLOTR],[Card1], [Lori]"){

  GIVEN( "valid Lori parameters" ){
    std::vector<int> validValues{0,1};

    THEN( "the returned class has the correct value" ){
      for( auto lori : validValues ){
        iRecordStream<char> issLori( 
            std::istringstream( std::to_string( lori ) ) );

        REQUIRE( lori == argument::extract< PLOTR::Card1::Lori >( 
                          issLori ).value );
      }
    }
  } // GIVEN
  GIVEN( "no parameter" ){
    THEN( "the default is returned" ){
      iRecordStream<char> issLori( std::istringstream( " /" ) );

      REQUIRE( 1 == argument::extract< PLOTR::Card1::Lori >( issLori ).value );
    }
  } //GIVEN
  GIVEN( "invalid Lori parameters" ){
    std::vector<int> invalidValues{ -2, -1, 2, 3 };

    THEN( "the returned class has the correct value" ){
      for( auto lori : invalidValues ){
        iRecordStream<char> issLori( 
            std::istringstream( std::to_string( lori ) ) );

        REQUIRE_THROWS( argument::extract< PLOTR::Card1::Lori >( issLori ) );
      }
    }
  } // GIVEN
} // SCENARIO
