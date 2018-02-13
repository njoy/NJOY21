#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "ERRORR, Rest, Card7",
          "[ERRORR] [Rest] [Card7]" ){
  GIVEN( "valid inputs" ){
    WHEN( "mf = 31" ){
      const int ngout = 35;

      THEN( "the values can be verified" ){
        iRecordStream<char> iss( std::istringstream( " 0 31 /" ) );

        ERRORR::Rest::Card7 card7( iss, ngout );

        REQUIRE( 0 == card7.iread.value );
        REQUIRE( 31 == card7.mfcov.value );
        REQUIRE( std::nullopt == card7.irespr );
        REQUIRE( std::nullopt == card7.legord );
        REQUIRE( std::nullopt == card7.ifisspEfmean );
        REQUIRE( std::nullopt == card7.dap );
      }
    } // WHEN

    WHEN( "mf = 33" ){
      const int ngout = 35;

      THEN( "the values can be verified" ){
        iRecordStream<char> iss( std::istringstream( " 1 33 0 0.6 /" ) );

        ERRORR::Rest::Card7 card7( iss, ngout );

        REQUIRE( 1 == card7.iread.value );
        REQUIRE( 33 == card7.mfcov.value );
        REQUIRE( 0 == card7.irespr->value );
        REQUIRE( std::nullopt == card7.legord );
        REQUIRE( std::nullopt == card7.ifisspEfmean );
        REQUIRE( Approx( 0.6 ) == card7.dap->value );
      }

      THEN( "the default values can be verified" ){
        iRecordStream<char> iss( std::istringstream( " 1 33 /" ) );

        ERRORR::Rest::Card7 card7( iss, ngout );

        REQUIRE( 1 == card7.iread.value );
        REQUIRE( 33 == card7.mfcov.value );
        REQUIRE( 1 == card7.irespr->value );
        REQUIRE( std::nullopt == card7.legord );
        REQUIRE( std::nullopt == card7.ifisspEfmean );
        REQUIRE( Approx( 0.0 ) == card7.dap->value );
      }

      THEN( "all default values can be verified" ){
        iRecordStream<char> iss( std::istringstream( " /" ) );

        ERRORR::Rest::Card7 card7( iss, ngout );

        REQUIRE( 0 == card7.iread.value );
        REQUIRE( 33 == card7.mfcov.value );
        REQUIRE( 1 == card7.irespr->value );
        REQUIRE( std::nullopt == card7.legord );
        REQUIRE( std::nullopt == card7.ifisspEfmean );
        REQUIRE( Approx( 0.0 ) == card7.dap->value );
      }
    } // WHEN

    WHEN( "mf = 34" ){
      const int ngout = 35;

      THEN( "the values can be verified" ){
        iRecordStream<char> iss( std::istringstream( " 2 34 1 /" ) );

        ERRORR::Rest::Card7 card7( iss, ngout );

        REQUIRE( 2 == card7.iread.value );
        REQUIRE( 34 == card7.mfcov.value );
        REQUIRE( std::nullopt == card7.irespr );
        REQUIRE( 1 == card7.legord->value );
        REQUIRE( std::nullopt == card7.ifisspEfmean );
        REQUIRE( std::nullopt == card7.dap );
      }

      THEN( "the default values can be verified" ){
        iRecordStream<char> iss( std::istringstream( " 2 34 /" ) );

        ERRORR::Rest::Card7 card7( iss, ngout );

        REQUIRE( 2 == card7.iread.value );
        REQUIRE( 34 == card7.mfcov.value );
        REQUIRE( std::nullopt == card7.irespr );
        REQUIRE( 1 == card7.legord->value );
        REQUIRE( std::nullopt == card7.ifisspEfmean );
        REQUIRE( std::nullopt == card7.dap );
      }
    } // WHEN

    WHEN( "mf = 35" ){
      const int ngout = 35;

      THEN( "the values can be verified" ){
        iRecordStream<char> iss( std::istringstream( " 0 35 12 2.e5 /" ) );

        ERRORR::Rest::Card7 card7( iss, ngout );

        REQUIRE( 0 == card7.iread.value );
        REQUIRE( 35 == card7.mfcov.value );
        REQUIRE( std::nullopt == card7.irespr );
        REQUIRE( std::nullopt == card7.legord );
        REQUIRE( 12 == card7.ifisspEfmean->first.value );
        REQUIRE( 2.0e5*dimwits::electronVolt ==
                                        *( card7.ifisspEfmean->second.value ) );
        REQUIRE( std::nullopt == card7.dap );
      }

      THEN( "the default values can be verified" ){
        iRecordStream<char> iss( std::istringstream( " 0 35 /" ) );

        ERRORR::Rest::Card7 card7( iss, ngout );

        REQUIRE( 0 == card7.iread.value );
        REQUIRE( 35 == card7.mfcov.value );
        REQUIRE( std::nullopt == card7.irespr );
        REQUIRE( std::nullopt == card7.legord );
        REQUIRE( -1 == card7.ifisspEfmean->first.value );
        REQUIRE( 2.0e6*dimwits::electronVolt ==
                                        *( card7.ifisspEfmean->second.value ) );
        REQUIRE( std::nullopt == card7.dap );
      }

      THEN( "the default values can be verified" ){
        iRecordStream<char> iss( std::istringstream( " 0 35 1 /" ) );

        ERRORR::Rest::Card7 card7( iss, ngout );

        REQUIRE( 0 == card7.iread.value );
        REQUIRE( 35 == card7.mfcov.value );
        REQUIRE( std::nullopt == card7.irespr );
        REQUIRE( std::nullopt == card7.legord );
        REQUIRE( 1 == card7.ifisspEfmean->first.value );
        REQUIRE( std::nullopt == card7.ifisspEfmean->second.value );
        REQUIRE( std::nullopt == card7.dap );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "too many values are provided" ){
      const int ngout = 35;
      iRecordStream<char> iss( std::istringstream( " 0 40 0.2 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( ERRORR::Rest::Card7( iss, ngout ) );
      }
    } // WHEN

    WHEN( "ngout is zero and iread is two" ){
      const int ngout = 0;
      iRecordStream<char> iss( std::istringstream( " 2 33 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( ERRORR::Rest::Card7( iss, ngout ) );
      }
    } // WHEN

    WHEN( "ngout is zero and mfcov = 31, 35, or 40" ){
      const int ngout = 0;

      for( std::string inp : {" 2 31 /", " 2 35 /", " 2 40 /"} ){
        iRecordStream<char> iss{ std::istringstream{ inp } };
  
        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( ERRORR::Rest::Card7( iss, ngout ) );
        }
      }
    } // WHEN

    WHEN( "an invalid value is provided" ){
      const int ngout = 35;
      iRecordStream<char> iss( std::istringstream( " 1 33 0 1.6 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( ERRORR::Rest::Card7( iss, ngout ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
