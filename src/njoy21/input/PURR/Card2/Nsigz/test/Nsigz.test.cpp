#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Nsigz input values",
          "[Card2], [Nsigz]" ){
  long ln(0);

  GIVEN( "no nsigz values" ){
    THEN( "the default value is returned" ){
      std::istringstream iss("");
      REQUIRE( PURR::Card2::Nsigz::defaultValue() == 
                argument::extract< PURR::Card2::Nsigz >( iss, ln ).value );
    }
  }

  GIVEN( "valid nsigz values" ){
    std::vector<int> validValues{1,2,4,8,16};

    THEN( "the returned class has the correct value" ){
      for( auto& nsigz : validValues ){
        std::istringstream iss( std::to_string(nsigz) );

        REQUIRE( 
          nsigz == argument::extract< PURR::Card2::Nsigz >( iss, ln ).value );
      }
    }
  }
  GIVEN( "invalid nsigz values" ){
    std::vector<int> invalidValues{0, -1};

    THEN( "an exception is thrown" ){
      for( auto& nsigz : invalidValues ){
        std::istringstream iss( std::to_string(nsigz) );

        REQUIRE_THROWS( argument::extract< PURR::Card2::Nsigz >( iss, ln ) );
      }
    }
  }
} // SCENARIO
