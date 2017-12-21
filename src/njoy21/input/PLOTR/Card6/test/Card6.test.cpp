#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Validating card6 inputs",
          "[PLOTR], [Card6]" ){
  Argument< PLOTR::Card4::Itype > itype; itype.value = 1;
  const int ileg = 1;

  GIVEN( "valid PLOTR Card6 inputs" ){
    WHEN( "All values are given" ){
      Argument< PLOTR::Card4::Ytag > ytag;
      iRecordStream<char> issCard6(
            std::istringstream(" 10.0 50.0 2.0 / " ) );
      PLOTR::Card6 card6( issCard6, itype, ytag, ileg );

      THEN( "the members can be tested" ){
        REQUIRE( Approx( 10.0 ) == *( card6.yl.value ) );
        REQUIRE( Approx( 50.0 ) == *( card6.yh.value ) );
        REQUIRE( Approx( 2.0 ) == *( card6.ystep.value ) );
        REQUIRE( Approx( 50.0 ) == *( ytag.value ) );
      }
    } //WHEN
    WHEN( "No values are given" ){
      Argument< PLOTR::Card4::Ytag > ytag; ytag.value = 80.0;
      iRecordStream<char> issCard6( std::istringstream(" / "));
      PLOTR::Card6 card6( issCard6, itype, ytag, ileg );

      THEN( "the members can be tested" ){
        REQUIRE( std::nullopt == card6.yl.value );
        REQUIRE( std::nullopt == card6.yh.value );
        REQUIRE( std::nullopt == card6.ystep.value );
        REQUIRE( Approx( 80.0 ) == *( ytag.value ) );
      }
    } //WHEN

    WHEN( "ytag already has a value" ){
      Argument< PLOTR::Card4::Ytag > ytag; ytag.value = 8.0;
      iRecordStream<char> issCard6( std::istringstream(" 10.0 50.0 2.0 /" ) );
      PLOTR::Card6 card6( issCard6, itype, ytag, ileg );

      THEN( "the ytag value is unchanged and the rest are set" ){
        REQUIRE( Approx( 10.0 ) == *( card6.yl.value ) );
        REQUIRE( Approx( 50.0 ) == *( card6.yh.value ) );
        REQUIRE( Approx( 2.0  ) == *( card6.ystep.value ) );
        REQUIRE( Approx( 8.0  ) == *( ytag.value ) );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "One value is wrong" ){
      Argument< PLOTR::Card4::Ytag > ytag;
      {
        iRecordStream<char> issCard6( std::istringstream(
              "1.0 -1.0 0.5/" ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( PLOTR::Card6( issCard6, itype, ytag, ileg ) );
        }
      }{
        iRecordStream<char> issCard6( std::istringstream(
              "1.0 4.0 -0.6/" ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( PLOTR::Card6( issCard6, itype, ytag, ileg ) );
        }
      }
    }//WHEN
    WHEN( "An extra value is given" ){
      Argument< PLOTR::Card4::Ytag > ytag;
      iRecordStream<char> issCard6( std::istringstream(
            "1.0 10.0 1.0 20 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( PLOTR::Card6( issCard6, itype, ytag, ileg ) );
      }
    }//WHEN
    WHEN( "One default is used" ){
      Argument< PLOTR::Card4::Ytag > ytag;
      iRecordStream<char> issCard6( std::istringstream(" 500.0 400000.0 / " ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( PLOTR::Card6( issCard6, itype, ytag, ileg ) );
      }
    } //WHEN
  }//GIVEN
}//SCENARIO
