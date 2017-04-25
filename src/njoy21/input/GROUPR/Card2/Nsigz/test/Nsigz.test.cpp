#define CATCH_CONFIG_MAIN

#include <numeric>

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Nsigz output values", "[GROUPR],[Card2], [Nsigz]"){

  GIVEN( "valid Nsigz parameters" ){
    std::vector<int> validValues(10);
    std::iota( validValues.begin(), validValues.end(), 0);

    THEN( "the returned class has the correct value" ){
      for( auto nsigz : validValues ){
        iRecordStream<char> issNsigz( 
            std::istringstream( std::to_string( nsigz ) ) );

        REQUIRE( nsigz == argument::extract< GROUPR::Card2::Nsigz >( 
                          issNsigz ).value );
      }
    }
  } // GIVEN
  GIVEN( "no nsigz value" ){
    THEN( "the default value is returned" ){
      iRecordStream<char> iss( std::istringstream( "/") );
      REQUIRE( GROUPR::Card2::Nsigz::defaultValue() == 
                argument::extract< GROUPR::Card2::Nsigz >( iss ).value );
    }
  }
  GIVEN( "invalid Nsigz parameters" ){
    std::vector<int> invalidValues{ -2, -1 };

    THEN( "the returned class has the correct value" ){
      for( auto nsigz : invalidValues ){
        iRecordStream<char> issNsigz( 
            std::istringstream( std::to_string( nsigz ) ) );

        REQUIRE_THROWS( argument::extract< GROUPR::Card2::Nsigz >( issNsigz ) );
      }
    }
  } // GIVEN
} // SCENARIO
