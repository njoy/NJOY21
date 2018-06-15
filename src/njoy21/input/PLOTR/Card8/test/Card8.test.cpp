#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Validating card8 inputs",
          "[PLOTR], [Card8]" ){

  Argument< PLOTR::Card4::Jtype > jtype; jtype.value = 0;
  GIVEN( "valid PLOTR Card8 inputs" ){
    WHEN( "Iverf is 0"){
      iRecordStream<char> issCard8(
            std::istringstream(" 0 19 -1 -1 -1 -100.0 -10 / " ) );
      THEN( "none of the other values matter" ){
        PLOTR::Card8 card8(issCard8, jtype.value);
        REQUIRE( 0 == card8.iverf.value );
      }
    }
    WHEN( "All values are given" ){
      iRecordStream<char> issCard8(
            std::istringstream(" 2 20 9235 6 17 150.0 20 2 2 / " ) );
      PLOTR::Card8 card8(issCard8, jtype.value);

      THEN( "the members can be tested" ){
        REQUIRE( 2 == card8.iverf.value );
        REQUIRE( 20 == card8.nin.value );
        REQUIRE( 9235 == card8.matd.value );
        REQUIRE( 6 == card8.mfd.value );
        REQUIRE( 17 == card8.mtd.value );
        REQUIRE( 150.0 * dimwits::kelvin == card8.temper.value );
        REQUIRE( 20 == card8.nth.value );
        REQUIRE( 2 == card8.ntpnkh->first.value );
        REQUIRE( 2 == card8.ntpnkh->second.value );
      }
    } //WHEN
    WHEN( "The available defaults are used (temper, nth, ntp, and nkh)" ){
      iRecordStream<char> issCard8( 
            std::istringstream(" 4 44 1 7 20 / " ) );
      PLOTR::Card8 card8(issCard8, jtype.value);

      THEN( "the members can be tested" ){
        REQUIRE( 4 == card8.iverf.value );
        REQUIRE( 44 == card8.nin.value );
        REQUIRE( 1 == card8.matd.value );
        REQUIRE( 7 == card8.mfd.value );
        REQUIRE( 20 == card8.mtd.value );
        REQUIRE( 0.0 * dimwits::kelvin == card8.temper.value );
        REQUIRE( 1 == card8.nth.value );
        REQUIRE( 1 == card8.ntpnkh->first.value );
        REQUIRE( 1 == card8.ntpnkh->second.value );
      }
    } //WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "All values are wrong" ){
      iRecordStream<char> issCard8( std::istringstream(
             "-1 3 -10 11 221 -20.0 10 10 10 /" ) );
  
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( PLOTR::Card8(issCard8, jtype.value) );
      }
    }//WHEN
    WHEN( "One value is wrong" ){
      {
        iRecordStream<char> issCard8( std::istringstream(
              "3 19 9235 3 10 10.0 /" ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( PLOTR::Card8(issCard8, jtype.value) );
        }
      }{
        iRecordStream<char> issCard8( std::istringstream(
              "4 22 -9 3 10 10.0 /" ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( PLOTR::Card8(issCard8, jtype.value) );
        }
      }
    }//WHEN
    WHEN( "An extra value is given" ){
      iRecordStream<char> issCard8( std::istringstream(
            std::istringstream(" 2 20 9235 15 6 150.0 20 2 2 1 / " ) ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( PLOTR::Card8(issCard8, jtype.value) );
      }
    }//WHEN
  }//GIVEN
}//SCENARIO
