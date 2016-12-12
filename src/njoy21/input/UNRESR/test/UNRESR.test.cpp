#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

std::string sCard1(" 21 22 23\n");
std::string sCard2_full(" 9228 3 2 0/\n");
std::string sCard2_empty(" 9228 3 2 /\n"); // Optional values excluded
std::string sCard2_0(" 0 /");

std::string sCard3(" 293.6 600 800 /\n");
std::string sCard4(" 1 2 /\n");

SCENARIO( "Parsing valid UNRESR input" ){
  std::istringstream iss;
  long ln(0);
  WHEN( "all optional values are given" ){
    iss.str( sCard1 + sCard2_full + sCard3 + sCard4 + sCard2_0 );

    THEN( "the read values can ve verified" ){
      UNRESR unresr( iss, ln );
      REQUIRE( 21 == unresr.card1.nendf.value );
      REQUIRE( 22 == unresr.card1.nin.value );
      REQUIRE( 23 == unresr.card1.nout.value );

      REQUIRE( 1 == unresr.cardSequence.size() );

      auto& card2 = std::get<0>( unresr.cardSequence.front() );
      REQUIRE( 9228 == card2.matd.value );
      REQUIRE( 3 == card2.ntemp.value );
      REQUIRE( 2 == card2.nsigz.value );
      REQUIRE( 0 == card2.iprint.value );

      auto& card3 = std::get<1>( unresr.cardSequence.front() );
      REQUIRE( 3 == card3.temp.value.size() );
      REQUIRE( 293.6*dimwits::kelvin == card3.temp.value[0] );
      REQUIRE( 600*dimwits::kelvin == card3.temp.value[1] );
      REQUIRE( 800*dimwits::kelvin == card3.temp.value[2] );

      auto& card4 = std::get<2>( unresr.cardSequence.front() );
      REQUIRE( 2 == card4.sigz.value.size() );
      REQUIRE( 1*dimwits::barn == card4.sigz.value[0] );
      REQUIRE( 2*dimwits::barn == card4.sigz.value[1] );
    }
  }
  WHEN( "no optional values are given" ){
    iss.str( sCard1 + sCard2_empty + sCard3 + sCard4 + sCard2_0 );

    THEN( "the read values can ve verified" ){
      UNRESR unresr( iss, ln );
      REQUIRE( 21 == unresr.card1.nendf.value );
      REQUIRE( 22 == unresr.card1.nin.value );
      REQUIRE( 23 == unresr.card1.nout.value );

      auto& card2 = std::get<0>( unresr.cardSequence.front() );
      REQUIRE( 9228 == card2.matd.value );
      REQUIRE( 3 == card2.ntemp.value );
      REQUIRE( 2 == card2.nsigz.value );
      REQUIRE( 0 == card2.iprint.value );
    }
  }
  WHEN( "two materials are given" ){
    iss.str( sCard1 + sCard2_empty + sCard3 + sCard4 +
                      sCard2_full + sCard3 + sCard4 + sCard2_0 );

    THEN( "the read values can ve verified" ){
      UNRESR unresr( iss, ln );

      REQUIRE( 2 == unresr.cardSequence.size() );
    }
  } // GIVEN
} // SCENARIO

SCENARIO( "Parsing invlaid UNRESR input" ){
  std::istringstream iss;
  long ln(0);

  WHEN( "Only terminating Card2" ){
    iss.str( sCard1 + sCard2_0 );
    njoy::Log::info(iss.str() );

    THEN( "an exception is thrown" ){
      REQUIRE_THROWS( UNRESR( iss, ln ) );
    }
  }
  WHEN( "Cards with non-terminating-Card2" ){
    iss.str( sCard1 + sCard2_full + sCard3 + sCard4);

    THEN( "an exception is thrown" ){
      REQUIRE_THROWS( UNRESR( iss, ln ) );
    }
  }
  WHEN( "Card3 has too few entries" ){
    njoy::Log::info(
        "\nTesting failure when Card3 has too few entries.\n" );
    iss.str( sCard1 + "9228 4 2 /\n" + sCard3 + sCard4 + sCard2_0 );

    THEN( "an exception is thrown" ){
      REQUIRE_THROWS( UNRESR( iss, ln ) );
    }
  }
  WHEN( "Card3 has too many entries" ){
    njoy::Log::info(
        "\nTesting failure when Card3 has too many entries.\n" );
    iss.str( sCard1 + "9228 2 2 /\n" + sCard3 + sCard4 + sCard2_0 );

    THEN( "an exception is thrown" ){
      REQUIRE_THROWS( UNRESR( iss, ln ) );
    }
  }
  WHEN( "Card4 has too few entries" ){
    njoy::Log::info(
        "\nTesting failure when Card4 has too few entries.\n" );
    iss.str( sCard1 + "9228 3 3 /\n" + sCard3 + sCard4 + sCard2_0 );

    THEN( "an exception is thrown" ){
      REQUIRE_THROWS( UNRESR( iss, ln ) );
    }
  }
  WHEN( "Card4 has too many entries" ){
    njoy::Log::info(
        "\nTesting failure when Card4 has too many entries.\n" );
    iss.str( sCard1 + "9228 3 1 /\n" + sCard3 + sCard4 + sCard2_0 );

    THEN( "an exception is thrown" ){
      REQUIRE_THROWS( UNRESR( iss, ln ) );
    }
  }
}
