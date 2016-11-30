#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "special values" ){
  {
    std::istringstream iss("   0");
    long lineNumber = 1;
    REQUIRE_THROWS( argument::extract< MODER::Card3::Matd >( iss, lineNumber ) );
  }{
    std::istringstream iss("   125");
    long lineNumber = 1;
    REQUIRE( argument::extract< MODER::Card3::Matd >
	     ( iss, lineNumber ).value == 125 );
  }
  REQUIRE( argument::primitive::HasDefault< MODER::Card3::Matd >::value );
}
