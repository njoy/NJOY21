#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;
using namespace dimwits;

SCENARIO( "bugless" ){
  SECTION("Multiple Temperatures"){
    iRecordStream<char> multipleTemperature( std::istringstream(
    " 20 21 22\n"
    " 125 2 0 0 0\n"
    " 0.001 1 0.02 1e-07\n"
    " 300 1200\n"
    " 0/\n") );

    BROADR broadr( multipleTemperature );

    REQUIRE( broadr.card1.nendf.value == 20 );
    REQUIRE( broadr.card1.nin.value == 21 );
    REQUIRE( broadr.card1.nout.value == 22 );

    REQUIRE( broadr.card2.mat1.value == 125 );
    REQUIRE( broadr.card2.ntemp2.value == 2 );
    REQUIRE( broadr.card2.istart.value == 0 );
    REQUIRE( broadr.card2.istrap.value == 0 );
    REQUIRE( broadr.card2.temp1.value == 0.0 * kelvin );

    REQUIRE( broadr.card3.errthn.value == 1.0E-3 );
    REQUIRE( broadr.card3.thnmax.value == 1.0 * electronVolts );
    REQUIRE( broadr.card3.errmax.value == 0.02 );
    REQUIRE( broadr.card3.errint.value == 1.0E-7 * barns );

    REQUIRE( broadr.card4.temp2.value.front() == 300.0 * kelvin );
    REQUIRE( broadr.card4.temp2.value.back() == 1200.0 * kelvin );

    REQUIRE( not broadr.card5List.size() );
  }

  SECTION( "Multiple Materials" ){
    iRecordStream<char> multipleMaterial( std::istringstream(
    " 20 21 22\n"
    " 125 2 0 0 0\n"
    " 0.001 1 0.02 1e-07\n"
    " 300 1200\n"
    " 825\n"
    " 9225\n"
    " 9228 \n"
    " 0/\n") );

    BROADR broadr( multipleMaterial );

    REQUIRE( broadr.card5List.size() == 3 );
    REQUIRE( broadr.card5List.front().mat1.value == 825 );
    REQUIRE( broadr.card5List.at(1).mat1.value == 9225 );
    REQUIRE( broadr.card5List.back().mat1.value == 9228 );
  }
}

SCENARIO("bugged"){
  SECTION("Too few temperatures provided"){
    iRecordStream<char> multipleTemperature( std::istringstream(
      " 20 21 22\n"
      " 9228 3 0 0 0\n"
      " 0.001 1 0.02 1e-07\n"
      " 300 1200\n"
      " 0/\n") );
    REQUIRE_THROWS( BROADR( multipleTemperature ) );
  }

  SECTION("unsorted MAT values"){
    iRecordStream<char> iss( std::istringstream(
      " 20 21 22\n"
      " 9228 2 0 0 0\n"
      " 0.001 1 0.01 1e-07\n"
      " 300 1200\n"
      " 9225 \n"
      " 125\n"
      " 825\n"
      " 0\n") );
    REQUIRE_THROWS( BROADR( iss ) );
  }
}
