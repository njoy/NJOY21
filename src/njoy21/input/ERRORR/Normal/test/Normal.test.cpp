#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "ERRORR, Normal",
          "[ERRORR] [Normal]" ){
  GIVEN( "valid inputs" ){
    WHEN( "simple set of valid inputs are provided" ){
      iRecordStream<char> iss( std::istringstream(
 " 600 12 4 0 0 /\n" // matd, ign, iwt, iprint, irelco
 " 1 314.15 /\n" // mprint, tempin
 " 0 31 /\n" // iread, mfcov
 " 1.0 2.0 3.0 4.0 /"
      ) );

      THEN( "the values can be verified" ){
        ERRORR::Normal normal( iss, 35, 0 );

        REQUIRE( 600 == normal.card2.matd.value );
        REQUIRE( 12 == normal.card2.ign.value );
        REQUIRE( 4 == normal.card2.iwt.value );
        REQUIRE( 0 == normal.card2.iprint.value );
        REQUIRE( 0 == normal.card2.irelco.value );

        REQUIRE( 1 == normal.card3.mprint.value );
        REQUIRE( 314.15*dimwits::kelvin == normal.card3.tempin.value );

        REQUIRE( 0 == normal.card7.iread.value );
        REQUIRE( 31 == normal.card7.mfcov.value );

        REQUIRE( 1.0*dimwits::electronVolt == normal.card13b->eb.value );
        REQUIRE( 2.0*dimwits::electronVolt == normal.card13b->tb.value );
        REQUIRE( 3.0*dimwits::electronVolt == normal.card13b->ec.value );
        REQUIRE( 4.0*dimwits::electronVolt == normal.card13b->tc.value );
      }
    } // WHEN

    WHEN( "another set of valid inputs are provided" ){
      iRecordStream<char> iss( std::istringstream(
 " 600 1 4 0 0 /\n"
 " 1 314.15 /\n"
 " 0 31 /\n"
 " 6 /\n"
 " 0.05 1.0 200.0 2e4 5e5 1e6 2e6 /\n"
 " 1.0 2.0 3.0 4.0 /"
      ) );

      THEN( "the values can be verified" ){
        ERRORR::Normal normal( iss, 35, 0 );

        REQUIRE( 600 == normal.card2.matd.value );
        REQUIRE( 1 == normal.card2.ign.value );
        REQUIRE( 4 == normal.card2.iwt.value );
        REQUIRE( 0 == normal.card2.iprint.value );
        REQUIRE( 0 == normal.card2.irelco.value );

        REQUIRE( 1 == normal.card3.mprint.value );
        REQUIRE( 314.15*dimwits::kelvin == normal.card3.tempin.value );

        REQUIRE( 0 == normal.card7.iread.value );
        REQUIRE( 31 == normal.card7.mfcov.value );

        REQUIRE( 6 == normal.card12ab->first.ngn.value );

        REQUIRE( 7 == normal.card12ab->second.egn.value.size() );

        REQUIRE( 0.05*dimwits::electronVolt ==
                                      normal.card12ab->second.egn.value.at(0) );
        REQUIRE( 1.0*dimwits::electronVolt ==
                                      normal.card12ab->second.egn.value.at(1) );
        REQUIRE( 200.0*dimwits::electronVolt ==
                                      normal.card12ab->second.egn.value.at(2) );
        REQUIRE( 2.e4*dimwits::electronVolt ==
                                      normal.card12ab->second.egn.value.at(3) );
        REQUIRE( 5.e5*dimwits::electronVolt ==
                                      normal.card12ab->second.egn.value.at(4) );
        REQUIRE( 1.e6*dimwits::electronVolt ==
                                      normal.card12ab->second.egn.value.at(5) );
        REQUIRE( 2.e6*dimwits::electronVolt ==
                                      normal.card12ab->second.egn.value.at(6) );

        REQUIRE( 1.0*dimwits::electronVolt == normal.card13b->eb.value );
        REQUIRE( 2.0*dimwits::electronVolt == normal.card13b->tb.value );
        REQUIRE( 3.0*dimwits::electronVolt == normal.card13b->ec.value );
        REQUIRE( 4.0*dimwits::electronVolt == normal.card13b->tc.value );
      }
    } // WHEN

    WHEN( "another valid input" ){
      iRecordStream<char> iss( std::istringstream(
 " 600 12 1 0 0 /\n" // matd, ign, iwt, iprint, irelco
 " 1 314.15 /\n" // mprint, tempin
 " 0 31 /\n" // iread, mfcov
 "0. 0. 0 0 1 6\n" // Card13
 "6 5\n"
 "1.00000E-05 8.00000E-20 1.00000E+03 9.13415E-10 1.00000E+04 6.13955E-08 \n"
 "1.00925E+04 6.17490E-08 1.01859E+04 6.09190E-08 1.02802E+04 6.19874E-08 /"
      ) );

      THEN( "the values can be verified" ){
        ERRORR::Normal normal( iss, 35, 0 );

        REQUIRE( 600 == normal.card2.matd.value );
        REQUIRE( 12 == normal.card2.ign.value );
        REQUIRE( 1 == normal.card2.iwt.value );
        REQUIRE( 0 == normal.card2.iprint.value );
        REQUIRE( 0 == normal.card2.irelco.value );

        REQUIRE( 1 == normal.card3.mprint.value );
        REQUIRE( 314.15*dimwits::kelvin == normal.card3.tempin.value );

        REQUIRE( 0 == normal.card7.iread.value );
        REQUIRE( 31 == normal.card7.mfcov.value );
      }
    } // WHEN

    WHEN( "yet another valid input is provided" ){
      iRecordStream<char> iss( std::istringstream(
 " 600 12 2 0 0 /\n" // matd, ign, iwt, iprint, irelco
 " 1 314.15 /\n" // mprint, tempin
 " 0 31 /\n" // iread, mfcov
 " -301 -999 201 222 /\n"
 " 1234 123 2345 234 /\n"
 " 3456 345 4567 456 /\n"
 " 0 /"
      ) );

      THEN( "the values can be verified" ){
        ERRORR::Normal normal( iss, 35, 36 );

        REQUIRE( 600 == normal.card2.matd.value );
        REQUIRE( 12 == normal.card2.ign.value );
        REQUIRE( 2 == normal.card2.iwt.value );
        REQUIRE( 0 == normal.card2.iprint.value );
        REQUIRE( 0 == normal.card2.irelco.value );

        REQUIRE( 1 == normal.card3.mprint.value );
        REQUIRE( 314.15*dimwits::kelvin == normal.card3.tempin.value );

        REQUIRE( 0 == normal.card7.iread.value );
        REQUIRE( 31 == normal.card7.mfcov.value );

        REQUIRE( 3 == normal.card11List->size() );

        REQUIRE( -301 == normal.card11List->at(0).matb.value );
        REQUIRE( -999 ==
                      std::get<0>( *( normal.card11List->at(0).rest ) ).value );
        REQUIRE( 201 ==
                      std::get<1>( *( normal.card11List->at(0).rest ) ).value );
        REQUIRE( 222 ==
                      std::get<2>( *( normal.card11List->at(0).rest ) ).value );

        REQUIRE( 1234 == normal.card11List->at(1).matb.value );
        REQUIRE( 123 ==
                      std::get<0>( *( normal.card11List->at(1).rest ) ).value );
        REQUIRE( 2345 ==
                      std::get<1>( *( normal.card11List->at(1).rest ) ).value );
        REQUIRE( 234 ==
                      std::get<2>( *( normal.card11List->at(1).rest ) ).value );

        REQUIRE( 3456 == normal.card11List->at(2).matb.value );
        REQUIRE( 345 ==
                      std::get<0>( *( normal.card11List->at(2).rest ) ).value );
        REQUIRE( 4567 ==
                      std::get<1>( *( normal.card11List->at(2).rest ) ).value );
        REQUIRE( 456 ==
                      std::get<2>( *( normal.card11List->at(2).rest ) ).value );
      }
    } // WHEN

    WHEN( "and yet another valid input is provided" ){
      iRecordStream<char> iss( std::istringstream(
 " 600 12 2 0 0 /\n" // matd, ign, iwt, iprint, irelco
 " 1 314.15 /\n" // mprint, tempin
 " 2 31 /\n" // iread, mfcov
 " 9999 999 /\n" // mat1 mt1
 " 8888 888 /\n"
 " 7777 777 /\n"
 " 0 /"
      ) );

      THEN( "the values can be verified" ){
        ERRORR::Normal normal( iss, 35, 0 );

        REQUIRE( 600 == normal.card2.matd.value );
        REQUIRE( 12 == normal.card2.ign.value );
        REQUIRE( 2 == normal.card2.iwt.value );
        REQUIRE( 0 == normal.card2.iprint.value );
        REQUIRE( 0 == normal.card2.irelco.value );

        REQUIRE( 1 == normal.card3.mprint.value );
        REQUIRE( 314.15*dimwits::kelvin == normal.card3.tempin.value );

        REQUIRE( 2 == normal.card7.iread.value );
        REQUIRE( 31 == normal.card7.mfcov.value );

        REQUIRE( 3 == normal.card10List->size() );

        REQUIRE( 9999 == normal.card10List->at(0).mat1.value );
        REQUIRE( 999 == normal.card10List->at(0).mt1->value );

        REQUIRE( 8888 == normal.card10List->at(1).mat1.value );
        REQUIRE( 888 == normal.card10List->at(1).mt1->value );

        REQUIRE( 7777 == normal.card10List->at(2).mat1.value );
        REQUIRE( 777 == normal.card10List->at(2).mt1->value );
      }
    } // WHEN

    WHEN( "meanwhile another valid input is provided" ){
      iRecordStream<char> iss( std::istringstream(
 " 600 12 3 0 0 /\n" // matd, ign, iwt, iprint, irelco
 " 1 314.15 /\n" // mprint, tempin
 " 1 31 /\n" // iread, mfcov
 " 3 4 /\n" // nmt, nek
 " 101 102 103 /\n" // 3*mts
 " 0.01 1.0 10.0 100.0 200.0 /\n" // (nek+1)*ek
 " /\n"
 " /\n"
 " /\n"
 " /\n"
 " /\n"
 " /\n"
 " /\n"
 " /\n"
 " /\n"
 " /\n"
 " /\n"
 " /"
      ) );

      THEN( "the values can be verified" ){
        ERRORR::Normal normal( iss, 35, 0 );

        REQUIRE( 600 == normal.card2.matd.value );
        REQUIRE( 12 == normal.card2.ign.value );
        REQUIRE( 3 == normal.card2.iwt.value );
        REQUIRE( 0 == normal.card2.iprint.value );
        REQUIRE( 0 == normal.card2.irelco.value );

        REQUIRE( 1 == normal.card3.mprint.value );
        REQUIRE( 314.15*dimwits::kelvin == normal.card3.tempin.value );

        REQUIRE( 1 == normal.card7.iread.value );
        REQUIRE( 31 == normal.card7.mfcov.value );

        REQUIRE( 3 == std::get<0>( *( normal.iread1 ) ).nmt.value );
        REQUIRE( 4 == std::get<0>( *( normal.iread1 ) ).nek.value );

        REQUIRE( 3 == std::get<1>( *( normal.iread1 ) ).mts.value.size() );

        REQUIRE( 101 == std::get<1>( *( normal.iread1 ) ).mts.value.at(0) );
        REQUIRE( 102 == std::get<1>( *( normal.iread1 ) ).mts.value.at(1) );
        REQUIRE( 103 == std::get<1>( *( normal.iread1 ) ).mts.value.at(2) );

        REQUIRE( 5 == std::get<2>( *( normal.iread1 ) )->first.ek.value.size());

        REQUIRE( 0.01*dimwits::electronVolt ==
                      std::get<2>( *( normal.iread1 ) )->first.ek.value.at(0) );
        REQUIRE( 1.0*dimwits::electronVolt ==
                      std::get<2>( *( normal.iread1 ) )->first.ek.value.at(1) );
        REQUIRE( 10.0*dimwits::electronVolt ==
                      std::get<2>( *( normal.iread1 ) )->first.ek.value.at(2) );
        REQUIRE( 100.0*dimwits::electronVolt ==
                      std::get<2>( *( normal.iread1 ) )->first.ek.value.at(3) );
        REQUIRE( 200.0*dimwits::electronVolt ==
                      std::get<2>( *( normal.iread1 ) )->first.ek.value.at(4) );

        for( int i = 0; i < 4; i++ ){
          for( int j = 0; j < 3; j++ ){
            for( int k = 0; k < 3; k++ ){
              if( k == j ){
                REQUIRE( 1 == std::get<2>( *( normal.iread1 ) )->
                                            second.at(j+i*3).akxy.value.at(k) );
              } else {
                REQUIRE( 0 == std::get<2>( *( normal.iread1 ) )->
                                            second.at(j+i*3).akxy.value.at(k) );
              }
            }
          }
        }
      }
    } // WHEN

    WHEN( "a wild valid input is provided" ){
      iRecordStream<char> iss( std::istringstream(
 " 600 12 3 0 0 /\n" // matd, ign, iwt, iprint, irelco
 " 1 314.15 /\n" // mprint, tempin
 " 0 33 0 1 -1 2.0 0.3 /" // iread, mfcov
      ) );

      THEN( "the values can be verified" ){
        ERRORR::Normal normal( iss, 35, 0 );

        REQUIRE( 600 == normal.card2.matd.value );
        REQUIRE( 12 == normal.card2.ign.value );
        REQUIRE( 3 == normal.card2.iwt.value );
        REQUIRE( 0 == normal.card2.iprint.value );
        REQUIRE( 0 == normal.card2.irelco.value );

        REQUIRE( 1 == normal.card3.mprint.value );
        REQUIRE( 314.15*dimwits::kelvin == normal.card3.tempin.value );

        REQUIRE( 0 == normal.card7.iread.value );
        REQUIRE( 33 == normal.card7.mfcov.value );
        REQUIRE( 0 == normal.card7.irespr.value );
        REQUIRE( Approx( 0.3 ) == normal.card7.dap.value );
      }
    } // WHEN

    WHEN( "another valid input is provided again" ){
      iRecordStream<char> iss( std::istringstream(
 " 600 12 3 0 0 /\n" // matd, ign, iwt, iprint, irelco
 " 1 314.15 /\n" // mprint, tempin
 " 0 34 1 1 /" // iread, mfcov
      ) );

      THEN( "the values can be verified" ){
        ERRORR::Normal normal( iss, 35, 0 );

        REQUIRE( 600 == normal.card2.matd.value );
        REQUIRE( 12 == normal.card2.ign.value );
        REQUIRE( 3 == normal.card2.iwt.value );
        REQUIRE( 0 == normal.card2.iprint.value );
        REQUIRE( 0 == normal.card2.irelco.value );

        REQUIRE( 1 == normal.card3.mprint.value );
        REQUIRE( 314.15*dimwits::kelvin == normal.card3.tempin.value );

        REQUIRE( 0 == normal.card7.iread.value );
        REQUIRE( 34 == normal.card7.mfcov.value );
        REQUIRE( 1 == normal.card7.legord.value );
      }
    } // WHEN

    WHEN( "a final valid input is provided" ){
      iRecordStream<char> iss( std::istringstream(
 " 600 12 3 0 0 /\n" // matd, ign, iwt, iprint, irelco
 " 1 314.15 /\n" // mprint, tempin
 " 0 35 1 1 1 2.2e5 /" // iread, mfcov
      ) );

      THEN( "the values can be verified" ){
        ERRORR::Normal normal( iss, 35, 0 );

        REQUIRE( 600 == normal.card2.matd.value );
        REQUIRE( 12 == normal.card2.ign.value );
        REQUIRE( 3 == normal.card2.iwt.value );
        REQUIRE( 0 == normal.card2.iprint.value );
        REQUIRE( 0 == normal.card2.irelco.value );

        REQUIRE( 1 == normal.card3.mprint.value );
        REQUIRE( 314.15*dimwits::kelvin == normal.card3.tempin.value );

        REQUIRE( 0 == normal.card7.iread.value );
        REQUIRE( 35 == normal.card7.mfcov.value );
        REQUIRE( 1 == normal.card7.ifissp.value );
        REQUIRE( 2.2e5*dimwits::electronVolt == normal.card7.efmean.value );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "an invalid value is provided" ){
      iRecordStream<char> iss( std::istringstream(
 " 600 12 3 0 0 /\n" // matd, ign, iwt, iprint, irelco
 " 1 -314.15 /\n" // mprint, tempin
 " 0 31 /" // iread, mfcov
      ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( ERRORR::Normal( iss, 35, 0 ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
