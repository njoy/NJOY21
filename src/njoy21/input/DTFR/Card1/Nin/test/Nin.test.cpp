#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "nin input values" ){
  GIVEN( "valid nin tape values" ){
    std::vector<int> validValues{-20, 20, 42, 99, -99};

    THEN( "the returned class has the correct tape value" ){
      for( auto nin : validValues ){
        iRecordStream<char> iss(
            std::istringstream( std::to_string(nin)) );
        REQUIRE(nin == argument::extract< 
                         DTFR::Card1::Nin >( iss ).value );
      }
    } // THEN
  } // GIVEN

  GIVEN( "invalid nin tape values" ){
    std::vector<int> invalidValues{-19, 19, 100, -100};
    THEN( "an exception is thrown" ){

      for( auto nin : invalidValues ){
        iRecordStream<char> iss(
            std::istringstream( std::to_string(nin)) );
        REQUIRE_THROWS(argument::extract<DTFR::Card1::Nin>(iss));
      }
    } // THEN
  } // GIVEN
} // SCENARIO

