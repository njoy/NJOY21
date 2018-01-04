#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "WIMSR",
          "[WIMSR]" ){
  GIVEN( "valid inputs" ){
    WHEN( "the example from test problem 11 is used" ){
      std::string Card1( "-26 27\n" );
      std::string Card2( "1/\n" );
      std::string Card3( "1050 1 1050./\n" );
      std::string Card4( "3 7 1e10 3 10.890 221 0/\n" );
      std::string Card7( "1. 1. 1. 1. 1. 1. 1. 1. 1. 1. 1. 1. 1./" );

      iRecordStream<char> iss( std::istringstream( 
        Card1 +
        Card2 +
        Card3 +
        Card4 +
        Card7 ) );

      WIMSR wimsr( iss );

      THEN( "the values can be verified" ){
        REQUIRE( -26 == wimsr.card1.ngendf.value );
        REQUIRE( 27 == wimsr.card1.nout.value );

        REQUIRE( 1 == wimsr.card2.iprint.value );
        REQUIRE( 4 == wimsr.card2.iverw.value ); // default
        REQUIRE( 0 == wimsr.card2.igroup.value ); // default

        REQUIRE( std::nullopt == wimsr.card2a ); // Card2::Igroup != 9

        REQUIRE( 1050 == wimsr.card3.mat.value );
        REQUIRE( 1 == wimsr.card3.nfid.value );
        REQUIRE( Approx( 1050.0 ) == wimsr.card3.rdfid.value );
        REQUIRE( 0 == wimsr.card3.iburn.value ); // default

        REQUIRE( 3 == wimsr.card4.ntemp.value );
        REQUIRE( 7 == wimsr.card4.nsigz.value );
        REQUIRE( Approx( 1.0e10 ) == wimsr.card4.sgref.value );
        REQUIRE( 3 == wimsr.card4.ires.value );
        REQUIRE( Approx( 10.890 ) == wimsr.card4.sigp.value );
        REQUIRE( 221 == wimsr.card4.mti.value );
        REQUIRE( 0 == wimsr.card4.mtc.value );
        REQUIRE( 1 == wimsr.card4.ip1opt.value ); // default
        REQUIRE( 0 == wimsr.card4.inorf.value ); // default
        REQUIRE( 0 == wimsr.card4.isof.value ); // default
        REQUIRE( 0 == wimsr.card4.ifprod.value ); // default
        REQUIRE( 0 == wimsr.card4.jp1.value ); // default

        REQUIRE( std::nullopt == wimsr.card56List ); // Card3::Iburn !>0

        for( size_t i = 0; i < 13; i++ ){
          REQUIRE( Approx( 1.0 ) == wimsr.card7.lambda.value.at(i) );
        }

        REQUIRE( std::nullopt == wimsr.card8 ); // Card4::Jp1 !>0
      } // THEN
    } // WHEN

    WHEN( "an input with no defaults is given" ){
      std::string Card1( " -26 27\n" );
      std::string Card2( " 1 5 9/\n" );
      std::string Card2a( " 15 4 5 6/\n" );
      std::string Card3( " 1050 1 1050. 1/\n" );
      std::string Card4( " 12 13 1.e12 14 0 0 0 1 0 0 2 5/\n" );
      std::string Card5( " 4 4.8e5/\n" );
      std::string Card6a( " 1051 1.0/\n" );
      std::string Card6b( " 1030 0.062/\n" );
      std::string Card6c( " 1010 0.4/\n 1011 0.6/\n" );
      std::string Card7( " 0.1 0.2 0.3 0.4 0.5/\n" );
      std::string Card8( " 0.6 0.7 0.8 0.9 1.0/\n" );

      iRecordStream<char> iss( std::istringstream(
        Card1 +
        Card2 +
        Card2a +
        Card3 +
        Card4 +
        Card5 +
        Card6a +
        Card6b +
        Card6c +
        Card7 +
        Card8 ) );

      WIMSR wimsr( iss );

      THEN( "the values can be verified" ){
        REQUIRE( -26 == wimsr.card1.ngendf.value );
        REQUIRE( 27 == wimsr.card1.nout.value );

        REQUIRE( 1 == wimsr.card2.iprint.value );
        REQUIRE( 5 == wimsr.card2.iverw.value );
        REQUIRE( 9 == wimsr.card2.igroup.value );

        REQUIRE( 15 == wimsr.card2a->ngnd.value );
        REQUIRE( 4 == wimsr.card2a->nfg.value );
        REQUIRE( 5 == wimsr.card2a->nrg.value );
        REQUIRE( 6 == wimsr.card2a->igref.value );

        REQUIRE( 1050 == wimsr.card3.mat.value );
        REQUIRE( 1 == wimsr.card3.nfid.value );
        REQUIRE( Approx( 1050.0 ) == wimsr.card3.rdfid.value );
        REQUIRE( 1 == wimsr.card3.iburn.value );

        REQUIRE( 12 == wimsr.card4.ntemp.value );
        REQUIRE( 13 == wimsr.card4.nsigz.value );
        REQUIRE( Approx( 1.0e12 ) == wimsr.card4.sgref.value );
        REQUIRE( 14 == wimsr.card4.ires.value );
        REQUIRE( 0 == wimsr.card4.sigp.value );
        REQUIRE( 0 == wimsr.card4.mti.value );
        REQUIRE( 0 == wimsr.card4.mtc.value );
        REQUIRE( 1 == wimsr.card4.ip1opt.value );
        REQUIRE( 0 == wimsr.card4.inorf.value );
        REQUIRE( 0 == wimsr.card4.isof.value );
        REQUIRE( 2 == wimsr.card4.ifprod.value );
        REQUIRE( 5 == wimsr.card4.jp1.value );

        auto card5 = std::get<0>( *( wimsr.card56List ) );
        auto card6a = std::get<1>( *( wimsr.card56List ) );
        auto card6b = std::get<2>( *( wimsr.card56List ) );
        auto card6c = std::get<3>( *( wimsr.card56List ) );

        REQUIRE( 4 == card5.ntis.value );
        REQUIRE( Approx( 4.8e5 ) == card5.efiss.value );

        REQUIRE( 1051 == card6a.identa.value );
        REQUIRE( Approx( 1.0 ) == card6a.yield.value );

        REQUIRE( 1030 == card6b.identa.value );
        REQUIRE( Approx( 0.062 ) == card6b.lambda.value );

        REQUIRE( 1010 == card6c->at(0).identa.value );
        REQUIRE( Approx( 0.4 ) == card6c->at(0).yield.value );

        REQUIRE( 1011 == card6c->at(1).identa.value );
        REQUIRE( Approx( 0.6 ) == card6c->at(1).yield.value );

        REQUIRE( Approx( 0.1 ) == wimsr.card7.lambda.value.at(0) );
        REQUIRE( Approx( 0.2 ) == wimsr.card7.lambda.value.at(1) );
        REQUIRE( Approx( 0.3 ) == wimsr.card7.lambda.value.at(2) );
        REQUIRE( Approx( 0.4 ) == wimsr.card7.lambda.value.at(3) );
        REQUIRE( Approx( 0.5 ) == wimsr.card7.lambda.value.at(4) );

        REQUIRE( Approx( 0.6 ) == wimsr.card8->p1flx.value.at(0) );
        REQUIRE( Approx( 0.7 ) == wimsr.card8->p1flx.value.at(1) );
        REQUIRE( Approx( 0.8 ) == wimsr.card8->p1flx.value.at(2) );
        REQUIRE( Approx( 0.9 ) == wimsr.card8->p1flx.value.at(3) );
        REQUIRE( Approx( 1.0 ) == wimsr.card8->p1flx.value.at(4) );
      } // THEN
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "a card2a is expected, but not provided" ){
      std::string Card1( "-26 27\n" );
      std::string Card2( "1 4 9/\n" );
      std::string Card3( "1050 1 1050./\n" );
      std::string Card4( "3 7 1e10 3 10.890 221 0/\n" );
      std::string Card7( "1. 1. 1. 1. 1. 1. 1. 1. 1. 1. 1. 1. 1./" );

      iRecordStream<char> iss( std::istringstream( 
        Card1 +
        Card2 +
        Card3 +
        Card4 +
        Card7 ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( WIMSR( iss ) );
      }
    } // WHEN

    WHEN( "card5 and card6[a-c] is expected, but not provided" ){
      std::string Card1( "-26 27\n" );
      std::string Card2( "1/\n" );
      std::string Card3( "1050 1 1050. 1/\n" );
      std::string Card4( "3 7 1e10 3 10.890 221 0/\n" );
      std::string Card7( "1. 1. 1. 1. 1. 1. 1. 1. 1. 1. 1. 1. 1./" );

      iRecordStream<char> iss( std::istringstream( 
        Card1 +
        Card2 +
        Card3 +
        Card4 +
        Card7 ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( WIMSR( iss ) );
      }
    } // WHEN

    WHEN( "one fewer card6c is provided than expected" ){
      std::string Card1( " -26 27\n" );
      std::string Card2( " 1 5 9/\n" );
      std::string Card2a( " 15 4 5 6/\n" );
      std::string Card3( " 1050 1 1050. 1/\n" );
      std::string Card4( " 12 13 1.e12 14 0 0 0 1 0 0 2 5/\n" );
      std::string Card5( " 4 4.8e5/\n" );
      std::string Card6a( " 1051 1.0/\n" );
      std::string Card6b( " 1030 0.062/\n" );
      std::string Card6c( " 1010 0.4/\n" );
      std::string Card7( " 0.1 0.2 0.3 0.4 0.5/\n" );
      std::string Card8( " 0.6 0.7 0.8 0.9 1.0/\n" );

      iRecordStream<char> iss( std::istringstream(
        Card1 +
        Card2 +
        Card2a +
        Card3 +
        Card4 +
        Card5 +
        Card6a +
        Card6b +
        Card6c +
        Card7 +
        Card8 ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( WIMSR( iss ) );
      }
    } // WHEN

    WHEN( "Card8 is expected, but not provided" ){
      std::string Card1( " -26 27\n" );
      std::string Card2( " 1 5 9/\n" );
      std::string Card2a( " 15 4 5 6/\n" );
      std::string Card3( " 1050 1 1050. 1/\n" );
      std::string Card4( " 12 13 1.e12 14 0 0 0 1 0 0 2 5/\n" );
      std::string Card5( " 4 4.8e5/\n" );
      std::string Card6a( " 1051 1.0/\n" );
      std::string Card6b( " 1030 0.062/\n" );
      std::string Card6c( " 1010 0.4/\n 1011 0.6/\n" );
      std::string Card7( " 0.1 0.2 0.3 0.4 0.5/\n" );

      iRecordStream<char> iss( std::istringstream(
        Card1 +
        Card2 +
        Card2a +
        Card3 +
        Card4 +
        Card5 +
        Card6a +
        Card6b +
        Card6c +
        Card7 ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( WIMSR( iss ) );
      }
    } // WHEN

/*
    WHEN( "an extra card is added to the end" ){
      std::string Card1( "-26 27\n" );
      std::string Card2( "1/\n" );
      std::string Card3( "1050 1 1050./\n" );
      std::string Card4( "3 7 1e10 3 10.890 221 0/\n" );
      std::string Card7( "1. 1. 1. 1. 1. 1. 1. 1. 1. 1. 1. 1. 1./" );
      std::string CardBonus( "\n8 10 0/" );

      iRecordStream<char> iss( std::istringstream( 
        Card1 +
        Card2 +
        Card3 +
        Card4 +
        Card7 +
        CardBonus) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( WIMSR( iss ) );
      }
    } // WHEN

    WHEN( "an unexpected Card8 is provided" ){
      std::string Card1( " -26 27\n" );
      std::string Card2( " 1 5 9/\n" );
      std::string Card2a( " 15 4 5 6/\n" );
      std::string Card3( " 1050 1 1050. 1/\n" );
      std::string Card4( " 12 13 1.e12 14 0 0 0 1 0 0 2 0/\n" );
      std::string Card5( " 4 4.8e5/\n" );
      std::string Card6a( " 1051 1.0/\n" );
      std::string Card6b( " 1030 0.062/\n" );
      std::string Card6c( " 1010 0.4/\n 1011 0.6/\n" );
      std::string Card7( " 0.1 0.2 0.3 0.4 0.5/\n" );
      std::string Card8( " 0.6 0.7 0.8 0.9 1.0/\n" );

      iRecordStream<char> iss( std::istringstream(
        Card1 +
        Card2 +
        Card2a +
        Card3 +
        Card4 +
        Card5 +
        Card6a +
        Card6b +
        Card6c +
        Card7 +
        Card8 ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( WIMSR( iss ) );
      }
    } // WHEN
*/
  } // GIVEN
} // SCENARIO
