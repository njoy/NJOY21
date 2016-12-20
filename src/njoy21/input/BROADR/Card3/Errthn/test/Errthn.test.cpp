#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "value range" ){
  {
    iRecordStream<char> iss( std::istringstream("   -1.0") );
    REQUIRE_THROWS( argument::extract< BROADR::Card3::Errthn >( iss ) );
  }{
    iRecordStream<char> iss( std::istringstream("   0.0") );
    REQUIRE_THROWS( argument::extract< BROADR::Card3::Errthn >( iss ) );
  }{
    iRecordStream<char> iss( std::istringstream("   1.0") );
    REQUIRE( argument::extract< BROADR::Card3::Errthn >( iss ).value == 1.0 );
  }{
    iRecordStream<char> iss( std::istringstream("   ") );
    REQUIRE_THROWS( argument::extract< BROADR::Card3::Errthn >( iss ) );
  }
}
