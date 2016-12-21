#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

std::string sCard1(" 21 22 23\n");
std::string sCard2_full(" 9228 3 2 16 90 0 3 /\n");
std::string sCard2_empty(" 9228 3 2 /\n"); // Optional values excluded
std::string sCard2_0(" 0 /");

std::string sCard3(" 293.6 600 800 /\n");
std::string sCard4(" 1 2 /\n");

SCENARIO( "Parsing valid PURR input" ){
  WHEN( "all optional values are given" ){
    std::istringstream iss( sCard1 + sCard2_full + sCard3 + sCard4 + sCard2_0 );
    njoy::Log::info( "\n{}\n", iss.str() );
    iRecordStream< char> iRS( std::move( iss ) );

    THEN( "the read values can ve verified" ){
      PURR purr( iRS );
      REQUIRE( 21 == purr.card1.nendf.value );
      REQUIRE( 22 == purr.card1.nin.value );
      REQUIRE( 23 == purr.card1.nout.value );

      REQUIRE( 1 == purr.cardSequence.size() );

      auto& card2 = std::get<0>( purr.cardSequence.front() );
      REQUIRE( 9228 == card2.matd.value );
      REQUIRE( 3 == card2.ntemp.value );
      REQUIRE( 2 == card2.nsigz.value );
      REQUIRE( 16 == card2.nbin.value );
      REQUIRE( 90 == card2.nladr.value );
      REQUIRE( 0 == card2.iprint.value );
      REQUIRE( 3 == card2.nunx.value );

      auto& card3 = std::get<1>( purr.cardSequence.front() );
      REQUIRE( 3 == card3.temp.value.size() );
      REQUIRE( 293.6*dimwits::kelvin == card3.temp.value[0] );
      REQUIRE( 600*dimwits::kelvin == card3.temp.value[1] );
      REQUIRE( 800*dimwits::kelvin == card3.temp.value[2] );

      auto& card4 = std::get<2>( purr.cardSequence.front() );
      REQUIRE( 2 == card4.sigz.value.size() );
      REQUIRE( 1*dimwits::barn == card4.sigz.value[0] );
      REQUIRE( 2*dimwits::barn == card4.sigz.value[1] );
    }
  }
  WHEN( "no optional values are given" ){
    std::istringstream iss(sCard1 + sCard2_empty + sCard3 + sCard4 + sCard2_0 );
    njoy::Log::info( "\n{}\n", iss.str() );
    iRecordStream< char > iRS( std::move(iss) );

    THEN( "the read values can ve verified" ){
      PURR purr( iRS );
      REQUIRE( 21 == purr.card1.nendf.value );
      REQUIRE( 22 == purr.card1.nin.value );
      REQUIRE( 23 == purr.card1.nout.value );

      auto& card2 = std::get<0>( purr.cardSequence.front() );
      REQUIRE( 9228 == card2.matd.value );
      REQUIRE( 3 == card2.ntemp.value );
      REQUIRE( 2 == card2.nsigz.value );
      REQUIRE( 20 == card2.nbin.value );
      REQUIRE( 64 == card2.nladr.value );
      REQUIRE( 1 == card2.iprint.value );
      REQUIRE( 0 == card2.nunx.value );
    }
  }
  WHEN( "two materials are given" ){
    std::istringstream iss( sCard1 + sCard2_empty + sCard3 + sCard4 +
                      sCard2_full + sCard3 + sCard4 + sCard2_0  );
    njoy::Log::info( "\n{}\n", iss.str() );
    iRecordStream< char > iRS( std::move(iss) );

    THEN( "the read values can ve verified" ){
      PURR purr( iRS );

      REQUIRE( 2 == purr.cardSequence.size() );
    }
  } // GIVEN
} // SCENARIO

SCENARIO( "Parsing invlaid PURR input" ){
  WHEN( "Only terminating Card2" ){
    iRecordStream< char> iss(
        std::istringstream( sCard1 + sCard2_0 ) );

    THEN( "an exception is thrown" ){
      REQUIRE_THROWS( PURR purr( iss ) );
    }
  }
  WHEN( "Cards with non-terminating-Card2" ){
    iRecordStream< char> iss(
        std::istringstream( sCard1 + sCard2_full + sCard3 + sCard4) );

    THEN( "an exception is thrown" ){
      REQUIRE_THROWS( PURR purr( iss ) );
    }
  }
  WHEN( "Card3 has too few entries" ){
    njoy::Log::info(
        "\nTesting failure when Card3 has too few entries.\n" );
    iRecordStream< char> iss(
        std::istringstream( sCard1 + "9228 4 2 /\n" + sCard3 + sCard4 + sCard2_0 ) );

    THEN( "an exception is thrown" ){
      REQUIRE_THROWS( PURR purr( iss ) );
    }
  }
  WHEN( "Card3 has too many entries" ){
    njoy::Log::info(
        "\nTesting failure when Card3 has too many entries.\n" );
    iRecordStream< char> iss(
        std::istringstream( sCard1 + "9228 2 2 /\n" + sCard3 + sCard4 + sCard2_0 ) );

    THEN( "an exception is thrown" ){
      REQUIRE_THROWS( PURR purr( iss ) );
    }
  }
  WHEN( "Card4 has too few entries" ){
    njoy::Log::info(
        "\nTesting failure when Card4 has too few entries.\n" );
    iRecordStream< char> iss(
        std::istringstream( sCard1 + "9228 3 3 /\n" + sCard3 + sCard4 + sCard2_0 ) );

    THEN( "an exception is thrown" ){
      REQUIRE_THROWS( PURR purr( iss ) );
    }
  }
  WHEN( "Card4 has too many entries" ){
    njoy::Log::info(
        "\nTesting failure when Card4 has too many entries.\n" );
    iRecordStream< char> iss(
        std::istringstream( sCard1 + "9228 3 1 /\n" + sCard3 + sCard4 + sCard2_0 ) );

    THEN( "an exception is thrown" ){
      REQUIRE_THROWS( PURR purr( iss ) );
    }
  }
}
