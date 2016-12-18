#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "RECONR Card5 cards", "[Card5], [Cards]"){
  GIVEN( "valid cards" ){
    THEN( "the cards value is correctly read and returned" ){
      std::string value("");
      iRecordStream<char> iss( std::istringstream( "'" + value + "'" ) );
      REQUIRE( value == argument::extract< RECONR::Card5::Cards >( iss ).value );
    }

    THEN( "the Cards value is correctly read and returned" ){
      std::string value(
          "012345678901234567890123456789012345678901234567890123456789012345");
      iRecordStream<char> iss( std::istringstream( "'" + value + "'" ) );
      REQUIRE( value == argument::extract< RECONR::Card5::Cards >( iss ).value );
    }
  }
  GIVEN( "invalid cards" ){
    THEN( "an exception is thrown" ){
      std::string value(
          "0123456789012345678901234567890123456789"
          "012345678901234567890123456");
      iRecordStream<char> iss( std::istringstream( "'" + value + "'" ) );
      REQUIRE_THROWS( argument::extract< RECONR::Card5::Cards >( iss ) );
    }
  }
}
