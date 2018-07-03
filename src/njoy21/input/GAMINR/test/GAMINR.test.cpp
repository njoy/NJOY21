#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

std::string sCard1( "-30 -32 0 -34 /\n" );
std::string sCard3( "GAMINR Card4 title for testing" );
std::string sCard6_7{
      "3 18 'MF3 MT18' /\n"      // Card 6.1
      "3 102 'MF3 MT102' /\n"    // Card 6.2
      "10 18 'Test3' /\n"        // Card 6.3
      "0 /\n"                    // Card 6.4
      "9235 /\n"                 // Card7
      "3 18 'MF3 MT18' /\n"      // Card 6.5
      "0 /\n"                    // Card 6.6
      "0 /\n"                    // Card7
};


SCENARIO( "Parsing valid GAMINR input" ){
  WHEN( "reading in a very generic input" ){
    iRecordStream<char> iss( std::istringstream(
      sCard1
      + "100 7 3 4 0/\n"         // Card2
      + "'" + sCard3 + "' /\n"
      + sCard6_7
    ) );

    GAMINR gaminr( iss );

    THEN( "the Card1 input values can be verified" ){
      REQUIRE( -30 == gaminr.card1.nendf.value );
      REQUIRE( -32 == gaminr.card1.npend.value );
      REQUIRE(   0 == gaminr.card1.ngam1.value );
      REQUIRE( -34 == gaminr.card1.ngam2.value );
    }
    THEN( "the Card2 input values can be verified" ){
      REQUIRE( 100 == gaminr.card2.matb.value );
      REQUIRE( 7 == gaminr.card2.igg.value );
      REQUIRE( 3 == gaminr.card2.iwt.value );
      REQUIRE( 4 == gaminr.card2.lord.value );
      REQUIRE( 0 == gaminr.card2.iprint.value );
    }
    THEN( "the Card3 input values can be verified" ){
      REQUIRE( sCard3 == gaminr.card3.title.value );
    }

    THEN( "the Card4 optional must be empty (i.e., not exist )" ){
      REQUIRE( std::nullopt == gaminr.card4 );
    }

    THEN( "the Card5 optional must be empty (i.e., not exist )" ){
      REQUIRE( std::nullopt == gaminr.card5 );
    }

    THEN( "the material input values can be verified" ){

      REQUIRE( 2 == gaminr.materials.size() );
      REQUIRE( 3 == gaminr.materials.at(0).card6.size() );
      REQUIRE( 1 == gaminr.materials.at(1).card6.size() );
      int i;
      { i = 0;
        REQUIRE( 3 == gaminr.materials.at(0).card6.at(i).mfd.value );
        REQUIRE( 18 == gaminr.materials.at(0).card6.at(i).rest->first.value );
        REQUIRE( "MF3 MT18" ==
                        gaminr.materials.at(0).card6.at(i).rest->second.value );
      }
      { i = 1;
        REQUIRE( 3 == gaminr.materials.at(0).card6.at(i).mfd.value );
        REQUIRE( 102 == gaminr.materials.at(0).card6.at(i).rest->first.value );
        REQUIRE( "MF3 MT102" ==
                        gaminr.materials.at(0).card6.at(i).rest->second.value );
      }
      { i = 2;
        REQUIRE( 10 == gaminr.materials.at(0).card6.at(i).mfd.value );
        REQUIRE( 18 == gaminr.materials.at(0).card6.at(i).rest->first.value );
        REQUIRE( "Test3" ==
                        gaminr.materials.at(0).card6.at(i).rest->second.value );
      }

      REQUIRE( 9235 == gaminr.materials.at(0).card7.matd.value );

      { i = 0;
        REQUIRE( 3 == gaminr.materials.at(1).card6.at(i).mfd.value );
        REQUIRE( 18 == gaminr.materials.at(1).card6.at(i).rest->first.value );
        REQUIRE( "MF3 MT18" ==
                        gaminr.materials.at(1).card6.at(i).rest->second.value );
      }

      REQUIRE( 0 == gaminr.materials.at(1).card7.matd.value );
    }
  }

  WHEN( "reading in a more complicated input, igg=1, iwt=-1" ){
    iRecordStream<char> iss( std::istringstream(
      sCard1
      + "125 1 1 4 0 /\n"      // Card2 -> igg=1,iwt=1,lord=4,iprint=0
      + "'" + sCard3 + "' /\n" // Card3
      + "5 1 2 3 4 5 6 /\n"    // Card4
      + "0. 0. 0 0 1 6\n"      // Card5
      + "6 5\n"
      + "1.00000E-05 8.00000E-20 1.00000E+03 9.13415E-10 1.00000E+04 6.13955E-08 \n"
      + "1.00925E+04 6.17490E-08 1.01859E+04 6.09190E-08 1.02802E+04 6.19874E-08 /\n"
      + sCard6_7
    ) );

    GAMINR gaminr( iss );

    THEN( "the Card1 input values can be verified" ){
      REQUIRE( -30 == gaminr.card1.nendf.value );
      REQUIRE( -32 == gaminr.card1.npend.value );
      REQUIRE(   0 == gaminr.card1.ngam1.value );
      REQUIRE( -34 == gaminr.card1.ngam2.value );
    }
    THEN( "the Card2 input values can be verified" ){
      REQUIRE( 125 == gaminr.card2.matb.value );
      REQUIRE( 1 == gaminr.card2.igg.value );
      REQUIRE( 1 == gaminr.card2.iwt.value );
      REQUIRE( 4 == gaminr.card2.lord.value );
      REQUIRE( 0 == gaminr.card2.iprint.value );
    }

    THEN( "the material input values can be verified" ){

      REQUIRE( 2 == gaminr.materials.size() );
      REQUIRE( 3 == gaminr.materials.at(0).card6.size() );
      REQUIRE( 1 == gaminr.materials.at(1).card6.size() );
      int i;
      { i = 0;
        REQUIRE( 3 == gaminr.materials.at(0).card6.at(i).mfd.value );
        REQUIRE( 18 == gaminr.materials.at(0).card6.at(i).rest->first.value );
        REQUIRE( "MF3 MT18" ==
                        gaminr.materials.at(0).card6.at(i).rest->second.value );
      }
      { i = 1;
        REQUIRE( 3 == gaminr.materials.at(0).card6.at(i).mfd.value );
        REQUIRE( 102 == gaminr.materials.at(0).card6.at(i).rest->first.value );
        REQUIRE( "MF3 MT102" ==
                        gaminr.materials.at(0).card6.at(i).rest->second.value );
      }
      { i = 2;
        REQUIRE( 10 == gaminr.materials.at(0).card6.at(i).mfd.value );
        REQUIRE( 18 == gaminr.materials.at(0).card6.at(i).rest->first.value );
        REQUIRE( "Test3" ==
                        gaminr.materials.at(0).card6.at(i).rest->second.value );
      }

      REQUIRE( 9235 == gaminr.materials.at(0).card7.matd.value );

      { i = 0;
        REQUIRE( 3 == gaminr.materials.at(1).card6.at(i).mfd.value );
        REQUIRE( 18 == gaminr.materials.at(1).card6.at(i).rest->first.value );
        REQUIRE( "MF3 MT18" ==
                        gaminr.materials.at(1).card6.at(i).rest->second.value );
      }

      REQUIRE( 0 == gaminr.materials.at(1).card7.matd.value );
    }

    THEN( "the Card4 input values can be verified" ){
      auto card4 = (*gaminr.card4);
      REQUIRE( 5 == card4.ngg.value );
      REQUIRE( 6 == card4.egg.value.size() );
      REQUIRE( 1*dimwits::electronVolt == card4.egg.value[0] );
      REQUIRE( 2*dimwits::electronVolt == card4.egg.value[1] );
      REQUIRE( 3*dimwits::electronVolt == card4.egg.value[2] );
      REQUIRE( 4*dimwits::electronVolt == card4.egg.value[3] );
      REQUIRE( 5*dimwits::electronVolt == card4.egg.value[4] );
      REQUIRE( 6*dimwits::electronVolt == card4.egg.value[5] );
    }
    THEN( "the card5 values can be verified" ){
      auto card5 = (*gaminr.card5);
      REQUIRE( 1E-5        == card5.wght.value.x()[0] );
      REQUIRE( 1E3         == card5.wght.value.x()[1] );
      REQUIRE( 1E4         == card5.wght.value.x()[2] );
      REQUIRE( 1.00925E4   == card5.wght.value.x()[3] );
      REQUIRE( 1.01859E4   == card5.wght.value.x()[4] );
      REQUIRE( 1.02802E4   == card5.wght.value.x()[5] );

      REQUIRE( 8.0E-20     == card5.wght.value.y()[0] );
      REQUIRE( 9.13415E-10 == card5.wght.value.y()[1] );
      REQUIRE( 6.13955E-8  == card5.wght.value.y()[2] );
      REQUIRE( 6.17490E-8  == card5.wght.value.y()[3] );
      REQUIRE( 6.09190E-8  == card5.wght.value.y()[4] );
      REQUIRE( 6.19874E-8  == card5.wght.value.y()[5] );
    }
  }
}

