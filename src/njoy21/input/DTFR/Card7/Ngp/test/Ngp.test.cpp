#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "DTFR ngp values",
  "[DTFR],[Card7], [Ngp]"){

  GIVEN( "valid ngp values" ){
    std::vector<int> validValues{0, 1, 2};

    THEN( "the returned class has the correct value" ){
      for( auto& ngp : validValues ){
        iRecordStream<char> iss(
          std::istringstream( std::to_string(ngp) ) );

        REQUIRE( ngp == argument::extract< 
          DTFR::Card7::Ngp >( iss ).value );
      }
    } // THEN
  } // GIVEN

  GIVEN( "invalid ngp values" ){
    std::vector<int> invalidValues{-1, -2};

    THEN( "an exception is thrown" ){
      for( auto& ngp : invalidValues ){
        iRecordStream<char> iss(
          std::istringstream( std::to_string(ngp) ) );

        REQUIRE_THROWS( argument::extract< 
          DTFR::Card7::Ngp >( iss ) );
      }
    } // THEN
  } // GIVEN

  GIVEN( "no input ngp value" ){
    THEN( "default value is used" ){
      iRecordStream<char> iss(
        std::istringstream( " /" ) );
      REQUIRE( 0 == argument::extract< 
        DTFR::Card7::Ngp >( iss ).value );
    } // THEN
  } // GIVEN
} // SCENARIO
