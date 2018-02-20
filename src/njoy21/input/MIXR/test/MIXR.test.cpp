#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "MIXR",
          "[MIXR]" ){
  GIVEN( "valid inputs" ){
    WHEN( "example input from MIXR chapter of manual is provided" ){
      std::string inp(
 " 20 -22 -23 -24 -25 /\n"
 " 1 301 444 /\n"
 " 2625 0.0590 /\n"
 " 2631 0.9172 /\n"
 " 2634 0.0210 /\n"
 " 2637 0.0028 /\n"
 " 300 /\n"
 " 2600 26000 56. /\n"
 " 'Fe-nat for ENDF/B-VI from MIXR' /"
      );

      iRecordStream<char> iss{ std::istringstream{ inp } };

      THEN( "the values can be verified" ){
        MIXR mixr( iss );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "more materials than inputs are provided" ){
      std::string inp(
 " 20 -22 -23 -24 -25 /\n"
 " 1 301 444 /\n"
 " 2625 0.0590 /\n"
 " 2631 0.9172 /\n"
 " 2634 0.0210 /\n"
 " 2637 0.0018 /\n"
 " 2633 0.0010 /\n"
 " 300 /\n"
 " 2600 26000 56. /\n"
 " 'Fe-nat for ENDF/B-VI from MIXR' /"
      );

      iRecordStream<char> iss{ std::istringstream{ inp } };

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( MIXR( iss ) );
      }
    } // WHEN

    WHEN( "more inputs than materials are provided" ){
      std::string inp(
 " 20 -22 -23 -24 -25 -26 /\n"
 " 1 301 444 /\n"
 " 2625 0.0590 /\n"
 " 2631 0.9172 /\n"
 " 2634 0.0210 /\n"
 " 2637 0.0028 /\n"
 " 300 /\n"
 " 2600 26000 56. /\n"
 " 'Fe-nat for ENDF/B-VI from MIXR' /"
      );

      iRecordStream<char> iss{ std::istringstream{ inp } };

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( MIXR( iss ) );
      }
    } // WHEN

    WHEN( "no description card is provided" ){
      std::string inp(
 " 20 -22 -23 -24 -25 /\n"
 " 1 301 444 /\n"
 " 2625 0.0590 /\n"
 " 2631 0.9172 /\n"
 " 2634 0.0210 /\n"
 " 2637 0.0028 /\n"
 " 300 /\n"
 " 2600 26000 56. /"
      );

      iRecordStream<char> iss{ std::istringstream{ inp } };

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( MIXR( iss ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
