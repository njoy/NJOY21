#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "moder card2 tapeid" ){
  {
    std::string value("");
    iRecordStream<char> iss( std::istringstream( "'" + value + "'" ) );
    REQUIRE( value == argument::extract< MODER::Card2::Tapeid >( iss ).value );
  }{
    std::string value("012345678901234567890123456789012345678901234567890123456789012345");
    iRecordStream<char> iss( std::istringstream( "'" + value + "'" ) );
    REQUIRE( value == argument::extract< MODER::Card2::Tapeid >( iss ).value );
  }{
    std::string value("'0123456789012345678901234567890123456789012345678901234567890123456'");
    iRecordStream<char> iss( ( std::istringstream( value ) ) );
    REQUIRE_THROWS( argument::extract< MODER::Card2::Tapeid >( iss ) );
  }
}
