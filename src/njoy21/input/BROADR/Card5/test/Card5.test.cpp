#define CATCH_CONFIG_MAIN
 
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "value range" ){
  {
    iRecordStream<char> iss( std::istringstream("  -1") );
    REQUIRE_THROWS( BROADR::Card5 card5( iss ) );
  }{
    iRecordStream<char> iss( std::istringstream("   0") );
    REQUIRE( BROADR::Card5( iss ).mat1.value == 0 );
  }{
    iRecordStream<char> iss( std::istringstream("   1") );
    REQUIRE( BROADR::Card5( iss ).mat1.value == 1 );
  }{
    iRecordStream<char> iss( std::istringstream("   5000") );
    REQUIRE( BROADR::Card5( iss ).mat1.value == 5000 );
  }{
    iRecordStream<char> iss( std::istringstream("   9999") );
    REQUIRE( BROADR::Card5( iss ).mat1.value == 9999 );
  }{
    iRecordStream<char> iss( std::istringstream("   10000") );
    REQUIRE_THROWS( BROADR::Card5 card5( iss ) );
  }{
    iRecordStream<char> iss( std::istringstream("  ") );
    REQUIRE_THROWS( BROADR::Card5 card5( iss ) );
  }
}
