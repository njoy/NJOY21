#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;
SCENARIO( "LEAPR Card12 input values",
  "[LEAPR], [Card12]" ){
  GIVEN( "a small value for ni" ){
    Argument< LEAPR::Card11::Ni > ni;
    ni.value = 3;

    WHEN( "there are the correct number of rhos and they are valid" ){
      iRecordStream< char> iss( std::istringstream(" 1.0 2.0 3.0") );

      THEN( "the rho values can be extracted correctly" ){
        std::vector< double > refRhos{ 1.0, 2.0, 3.0 };
        LEAPR::Card12 card12( iss, ni );
        REQUIRE( refRhos * dimwits::electronVolts == card12.rho.value );
      } // THEN
    } // WHEN
    WHEN( "the rho values are invalid" ){
      iRecordStream< char> iss( std::istringstream("-1.0 2.0 3.0") );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( LEAPR::Card12( iss, ni ) );
      } // THEN
    } // WHEN
    WHEN( "too few rho values are provided" ){
      iRecordStream< char> iss( std::istringstream("1.0 2.0") );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( LEAPR::Card12( iss, ni ) );
      } // THEN
    } // WHEN
    WHEN( "too many rho values are provided" ){
      iRecordStream< char> iss( std::istringstream("1.0 2.0 3.0 4.0") );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( LEAPR::Card12( iss, ni ) );
      } // THEN
    } // WHEN
  } // GIVEN

  GIVEN( "a larger value for ni" ){
    Argument< LEAPR::Card11::Ni > ni;
    ni.value = 15;

    WHEN( "there are the correct number of rhos and they are valid" ){
      iRecordStream< char> iss( std::istringstream(
      ".010 .015 .025 .035 .050 .075 .101 .150\n"
      "2.5e-1 3.3e-1  5.04e-1 7.56e-1 1.01e+0 1.26e+0 1.51e+0/"
      ) );

      THEN( "the rho values can be extracted correctly" ){
        std::vector< double > refRhos{.01, .015, .025, .035, .05,
          .075, .101, .150, .25, .33, .504, .756, 1.01, 1.26, 1.51};
        LEAPR::Card12 card12( iss, ni );
        REQUIRE( refRhos * dimwits::electronVolts == card12.rho.value );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
