#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Validating card0 inputs",
          "[PLOTR], [Card0]" ){

  GIVEN( "valid PLOTR Card0 inputs" ){
    WHEN( "All values are given" ){
      {
        iRecordStream<char> issCard0( std::istringstream("20 21 / " ) );
        PLOTR::Card0 card0(issCard0);

        THEN( "the members can be tested" ){
          REQUIRE( 20 == card0.nplt.value );
          REQUIRE( 21 == card0.nplt0.value );
        }
      }{
        iRecordStream<char> issCard0( std::istringstream("20 / " ) );
        PLOTR::Card0 card0(issCard0);

        THEN( "the members can be tested" ){
          REQUIRE( 20 == card0.nplt.value );
          REQUIRE( 0 == card0.nplt0.value );
        }
      }
    } //WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "Duplicate values for Nplt and Nplt0" ){
      iRecordStream<char> issCard0( std::istringstream("20 20 /" ) );
  
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( PLOTR::Card0(issCard0) );
      }
    }
  }
}
