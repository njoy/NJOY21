#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "expected successes" ){
  GIVEN( "valid input" ){
    std::vector<int> validValues{20,-20,99,-99,59,-59};

    THEN( "the returned class has the correct tape value" ){
      for( auto nplt: validValues ){
        iRecordStream<char> issNplt(
            std::istringstream( std::to_string(nplt)) );
        REQUIRE(nplt == argument::extract<
                         PLOTR::Card0::Nplt>( issNplt ).value);
      }
    }
  } // GIVEN
}

SCENARIO( "expected failures" ){
  GIVEN( "invalid input" ){
    std::vector<int> invalidValues{19,-19,100,-100,0};

    THEN( "the function throws an exception" ){
      for( auto nplt : invalidValues ){
        iRecordStream<char> issNplt(
            std::istringstream( std::to_string(nplt)) );
        REQUIRE_THROWS(argument::extract<PLOTR::Card0::Nplt>(issNplt));
      }
    }
  } // GIVEN
  {
    iRecordStream<char> iss( std::istringstream(" cat") );
    REQUIRE_THROWS( argument::extract
                         <PLOTR::Card0::Nplt>( iss ) );
  }{
    iRecordStream<char> iss( std::istringstream("    ") );
    REQUIRE_THROWS( argument::extract
                         <PLOTR::Card0::Nplt>( iss ) );
  }
}
