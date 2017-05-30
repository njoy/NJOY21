#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "special values" ){
  {
    iRecordStream<char> iss( std::istringstream("   0") );
    REQUIRE_THROWS( argument::extract< MODER::Card3::Matd >( iss ) );
  }{
      iRecordStream<char> iss( std::istringstream("   125") );
    REQUIRE( argument::extract< MODER::Card3::Matd >( iss ).value == 125 );
  }
  REQUIRE( argument::policy::hasDefault< MODER::Card3::Matd > );
}