SCENARIO( "Parsing invalid GAMINR input" ){
  WHEN( "too many gamm groups" ){
    iRecordStream<char> iss( std::istringstream(
      sCard1
      + "125 1 2 4 1 /\n"         // Card2
      + "'" + sCard3 + "' /\n"
      + "4 1 2 3 4 5 6/\n"       // Card4
      + sCard6_7
    ) );

    THEN( "an exception is thrown" ){
      REQUIRE_THROWS( GAMINR( iss ) );
    }
  }
  WHEN( "too few gamma groups" ){
    iRecordStream<char> iss( std::istringstream(
      sCard1
      + "125 1 2 4 1 /\n"         // Card2
      + "'" + sCard3 + "' /\n"
      + "4 1 2 3 4 /\n"       // Card4
      + sCard6_7
    ) );

    THEN( "an exception is thrown" ){
      REQUIRE_THROWS( GAMINR( iss ) );
    }
  }
  WHEN( "No terminating mfd=0" ){
    iRecordStream<char> iss( std::istringstream(
      sCard1
      + "125 0 2 4 1 /\n"         // Card2
      + "'" + sCard3 + "' /\n"
      "3 18 'MF3 MT18' /\n"         // Card 6.1
      "3 102 'MF3 MT102' /\n"       // Card 6.2
      "10 /\n"                      // Card 6.3
      //"0 /\n"                       // Card 6.4
      "9235 /\n"                       // Card7
      "3 18 'MF3 MT18' /\n"         // Card 6.5
      "0 /\n"                       // Card7
    ) );

    THEN( "an exception is thrown" ){
      REQUIRE_THROWS( GAMINR( iss ) );
    }
  }
  WHEN( "No terminating matd=0" ){
    iRecordStream<char> iss( std::istringstream(
      sCard1
      + "125 0 2 4 1 /\n"         // Card2
      + "'" + sCard3 + "' /\n"
      "3 18 'MF3 MT18' /\n"         // Card 6.1
      "3 102 'MF3 MT102' /\n"       // Card 6.2
      "10 /\n"                      // Card 6.3
      "0 /\n"                       // Card 6.4
      "9235 /\n"                       // Card7
      "3 18 'MF3 MT18' /\n"         // Card 6.5
      //"0 /\n"                       // Card7
    ) );

    THEN( "an exception is thrown" ){
      REQUIRE_THROWS( GAMINR( iss ) );
    }
  }
}
