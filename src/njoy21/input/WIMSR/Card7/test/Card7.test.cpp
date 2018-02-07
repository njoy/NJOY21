#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "WISMR, Card7",
          "[WIMSR] [Card7]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      const int igroup = 0;
      const int nrg = 13;
      std::vector<double> ref{ 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9,
                               1.0, 1.1, 1.2, 1.3 };
      iRecordStream<char> iss( std::istringstream(
                   " 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0 1.1 1.2 1.3 /" ) );

      WIMSR::Card7 card7( iss, igroup, nrg );

      THEN( "the values can be verified" ){
        REQUIRE( ref == card7.lambda.value );
      } // THEN
    } // WHEN

    WHEN( "valid inputs are provided with non-default group structure" ){
      const int igroup = 1;
      const int nrg = 12;
      std::vector<double> ref{ 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9,
                               1.0, 1.1, 1.2 };
      iRecordStream<char> iss( std::istringstream(
                       " 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0 1.1 1.2 /" ) );

      WIMSR::Card7 card7( iss, igroup, nrg );

      THEN( "the values can be verified" ){
        REQUIRE( ref == card7.lambda.value );
      } // THEN
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "too few values are given with default" ){
      const int igroup = 0;
      const int nrg = 13;
      iRecordStream<char> iss( std::istringstream(
                       " 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0 1.1 1.2 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( WIMSR::Card7( iss, igroup, nrg ) );
      } // THEN
    } // WHEN

    WHEN( "too few values are given with non-default group structure" ){
      const int igroup = 1;
      const int nrg = 14;
      iRecordStream<char> iss( std::istringstream(
                       " 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0 1.1 1.2 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( WIMSR::Card7( iss, igroup, nrg ) );
      } // THEN
    } // WHEN

    WHEN( "too many values are given" ){
      const int igroup = 0;
      const int nrg = 13;
      iRecordStream<char> iss( std::istringstream(
               " 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0 1.1 1.2 1.3 1.4 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( WIMSR::Card7( iss, igroup, nrg ) );
      } // THEN
    } // WHEN

    WHEN( "too many values are given with non-default group structure" ){
      const int igroup = 1;
      const int nrg = 4;
      iRecordStream<char> iss( std::istringstream( " 0.1 0.2 0.3 0.4 0.5 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( WIMSR::Card7( iss, igroup, nrg ) );
      } // THEN
    } // WHEN

    WHEN( "a value is invalid" ){
      const int igroup = 0;
      const int nrg = 13;
      iRecordStream<char> iss( std::istringstream(
                  " 0.1 0.2 0.3 0.4 0.5 -0.6 0.7 0.8 0.9 1.0 1.1 1.2 1.3 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( WIMSR::Card7( iss, igroup, nrg ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
