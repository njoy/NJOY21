#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "RECONR card2 tlabel", "[Card2], [Tlabel]"){
  GIVEN( "valid tlabels" ){
    THEN( "the tlabel value is correctly read and returned" ){
      std::string value("");
      iRecordStream<char> iss( std::istringstream( "'" + value + "'" ) );
      REQUIRE( value == argument::extract< RECONR::Card2::Tlabel >(iss).value );
    }

    THEN( "the tlabel value is correctly read and returned" ){
      std::string value(
          "012345678901234567890123456789012345678901234567890123456789012345");
      iRecordStream<char> iss( std::istringstream( "'" + value + "'" ) );
      REQUIRE( value == argument::extract< RECONR::Card2::Tlabel >(iss).value );
    }
  }
  GIVEN( "invalid tlabels" ){
    THEN( "an exception is thrown" ){
      std::string value(
          "0123456789012345678901234567890123456789012345678901234567890123456");
      iRecordStream<char> iss( std::istringstream( "'" + value + "'" ) );
      REQUIRE_THROWS( argument::extract< RECONR::Card2::Tlabel >(iss) );
    }
  }
} // SCENARIO
