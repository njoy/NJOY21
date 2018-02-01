#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "CCCCR",
          "[CCCCR]" ){
  GIVEN( "valid inputs" ){
    WHEN( "neither CISOTX nor CBRKXS are used" ){
      std::string inp(
 std::string( " 22 0 0 0 /\n" ) +
 std::string( " 0 /\n" ) +
 std::string( " /\n" ) +
 std::string( " 12 13 4 3 1 /\n" ) +
 std::string( " 'iso1' 'aiso1' 'ident1' 'hmat1' 1 1.1 /\n" ) +
 std::string( " 'iso2' 'aiso2' 'ident2' 'hmat2' 2 2.2 /\n" ) +
 std::string( " 'iso3' 'aiso3' 'ident3' 'hmat3' 3 3.3 /\n" ) +
 std::string( " 'iso4' 'aiso4' 'ident4' 'hmat4' 4 4.4 /" )
      );

      iRecordStream<char> iss{ std::istringstream{ inp } };

      THEN( "the values can be verified" ){
        CCCCR ccccr( iss );

        REQUIRE( 22 == ccccr.card1.nin.value );
        REQUIRE( 0 == ccccr.card1.nisot.value );
        REQUIRE( 0 == ccccr.card1.nbrks.value );
        REQUIRE( 0 == ccccr.card1.ndlay.value );

        REQUIRE( 0 == ccccr.card2.lprint.value );
        REQUIRE( 0 == ccccr.card2.ivers.value );
        REQUIRE( "" == ccccr.card2.huse.value );

        REQUIRE( "" == ccccr.card3.hsetid.value );

        REQUIRE( 12 == ccccr.card4.ngroup.value );
        REQUIRE( 13 == ccccr.card4.nggrup.value );
        REQUIRE( 4 == ccccr.card4.niso.value );
        REQUIRE( 3 == ccccr.card4.maxord.value );
        REQUIRE( 1 == ccccr.card4.ifopt.value );

        REQUIRE( "iso1" == ccccr.card5.at(0).hisnm.value );
        REQUIRE( "aiso1" == ccccr.card5.at(0).habsid.value );
        REQUIRE( "ident1" == ccccr.card5.at(0).hident.value );
        REQUIRE( "hmat1" == ccccr.card5.at(0).hmat.value );
        REQUIRE( 1 == ccccr.card5.at(0).imat.value );
        REQUIRE( Approx( 1.1 ) == ccccr.card5.at(0).xspo.value );

        REQUIRE( "iso2" == ccccr.card5.at(1).hisnm.value );
        REQUIRE( "aiso2" == ccccr.card5.at(1).habsid.value );
        REQUIRE( "ident2" == ccccr.card5.at(1).hident.value );
        REQUIRE( "hmat2" == ccccr.card5.at(1).hmat.value );
        REQUIRE( 2 == ccccr.card5.at(1).imat.value );
        REQUIRE( Approx( 2.2 ) == ccccr.card5.at(1).xspo.value );

        REQUIRE( "iso3" == ccccr.card5.at(2).hisnm.value );
        REQUIRE( "aiso3" == ccccr.card5.at(2).habsid.value );
        REQUIRE( "ident3" == ccccr.card5.at(2).hident.value );
        REQUIRE( "hmat3" == ccccr.card5.at(2).hmat.value );
        REQUIRE( 3 == ccccr.card5.at(2).imat.value );
        REQUIRE( Approx( 3.3 ) == ccccr.card5.at(2).xspo.value );

        REQUIRE( "iso4" == ccccr.card5.at(3).hisnm.value );
        REQUIRE( "aiso4" == ccccr.card5.at(3).habsid.value );
        REQUIRE( "ident4" == ccccr.card5.at(3).hident.value );
        REQUIRE( "hmat4" == ccccr.card5.at(3).hmat.value );
        REQUIRE( 4 == ccccr.card5.at(3).imat.value );
        REQUIRE( Approx( 4.4 ) == ccccr.card5.at(3).xspo.value );
      }
    } // WHEN

    WHEN( "CISOTX is used, but not CBRKXS" ){
      std::string inp(
 std::string( " 22 -23 0 0 /\n" ) +
 std::string( " 1 /\n" ) +
 std::string( " /\n" ) +
 std::string( " 12 13 4 3 1 /\n" ) +
 std::string( " 'iso1' 'aiso1' 'ident1' 'hmat1' 1 1.1 /\n" ) +
 std::string( " 'iso2' 'aiso2' 'ident2' 'hmat2' 2 2.2 /\n" ) +
 std::string( " 'iso3' 'aiso3' 'ident3' 'hmat3' 3 3.3 /\n" ) +
 std::string( " 'iso4' 'aiso4' 'ident4' 'hmat4' 4 4.4 /\n" ) +
 std::string( " 1 0 3 -1 /\n" ) +
 std::string( " 1 1.0 1.1 1.2 1.3 1.4 1.5 /\n" ) +
 std::string( " 2 2.0 2.1 2.2 2.3 2.4 2.5 /\n" ) +
 std::string( " 3 3.0 3.1 3.2 3.3 3.4 3.5 /\n" ) +
 std::string( " 4 4.0 4.1 4.2 4.3 4.4 4.5 /" )
      );

      iRecordStream<char> iss{ std::istringstream{ inp } };

      THEN( "the values can be verified" ){
        CCCCR ccccr( iss );

        REQUIRE( 22 == ccccr.card1.nin.value );
        REQUIRE( -23 == ccccr.card1.nisot.value );
        REQUIRE( 0 == ccccr.card1.nbrks.value );
        REQUIRE( 0 == ccccr.card1.ndlay.value );

        REQUIRE( 1 == ccccr.card2.lprint.value );
        REQUIRE( 0 == ccccr.card2.ivers.value );
        REQUIRE( "" == ccccr.card2.huse.value );

        REQUIRE( "" == ccccr.card3.hsetid.value );

        REQUIRE( 12 == ccccr.card4.ngroup.value );
        REQUIRE( 13 == ccccr.card4.nggrup.value );
        REQUIRE( 4 == ccccr.card4.niso.value );
        REQUIRE( 3 == ccccr.card4.maxord.value );
        REQUIRE( 1 == ccccr.card4.ifopt.value );

        REQUIRE( "iso1" == ccccr.card5.at(0).hisnm.value );
        REQUIRE( "aiso1" == ccccr.card5.at(0).habsid.value );
        REQUIRE( "ident1" == ccccr.card5.at(0).hident.value );
        REQUIRE( "hmat1" == ccccr.card5.at(0).hmat.value );
        REQUIRE( 1 == ccccr.card5.at(0).imat.value );
        REQUIRE( Approx( 1.1 ) == ccccr.card5.at(0).xspo.value );

        REQUIRE( "iso2" == ccccr.card5.at(1).hisnm.value );
        REQUIRE( "aiso2" == ccccr.card5.at(1).habsid.value );
        REQUIRE( "ident2" == ccccr.card5.at(1).hident.value );
        REQUIRE( "hmat2" == ccccr.card5.at(1).hmat.value );
        REQUIRE( 2 == ccccr.card5.at(1).imat.value );
        REQUIRE( Approx( 2.2 ) == ccccr.card5.at(1).xspo.value );

        REQUIRE( "iso3" == ccccr.card5.at(2).hisnm.value );
        REQUIRE( "aiso3" == ccccr.card5.at(2).habsid.value );
        REQUIRE( "ident3" == ccccr.card5.at(2).hident.value );
        REQUIRE( "hmat3" == ccccr.card5.at(2).hmat.value );
        REQUIRE( 3 == ccccr.card5.at(2).imat.value );
        REQUIRE( Approx( 3.3 ) == ccccr.card5.at(2).xspo.value );

        REQUIRE( "iso4" == ccccr.card5.at(3).hisnm.value );
        REQUIRE( "aiso4" == ccccr.card5.at(3).habsid.value );
        REQUIRE( "ident4" == ccccr.card5.at(3).hident.value );
        REQUIRE( "hmat4" == ccccr.card5.at(3).hmat.value );
        REQUIRE( 4 == ccccr.card5.at(3).imat.value );
        REQUIRE( Approx( 4.4 ) == ccccr.card5.at(3).xspo.value );
        
        REQUIRE( 1 == ccccr.cisotx->card1.nsblok.value );
        REQUIRE( 0 == ccccr.cisotx->card1.maxup.value );
        REQUIRE( 3 == ccccr.cisotx->card1.maxdn.value );
        REQUIRE( -1 == ccccr.cisotx->card1.ichix.value );

        REQUIRE( std::nullopt == ccccr.cisotx->card2 );
        REQUIRE( std::nullopt == ccccr.cisotx->card3 );

        for( int i = 0; i < 4; i++ ){
          REQUIRE( i+1 == ccccr.cisotx->card4.at(i).kbr.value );
          REQUIRE( Approx( i+1.0 ) == ccccr.cisotx->card4.at(i).amass.value );
          REQUIRE( Approx( i+1.1 ) == ccccr.cisotx->card4.at(i).efiss.value );
          REQUIRE( Approx( i+1.2 ) == ccccr.cisotx->card4.at(i).ecapt.value );
          REQUIRE( ( i + 1.3 )*dimwits::kelvin ==
                                         ccccr.cisotx->card4.at(i).temp.value );
          REQUIRE( Approx( i+1.4 ) == ccccr.cisotx->card4.at(i).sigpot.value );
          REQUIRE( Approx( i+1.5 ) == ccccr.cisotx->card4.at(i).adens.value );
        }
      }
    } // WHEN

    WHEN( "CBRKXS is used, but not CISOTX" ){
      std::string inp(
 std::string( " 22 0 -23 0 /\n" ) +
 std::string( " 0 /\n" ) +
 std::string( " /\n" ) +
 std::string( " 12 13 4 3 1 /\n" ) +
 std::string( " 'iso1' 'aiso1' 'ident1' 'hmat1' 1 1.1 /\n" ) +
 std::string( " 'iso2' 'aiso2' 'ident2' 'hmat2' 2 2.2 /\n" ) +
 std::string( " 'iso3' 'aiso3' 'ident3' 'hmat3' 3 3.3 /\n" ) +
 std::string( " 'iso4' 'aiso4' 'ident4' 'hmat4' 4 4.4 /\n" ) +
 std::string( " -12 -14 /" )
      );

      iRecordStream<char> iss{ std::istringstream{ inp } };

      THEN( "the values can be verified" ){
        CCCCR ccccr( iss );

        REQUIRE( 22 == ccccr.card1.nin.value );
        REQUIRE( 0 == ccccr.card1.nisot.value );
        REQUIRE( -23 == ccccr.card1.nbrks.value );
        REQUIRE( 0 == ccccr.card1.ndlay.value );

        REQUIRE( 0 == ccccr.card2.lprint.value );
        REQUIRE( 0 == ccccr.card2.ivers.value );
        REQUIRE( "" == ccccr.card2.huse.value );

        REQUIRE( "" == ccccr.card3.hsetid.value );

        REQUIRE( 12 == ccccr.card4.ngroup.value );
        REQUIRE( 13 == ccccr.card4.nggrup.value );
        REQUIRE( 4 == ccccr.card4.niso.value );
        REQUIRE( 3 == ccccr.card4.maxord.value );
        REQUIRE( 1 == ccccr.card4.ifopt.value );

        REQUIRE( "iso1" == ccccr.card5.at(0).hisnm.value );
        REQUIRE( "aiso1" == ccccr.card5.at(0).habsid.value );
        REQUIRE( "ident1" == ccccr.card5.at(0).hident.value );
        REQUIRE( "hmat1" == ccccr.card5.at(0).hmat.value );
        REQUIRE( 1 == ccccr.card5.at(0).imat.value );
        REQUIRE( Approx( 1.1 ) == ccccr.card5.at(0).xspo.value );

        REQUIRE( "iso2" == ccccr.card5.at(1).hisnm.value );
        REQUIRE( "aiso2" == ccccr.card5.at(1).habsid.value );
        REQUIRE( "ident2" == ccccr.card5.at(1).hident.value );
        REQUIRE( "hmat2" == ccccr.card5.at(1).hmat.value );
        REQUIRE( 2 == ccccr.card5.at(1).imat.value );
        REQUIRE( Approx( 2.2 ) == ccccr.card5.at(1).xspo.value );

        REQUIRE( "iso3" == ccccr.card5.at(2).hisnm.value );
        REQUIRE( "aiso3" == ccccr.card5.at(2).habsid.value );
        REQUIRE( "ident3" == ccccr.card5.at(2).hident.value );
        REQUIRE( "hmat3" == ccccr.card5.at(2).hmat.value );
        REQUIRE( 3 == ccccr.card5.at(2).imat.value );
        REQUIRE( Approx( 3.3 ) == ccccr.card5.at(2).xspo.value );

        REQUIRE( "iso4" == ccccr.card5.at(3).hisnm.value );
        REQUIRE( "aiso4" == ccccr.card5.at(3).habsid.value );
        REQUIRE( "ident4" == ccccr.card5.at(3).hident.value );
        REQUIRE( "hmat4" == ccccr.card5.at(3).hmat.value );
        REQUIRE( 4 == ccccr.card5.at(3).imat.value );
        REQUIRE( Approx( 4.4 ) == ccccr.card5.at(3).xspo.value );

        REQUIRE( -12 == ccccr.cbrkxs->card1.nti.value );
        REQUIRE( -14 == ccccr.cbrkxs->card1.nzi.value );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "CISOTX is expected, but not given" ){
      std::string inp(
 std::string( " 22 -23 0 0 /\n" ) +
 std::string( " 0 /\n" ) +
 std::string( " /\n" ) +
 std::string( " 12 13 4 3 1 /\n" ) +
 std::string( " 'iso1' 'aiso1' 'ident1' 'hmat1' 1 1.1 /\n" ) +
 std::string( " 'iso2' 'aiso2' 'ident2' 'hmat2' 2 2.2 /\n" ) +
 std::string( " 'iso3' 'aiso3' 'ident3' 'hmat3' 3 3.3 /\n" ) +
 std::string( " 'iso4' 'aiso4' 'ident4' 'hmat4' 4 4.4 /" )
      );

      iRecordStream<char> iss{ std::istringstream{ inp } };

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( CCCCR( iss ) );
      }
    }

    WHEN( "CBRKXS is expected, but not given" ){
      std::string inp(
 std::string( " 22 0 -23 0 /\n" ) +
 std::string( " 0 /\n" ) +
 std::string( " /\n" ) +
 std::string( " 12 13 4 3 1 /\n" ) +
 std::string( " 'iso1' 'aiso1' 'ident1' 'hmat1' 1 1.1 /\n" ) +
 std::string( " 'iso2' 'aiso2' 'ident2' 'hmat2' 2 2.2 /\n" ) +
 std::string( " 'iso3' 'aiso3' 'ident3' 'hmat3' 3 3.3 /\n" ) +
 std::string( " 'iso4' 'aiso4' 'ident4' 'hmat4' 4 4.4 /" )
      );

      iRecordStream<char> iss{ std::istringstream{ inp } };

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( CCCCR( iss ) );
      }
    }

    WHEN( "too few card5's are given" ){
      std::string inp(
 std::string( " 22 0 0 0 /\n" ) +
 std::string( " 0 /\n" ) +
 std::string( " /\n" ) +
 std::string( " 12 13 4 3 1 /\n" ) +
 std::string( " 'iso1' 'aiso1' 'ident1' 'hmat1' 1 1.1 /\n" ) +
 std::string( " 'iso2' 'aiso2' 'ident2' 'hmat2' 2 2.2 /\n" ) +
 std::string( " 'iso4' 'aiso4' 'ident4' 'hmat4' 4 4.4 /" )
      );

      iRecordStream<char> iss{ std::istringstream{ inp } };

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( CCCCR( iss ) );
      }
    }
  } // GIVEN
} // SCENARIO
