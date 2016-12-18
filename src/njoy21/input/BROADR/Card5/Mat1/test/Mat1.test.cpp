#define CATCH_CONFIG_MAIN
 
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "value range" ){
  {
    iRecordStream<char> iss( std::istringstream("  -1") );
    REQUIRE_THROWS( argument::extract< BROADR::Card5::Mat1 >( iss ) );
  }{
    iRecordStream<char> iss( std::istringstream("   0") );
    REQUIRE( argument::extract< BROADR::Card5::Mat1 >( iss ).value == 0 );
  }{
    iRecordStream<char> iss( std::istringstream("   1") );
    REQUIRE( argument::extract< BROADR::Card5::Mat1 >( iss ).value == 1 );
  }{
    iRecordStream<char> iss( std::istringstream("   5000") );
    REQUIRE( argument::extract< BROADR::Card5::Mat1 >( iss ).value == 5000 );
  }{
    iRecordStream<char> iss( std::istringstream("   9999") );
    REQUIRE( argument::extract< BROADR::Card5::Mat1 >( iss ).value == 9999 );
  }{
    iRecordStream<char> iss( std::istringstream("   10000") );
    REQUIRE_THROWS( argument::extract< BROADR::Card5::Mat1 >( iss ) );
  }{
    iRecordStream<char> iss( std::istringstream("   ") );
    REQUIRE_THROWS( argument::extract< BROADR::Card5::Mat1 >( iss ) );
  }
}
