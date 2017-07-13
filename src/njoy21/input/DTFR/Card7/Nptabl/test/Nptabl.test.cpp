#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "DTFR nptabl values",
  "[DTFR],[Card7], [Nptabl]"){

  GIVEN( "valid nptabl values" ){
    std::vector<int> validValues{0, 1, 2};

    THEN( "the returned class has the correct value" ){
      for( auto& nptabl : validValues ){
        iRecordStream<char> iss(
          std::istringstream( std::to_string(nptabl) ) );

        REQUIRE( nptabl == argument::extract< 
          DTFR::Card7::Nptabl >( iss ).value );
      }
    } // THEN
  } // GIVEN

  GIVEN( "invalid nptabl values" ){
    std::vector<int> invalidValues{-1, -2};

    THEN( "an exception is thrown" ){
      for( auto& nptabl : invalidValues ){
        iRecordStream<char> iss(
          std::istringstream( std::to_string(nptabl) ) );

        REQUIRE_THROWS( argument::extract< 
          DTFR::Card7::Nptabl >( iss ) );
      }
    } // THEN
  } // GIVEN
 
  GIVEN( "no input nptabl value" ){
    THEN( "default value is used" ){
      iRecordStream<char> iss(
        std::istringstream( " /" ) );
      REQUIRE( 0 == argument::extract< 
        DTFR::Card7::Nptabl >( iss ).value );
    } // THEN
  } // GIVEN
} // SCENARIO
