#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Nladr input values",
          "[Card2], [Nladr]" ){
  long ln(0);

  GIVEN( "valid nladr values" ){
    std::vector<int> validValues{15, 16, 20, 25, 100};

    THEN( "the returned class has the correct value" ){
      for( auto& nladr : validValues ){
        std::istringstream iss( std::to_string(nladr) );

        REQUIRE( 
          nladr == argument::extract< PURR::Card2::Nladr >( iss, ln ).value );
      }
    }
  }

  GIVEN( "no nladr values" ){
    THEN( "the default value is returned" ){
      std::istringstream iss("");
      REQUIRE( PURR::Card2::Nladr::defaultValue() == 
                argument::extract< PURR::Card2::Nladr >( iss, ln ).value );
    }
  }
  
  GIVEN( "invalid nladr values" ){
    std::vector<int> invalidValues{0, -1};

    THEN( "an exception is thrown" ){
      for( auto& nladr : invalidValues ){
        std::istringstream iss( std::to_string(nladr) );

        REQUIRE_THROWS( argument::extract< PURR::Card2::Nladr >( iss, ln ) );
      }
    }
  }
} // SCENARIO

