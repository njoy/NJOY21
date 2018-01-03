#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "WIMSR, Card8, P1flx",
          "[WIMSR] [Card8] [P1flx]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid values are provided" ){
      const unsigned int jp1 = 5;
      const unsigned int ngnd = 7;
      iRecordStream<char> iss( std::istringstream( " 1.0 2.0 3.0 4.0 5.0" ) );

      THEN( "the values can be verified" ){
        std::vector<double> ref {1.0, 2.0, 3.0, 4.0, 5.0};
        REQUIRE( ref == argument::extract< WIMSR::Card8::P1flx >(
                                           iss, jp1, ngnd ).value );
      } // THEN
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "the number of values is greater than ngnd" ){
      const unsigned int jp1 = 5;
      const unsigned int ngnd = 4;
      iRecordStream<char> iss( std::istringstream( " 1.0 2.0 3.0 4.0 5.0" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< WIMSR::Card8::P1flx >(
                                           iss, jp1, ngnd ) );
      } // THEN
    } // WHEN

    WHEN( "there are fewer than jp1 elements" ){
      const unsigned int jp1 = 5;
      const unsigned int ngnd = 7;
      iRecordStream<char> iss( std::istringstream( " 1.0 2.0 3.0 4.0" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< WIMSR::Card8::P1flx >(
                                           iss, jp1, ngnd ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
