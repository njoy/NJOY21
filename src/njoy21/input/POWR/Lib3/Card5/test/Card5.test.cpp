#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "POWR, Lib3, Card5",
          "[POWR] [Lib3] [Card5]" ){
  GIVEN( "valid inputs" ){
    WHEN( "simplest input: nina = 1, mode = 1" ){
      iRecordStream<char> iss( std::istringstream(" 1 1 1 1.0 1 2 0 0 /") );

      THEN( "the values can be verified" ){
        POWR::Lib3::Card5 card5( iss, 1 );

        REQUIRE( 1 == card5.nina.value );
        REQUIRE( 1 == card5.ntemp.value );
        REQUIRE( 1 == card5.nsigz.value );
        REQUIRE( Approx( 1.0 ) == card5.sgref.value );
        REQUIRE( std::nullopt == card5.nina03 );
        REQUIRE( 1 == std::get<0>( *( card5.ntapea0 ) ).value );
        REQUIRE( 2 == std::get<1>( *( card5.ntapea0 ) ).value );
        REQUIRE( 0 == std::get<2>( *( card5.ntapea0 ) ).value );
        REQUIRE( 0 == std::get<3>( *( card5.ntapea0 ) ).value );
        REQUIRE( std::nullopt == card5.mode0 );
      }
    } // WHEN

    WHEN( "nina = 3 and mode = 1" ){
      iRecordStream<char> iss( std::istringstream(
                                              " 3 2 1 4.0 0 12.1 1 2 0 0 /" ) );

      THEN( "the values can be verified" ){
        POWR::Lib3::Card5 card5( iss, 1 );

        REQUIRE( 3 == card5.nina.value );
        REQUIRE( 2 == card5.ntemp.value );
        REQUIRE( 1 == card5.nsigz.value );
        REQUIRE( Approx( 4.0 ) == card5.sgref.value );
        REQUIRE( 0 == card5.nina03->first.value );
        REQUIRE( Approx( 12.1 ) == card5.nina03->second.value );
        REQUIRE( 1 == std::get<0>( *( card5.ntapea0 ) ).value );
        REQUIRE( 2 == std::get<1>( *( card5.ntapea0 ) ).value );
        REQUIRE( 0 == std::get<2>( *( card5.ntapea0 ) ).value );
        REQUIRE( 0 == std::get<3>( *( card5.ntapea0 ) ).value );
        REQUIRE( std::nullopt == card5.mode0 );
      }
    } // WHEN

    WHEN( "nina = 1 and mode = 0" ){
      iRecordStream<char> iss( std::istringstream(" 1 2 1 4.0 1 2 0 0 4 5 /") );

      THEN( "the values can be verified" ){
        POWR::Lib3::Card5 card5( iss, 0 );

        REQUIRE( 1 == card5.nina.value );
        REQUIRE( 2 == card5.ntemp.value );
        REQUIRE( 1 == card5.nsigz.value );
        REQUIRE( Approx( 4.0 ) == card5.sgref.value );
        REQUIRE( std::nullopt == card5.nina03 );
        REQUIRE( 1 == std::get<0>( *( card5.ntapea0 ) ).value );
        REQUIRE( 2 == std::get<1>( *( card5.ntapea0 ) ).value );
        REQUIRE( 0 == std::get<2>( *( card5.ntapea0 ) ).value );
        REQUIRE( 0 == std::get<3>( *( card5.ntapea0 ) ).value );
        REQUIRE( 4 == card5.mode0->first.value );
        REQUIRE( 5 == card5.mode0->second.value );
      }
    } // WHEN

    WHEN( "nina = 3 and mode = 0" ){
      iRecordStream<char> iss( std::istringstream(
                                          " 3 2 1 4.0 0 12.1 1 2 0 0 4 5 /" ) );

      THEN( "the values can be verified" ){
        POWR::Lib3::Card5 card5( iss, 0 );

        REQUIRE( 3 == card5.nina.value );
        REQUIRE( 2 == card5.ntemp.value );
        REQUIRE( 1 == card5.nsigz.value );
        REQUIRE( Approx( 4.0 ) == card5.sgref.value );
        REQUIRE( 0 == card5.nina03->first.value );
        REQUIRE( Approx( 12.1 ) == card5.nina03->second.value );
        REQUIRE( 1 == std::get<0>( *( card5.ntapea0 ) ).value );
        REQUIRE( 2 == std::get<1>( *( card5.ntapea0 ) ).value );
        REQUIRE( 0 == std::get<2>( *( card5.ntapea0 ) ).value );
        REQUIRE( 0 == std::get<3>( *( card5.ntapea0 ) ).value );
        REQUIRE( 4 == card5.mode0->first.value );
        REQUIRE( 5 == card5.mode0->second.value );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "too many values are given with nina = 3 and mode = 0" ){
      iRecordStream<char> iss( std::istringstream(
                                        " 3 2 1 4.0 0 12.1 1 2 0 0 4 5 6 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( POWR::Lib3::Card5( iss, 0 ) );
      }
    } // WHEN

    WHEN( "too many values are given with nina = 1 and mode = 0" ){
      iRecordStream<char> iss( std::istringstream(
                                               " 1 2 1 4.0 1 2 0 0 4 5 6 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( POWR::Lib3::Card5( iss, 0 ) );
      }
    } // WHEN

    WHEN( "too many values are given with nina = 3 and mode = 1" ){
      iRecordStream<char> iss( std::istringstream(
                                            " 3 2 1 4.0 0 12.1 1 2 0 0 6 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( POWR::Lib3::Card5( iss, 1 ) );
      }
    } // WHEN

    WHEN( "too manay values are given with nina = 1 and mode = 1" ){
      iRecordStream<char> iss(std::istringstream(" 1 1 1 1.0 1 2 0 0 6 /"));

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( POWR::Lib3::Card5( iss, 1 ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
