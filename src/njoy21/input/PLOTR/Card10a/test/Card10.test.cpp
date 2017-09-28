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
        REQUIRE( 10.0f == card10a.xtag.value );
        REQUIRE( 50.0f == card10a.ytag.value );
        REQUIRE( 2.0f == card10a.xpoint.value );
      }
    } //WHEN
    WHEN( "All zeros" ){
      iRecordStream<char> issCard10a( std::istringstream(
                           " 0.0 0.0 0.0 / " ) );
      PLOTR::Card10a card10a(issCard10a);

      THEN( "the members can be tested" ){
        REQUIRE( 0.0f == card10a.xtag.value );
        REQUIRE( 0.0f == card10a.ytag.value );
        REQUIRE( 0.0f == card10a.xpoint.value );
      }
    } //WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "All values are wrong" ){
      iRecordStream<char> issCard10a( std::istringstream(
             "-1.0 -1.0 /" ) );
  
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( PLOTR::Card10a(issCard10a) );
      }
    }//WHEN
    WHEN( "One value is wrong" ){
      {
        iRecordStream<char> issCard10a( std::istringstream(
              "1.0 -1.0 0.5/" ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( PLOTR::Card10a(issCard10a) );
        }
      }
    }//WHEN
    WHEN( "An extra value is given" ){
      iRecordStream<char> issCard10a( std::istringstream(
            "1.0 10.0 1.0 20 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( PLOTR::Card10a(issCard10a) );
      }
    }//WHEN
  }//GIVEN
}//SCENARIO
