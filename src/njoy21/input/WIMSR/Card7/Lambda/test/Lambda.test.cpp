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
      std::vector<double> res = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9,
                                 1.0, 1.1, 1.2, 1.3};
      iRecordStream<char> iss( std::istringstream(
                   " 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0 1.1 1.2 1.3" ) );

      THEN( "the values can be verified" ){
        auto res_val = argument::extract< WIMSR::Card7::Lambda >(iss, nrg,
                                                                 igroup ).value;
        REQUIRE( res == res_val );
      }
    } // WHEN

    WHEN( "valid inputs are provided using non-default igroup structure" ){
      const int igroup = 1;
      const unsigned int nrg = 12;
      std::vector<double> res {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9,
                               1.0, 1.1, 1.2};
      iRecordStream<char> iss( std::istringstream(
                   " 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0 1.1 1.2" ) );

      THEN( "the values can be verified" ){
        auto res_val = argument::extract< WIMSR::Card7::Lambda >(iss, nrg,
                                                                 igroup ).value;

        REQUIRE( res == res_val );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "the number of values doesn't match for default group structure" ){
      const int igroup = 0;
      const unsigned int nrg = 12;
      iRecordStream<char> iss( std::istringstream(
                   " 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0 1.1 1.2" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< WIMSR::Card7::Lambda >(
                        iss, nrg, igroup ) );
      }
    } // WHEN

    WHEN( "too few elements are provided" ){
      const int igroup = 1;
      const unsigned int nrg = 12;
      iRecordStream<char> iss( std::istringstream(
                   " 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0 1.1" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< WIMSR::Card7::Lambda >(
                        iss, nrg, igroup ) );
      }
    } // WHEN

    WHEN( "an negative lambda is included" ){
      const int igroup = 1;
      const unsigned int nrg = 12;
      iRecordStream<char> iss( std::istringstream(
                   " 0.1 0.2 0.3 0.4 0.5 0.6 0.7 -0.8 0.9 1.0 1.1 1.2" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< WIMSR::Card7::Lambda >(
                        iss, nrg, igroup ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
