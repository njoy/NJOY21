#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "icolor output values",
  "[COVR], [Card2], [Icolor]"){

  GIVEN( "valid inputs for nin, nout, and npend" ){
    WHEN( "the icolor value is valid" ){
      std::vector<int> validValues{0, 1, 2};
      THEN( "the returned class has the correct tape value" ){
        for( auto& icolor : validValues ){
          iRecordStream<char> iss(
            std::istringstream( std::to_string( icolor ) ) );
          REQUIRE( icolor == argument::extract< 
            COVR::Card2::Icolor >( iss ).value );
        }
      } // THEN
    } // WHEN

    WHEN( "no icolor value given " ){
      THEN( "default value is substituted in" ){
        iRecordStream<char> iss( std::istringstream( "  /" ) );
        REQUIRE( 0 == argument::extract<
          COVR::Card2::Icolor > ( iss ).value );
      } // THEN
    } // WHEN
  
    WHEN( "icolor tapes are out of range" ){
      std::vector<int> invalidValues{-1, 3, 4};
      THEN( "an exception is thrown" ){
        for( auto& icolor : invalidValues ){
          iRecordStream<char> iss(
            std::istringstream( std::to_string( icolor ) ) );
          REQUIRE_THROWS( argument::extract<
            COVR::Card2::Icolor>( iss ) );
        }
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO

