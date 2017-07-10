#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

std::string sCard1( "20 21 0 30 31 /\n" );
std::string sCard3( "Here is a descriptive character string for Card3.");

SCENARIO( "Parsing valid ACER input" ){
  WHEN( "processing a 'fast' data file, iopt=1" ){

    iRecordStream<char> iss( std::istringstream( 
            sCard1
            + "1 1 1 .80 0 /\n"       // Card2
            + "'" + sCard3 + "'/\n"   // Card3
            + " 1001 293.6 /\n"       // Card5
            + " 0 1 /\n"              // Card6
            + " -1 1E4 5 /\n"         // Card7
            ) );

    THEN( "the input values can be verified" ){
      ACER acer( iss );

      // Card1
      REQUIRE( 20 == acer.card1.nendf.value );
      REQUIRE( 21 == acer.card1.npend.value );
      REQUIRE(  0 == acer.card1.ngend.value );
      REQUIRE( 30 == acer.card1.nace.value );
      REQUIRE( 31 == acer.card1.ndir.value );
      // Card2
      REQUIRE(  1 == acer.card2.iopt.value );
      REQUIRE(  1 == acer.card2.iprint.value );
      REQUIRE(  1 == acer.card2.itype.value );
      REQUIRE( ".80" == acer.card2.suff.value );
      REQUIRE(  0 == acer.card2.nxtra.value );
      // Card3
      REQUIRE( sCard3 == acer.card3.hk.value );
      // Card5
      auto card5 = std::get<0>(*acer.fastCards);
      REQUIRE( 1001 == card5.matd.value );
      REQUIRE( 293.6*dimwits::kelvin == card5.tempd.value );
      // Card6
      auto card6 = std::get<1>(*acer.fastCards);
      REQUIRE( 0 == card6.newfor.value );
      REQUIRE( 1 == card6.iopp.value );
      // Card7
      auto card7 = std::get<2>(*acer.fastCards);
      REQUIRE( -1 == card7.thin1.value );
      REQUIRE( 1E4*dimwits::electronVolt == card7.thin2.value );
      REQUIRE( 5 == card7.thin3.value );

      REQUIRE( not acer.card4 );
      REQUIRE( not acer.thermalCards );
      REQUIRE( not acer.card10 );
      REQUIRE( not acer.card11 );
      REQUIRE( not acer.card12 );
    }
  }
  WHEN( "processing a 'thermal' data file, iopt=2" ){
    iRecordStream<char> iss( std::istringstream( 
            sCard1
            + "2 1 1 .80 2 /\n"                   // Card2
            + "'" + sCard3 + "'/\n"               // Card3
            + " 1001 0.99167 92235 233.02479 /\n" // Card4
            + " 1 293.6 'lwtr' /\n"               // Card8
            + " 1001 8016 9235 /\n"               // Card8a
            + " 1 80 231 0 1 10.1 2 /"            // Card9
            ) );

    THEN( "the input values can be verified" ){
      ACER acer( iss );

      // Card1
      REQUIRE( 20 == acer.card1.nendf.value );
      REQUIRE( 21 == acer.card1.npend.value );
      REQUIRE(  0 == acer.card1.ngend.value );
      REQUIRE( 30 == acer.card1.nace.value );
      REQUIRE( 31 == acer.card1.ndir.value );
      // Card2
      REQUIRE(  2 == acer.card2.iopt.value );
      REQUIRE(  1 == acer.card2.iprint.value );
      REQUIRE(  1 == acer.card2.itype.value );
      REQUIRE( ".80" == acer.card2.suff.value );
      REQUIRE(  2 == acer.card2.nxtra.value );
      // Card3
      REQUIRE( sCard3 == acer.card3.hk.value );
      // Card4
      auto values = acer.card4->izaw.value;
      REQUIRE( 1001 == values[0].first );
      REQUIRE( 0.99167 == values[0].second );
      REQUIRE( 92235 == values[1].first );
      REQUIRE( 233.02479 == values[1].second );
      // Card8
      auto card8 = std::get<0>(*acer.thermalCards);
      REQUIRE( 1 == card8.matd.value );
      REQUIRE( 293.6*dimwits::kelvin == card8.tempd.value );
      REQUIRE( "lwtr" == *card8.tname.value );
      // Card8a
      auto card8a = std::get<1>(*acer.thermalCards);
      REQUIRE( 1001 == card8a.iza01.value );
      REQUIRE( 8016 == card8a.iza02.value );
      REQUIRE( 9235 == card8a.iza03.value );
      // Card9
      auto card9 = std::get<2>(*acer.thermalCards);
      REQUIRE( 1 == card9.mti.value );
      REQUIRE( 80 == card9.nbint.value );
      REQUIRE( 231 == card9.mte.value );
      REQUIRE( 0 == card9.ielas.value );
      REQUIRE( 1 == card9.nmix.value );
      REQUIRE( 10.1*dimwits::electronVolt == card9.emax.value );
      REQUIRE( 2 == card9.iwt.value );

      REQUIRE( not acer.fastCards );
      REQUIRE( not acer.card10 );
      REQUIRE( not acer.card11 );
      REQUIRE( not acer.card12 );
    }
  }
  WHEN( "processing a 'dosimetry' data file, iopt=3" ){
    iRecordStream<char> iss( std::istringstream( 
            sCard1
            + "3 1 1 .80 0 /\n"                   // Card2
            + "'" + sCard3 + "'/\n"               // Card3
            + " 9235 600 /\n"                     // Card10
            ) );
    THEN( "the input values can be verified" ){
      ACER acer( iss );

      // Card1
      REQUIRE( 20 == acer.card1.nendf.value );
      REQUIRE( 21 == acer.card1.npend.value );
      REQUIRE(  0 == acer.card1.ngend.value );
      REQUIRE( 30 == acer.card1.nace.value );
      REQUIRE( 31 == acer.card1.ndir.value );
      // Card2
      REQUIRE(  3 == acer.card2.iopt.value );
      REQUIRE(  1 == acer.card2.iprint.value );
      REQUIRE(  1 == acer.card2.itype.value );
      REQUIRE( ".80" == acer.card2.suff.value );
      REQUIRE(  0 == acer.card2.nxtra.value );
      // Card3
      REQUIRE( sCard3 == acer.card3.hk.value );
      // Card10
      REQUIRE( 9235 == acer.card10->matd.value );
      REQUIRE( 600*dimwits::kelvin == acer.card10->tempd.value );

      REQUIRE( not acer.card4 );
      REQUIRE( not acer.fastCards );
      REQUIRE( not acer.thermalCards );
      REQUIRE( not acer.card11 );
      REQUIRE( not acer.card12 );
    }
  }
  WHEN( "processing a 'photo-atomic' data file, iopt=4" ){
    iRecordStream<char> iss( std::istringstream( 
            sCard1
            + "4 1 1 .80 0 /\n"                   // Card2
            + "'" + sCard3 + "'/\n"               // Card3
            + " 9235 /\n"                         // Card11
            ) );
    THEN( "the input values can be verified" ){
      ACER acer( iss );

      // Card1
      REQUIRE( 20 == acer.card1.nendf.value );
      REQUIRE( 21 == acer.card1.npend.value );
      REQUIRE(  0 == acer.card1.ngend.value );
      REQUIRE( 30 == acer.card1.nace.value );
      REQUIRE( 31 == acer.card1.ndir.value );
      // Card2
      REQUIRE(  4 == acer.card2.iopt.value );
      REQUIRE(  1 == acer.card2.iprint.value );
      REQUIRE(  1 == acer.card2.itype.value );
      REQUIRE( ".80" == acer.card2.suff.value );
      REQUIRE(  0 == acer.card2.nxtra.value );
      // Card3
      REQUIRE( sCard3 == acer.card3.hk.value );
      // Card11
      REQUIRE( 9235 == acer.card11->matd.value );

      REQUIRE( not acer.card4 );
      REQUIRE( not acer.fastCards );
      REQUIRE( not acer.thermalCards );
      REQUIRE( not acer.card10 );
      REQUIRE( not acer.card12 );
    }
  }
  WHEN( "processing a 'photo-nuclear' data file, iopt=5" ){
    iRecordStream<char> iss( std::istringstream( 
            sCard1
            + "5 1 1 .80 0 /\n"                   // Card2
            + "'" + sCard3 + "'/\n"               // Card3
            + " 9235 /\n"                         // Card12
            ) );
    THEN( "the input values can be verified" ){
      ACER acer( iss );

      // Card1
      REQUIRE( 20 == acer.card1.nendf.value );
      REQUIRE( 21 == acer.card1.npend.value );
      REQUIRE(  0 == acer.card1.ngend.value );
      REQUIRE( 30 == acer.card1.nace.value );
      REQUIRE( 31 == acer.card1.ndir.value );
      // Card2
      REQUIRE(  5 == acer.card2.iopt.value );
      REQUIRE(  1 == acer.card2.iprint.value );
      REQUIRE(  1 == acer.card2.itype.value );
      REQUIRE( ".80" == acer.card2.suff.value );
      REQUIRE(  0 == acer.card2.nxtra.value );
      // Card3
      REQUIRE( sCard3 == acer.card3.hk.value );
      // Card11
      REQUIRE( 9235 == acer.card12->matd.value );

      REQUIRE( not acer.card4 );
      REQUIRE( not acer.fastCards );
      REQUIRE( not acer.thermalCards );
      REQUIRE( not acer.card10 );
      REQUIRE( not acer.card11 );
    }
  }
  WHEN( "reading/checking type 1 ACE files" ){
    iRecordStream<char> iss( std::istringstream( 
            sCard1
            + "7 1 1 .80 0 /\n"                   // Card2
            + "'" + sCard3 + "'/\n"               // Card3
            ) );
    THEN( "the input values can be verified" ){
      ACER acer( iss );

      // Card1
      REQUIRE( 20 == acer.card1.nendf.value );
      REQUIRE( 21 == acer.card1.npend.value );
      REQUIRE(  0 == acer.card1.ngend.value );
      REQUIRE( 30 == acer.card1.nace.value );
      REQUIRE( 31 == acer.card1.ndir.value );
      // Card2
      REQUIRE(  7 == acer.card2.iopt.value );
      REQUIRE(  1 == acer.card2.iprint.value );
      REQUIRE(  1 == acer.card2.itype.value );
      REQUIRE( ".80" == acer.card2.suff.value );
      REQUIRE(  0 == acer.card2.nxtra.value );
      // Card3
      REQUIRE( sCard3 == acer.card3.hk.value );

      REQUIRE( not acer.card4 );
      REQUIRE( not acer.fastCards );
      REQUIRE( not acer.thermalCards );
      REQUIRE( not acer.card10 );
      REQUIRE( not acer.card11 );
      REQUIRE( not acer.card12 );
    }
  }
  WHEN( "reading/checking type 2 ACE files" ){
    iRecordStream<char> iss( std::istringstream( 
            sCard1
            + "8 1 2 .80 0 /\n"                   // Card2
            + "'" + sCard3 + "'/\n"               // Card3
            ) );
    THEN( "the input values can be verified" ){
      ACER acer( iss );

      // Card1
      REQUIRE( 20 == acer.card1.nendf.value );
      REQUIRE( 21 == acer.card1.npend.value );
      REQUIRE(  0 == acer.card1.ngend.value );
      REQUIRE( 30 == acer.card1.nace.value );
      REQUIRE( 31 == acer.card1.ndir.value );
      // Card2
      REQUIRE(  8 == acer.card2.iopt.value );
      REQUIRE(  1 == acer.card2.iprint.value );
      REQUIRE(  2 == acer.card2.itype.value );
      REQUIRE( ".80" == acer.card2.suff.value );
      REQUIRE(  0 == acer.card2.nxtra.value );
      // Card3
      REQUIRE( sCard3 == acer.card3.hk.value );

      REQUIRE( not acer.card4 );
      REQUIRE( not acer.fastCards );
      REQUIRE( not acer.thermalCards );
      REQUIRE( not acer.card10 );
      REQUIRE( not acer.card11 );
      REQUIRE( not acer.card12 );
    }
  }
}
SCENARIO( "Parsing invalid ACER input" ){
}
