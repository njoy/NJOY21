#define CATCH_CONFIG_MAIN

#include <numeric>

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Ntemp output values", "[GROUPR],[Card2], [Ntemp]"){

  long ln{0};
  GIVEN( "valid Ntemp parameters" ){
    std::vector<int> validValues(10);
    std::iota( validValues.begin(), validValues.end(), 1);

    THEN( "the returned class has the correct value" ){
      for( auto ntemp : validValues ){
        iRecordStream<char> issNtemp( 
            std::istringstream( std::to_string( ntemp ) ) );

        REQUIRE( ntemp == argument::extract< GROUPR::Card2::Ntemp >( 
                          issNtemp ).value );
      }
    }
  } // GIVEN
  GIVEN( "no ntemp value" ){
    THEN( "the default value is returned" ){
      iRecordStream<char> iss( std::istringstream( "/") );
      REQUIRE( 1 == argument::extract< GROUPR::Card2::Ntemp >( iss ).value );
    }
  }
  GIVEN( "invalid Ntemp parameters" ){
    std::vector<int> invalidValues{ -2, -1 };

    THEN( "the returned class has the correct value" ){
      for( auto ntemp : invalidValues ){
        iRecordStream<char> issNtemp( 
            std::istringstream( std::to_string( ntemp ) ) );

        REQUIRE_THROWS( argument::extract< GROUPR::Card2::Ntemp >( issNtemp ) );
      }
    }
  } // GIVEN
} // SCENARIO
