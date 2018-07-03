#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Validating card5 inputs",
          "[PLOTR], [Card5]" ){
  Argument< PLOTR::Card4::Itype > itype; itype.value = 1;
  const int ileg = 1;

  GIVEN( "valid PLOTR Card5 inputs" ){
    WHEN( "All values are given" ){
      std::optional< double > xtagval;
      Argument< PLOTR::Card4::Xtag > xtag; xtag.value = xtagval;
      iRecordStream<char> issCard5(
            std::istringstream(" 10.0 50.0 2.0 / " ) );
      PLOTR::Card5 card5( issCard5, xtag, itype, ileg );

      THEN( "the members can be tested" ){
        REQUIRE( Approx( 10.0 ) == *( card5.el.value ) );
        REQUIRE( Approx( 50.0 ) == *( card5.eh.value ) );
        REQUIRE( Approx( 2.0 ) == *( card5.xstep.value ) );
        REQUIRE( Approx( 10.0 ) == *( xtag.value ) );
      }
    } //WHEN
    WHEN( "No values are given" ){
      Argument< PLOTR::Card4::Xtag > xtag;
      iRecordStream<char> issCard5( std::istringstream(" / "));
      PLOTR::Card5 card5( issCard5, xtag, itype, ileg );

      THEN( "the members can be tested" ){
        REQUIRE( std::nullopt == card5.el.value );
        REQUIRE( std::nullopt == card5.eh.value );
        REQUIRE( std::nullopt == card5.xstep.value );
        REQUIRE( std::nullopt == xtag.value );
      }
    } //WHEN
    WHEN( "Xtag alread has a value" ){
      std::optional< double > xtagval = 4.0;
      Argument< PLOTR::Card4::Xtag > xtag; xtag.value = xtagval;
      iRecordStream<char> issCard5( std::istringstream(
                          " 2.0 10.0 1.0 / " ) );
      PLOTR::Card5 card5( issCard5, xtag, itype, ileg );
      THEN( "the members can be tested and xtag retains its value" ){
        REQUIRE( Approx( 2.0 ) == *( card5.el.value ) );
        REQUIRE( Approx( 10.0 ) == *( card5.eh.value ) );
        REQUIRE( Approx( 1.0 ) == *( card5.xstep.value ) );
        REQUIRE( Approx( 4.0 ) == *( xtag.value ) );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    std::optional< double > xtagval;
    Argument< PLOTR::Card4::Xtag > xtag; xtag.value = xtagval;
    WHEN( "All values are wrong" ){
      iRecordStream<char> issCard5( std::istringstream(
             "-1.0 1.0 0.5/" ) );
  
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( PLOTR::Card5(issCard5, xtag, itype, ileg) );
      }
    }//WHEN
    WHEN( "One value is wrong" ){
      {
        iRecordStream<char> issCard5( std::istringstream(
              "1.0 -1.0 0.5/" ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( PLOTR::Card5(issCard5, xtag, itype, ileg) );
        }
      }{
        iRecordStream<char> issCard5( std::istringstream(
              "1.0 4.0 -0.6/" ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( PLOTR::Card5(issCard5, xtag, itype, ileg) );
        }
      }
    }//WHEN
    WHEN( "An extra value is given" ){
      iRecordStream<char> issCard5( std::istringstream(
            "1.0 10.0 1.0 20 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( PLOTR::Card5(issCard5, xtag, itype, ileg) );
      }
    }//WHEN
//    WHEN( "Only one default is used" ){
//      iRecordStream<char> issCard5( std::istringstream(" 500.0 400000.0 / " ) );
//
//      THEN( "an exception is thrown" ){
//        REQUIRE_THROWS( PLOTR::Card5( issCard5, xtag, itype, ileg ) );
//      }
//    } //WHEN
  }//GIVEN
}//SCENARIO
