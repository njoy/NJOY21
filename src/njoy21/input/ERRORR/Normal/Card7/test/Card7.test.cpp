#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "ERRORR, Normal, Card7",
          "[ERRORR] [Normal] [Card7]" ){
  GIVEN( "valid inputs" ){
    WHEN( "mf = 31" ){
      const int ngout = 35;

      THEN( "the values can be verified" ){
        iRecordStream<char> iss( std::istringstream( " 0 31 /" ) );

        ERRORR::Normal::Card7 card7( iss, ngout );

        REQUIRE( 0 == card7.iread.value );
        REQUIRE( 31 == card7.mfcov.value );
        REQUIRE( 1 == card7.irespr.value );
        REQUIRE( 1 == card7.legord.value );
        REQUIRE( -1 == card7.ifissp.value );
        REQUIRE( 2.e6*dimwits::electronVolt == *( card7.efmean.value ) );
        REQUIRE( Approx( 0.0 ) == card7.dap.value );
      }
    } // WHEN

    WHEN( "mf = 33" ){
      const int ngout = 35;

      THEN( "the values can be verified" ){
        iRecordStream<char> iss( std::istringstream(
                                                 " 1 33 0 2 -1 -10.0 0.6 /" ) );

        ERRORR::Normal::Card7 card7( iss, ngout );

        REQUIRE( 1 == card7.iread.value );
        REQUIRE( 33 == card7.mfcov.value );
        REQUIRE( 0 == card7.irespr.value );
        REQUIRE( 2 == card7.legord.value );
        REQUIRE( -1 == card7.ifissp.value );
        REQUIRE( -10.0*dimwits::electronVolt == *( card7.efmean.value ) );
        REQUIRE( Approx( 0.6 ) == card7.dap.value );
      }

      THEN( "the default values can be verified" ){
        iRecordStream<char> iss( std::istringstream( " 1 33 /" ) );

        ERRORR::Normal::Card7 card7( iss, ngout );

        REQUIRE( 1 == card7.iread.value );
        REQUIRE( 33 == card7.mfcov.value );
        REQUIRE( 1 == card7.irespr.value );
        REQUIRE( 1 == card7.legord.value );
        REQUIRE( -1 == card7.ifissp.value );
        REQUIRE( 2.e6*dimwits::electronVolt == *( card7.efmean.value ) );
        REQUIRE( Approx( 0.0 ) == card7.dap.value );
      }

      THEN( "all default values can be verified" ){
        iRecordStream<char> iss( std::istringstream( " /" ) );

        ERRORR::Normal::Card7 card7( iss, ngout );

        REQUIRE( 0 == card7.iread.value );
        REQUIRE( 33 == card7.mfcov.value );
        REQUIRE( 1 == card7.irespr.value );
        REQUIRE( 1 == card7.legord.value );
        REQUIRE( -1 == card7.ifissp.value );
        REQUIRE( 2.e6*dimwits::electronVolt == *( card7.efmean.value ) );
        REQUIRE( Approx( 0.0 ) == card7.dap.value );
      }
    } // WHEN

    WHEN( "mf = 34" ){
      const int ngout = 35;

      THEN( "the values can be verified" ){
        iRecordStream<char> iss( std::istringstream( " 2 34 0 1 /" ) );

        ERRORR::Normal::Card7 card7( iss, ngout );

        REQUIRE( 2 == card7.iread.value );
        REQUIRE( 34 == card7.mfcov.value );
        REQUIRE( 0 == card7.irespr.value );
        REQUIRE( 1 == card7.legord.value );
        REQUIRE( -1 == card7.ifissp.value );
        REQUIRE( 2.e6*dimwits::electronVolt == *( card7.efmean.value ) );
        REQUIRE( Approx( 0.0 ) == card7.dap.value );
      }

      THEN( "the default values can be verified" ){
        iRecordStream<char> iss( std::istringstream( " 2 34 /" ) );

        ERRORR::Normal::Card7 card7( iss, ngout );

        REQUIRE( 2 == card7.iread.value );
        REQUIRE( 34 == card7.mfcov.value );
        REQUIRE( 1 == card7.irespr.value );
        REQUIRE( 1 == card7.legord.value );
        REQUIRE( -1 == card7.ifissp.value );
        REQUIRE( 2.e6*dimwits::electronVolt == *( card7.efmean.value ) );
        REQUIRE( Approx( 0.0 ) == card7.dap.value );
      }
    } // WHEN

    WHEN( "mf = 35" ){
      const int ngout = 35;

      THEN( "the values can be verified" ){
        iRecordStream<char> iss( std::istringstream( " 0 35 1 1 12 2.e5 /" ) );

        ERRORR::Normal::Card7 card7( iss, ngout );

        REQUIRE( 0 == card7.iread.value );
        REQUIRE( 35 == card7.mfcov.value );
        REQUIRE( 1 == card7.irespr.value );
        REQUIRE( 1 == card7.legord.value );
        REQUIRE( 12 == card7.ifissp.value );
        REQUIRE( 2.0e5*dimwits::electronVolt == *( card7.efmean.value ) );
        REQUIRE( Approx( 0.0 ) == card7.dap.value );
      }

      THEN( "the default values can be verified" ){
        iRecordStream<char> iss( std::istringstream( " 0 35 /" ) );

        ERRORR::Normal::Card7 card7( iss, ngout );

        REQUIRE( 0 == card7.iread.value );
        REQUIRE( 35 == card7.mfcov.value );
        REQUIRE( 1 == card7.irespr.value );
        REQUIRE( 1 == card7.legord.value );
        REQUIRE( -1 == card7.ifissp.value );
        REQUIRE( 2.0e6*dimwits::electronVolt == *( card7.efmean.value ) );
        REQUIRE( Approx( 0.0 ) == card7.dap.value );
      }

      THEN( "the default values can be verified" ){
        iRecordStream<char> iss( std::istringstream( " 0 35 1 1 1 /" ) );

        ERRORR::Normal::Card7 card7( iss, ngout );

        REQUIRE( 0 == card7.iread.value );
        REQUIRE( 35 == card7.mfcov.value );
        REQUIRE( 1 == card7.irespr.value );
        REQUIRE( 1 == card7.legord.value );
        REQUIRE( 1 == card7.ifissp.value );
        REQUIRE( std::nullopt == card7.efmean.value );
        REQUIRE( Approx( 0.0 ) == card7.dap.value );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "too many values are provided" ){
      const int ngout = 35;
      iRecordStream<char> iss( std::istringstream(
                                                 " 0 40 1 1 -1 0.2 0.2 1 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( ERRORR::Normal::Card7( iss, ngout ) );
      }
    } // WHEN

    WHEN( "ngout is zero and iread is two" ){
      const int ngout = 0;
      iRecordStream<char> iss( std::istringstream( " 2 33 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( ERRORR::Normal::Card7( iss, ngout ) );
      }
    } // WHEN

    for( std::string inp : {" 2 31 /", " 2 35 /", " 2 40 /"} ){
      std::string situ( "ngout == 0 but can't with input: " + inp );
      WHEN( situ.c_str() ){
        const int ngout = 0;

        iRecordStream<char> iss{ std::istringstream{ inp } };
  
        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( ERRORR::Normal::Card7( iss, ngout ) );
        }
      }
    } // WHEN

    WHEN( "an invalid value is provided" ){
      const int ngout = 35;
      iRecordStream<char> iss( std::istringstream( " 1 33 1 1 -1 0 1.6 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( ERRORR::Normal::Card7( iss, ngout ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
