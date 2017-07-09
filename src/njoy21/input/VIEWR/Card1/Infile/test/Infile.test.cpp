#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "infile input values" ){
  GIVEN( "valid infile tape values" ){
    std::vector<int> validValues{20, 42, 99};

    THEN( "the returned class has the correct tape value" ){
      for( int infile : validValues ){
        iRecordStream<char> iss( std::istringstream( std::to_string(infile)) );
        REQUIRE( infile == argument::extract < VIEWR::Card1::Infile > ( iss ).value );
      }
    }
  } // GIVEN

  GIVEN( "invalid infile tape values" ){
    std::vector<int> invalidValues{-19, 19, 100, -100};
    THEN( "an exception is thrown" ){

      for( int infile : invalidValues ){
        iRecordStream<char> iss( std::istringstream( std::to_string(infile)) );
        REQUIRE_THROWS( argument::extract < VIEWR::Card1::Infile > ( iss ) );
      }
    }
  } // GIVEN
} // SCENARIO

