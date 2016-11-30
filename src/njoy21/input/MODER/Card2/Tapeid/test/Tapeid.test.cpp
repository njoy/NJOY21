#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "moder card2 tapeid" ){
  {
    std::string value("");
    std::istringstream iss( "'" + value + "'" );
    long lineNumber = 1;
    REQUIRE( value == argument::extract< MODER::Card2::Tapeid >( iss, lineNumber ).value );
  }{
    std::string value("012345678901234567890123456789012345678901234567890123456789012345");
    std::istringstream iss( "'" + value + "'" );
    long lineNumber = 1;
    REQUIRE( value == argument::extract< MODER::Card2::Tapeid >( iss, lineNumber ).value );
  }{
    std::string value("'0123456789012345678901234567890123456789012345678901234567890123456'");
    std::istringstream iss(value);
    long lineNumber = 1;
    REQUIRE_THROWS( argument::extract< MODER::Card2::Tapeid >( iss, lineNumber ) );
  }
}
