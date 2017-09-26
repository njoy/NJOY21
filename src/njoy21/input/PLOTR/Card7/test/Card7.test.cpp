#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Validating card7 inputs",
          "[PLOTR], [Card7]" ){

  GIVEN( "valid PLOTR Card7 inputs" ){
    WHEN( "All values are given" ){
      iRecordStream<char> issCard7(
            std::istringstream(" 10.0 50.0 2 / " ) );
      PLOTR::Card7 card7(issCard7);

      THEN( "the members can be tested" ){
        REQUIRE( 10.0f == card7.rbot.value );
        REQUIRE( 50.0f == card7.rtop.value );
        REQUIRE( 2.0f == card7.rstep.value );
      }
    } //WHEN
    WHEN( "A couple defaults are used" ){
      iRecordStream<char> issCard7( std::istringstream(" 500.0 400000.0 / " ) );
      PLOTR::Card7 card7(issCard7);

      THEN( "the members can be tested" ){
        REQUIRE( 500.0f == card7.rbot.value );
        REQUIRE( 400000.0f == card7.rtop.value );
        REQUIRE( 1.0f == card7.rstep.value );
      }
    } //WHEN
    WHEN( "No values are given" ){
      iRecordStream<char> issCard7( std::istringstream(" / "));
      PLOTR::Card7 card7(issCard7);

      THEN( "the members can be tested" ){
        REQUIRE( 0.0f == card7.rbot.value );
        REQUIRE( 1.0f == card7.rtop.value );
        REQUIRE( 1.0f == card7.rstep.value );
      }
    } //WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "All values are wrong" ){
      iRecordStream<char> issCard7( std::istringstream(
             "-1.0 1.0 0.5/" ) );
  
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( PLOTR::Card7(issCard7) );
      }
    }//WHEN
    WHEN( "One value is wrong" ){
      {
        iRecordStream<char> issCard7( std::istringstream(
              "1.0 -1.0 0.5/" ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( PLOTR::Card7(issCard7) );
        }
      }{
        iRecordStream<char> issCard7( std::istringstream(
              "1.0 4.0 -0.6/" ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( PLOTR::Card7(issCard7) );
        }
      }
    }//WHEN
    WHEN( "An extra value is given" ){
      iRecordStream<char> issCard7( std::istringstream(
            "1.0 10.0 1.0 20 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( PLOTR::Card7(issCard7) );
      }
    }//WHEN
  }//GIVEN
}//SCENARIO
