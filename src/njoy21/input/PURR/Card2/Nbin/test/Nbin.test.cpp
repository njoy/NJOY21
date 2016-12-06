#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Nbin input values",
          "[Card2], [Nbin]" ){
  long ln(0);

  GIVEN( "valid nbin values" ){
    std::vector<int> validValues{15, 16, 20, 25};

    THEN( "the returned class has the correct value" ){
      for( auto& nbin : validValues ){
        std::istringstream iss( std::to_string(nbin) );

        REQUIRE( 
          nbin == argument::extract< PURR::Card2::Nbin >( iss, ln ).value );
      }
    }
  }

  GIVEN( "no nbin values" ){
    THEN( "the default value is returned" ){
      std::istringstream iss("");
      REQUIRE( PURR::Card2::Nbin::defaultValue() == 
                argument::extract< PURR::Card2::Nbin >( iss, ln ).value );
    }
  }
  
  GIVEN( "invalid nbin values" ){
    std::vector<int> invalidValues{0, -1, 14};

    THEN( "an exception is thrown" ){
      for( auto& nbin : invalidValues ){
        std::istringstream iss( std::to_string(nbin) );

        REQUIRE_THROWS( argument::extract< PURR::Card2::Nbin >( iss, ln ) );
      }
    }
  }
} // SCENARIO
