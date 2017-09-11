#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "expected successes" ){
  GIVEN( "valid input" ){
    std::vector<int> validValues{20,-20,99,-99,59,-59};

    THEN( "the returned class has the correct tape value" ){
      for( auto nendf : validValues ){
        iRecordStream<char> issNendf(
            std::istringstream( std::to_string(nendf)) );
        REQUIRE(nendf == argument::extract<
                         GROUPR::Card1::Nendf >( issNendf ).value);
      }
    }
  } // GIVEN
}

SCENARIO( "expected failures" ){
  GIVEN( "invalid input" ){
    std::vector<int> invalidValues{19,-19,100,-100,0};

    THEN( "the function throws an exception" ){
      for( auto nendf : invalidValues ){
        iRecordStream<char> issNendf(
            std::istringstream( std::to_string(nendf)) );
        REQUIRE_THROWS(argument::extract<GAMINR::Card1::Nendf>(issNendf));
      }
    }
  } // GIVEN
  {
    iRecordStream<char> iss( std::istringstream(" cat") );
    REQUIRE_THROWS( argument::extract
                         <GAMINR::Card1::Nendf >( iss ) );
  }{
    iRecordStream<char> iss( std::istringstream("    ") );
    REQUIRE_THROWS( argument::extract
                         <GAMINR::Card1::Nendf >( iss ) );
  }
}
