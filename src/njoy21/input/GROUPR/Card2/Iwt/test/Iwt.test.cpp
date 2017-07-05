#define CATCH_CONFIG_MAIN

#include <numeric>

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Iwt output values", "[GROUPR],[Card2], [Iwt]"){

  long ln{0};
  GIVEN( "valid Iwt parameters" ){
    std::vector<int> validValues(25);
    std::iota( validValues.begin(), validValues.end(), -12);

    THEN( "the returned class has the correct value" ){
      for( auto iwt : validValues ){
        iRecordStream<char> issIwt( 
            std::istringstream( std::to_string( iwt ) ) );

        REQUIRE( iwt == argument::extract< GROUPR::Card2::Iwt >( 
                          issIwt ).value );
      }
    }
  } // GIVEN
  GIVEN( "invalid Iwt parameters" ){

    THEN( "the returned class has the correct value" ){
      for( auto iwt : { -13, -15, 13, 15 } ){
        iRecordStream<char> issIwt( 
            std::istringstream( std::to_string( iwt ) ) );

        REQUIRE_THROWS( argument::extract< GROUPR::Card2::Iwt >( issIwt ) );
      }
    }
  } // GIVEN
} // SCENARIO


