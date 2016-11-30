#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "RECONR card2 tlabel" ){
  GIVEN( "valid tlabels" ){
    THEN( "the tlabel value is correctly read and returned" ){
      std::string value("");
      std::istringstream iss( "'" + value + "'" );
      long lineNumber = 1;
      REQUIRE( value == argument::extract< 
                        RECONR::Card2::Tlabel >( iss, lineNumber ).value );
    }

    THEN( "the tlabel value is correctly read and returned" ){
      std::string value(
          "012345678901234567890123456789012345678901234567890123456789012345");
      std::istringstream iss( "'" + value + "'" );
      long lineNumber = 1;
      REQUIRE( value == argument::extract< 
                        RECONR::Card2::Tlabel >( iss, lineNumber ).value );
    }
  }
  GIVEN( "invalid tlabels" ){
    THEN( "an exception is thrown" ){
      std::string value(
          "0123456789012345678901234567890123456789"
          "012345678901234567890123456");
      std::istringstream iss( "'" + value + "'" );
      long lineNumber = 1;
      REQUIRE_THROWS( argument::extract< 
                     RECONR::Card2::Tlabel >( iss, lineNumber ) );
    }
  }
} // SCENARIO
