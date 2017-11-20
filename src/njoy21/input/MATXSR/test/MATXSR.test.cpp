#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "MATXSR",
          "[MATXSR]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      std::string in1{
      "0 33 35 /\n"
      "1 't2lanl njoy' /\n"
      "1 1 1 2 /\n"
      "'12-group photon interaction library' /\n"
      "'g' /\n"
      "12 /\n"
      "'gscat'/\n"
      "1 /\n"
      "1 /\n"
      "'h' 1 1 /\n"
      "'u' 92 92 /\n"};

      iRecordStream<char> iss( std::istringstream( in1 ) );

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
                 matxsr.card4.hsetid.value );

        REQUIRE( "g" == matxsr.card5.hpart.value );

        REQUIRE( 12 == matxsr.card6.ngrp.value );

        REQUIRE( "gscat" == matxsr.card7.htype.value );

        REQUIRE( 1 == matxsr.card8.jinp.value );

        REQUIRE( 1 == matxsr.card9.joutp.value );

        REQUIRE( "h" == matxsr.card10List.at(0).hmat.value );
        REQUIRE( 1 == matxsr.card10List.at(0).matno.value );
        REQUIRE( 1 == matxsr.card10List.at(0).matgg.value );

        REQUIRE( "u" == matxsr.card10List.at(1).hmat.value );
        REQUIRE( 92 == matxsr.card10List.at(1).matno.value );
        REQUIRE( 92 == matxsr.card10List.at(1).matgg.value );
      }
    }
  } // GIVEN
} // SCENARIO
