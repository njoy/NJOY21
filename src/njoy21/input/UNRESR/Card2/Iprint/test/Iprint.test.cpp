#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Iprint input values",
          "[Card2], [Iprint]" ){
  long ln(0);
  GIVEN( "valid iprint values" ){
    std::vector<int> validValues{0, 1, 2};

    THEN( "the returned class has the correct value" ){
      for( auto& iprint : validValues ){
        iRecordStream< char > iss(std::istringstream(  std::to_string(iprint)  ));

        REQUIRE( 
          iprint == argument::extract< UNRESR::Card2::Iprint >( iss ).value );
      }
    }
  }
  GIVEN( "no iprint values" ){
    THEN( "the default value is returned" ){
      iRecordStream< char > iss(std::istringstream( " /" ));
      REQUIRE( 0 == argument::extract< UNRESR::Card2::Iprint >( iss ).value );
    }
  }
  
  GIVEN( "invalid iprint values" ){
    std::vector<int> invalidValues{-1};

    THEN( "an exception is thrown" ){
      for( auto& iprint : invalidValues ){
        iRecordStream< char > iss(std::istringstream(  std::to_string(iprint)  ));

        REQUIRE_THROWS( argument::extract< UNRESR::Card2::Iprint >( iss ) );
      }
    }
  }
} // SCENARIO

