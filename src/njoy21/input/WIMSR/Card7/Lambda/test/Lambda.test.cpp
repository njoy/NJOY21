#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "WIMSR, Card7, Lambda",
          "[WIMSR] [Card7] [Lambda]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided using default igroup structure" ){
      const int igroup = 0;
      const unsigned int nrg = 13;
      iRecordStream<char> iss( std::istringstream(
                   " 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0 1.1 1.2 1.3 /" ) );

      THEN( "the values can be verified" ){
        for( int i = 0; i < 13; i++ ){
          REQUIRE( Approx( 0.1*(i+1) ) == argument::extract<
                   WIMSR::Card7::Lambda >( iss, igroup, nrg ).value.at(i) );
        }
      }
    } // WHEN

    WHEN( "valid inputs are provided using non-default igroup structure" ){
      const int igroup = 1;
      const unsigned int nrg = 12;
      iRecordStream<char> iss( std::istringstream(
                   " 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0 1.1 1.2 /" ) );

      THEN( "the values can be verified" ){
        for( int i = 0; i < 12; i++ ){
          REQUIRE( Approx( 0.1*(i+1) ) == argument::extract<
                   WIMSR::Card7::Lambda >( iss, igroup, nrg ).value.at(i) );
        }
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "the number of values doesn't match for default group structure" ){
      const int igroup = 0;
      const unsigned int nrg = 12;
      iRecordStream<char> iss( std::istringstream(
                   " 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0 1.1 1.2 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< WIMSR::Card7::Lambda >(
                        iss, igroup, nrg ) );
      }
    } // WHEN

    WHEN( "the number of values doesn't match nrg" ){
      const int igroup = 1;
      const unsigned int nrg = 13;
      iRecordStream<char> iss( std::istringstream(
                   " 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0 1.1 1.2 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< WIMSR::Card7::Lambda >(
                        iss, igroup, nrg ) );
      }
    } // WHEN

    WHEN( "an negative lambda is included" ){
      const int igroup = 1;
      const unsigned int nrg = 12;
      iRecordStream<char> iss( std::istringstream(
                   " 0.1 0.2 0.3 0.4 0.5 0.6 0.7 -0.8 0.9 1.0 1.1 1.2 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< WIMSR::Card7::Lambda >(
                        iss, igroup, nrg ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
