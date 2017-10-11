#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Validating card7 inputs",
          "[PLOTR], [Card7]" ){

  Argument< PLOTR::Card4::Jtype > jtype; jtype.value = 1;

  GIVEN( "valid PLOTR Card7 inputs" ){
    WHEN( "All values are given" ){
      iRecordStream<char> issCard7(
            std::istringstream(" 10.0 50.0 2 / " ) );
      PLOTR::Card7 card7(issCard7, jtype );

      THEN( "the members can be tested" ){
        REQUIRE( Approx( 10.0 ) == card7.rbot.value );
        REQUIRE( Approx( 50.0 ) == card7.rtop.value );
        REQUIRE( Approx( 2.0 ) == card7.rstep.value );
      }
    } //WHEN
    WHEN( "A couple defaults are used" ){
      iRecordStream<char> issCard7( std::istringstream(" 500.0 400000.0 / " ) );
      PLOTR::Card7 card7(issCard7, jtype );

      THEN( "the members can be tested" ){
        REQUIRE( Approx( 500.0 ) == card7.rbot.value );
        REQUIRE( Approx( 400000.0 ) == card7.rtop.value );
        REQUIRE( Approx( 1.0 ) == card7.rstep.value );
      }
    } //WHEN
    WHEN( "No values are given" ){
      iRecordStream<char> issCard7( std::istringstream(" / "));
      PLOTR::Card7 card7(issCard7, jtype );

      THEN( "the members can be tested" ){
        REQUIRE( Approx( 0.0 ) == card7.rbot.value );
        REQUIRE( Approx( 0.0 ) == card7.rtop.value );
        REQUIRE( Approx( 1.0 ) == card7.rstep.value );
      }
    } //WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "One value is wrong" ){
      {
        iRecordStream<char> issCard7( std::istringstream(
              "1.0 -1.0 0.5/" ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( PLOTR::Card7(issCard7, jtype ) );
        }
      }{
        iRecordStream<char> issCard7( std::istringstream(
              "1.0 4.0 -0.6/" ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( PLOTR::Card7(issCard7, jtype ) );
        }
      }
    }//WHEN
    WHEN( "An extra value is given" ){
      iRecordStream<char> issCard7( std::istringstream(
            "1.0 10.0 1.0 20 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( PLOTR::Card7(issCard7, jtype ) );
      }
    }//WHEN
  }//GIVEN
}//SCENARIO
