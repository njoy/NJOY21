#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "icolor output values",
  "[COVR], [Card2], [Icolor]"){

  GIVEN( "valid inputs for nin, nout, and npend" ){
    WHEN( "the icolor value is valid" ){
      THEN( "the returned class has the correct tape value" ){
        for( auto& icolor : {0, 1, 2} ){
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
      THEN( "an exception is thrown" ){
        for( auto& icolor : {-1, 3, 4} ){
          iRecordStream<char> iss(
            std::istringstream( std::to_string( icolor ) ) );
          REQUIRE_THROWS( argument::extract<
            COVR::Card2::Icolor>( iss ) );
        }
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO

