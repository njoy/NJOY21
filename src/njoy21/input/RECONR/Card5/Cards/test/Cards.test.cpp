#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "RECONR Card5 cards",
         "[Card5], [Cards]"){
  GIVEN( "valid cards" ){
    THEN( "the cards value is correctly read and returned" ){
      std::string value("");
      std::istringstream iss( "'" + value + "'" );
      long lineNumber = 1;
      REQUIRE( value == argument::extract< 
                        RECONR::Card5::Cards >( iss, lineNumber ).value );
    }

    THEN( "the Cards value is correctly read and returned" ){
      std::string value(
          "012345678901234567890123456789012345678901234567890123456789012345");
      std::istringstream iss( "'" + value + "'" );
      long lineNumber = 1;
      REQUIRE( value == argument::extract< 
                        RECONR::Card5::Cards >( iss, lineNumber ).value );
    }
  }
  GIVEN( "invalid cards" ){
    THEN( "an exception is thrown" ){
      std::string value(
          "0123456789012345678901234567890123456789"
          "012345678901234567890123456");
      std::istringstream iss( "'" + value + "'" );
      long lineNumber = 1;
      REQUIRE_THROWS( argument::extract< 
                     RECONR::Card5::Cards >( iss, lineNumber ) );
    }
  }
}
