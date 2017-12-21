#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "MATXSR", "[MATXSR]" ){

  std::string sCard1( "0 33 35 /" );
  std::string sCard2( "1 't2lanl njoy' /" );
  std::string sCard3( "1 1 1 2 /" );
  std::string sCard4( "12-group photon interaction library" );
  std::string sCard5( "g" );
  std::string sCard6( " 12 /" );
  std::string sCard7( "gscat" );
  std::string sCard8( " 1 /" );
  std::string sCard9( " 1 /" );
  std::string sCard10_1( " 'h' 1 1 /" );
  std::string sCard10_2( " 'u' 92 92 /" );
  GIVEN( "valid inputs" ){
    WHEN( "the example from NJOY2016 test 3 is used" ){
      iRecordStream<char> iss( std::istringstream(
        sCard1 + '\n'
      + sCard2 + '\n'
      + sCard3 + '\n'
      + "'" + sCard4 + "' /\n"
      + "'" + sCard5 + "' /\n"
      + sCard6 + '\n'
      + "'" + sCard7 + "' /\n"
      + sCard8 + '\n'
      + sCard9 + '\n'
      + sCard10_1 + '\n'
      + sCard10_2 ) );

      MATXSR matxsr( iss );
      THEN( "the values can be verified" ){
        REQUIRE( 0 == matxsr.card1.ngen1.value );
        REQUIRE( 33 == matxsr.card1.ngen2.value );
        REQUIRE( 35 == matxsr.card1.nmatx.value );

        REQUIRE( 1 == matxsr.card2.ivers.value );
        REQUIRE( "t2lanl njoy" == matxsr.card2.huse.value );

        REQUIRE( 1 == matxsr.card3.npart.value );
        REQUIRE( 1 == matxsr.card3.ntype.value );
        REQUIRE( 1 == matxsr.card3.nholl.value );
        REQUIRE( 2 == matxsr.card3.nmat.value );

        REQUIRE( "12-group photon interaction library" ==
                 matxsr.card4List.at(0).hsetid.value );

        REQUIRE( "g" == matxsr.card5.hpartList.value.at(0) );

        REQUIRE( 12 == matxsr.card6.ngrpList.value.at(0) );

        REQUIRE( "gscat" == matxsr.card7.htypeList.value.at(0) );

        REQUIRE( 1 == matxsr.card8.jinpList.value.at(0) );

        REQUIRE( 1 == matxsr.card9.joutpList.value.at(0) );

        REQUIRE( "h" == matxsr.card10List.at(0).hmat.value );
        REQUIRE( 1 == matxsr.card10List.at(0).matno.value );
        REQUIRE( 1 == matxsr.card10List.at(0).matgg.value );

        REQUIRE( "u" == matxsr.card10List.at(1).hmat.value );
        REQUIRE( 92 == matxsr.card10List.at(1).matno.value );
        REQUIRE( 92 == matxsr.card10List.at(1).matgg.value );
      }
    }

    WHEN( "a more complex example is used" ){
      std::string tCard3( "3 4 3 5 /" );
      std::string tCard4_1( "12-group photon interaction library" );
      std::string tCard4_2( "24-group neutron library" );
      std::string tCard4_3( "35-group proton interaction library" );
      std::string tCard5_1( "g" );
      std::string tCard5_2( "n" );
      std::string tCard5_3( "p" );
      std::string tCard6_1( " 12" );
      std::string tCard6_2( " 24" );
      std::string tCard6_3( " 35" );
      std::string tCard7_1( "ng" );
      std::string tCard8_1( " 2" );
      std::string tCard9_1( " 1" );
      std::string tCard7_2( "pn" );
      std::string tCard8_2( " 3" );
      std::string tCard9_2( " 2" );
      std::string tCard7_3( "nscat" );
      std::string tCard8_3( " 2" );
      std::string tCard9_3( " 2" );
      std::string tCard7_4( "gscat" );
      std::string tCard8_4( " 1 " );
      std::string tCard9_4( " 1 " );
      std::string tCard10_1( " 'h' 1 1 /" );
      std::string tCard10_2( " 'o' 8 8 /" );
      std::string tCard10_3( " 'u' 92 92 /" );
      std::string tCard10_4( " 'np' 93 93 /" );
      std::string tCard10_5( " 'pu' 94 94 /" );
      iRecordStream<char> iss( std::istringstream(
        sCard1 + "\n"
      + sCard2 + "\n"
      + tCard3 + "\n"
      + "'" + tCard4_1 + "' /\n"
      + "'" + tCard4_2 + "' /\n"
      + "'" + tCard4_3 + "' /\n"
      + "'" + tCard5_1 + "' "
      + "'" + tCard5_2 + "' "
      + "'" + tCard5_3 + "' /\n"
      + tCard6_1 + " "
      + tCard6_2 + " "
      + tCard6_3 + " /\n"
      + "'" + tCard7_1 + "' "
      + "'" + tCard7_2 + "' "
      + "'" + tCard7_3 + "' "
      + "'" + tCard7_4 + "' /\n"
      + tCard8_1 + " "
      + tCard8_2 + " "
      + tCard8_3 + " "
      + tCard8_4 + " /\n"
      + tCard9_1 + " "
      + tCard9_2 + " "
      + tCard9_3 + " "
      + tCard9_4 + " /\n"
      + tCard10_1 + '\n'
      + tCard10_2 + '\n'
      + tCard10_3 + '\n'
      + tCard10_4 + '\n'
      + tCard10_5 + '\n' ) );

      MATXSR matxsr( iss );
      THEN( "the values can be verified" ){
        REQUIRE( 0 == matxsr.card1.ngen1.value );
        REQUIRE( 33 == matxsr.card1.ngen2.value );
        REQUIRE( 35 == matxsr.card1.nmatx.value );

        REQUIRE( 1 == matxsr.card2.ivers.value );
        REQUIRE( "t2lanl njoy" == matxsr.card2.huse.value );

        REQUIRE( 3 == matxsr.card3.npart.value );
        REQUIRE( 4 == matxsr.card3.ntype.value );
        REQUIRE( 3 == matxsr.card3.nholl.value );
        REQUIRE( 5 == matxsr.card3.nmat.value );

        REQUIRE( tCard4_1 == matxsr.card4List.at(0).hsetid.value );
        REQUIRE( tCard4_2 == matxsr.card4List.at(1).hsetid.value );
        REQUIRE( tCard4_3 == matxsr.card4List.at(2).hsetid.value );

        REQUIRE( "g" == matxsr.card5.hpartList.value.at(0) );
        REQUIRE( "n" == matxsr.card5.hpartList.value.at(1) );
        REQUIRE( "p" == matxsr.card5.hpartList.value.at(2) );

        REQUIRE( 12 == matxsr.card6.ngrpList.value.at(0) );
        REQUIRE( 24 == matxsr.card6.ngrpList.value.at(1) );
        REQUIRE( 35 == matxsr.card6.ngrpList.value.at(2) );

        REQUIRE( "ng" == matxsr.card7.htypeList.value.at(0) );
        REQUIRE( "pn" == matxsr.card7.htypeList.value.at(1) );
        REQUIRE( "nscat" == matxsr.card7.htypeList.value.at(2) );
        REQUIRE( "gscat" == matxsr.card7.htypeList.value.at(3) );

        REQUIRE( 2 == matxsr.card8.jinpList.value.at(0) );
        REQUIRE( 3 == matxsr.card8.jinpList.value.at(1) );
        REQUIRE( 2 == matxsr.card8.jinpList.value.at(2) );
        REQUIRE( 1 == matxsr.card8.jinpList.value.at(3) );

        REQUIRE( 1 == matxsr.card9.joutpList.value.at(0) );
        REQUIRE( 2 == matxsr.card9.joutpList.value.at(1) );
        REQUIRE( 2 == matxsr.card9.joutpList.value.at(2) );
        REQUIRE( 1 == matxsr.card9.joutpList.value.at(3) );

        REQUIRE( "h" == matxsr.card10List.at(0).hmat.value );
        REQUIRE( 1 == matxsr.card10List.at(0).matno.value );
        REQUIRE( 1 == matxsr.card10List.at(0).matgg.value );

        REQUIRE( "o" == matxsr.card10List.at(1).hmat.value );
        REQUIRE( 8 == matxsr.card10List.at(1).matno.value );
        REQUIRE( 8 == matxsr.card10List.at(1).matgg.value );

        REQUIRE( "u" == matxsr.card10List.at(2).hmat.value );
        REQUIRE( 92 == matxsr.card10List.at(2).matno.value );
        REQUIRE( 92 == matxsr.card10List.at(2).matgg.value );

        REQUIRE( "np" == matxsr.card10List.at(3).hmat.value );
        REQUIRE( 93 == matxsr.card10List.at(3).matno.value );
        REQUIRE( 93 == matxsr.card10List.at(3).matgg.value );

        REQUIRE( "pu" == matxsr.card10List.at(4).hmat.value );
        REQUIRE( 94 == matxsr.card10List.at(4).matno.value );
        REQUIRE( 94 == matxsr.card10List.at(4).matgg.value );
      }
    }
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "too many card4s are given" ){
      iRecordStream<char> iss( std::istringstream(
        sCard1 + '\n'
      + sCard2 + '\n'
      + sCard3 + '\n'
      + "'" + sCard4 + "' /\n"
      + "'" + sCard4 + "' /\n"
      + "'" + sCard5 + "' /\n"
      + sCard6 + '\n'
      + "'" + sCard7 + "' /\n"
      + sCard8 + '\n'
      + sCard9 + '\n'
      + sCard10_1 + '\n'
      + sCard10_2 ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( MATXSR( iss ) );
      }
    }

    WHEN( "too few card9s are given" ){
      iRecordStream<char> iss( std::istringstream(
        sCard1 + '\n'
      + sCard2 + '\n'
      + sCard3 + '\n'
      + "'" + sCard4 + "' /\n"
      + "'" + sCard5 + "' /\n"
      + sCard6 + '\n'
      + "'" + sCard7 + "' /\n"
      + sCard8 + '\n'
      + sCard10_1 + '\n'
      + sCard10_1 + '\n'
      + sCard10_2 ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( MATXSR( iss ) );
      }
    }

    WHEN( "too few card10s are given" ){
      iRecordStream<char> iss( std::istringstream(
        sCard1 + '\n'
      + sCard2 + '\n'
      + sCard3 + '\n'
      + "'" + sCard4 + "' /\n"
      + "'" + sCard5 + "' /\n"
      + sCard6 + '\n'
      + "'" + sCard7 + "' /\n"
      + sCard8 + '\n'
      + sCard9 + '\n'
      + sCard10_2 ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( MATXSR( iss ) );
      }
    }
  } // GIVEN
} // SCENARIO
