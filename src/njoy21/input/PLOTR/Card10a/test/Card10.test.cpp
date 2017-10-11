#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Validating card10a inputs",
          "[PLOTR], [Card10a]" ){

  GIVEN( "valid PLOTR Card10a inputs" ){
    WHEN( "All values are given" ){
      iRecordStream<char> issCard10a(
            std::istringstream(" 10.0 50.0 2.0 / " ) );
      PLOTR::Card10a card10a(issCard10a);

      THEN( "the members can be tested" ){
        REQUIRE( Approx( 10.0 ) == card10a.xtag.value );
        REQUIRE( Approx( 50.0 ) == card10a.ytag.value );
        REQUIRE( Approx( 2.0 ) == card10a.xpoint.value );
      }
    } //WHEN
    WHEN( "All zeros" ){
      iRecordStream<char> issCard10a( std::istringstream(
                           " 0.0 0.0 0.0 / " ) );
      PLOTR::Card10a card10a(issCard10a);

      THEN( "the members can be tested" ){
        REQUIRE( Approx( 0.0 ) == card10a.xtag.value );
        REQUIRE( Approx( 0.0 ) == card10a.ytag.value );
        REQUIRE( Approx( 0.0 ) == card10a.xpoint.value );
      }
    } //WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "An extra value is given" ){
      iRecordStream<char> issCard10a( std::istringstream(
            "1.0 10.0 1.0 20 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( PLOTR::Card10a(issCard10a) );
      }
    }//WHEN
  }//GIVEN
}//SCENARIO
