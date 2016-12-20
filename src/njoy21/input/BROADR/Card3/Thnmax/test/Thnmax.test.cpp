#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "value range" ){
  {
    iRecordStream<char> iss( std::istringstream("   -1.0") );
    REQUIRE( argument::extract< BROADR::Card3::Thnmax >( iss ).value
	     == -1.0 * dimwits::electronVolt );
  }{
    iRecordStream<char> iss( std::istringstream("   0.0") );
    REQUIRE( argument::extract< BROADR::Card3::Thnmax >( iss ).value
	     == 0.0 * dimwits::electronVolt );
  }{
    iRecordStream<char> iss( std::istringstream("   1.0") );
    REQUIRE( argument::extract< BROADR::Card3::Thnmax >( iss ).value
	     == 1.0 * dimwits::electronVolt );
  }{
    iRecordStream<char> iss( std::istringstream(" / ") );
    REQUIRE( argument::extract< BROADR::Card3::Thnmax >( iss ).value
	     == 1.0 * dimwits::mega( dimwits::electronVolt ) );
  }
}
