#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "value range" ){
  Argument< BROADR::Card3::Errthn > errthn; errthn.value = 1.0;
  {
    iRecordStream<char> iss( std::istringstream("   -1.0") );
    REQUIRE_THROWS( argument::extract< BROADR::Card3::Errint >( iss, errthn ) );
  }{
    iRecordStream<char> iss( std::istringstream("   0.0") );
    REQUIRE_THROWS( argument::extract< BROADR::Card3::Errint >( iss, errthn ) );
  }{
    iRecordStream<char> iss( std::istringstream("   1.0") );
    REQUIRE( argument::extract< BROADR::Card3::Errint >( iss, errthn ).value
	     == 1.0 * dimwits::barns );
  }{
    iRecordStream<char> iss( std::istringstream(" /  ") );
    REQUIRE( argument::extract< BROADR::Card3::Errint >( iss, errthn ).value
	     == 1.0 * dimwits::barn * ( errthn.value / 2.0E4 ) );
  }
}
