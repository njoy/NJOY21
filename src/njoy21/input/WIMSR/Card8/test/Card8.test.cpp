#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "WIMSR, Card8",
          "[WIMSR] [Card8]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid values are provided" ){
      const unsigned int jp1 = 5;
      const unsigned int ngnd = 7;
      iRecordStream<char> iss( std::istringstream( " 1.0 2.0 3.0 4.0 5.0 /" ) );
  
      WIMSR::Card8 card8( iss, ngnd, jp1 );

      THEN( "the values can be verified" ){
        std::vector<double> ref{ 1.0, 2.0, 3.0, 4.0, 5.0 };
        REQUIRE( ref == card8.p1flx.value );
      } // THEN
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "too many values are provided" ){
      const unsigned int jp1 = 5;
      const unsigned int ngnd = 7;
      iRecordStream<char> iss( std::istringstream(
                               " 1.0 2.0 3.0 4.0 5.0 6.0 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( WIMSR::Card8( iss, ngnd, jp1 ) );
      } // THEN
    } // WHEN

    WHEN( "too few values are provided" ){
      const unsigned int jp1 = 5;
      const unsigned int ngnd = 7;
      iRecordStream<char> iss( std::istringstream( " 1.0 2.0 3.0 4.0 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( WIMSR::Card8( iss, ngnd, jp1 ) );
      } // THEN
    } // WHEN

    WHEN( "more values than ngnd are provided" ){
      const unsigned int jp1 = 5;
      const unsigned int ngnd = 4;
      iRecordStream<char> iss( std::istringstream( " 1.0 2.0 3.0 4.0 5.0 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( WIMSR::Card8( iss, ngnd, jp1 ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
