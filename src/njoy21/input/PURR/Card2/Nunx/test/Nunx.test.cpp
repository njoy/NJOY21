#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Nunx input values",
          "[Card2], [Nunx]" ){
  long ln(0);
  GIVEN( "valid nunx values" ){
    std::vector<int> validValues{0, 1, 2, 100};

    THEN( "the returned class has the correct value" ){
      for( auto& nunx : validValues ){
        std::istringstream iss( std::to_string(nunx) );

        REQUIRE( 
          nunx == argument::extract< PURR::Card2::Nunx >( iss, ln ).value );
      }
    }
  }
  GIVEN( "no nunx values" ){
    THEN( "the default value is returned" ){
      std::istringstream iss("");
      REQUIRE( PURR::Card2::Nunx::defaultValue() == 
                argument::extract< PURR::Card2::Nunx >( iss, ln ).value );
    }
  }
  
  GIVEN( "invalid nunx values" ){
    std::vector<int> invalidValues{-1};

    THEN( "an exception is thrown" ){
      for( auto& nunx : invalidValues ){
        std::istringstream iss( std::to_string(nunx) );

        REQUIRE_THROWS( argument::extract< PURR::Card2::Nunx >( iss, ln ) );
      }
    }
  }
} // SCENARIO

