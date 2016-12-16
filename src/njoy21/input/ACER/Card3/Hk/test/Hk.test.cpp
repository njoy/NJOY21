#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "ACER card3 hk",
         "[Card3], [Hk]"){
  GIVEN( "valid hks" ){
    THEN( "the hk value is correctly read and returned" ){
      std::string value("");
      iRecordStream<char> iss(
          std::istringstream( "'" + value + "'" ) );
      REQUIRE( value == argument::extract< 
                        ACER::Card3::Hk >( iss ).value );
    }

    THEN( "the hk value is correctly read and returned" ){
      std::string value(
          "123456789012345678901234567890123456789012345678901234567890123456");
      iRecordStream<char> iss(
          std::istringstream( "'" + value + "'" ) );
      REQUIRE( value == argument::extract< 
                        ACER::Card3::Hk >( iss ).value );
    }
  }
  GIVEN( "invalid hks" ){
    THEN( "an exception is thrown" ){
      std::string value(
          "1234567890123456789012345678901234567890"
          "1234567890123456789012345678901");
      iRecordStream<char> iss(
          std::istringstream( "'" + value + "'" ) );
      REQUIRE_THROWS( argument::extract< 
                     ACER::Card3::Hk >( iss ) );
    }
  }
} // SCENARIO

