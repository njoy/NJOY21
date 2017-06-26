#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

std::string sCard1( "-30 -32 0 -34 /\n" );
std::string sCard3( "GROUPR Card3 title for testing" );
std::string sCard4( "293.6 /\n" );
std::string sCard5( "1E-10 /\n" );
std::string sCard9_10{
      "3 18 'MF3 MT18' /\n"         // Card 9.1
      "3 102 'MF3 MT102' /\n"       // Card 9.2
      "10 /\n"                      // Card 9.3
      "0 /\n"                       // Card 9.4
      "0 /\n"                       // Card10
};
SCENARIO( "Parsing valid GROUPR input" ){
  WHEN( "reading in a very generic input" ){
    std::string input{
    };
    iRecordStream<char> iss( std::istringstream(
      sCard1
      + "125 2 0 2 4 1 1 1 /\n"         // Card2
      + "'" + sCard3 + "' /\n"
      + sCard4
      + sCard5
      + sCard9_10
    ) );

    GROUPR groupr( iss );

    THEN( "the Card1 input values can be verified" ){
      REQUIRE( -30 == groupr.card1.nendf.value );
      REQUIRE( -32 == groupr.card1.npend.value );
      REQUIRE(   0 == groupr.card1.ngout1.value );
      REQUIRE( -34 == groupr.card1.ngout2.value );
    }
    THEN( "the Card2 input values can be verified" ){
      REQUIRE( 125 == groupr.card2.matb.value );
      REQUIRE( 2 == groupr.card2.ign.value );
      REQUIRE( 0 == groupr.card2.igg.value );
      REQUIRE( 2 == groupr.card2.iwt.value );
      REQUIRE( 4 == groupr.card2.lord.value );
      REQUIRE( 1 == groupr.card2.ntemp.value );
      REQUIRE( 1 == groupr.card2.nsigz.value );
      REQUIRE( 1 == groupr.card2.iprint.value );
    }
    THEN( "the Card3 input values can be verified" ){
      REQUIRE( sCard3 == groupr.card3.title.value );
    }
    THEN( "the Card4 input values can be verified" ){
      REQUIRE( 293.6*dimwits::kelvin == groupr.card4.temp.value[0] );
    }
    THEN( "the Card5 input values can be verified" ){
      REQUIRE( 1E-10*dimwits::barn == groupr.card5.sigz.value[0] );
    }
    THEN( "the Card9 input values can be verified" ){

      REQUIRE( 4 == (*groupr.card9List).size() );
      int i;
      { i = 0;
        REQUIRE( 3 == (*groupr.card9List)[i].mfd.value );
        REQUIRE( 18 == (*groupr.card9List)[i].mtd.value );
        REQUIRE( "MF3 MT18" == (*groupr.card9List)[i].mtname.value );
      }
      { i = 1;
        REQUIRE( 3 == (*groupr.card9List)[i].mfd.value );
        REQUIRE( 102 == (*groupr.card9List)[i].mtd.value );
        REQUIRE( "MF3 MT102" == (*groupr.card9List)[i].mtname.value );
      }
      { i = 2;
        REQUIRE( 10 == (*groupr.card9List)[i].mfd.value );
        REQUIRE( 0 == (*groupr.card9List)[i].mtd.value );
        REQUIRE( "" == (*groupr.card9List)[i].mtname.value );
      }
      { i = 3;
        REQUIRE( 0 == (*groupr.card9List)[i].mfd.value );
        REQUIRE( 0 == (*groupr.card9List)[i].mtd.value );
        REQUIRE( "" == (*groupr.card9List)[i].mtname.value );
      }
    }
    THEN( "the Card10 input values can be verified" ){
      REQUIRE( 1 == (*groupr.card10List).size() );
      REQUIRE( 0 == (*groupr.card10List)[0].matd.value );
    }
  }
}

SCENARIO( "Parsing invalid GROUPR input" ){
  WHEN( "No terminating mfd=0" ){
  }
  WHEN( "No terminating matd=0" ){
  }
}
