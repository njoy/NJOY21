#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Validating card13 inputs",
          "[PLOTR], [Card13]" ){

  GIVEN( "valid PLOTR Card13 inputs" ){
    WHEN( "All values are given" ){
      iRecordStream<char> issCard13(
            std::istringstream("10.0 20.0 19.9 20.1 9.9 10.1 / " ) );
      PLOTR::Card13 card13(issCard13);

      THEN( "the members can be tested" ){
        REQUIRE( Approx( 10.0 ) == *( card13.xdata.value ) );
        REQUIRE( Approx( 20.0 ) == *( card13.ydata.value ) );
        REQUIRE( Approx( 19.9 ) == *( card13.yerr1.value ) );
        REQUIRE( Approx( 20.1 ) == *( card13.yerr2.value ) );
        REQUIRE( Approx(  9.9 ) == *( card13.xerr1.value ) );
        REQUIRE( Approx( 10.1 ) == *( card13.xerr2.value ) );
      }
    } //WHEN
    WHEN( "All zeros" ){
      iRecordStream<char> issCard13( std::istringstream(
                           " 0.0 0.0 0.0 0.0 0.0 0.0 / " ) );
      PLOTR::Card13 card13(issCard13);

      THEN( "the members can be tested" ){
        REQUIRE( Approx( 0.0 ) == *( card13.xdata.value ) );
        REQUIRE( Approx( 0.0 ) == *( card13.ydata.value ) );
        REQUIRE( Approx( 0.0 ) == *( card13.yerr1.value ) );
        REQUIRE( Approx( 0.0 ) == *( card13.yerr2.value ) );
        REQUIRE( Approx( 0.0 ) == *( card13.xerr1.value ) );
        REQUIRE( Approx( 0.0 ) == *( card13.xerr2.value ) );
      }
    } //WHEN
    WHEN( "No values" ){
      iRecordStream<char> issCard13( std::istringstream( " /" ) );
      PLOTR::Card13 card13(issCard13);

      THEN( "all values are nullopt" ){
        REQUIRE( std::nullopt == card13.xdata.value );
        REQUIRE( std::nullopt == card13.ydata.value );
        REQUIRE( std::nullopt == card13.yerr1.value );
        REQUIRE( std::nullopt == card13.yerr2.value );
        REQUIRE( std::nullopt == card13.xerr1.value );
        REQUIRE( std::nullopt == card13.xerr2.value );
      }
    }
    WHEN( "The second yerr value is left blank" ){
      iRecordStream<char> issCard13( std::istringstream(
                          " 22.0 35.0 32.0 0.0 20.0 0.0 /" ) );
      THEN( "The value is set as equal to the first yerr value" ){
        PLOTR::Card13 card13(issCard13);
        REQUIRE( Approx( 32.0 ) == *( card13.yerr2.value ) );
        REQUIRE( Approx( 20.0 ) == *( card13.xerr2.value ) );
      }
    }
  } // GIVEN

  GIVEN( "Invalid parameters" ){
    WHEN( "An error bar is less than 0.0" ){
      iRecordStream<char> issCard13( std::istringstream(
                          " 2.0 4.0 3.9 3.8 -1.0 3.0 /" ) );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( PLOTR::Card13( issCard13 ) );
      }
    }
  } // GIVEN
}//SCENARIO
