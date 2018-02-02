#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "COVR",
          "[COVR]" ){
  GIVEN( "valid inputs" ){
    WHEN( "card23a is used with valid inputs" ){
      std::string inp(
 std::string( " 22 -23 /\n" ) + // Card1
 std::string( " 2 /\n" ) + // Card2
 std::string( " 4 0.01 0.1 0.9 1.0 /\n" ) + // Card2'
 std::string( " 0.001 /\n" ) + // Card2a
 std::string( " /\n" ) + // Card3a
 std::string( " 2111 5 2112 2 /" ) // Card4
      );

      iRecordStream<char> iss{ std::istringstream{ inp } };

      THEN( "an exception is thrown" ){
        COVR covr( iss );

        REQUIRE( 22 == covr.card1.nin.value );
        REQUIRE( -23 == covr.card1.nout.value );
        REQUIRE( 0 == covr.card1.nplot.value );

        REQUIRE( 2 == std::get< 0 >( *( covr.card23a ) ).icolor.value );

        REQUIRE( 4 == std::get< 1 >( *( covr.card23a ) )->nlev.value );
        REQUIRE( Approx( 0.01 ) ==
                       std::get< 1 >( *( covr.card23a ) )->tlev.value.at( 0 ) );
        REQUIRE( Approx( 0.1 ) ==
                       std::get< 1 >( *( covr.card23a ) )->tlev.value.at( 1 ) );
        REQUIRE( Approx( 0.9 ) ==
                       std::get< 1 >( *( covr.card23a ) )->tlev.value.at( 2 ) );
        REQUIRE( Approx( 1.0 ) ==
                       std::get< 1 >( *( covr.card23a ) )->tlev.value.at( 3 ) );

        REQUIRE( Approx( 0.001 ) ==
                               std::get< 2 >( *( covr.card23a ) ).epmin.value );

        REQUIRE( 1 == std::get< 3 >( *( covr.card23a ) ).irelco.value );
        REQUIRE( 1 == std::get< 3 >( *( covr.card23a ) ).ncase.value );
        REQUIRE( 0 == std::get< 3 >( *( covr.card23a ) ).noleg.value );
        REQUIRE( 1 == std::get< 3 >( *( covr.card23a ) ).nstart.value );
        REQUIRE( 1 == std::get< 3 >( *( covr.card23a ) ).ndiv.value );

        REQUIRE( std::nullopt == covr.card23b );

        REQUIRE( 1 == covr.card4List.size() );

        REQUIRE( 2111 == covr.card4List.at( 0 ).mat.value );
        REQUIRE( 5 == covr.card4List.at( 0 ).mt.value );
        REQUIRE( 2112 == covr.card4List.at( 0 ).mat1.value );
        REQUIRE( 2 == covr.card4List.at( 0 ).mt1.value );
      }
    } // WHEN

    WHEN( "card23b is used with valid inputs" ){
      std::string inp(
 std::string( " 22 23 -24 /\n" ) + // Card1
 std::string( " 3 2 /\n" ) + // Card2b
 std::string( " '123456' /\n" ) + // Card3b
 std::string( " '123456789012345678901' /\n" ) + // Card3c
 std::string( " 2111 5 2112 2 /\n" ) + // Card4
 std::string( " 3111 -6 -3112 -3 /" ) // Card4
      );

      iRecordStream<char> iss{ std::istringstream{ inp } };

      THEN( "an exception is thrown" ){
        COVR covr( iss );

        REQUIRE( 22 == covr.card1.nin.value );
        REQUIRE( 23 == covr.card1.nout.value );
        REQUIRE( -24 == covr.card1.nplot.value );

        REQUIRE( std::nullopt == covr.card23a );

        REQUIRE( 3 == std::get< 0 >( *( covr.card23b ) ).matype.value );
        REQUIRE( 2 == std::get< 0 >( *( covr.card23b ) ).ncase.value );

        REQUIRE( "123456" == std::get< 1 >( *( covr.card23b ) ).hlibid.value );

        REQUIRE( "123456789012345678901" ==
                              std::get< 2 >( *( covr.card23b ) ).hdescr.value );

        REQUIRE( 2 == covr.card4List.size() );

        REQUIRE( 2111 == covr.card4List.at( 0 ).mat.value );
        REQUIRE( 5 == covr.card4List.at( 0 ).mt.value );
        REQUIRE( 2112 == covr.card4List.at( 0 ).mat1.value );
        REQUIRE( 2 == covr.card4List.at( 0 ).mt1.value );

        REQUIRE( 3111 == covr.card4List.at( 1 ).mat.value );
        REQUIRE( -6 == covr.card4List.at( 1 ).mt.value );
        REQUIRE( -3112 == covr.card4List.at( 1 ).mat1.value );
        REQUIRE( -3 == covr.card4List.at( 1 ).mt1.value );
      }
    } // WHEN

    WHEN( "the input from test problem 5 is used" ){
      std::string inp(
 std::string( " 33 0 34 /\n" ) + // Card1
 std::string( " 1 /\n" ) + // Card2b
 std::string( " /\n" ) + // Card3b
 std::string( " /\n" ) + // Card3c
 std::string( " 1306 /" )
      );

      iRecordStream<char> iss{ std::istringstream{ inp } };

      THEN( "the values can be verified" ){
        COVR covr( iss );

        REQUIRE( 33 == covr.card1.nin.value );
        REQUIRE( 0 == covr.card1.nout.value );
        REQUIRE( 34 == covr.card1.nplot.value );

        REQUIRE( 1 == std::get< 0 >( *( covr.card23a ) ).icolor.value );
        REQUIRE( std::nullopt == std::get< 1 >( *( covr.card23a ) ) );

        REQUIRE( Approx( 0.0 ) == std::get< 2 >( *(covr.card23a) ).epmin.value);

        REQUIRE( 1 == std::get< 3 >( *( covr.card23a ) ).irelco.value );
        REQUIRE( 1 == std::get< 3 >( *( covr.card23a ) ).ncase.value );
        REQUIRE( 0 == std::get< 3 >( *( covr.card23a ) ).noleg.value );
        REQUIRE( 1 == std::get< 3 >( *( covr.card23a ) ).nstart.value );
        REQUIRE( 1 == std::get< 3 >( *( covr.card23a ) ).ndiv.value );

        REQUIRE( 1 == covr.card4List.size() );

        REQUIRE( 1306 == covr.card4List.at( 0 ).mat.value );
        REQUIRE( 0 == covr.card4List.at( 0 ).mt.value );
        REQUIRE( 0 == covr.card4List.at( 0 ).mat1.value );
        REQUIRE( 0 == covr.card4List.at( 0 ).mt1.value );
      }
    } // WHEN

    WHEN( "the first input from test problem 15 is used (mf31 plot file)" ){
      std::string inp(
 std::string( " 25 0 35 /\n" ) + // Card1
 std::string( " 1 /\n" ) + // Card2b
 std::string( " /\n" ) + // Card3b
 std::string( " /\n" ) + // Card3c
 std::string( " 9237 /" )
      );

      iRecordStream<char> iss{ std::istringstream{ inp } };

      THEN( "the values can be verified" ){
        COVR covr( iss );

        REQUIRE( 25 == covr.card1.nin.value );
        REQUIRE( 0 == covr.card1.nout.value );
        REQUIRE( 35 == covr.card1.nplot.value );

        REQUIRE( 1 == std::get< 0 >( *( covr.card23a ) ).icolor.value );
        REQUIRE( std::nullopt == std::get< 1 >( *( covr.card23a ) ) );

        REQUIRE( Approx( 0.0 ) == std::get< 2 >( *(covr.card23a) ).epmin.value);

        REQUIRE( 1 == std::get< 3 >( *( covr.card23a ) ).irelco.value );
        REQUIRE( 1 == std::get< 3 >( *( covr.card23a ) ).ncase.value );
        REQUIRE( 0 == std::get< 3 >( *( covr.card23a ) ).noleg.value );
        REQUIRE( 1 == std::get< 3 >( *( covr.card23a ) ).nstart.value );
        REQUIRE( 1 == std::get< 3 >( *( covr.card23a ) ).ndiv.value );

        REQUIRE( 1 == covr.card4List.size() );

        REQUIRE( 9237 == covr.card4List.at( 0 ).mat.value );
        REQUIRE( 0 == covr.card4List.at( 0 ).mt.value );
        REQUIRE( 0 == covr.card4List.at( 0 ).mat1.value );
        REQUIRE( 0 == covr.card4List.at( 0 ).mt1.value );
      }
    } // WHEN

    WHEN( "the second input from test problem 15 is used (mf33 plot file)" ){
      std::string inp(
 std::string( " 26 0 36 /\n" ) + // Card1
 std::string( " 1 /\n" ) + // Card2b
 std::string( " /\n" ) + // Card3b
 std::string( " 1 14 /\n" ) + // Card3c
 std::string( " 9237 1 9237 1 /\n" ) + // Card4
 std::string( " 9237 1 9237 2 /\n" ) + // Card4
 std::string( " 9237 2 9237 2 /\n" ) + // Card4
 std::string( " 9237 2 9237 4 /\n" ) + // Card4
 std::string( " 9237 2 9237 16 /\n" ) + // Card4
 std::string( " 9237 2 9237 17 /\n" ) + // Card4
 std::string( " 9237 2 9237 18 /\n" ) + // Card4
 std::string( " 9237 2 9237 102 /\n" ) + // Card4
 std::string( " 9237 4 9237 4 /\n" ) + // Card4
 std::string( " 9237 16 9237 16 /\n" ) + // Card4
 std::string( " 9237 17 9237 17 /\n" ) + // Card4
 std::string( " 9237 18 9237 18 /\n" ) + // Card4
 std::string( " 9237 18 9237 102 /\n" ) + // Card4
 std::string( " 9237 102 9237 102 /" ) // Card4
      );

      iRecordStream<char> iss{ std::istringstream{ inp } };

      THEN( "the values can be verified" ){
        COVR covr( iss );

        REQUIRE( 26 == covr.card1.nin.value );
        REQUIRE( 0 == covr.card1.nout.value );
        REQUIRE( 36 == covr.card1.nplot.value );

        REQUIRE( 1 == std::get< 0 >( *( covr.card23a ) ).icolor.value );
        REQUIRE( std::nullopt == std::get< 1 >( *( covr.card23a ) ) );

        REQUIRE( Approx( 0.0 ) == std::get< 2 >( *(covr.card23a) ).epmin.value);

        REQUIRE( 1 == std::get< 3 >( *( covr.card23a ) ).irelco.value );
        REQUIRE( 14 == std::get< 3 >( *( covr.card23a ) ).ncase.value );
        REQUIRE( 0 == std::get< 3 >( *( covr.card23a ) ).noleg.value );
        REQUIRE( 1 == std::get< 3 >( *( covr.card23a ) ).nstart.value );
        REQUIRE( 1 == std::get< 3 >( *( covr.card23a ) ).ndiv.value );

        REQUIRE( 14 == covr.card4List.size() );

        REQUIRE( 9237 == covr.card4List.at( 0 ).mat.value );
        REQUIRE( 1 == covr.card4List.at( 0 ).mt.value );
        REQUIRE( 9237 == covr.card4List.at( 0 ).mat1.value );
        REQUIRE( 1 == covr.card4List.at( 0 ).mt1.value );

        REQUIRE( 9237 == covr.card4List.at( 1 ).mat.value );
        REQUIRE( 1 == covr.card4List.at( 1 ).mt.value );
        REQUIRE( 9237 == covr.card4List.at( 1 ).mat1.value );
        REQUIRE( 2 == covr.card4List.at( 1 ).mt1.value );

        REQUIRE( 9237 == covr.card4List.at( 2 ).mat.value );
        REQUIRE( 2 == covr.card4List.at( 2 ).mt.value );
        REQUIRE( 9237 == covr.card4List.at( 2 ).mat1.value );
        REQUIRE( 2 == covr.card4List.at( 2 ).mt1.value );

        REQUIRE( 9237 == covr.card4List.at( 3 ).mat.value );
        REQUIRE( 2 == covr.card4List.at( 3 ).mt.value );
        REQUIRE( 9237 == covr.card4List.at( 3 ).mat1.value );
        REQUIRE( 4 == covr.card4List.at( 3 ).mt1.value );

        REQUIRE( 9237 == covr.card4List.at( 4 ).mat.value );
        REQUIRE( 2 == covr.card4List.at( 4 ).mt.value );
        REQUIRE( 9237 == covr.card4List.at( 4 ).mat1.value );
        REQUIRE( 16 == covr.card4List.at( 4 ).mt1.value );

        REQUIRE( 9237 == covr.card4List.at( 5 ).mat.value );
        REQUIRE( 2 == covr.card4List.at( 5 ).mt.value );
        REQUIRE( 9237 == covr.card4List.at( 5 ).mat1.value );
        REQUIRE( 17 == covr.card4List.at( 5 ).mt1.value );

        REQUIRE( 9237 == covr.card4List.at( 6 ).mat.value );
        REQUIRE( 2 == covr.card4List.at( 6 ).mt.value );
        REQUIRE( 9237 == covr.card4List.at( 6 ).mat1.value );
        REQUIRE( 18 == covr.card4List.at( 6 ).mt1.value );

        REQUIRE( 9237 == covr.card4List.at( 7 ).mat.value );
        REQUIRE( 2 == covr.card4List.at( 7 ).mt.value );
        REQUIRE( 9237 == covr.card4List.at( 7 ).mat1.value );
        REQUIRE( 102 == covr.card4List.at( 7 ).mt1.value );

        REQUIRE( 9237 == covr.card4List.at( 8 ).mat.value );
        REQUIRE( 4 == covr.card4List.at( 8 ).mt.value );
        REQUIRE( 9237 == covr.card4List.at( 8 ).mat1.value );
        REQUIRE( 4 == covr.card4List.at( 8 ).mt1.value );

        REQUIRE( 9237 == covr.card4List.at( 9 ).mat.value );
        REQUIRE( 16 == covr.card4List.at( 9 ).mt.value );
        REQUIRE( 9237 == covr.card4List.at( 9 ).mat1.value );
        REQUIRE( 16 == covr.card4List.at( 9 ).mt1.value );

        REQUIRE( 9237 == covr.card4List.at( 10 ).mat.value );
        REQUIRE( 17 == covr.card4List.at( 10 ).mt.value );
        REQUIRE( 9237 == covr.card4List.at( 10 ).mat1.value );
        REQUIRE( 17 == covr.card4List.at( 10 ).mt1.value );

        REQUIRE( 9237 == covr.card4List.at( 11 ).mat.value );
        REQUIRE( 18 == covr.card4List.at( 11 ).mt.value );
        REQUIRE( 9237 == covr.card4List.at( 11 ).mat1.value );
        REQUIRE( 18 == covr.card4List.at( 11 ).mt1.value );

        REQUIRE( 9237 == covr.card4List.at( 12 ).mat.value );
        REQUIRE( 18 == covr.card4List.at( 12 ).mt.value );
        REQUIRE( 9237 == covr.card4List.at( 12 ).mat1.value );
        REQUIRE( 102 == covr.card4List.at( 12 ).mt1.value );

        REQUIRE( 9237 == covr.card4List.at( 13 ).mat.value );
        REQUIRE( 102 == covr.card4List.at( 13 ).mt.value );
        REQUIRE( 9237 == covr.card4List.at( 13 ).mat1.value );
        REQUIRE( 102 == covr.card4List.at( 13 ).mt1.value );
      }
    } // WHEN

    WHEN( "the third input from test problem 15 is used (mf34 plot file)" ){
      std::string inp(
 std::string( " 27 0 37 /\n" ) + // Card1
 std::string( " 1 /\n" ) + // Card2b
 std::string( " /\n" ) + // Card3b
 std::string( " /\n" ) + // Card3c
 std::string( " 9237 /" )
      );

      iRecordStream<char> iss{ std::istringstream{ inp } };

      THEN( "the values can be verified" ){
        COVR covr( iss );

        REQUIRE( 27 == covr.card1.nin.value );
        REQUIRE( 0 == covr.card1.nout.value );
        REQUIRE( 37 == covr.card1.nplot.value );

        REQUIRE( 1 == std::get< 0 >( *( covr.card23a ) ).icolor.value );
        REQUIRE( std::nullopt == std::get< 1 >( *( covr.card23a ) ) );

        REQUIRE( Approx( 0.0 ) == std::get< 2 >( *(covr.card23a) ).epmin.value);

        REQUIRE( 1 == std::get< 3 >( *( covr.card23a ) ).irelco.value );
        REQUIRE( 1 == std::get< 3 >( *( covr.card23a ) ).ncase.value );
        REQUIRE( 0 == std::get< 3 >( *( covr.card23a ) ).noleg.value );
        REQUIRE( 1 == std::get< 3 >( *( covr.card23a ) ).nstart.value );
        REQUIRE( 1 == std::get< 3 >( *( covr.card23a ) ).ndiv.value );

        REQUIRE( 1 == covr.card4List.size() );

        REQUIRE( 9237 == covr.card4List.at( 0 ).mat.value );
        REQUIRE( 0 == covr.card4List.at( 0 ).mt.value );
        REQUIRE( 0 == covr.card4List.at( 0 ).mat1.value );
        REQUIRE( 0 == covr.card4List.at( 0 ).mt1.value );
      }
    } // WHEN

    WHEN( "the input from test problem 18 is used" ){
      std::string inp(
 std::string( " 28 0 38 /\n" ) + // Card1
 std::string( " 1 /\n" ) + // Card2b
 std::string( " 1.e3 /\n" ) + // Card3b
 std::string( " /\n" ) + // Card3c
 std::string( " 9999 /" )
      );

      iRecordStream<char> iss{ std::istringstream{ inp } };

      THEN( "the values can be verified" ){
        COVR covr( iss );

        REQUIRE( 28 == covr.card1.nin.value );
        REQUIRE( 0 == covr.card1.nout.value );
        REQUIRE( 38 == covr.card1.nplot.value );

        REQUIRE( 1 == std::get< 0 >( *( covr.card23a ) ).icolor.value );
        REQUIRE( std::nullopt == std::get< 1 >( *( covr.card23a ) ) );

        REQUIRE( Approx( 1000.0 ) ==
                               std::get< 2 >( *( covr.card23a ) ).epmin.value );

        REQUIRE( 1 == std::get< 3 >( *( covr.card23a ) ).irelco.value );
        REQUIRE( 1 == std::get< 3 >( *( covr.card23a ) ).ncase.value );
        REQUIRE( 0 == std::get< 3 >( *( covr.card23a ) ).noleg.value );
        REQUIRE( 1 == std::get< 3 >( *( covr.card23a ) ).nstart.value );
        REQUIRE( 1 == std::get< 3 >( *( covr.card23a ) ).ndiv.value );

        REQUIRE( 1 == covr.card4List.size() );

        REQUIRE( 9999 == covr.card4List.at( 0 ).mat.value );
        REQUIRE( 0 == covr.card4List.at( 0 ).mt.value );
        REQUIRE( 0 == covr.card4List.at( 0 ).mat1.value );
        REQUIRE( 0 == covr.card4List.at( 0 ).mt1.value );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "too few Card4s are provided" ){
      std::string inp(
 std::string( " 22 -23 /\n" ) +
 std::string( " /\n" ) + // Card2
 std::string( " /\n" ) + // Card2a
 std::string( " 1 2 /\n" ) + // Card3a
 std::string( " 2111 5 2112 2 /" )
      );

      iRecordStream<char> iss{ std::istringstream{ inp } };

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( COVR( iss ) );
      }
    } // WHEN

    WHEN( "too many cases are requested (41)" ){
      std::string inp(
 std::string( " 22 -23 /\n" ) +
 std::string( " /\n" ) + // Card2
 std::string( " /\n" ) + // Card2a
 std::string( " 1 41 /\n" ) + // Card3a
 std::string( " 1 1 1 1 /\n" ) +
 std::string( " 2 2 2 2 /\n" ) +
 std::string( " 3 3 3 3 /\n" ) +
 std::string( " 4 4 4 4 /\n" ) +
 std::string( " 5 5 5 5 /\n" ) +
 std::string( " 6 6 6 6 /\n" ) +
 std::string( " 7 7 7 7 /\n" ) +
 std::string( " 8 8 8 8 /\n" ) +
 std::string( " 9 9 9 9 /\n" ) +
 std::string( " 10 10 10 10 /\n" ) +
 std::string( " 11 11 11 11 /\n" ) +
 std::string( " 12 12 12 12 /\n" ) +
 std::string( " 13 13 13 13 /\n" ) +
 std::string( " 14 14 14 14 /\n" ) +
 std::string( " 15 15 15 15 /\n" ) +
 std::string( " 16 16 16 16 /\n" ) +
 std::string( " 17 17 17 17 /\n" ) +
 std::string( " 18 18 18 18 /\n" ) +
 std::string( " 19 19 19 19 /\n" ) +
 std::string( " 20 20 20 20 /\n" ) +
 std::string( " 21 21 21 21 /\n" ) +
 std::string( " 22 22 22 22 /\n" ) +
 std::string( " 23 23 23 23 /\n" ) +
 std::string( " 24 24 24 24 /\n" ) +
 std::string( " 25 25 25 25 /\n" ) +
 std::string( " 26 26 26 26 /\n" ) +
 std::string( " 27 27 27 27 /\n" ) +
 std::string( " 28 28 28 28 /\n" ) +
 std::string( " 29 29 29 29 /\n" ) +
 std::string( " 30 30 30 30 /\n" ) +
 std::string( " 31 31 31 31 /\n" ) +
 std::string( " 32 32 32 32 /\n" ) +
 std::string( " 33 33 33 33 /\n" ) +
 std::string( " 34 34 34 34 /\n" ) +
 std::string( " 35 35 35 35 /\n" ) +
 std::string( " 36 36 36 36 /\n" ) +
 std::string( " 37 37 37 37 /\n" ) +
 std::string( " 38 38 38 38 /\n" ) +
 std::string( " 39 39 39 39 /\n" ) +
 std::string( " 40 40 40 40 /\n" ) +
 std::string( " 41 41 41 41 /" )
      );

      iRecordStream<char> iss{ std::istringstream{ inp } };

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( COVR( iss ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
