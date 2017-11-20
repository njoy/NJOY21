#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "MATXSR",
          "[MATXSR]" ){

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

        REQUIRE( "g" == matxsr.card56List.at(0).first.hpart.value );

        REQUIRE( 12 == matxsr.card56List.at(0).second.ngrp.value );

        REQUIRE( "gscat" == std::get<MATXSR::Card7>(
                               matxsr.card789List.at(0)).htype.value );

        REQUIRE( 1 == std::get<MATXSR::Card8>(
                               matxsr.card789List.at(0)).jinp.value );

        REQUIRE( 1 == std::get<MATXSR::Card9>(
                               matxsr.card789List.at(0)).joutp.value );

        REQUIRE( "h" == matxsr.card10List.at(0).hmat.value );
        REQUIRE( 1 == matxsr.card10List.at(0).matno.value );
        REQUIRE( 1 == matxsr.card10List.at(0).matgg.value );

        REQUIRE( "u" == matxsr.card10List.at(1).hmat.value );
        REQUIRE( 92 == matxsr.card10List.at(1).matno.value );
        REQUIRE( 92 == matxsr.card10List.at(1).matgg.value );
      }
    }

    WHEN( "a more complex example is used" ){
      std::string tCard3( "3 4 2 5 /" );
      std::string tCard4_1( "12-group photon interaction library, 24-group neutron library" );
      std::string tCard4_2( "35-group proton interaction library" );
      std::string tCard5_1( "g" );
      std::string tCard5_2( "n" );
      std::string tCard5_3( "p" );
      std::string tCard6_1( " 12 /" );
      std::string tCard6_2( " 24 /" );
      std::string tCard6_3( " 35 /" );
      std::string tCard7_1( "ng" );
      std::string tCard8_1( " 2 /" );
      std::string tCard9_1( " 1 /" );
      std::string tCard7_2( "pn" );
      std::string tCard8_2( " 3 /" );
      std::string tCard9_2( " 2 /" );
      std::string tCard7_3( "nscat" );
      std::string tCard8_3( " 2 /" );
      std::string tCard9_3( " 2 /" );
      std::string tCard7_4( "gscat" );
      std::string tCard8_4( " 1 /" );
      std::string tCard9_4( " 1 /" );
      std::string tCard10_1( " 'h' 1 1 /" );
      std::string tCard10_2( " 'o' 8 8 /" );
      std::string tCard10_3( " 'u' 92 92 /" );
      std::string tCard10_4( " 'np' 93 93 /" );
      std::string tCard10_5( " 'pu' 94 94 /" );
      iRecordStream<char> iss( std::istringstream(
        sCard1 + '\n'
      + sCard2 + '\n'
      + tCard3 + '\n'
      + "'" + tCard4_1 + "' /\n"
      + "'" + tCard4_2 + "' /\n"
      + "'" + tCard5_1 + "' /\n"
      + "'" + tCard5_2 + "' /\n"
      + "'" + tCard5_3 + "' /\n"
      + tCard6_1 + '\n'
      + tCard6_2 + '\n'
      + tCard6_3 + '\n'
      + "'" + tCard7_1 + "' /\n"
      + "'" + tCard7_2 + "' /\n"
      + "'" + tCard7_3 + "' /\n"
      + "'" + tCard7_4 + "' /\n"
      + tCard8_1 + '\n'
      + tCard8_2 + '\n'
      + tCard8_3 + '\n'
      + tCard8_4 + '\n'
      + tCard9_1 + '\n'
      + tCard9_2 + '\n'
      + tCard9_3 + '\n'
      + tCard9_4 + '\n'
      + tCard10_1 + '\n'
      + tCard10_2 + '\n'
      + tCard10_3 + '\n'
      + tCard10_4 + '\n'
      + tCard10_5 ) );

      MATXSR matxsr( iss );
      THEN( "the values can be verified" ){
        REQUIRE( 0 == matxsr.card1.ngen1.value );
        REQUIRE( 33 == matxsr.card1.ngen2.value );
        REQUIRE( 35 == matxsr.card1.nmatx.value );

        REQUIRE( 1 == matxsr.card2.ivers.value );
        REQUIRE( "t2lanl njoy" == matxsr.card2.huse.value );

        REQUIRE( 3 == matxsr.card3.npart.value );
        REQUIRE( 4 == matxsr.card3.ntype.value );
        REQUIRE( 2 == matxsr.card3.nholl.value );
        REQUIRE( 5 == matxsr.card3.nmat.value );

        REQUIRE( tCard4_1 == matxsr.card4List.at(0).hsetid.value );
        REQUIRE( tCard4_2 == matxsr.card4List.at(1).hsetid.value );

        REQUIRE( "g" == matxsr.card56List.at(0).first.hpart.value );
        REQUIRE( "n" == matxsr.card56List.at(1).first.hpart.value );
        REQUIRE( "p" == matxsr.card56List.at(2).first.hpart.value );

        REQUIRE( 12 == matxsr.card56List.at(0).second.ngrp.value );
        REQUIRE( 24 == matxsr.card56List.at(1).second.ngrp.value );
        REQUIRE( 35 == matxsr.card56List.at(2).second.ngrp.value );

        REQUIRE( "ng" == std::get<MATXSR::Card7>(
                               matxsr.card789List.at(0)).htype.value );

        REQUIRE( 2 == std::get<MATXSR::Card8>(
                               matxsr.card789List.at(0)).jinp.value );

        REQUIRE( 1 == std::get<MATXSR::Card9>(
                               matxsr.card789List.at(0)).joutp.value );

        REQUIRE( "pn" == std::get<MATXSR::Card7>(
                               matxsr.card789List.at(1)).htype.value );
        REQUIRE( 3 == std::get<MATXSR::Card8>(
                               matxsr.card789List.at(1)).jinp.value );
        REQUIRE( 2 == std::get<MATXSR::Card9>(
                               matxsr.card789List.at(1)).joutp.value );

        REQUIRE( "nscat" == std::get<MATXSR::Card7>(
                               matxsr.card789List.at(2)).htype.value );
        REQUIRE( 2 == std::get<MATXSR::Card8>(
                               matxsr.card789List.at(2)).jinp.value );
        REQUIRE( 2 == std::get<MATXSR::Card9>(
                               matxsr.card789List.at(2)).joutp.value );

        REQUIRE( "gscat" == std::get<MATXSR::Card7>(
                               matxsr.card789List.at(3)).htype.value );
        REQUIRE( 1 == std::get<MATXSR::Card8>(
                               matxsr.card789List.at(3)).jinp.value );
        REQUIRE( 1 == std::get<MATXSR::Card9>(
                               matxsr.card789List.at(3)).joutp.value );

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

    WHEN( "too many card10s are given" ){
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
