#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;
SCENARIO( "LEAPR Card9 beta input values",
  "[LEAPR], [Card9], [Beta]" ){
  GIVEN( "a small value for nbeta" ){
    Argument< LEAPR::Card7::Nbeta > nbeta;
    nbeta.value = 3;

    WHEN( "there are the correct number of betas and they are valid" ){
      iRecordStream< char> iss( std::istringstream(" 1.0 2.0 3.0") );

      THEN( "the beta values can be extracted correctly" ){
        std::vector< double > refBetas{ 1.0, 2.0, 3.0 };
        LEAPR::Card9 card9( iss, nbeta );
        REQUIRE( refBetas == card9.beta.value );
      } // THEN
    } // WHEN
    WHEN( "the beta values are invalid" ){
      iRecordStream< char> iss( std::istringstream("-1.0 2.0 3.0") );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( LEAPR::Card9( iss, nbeta ) );
      } // THEN
    } // WHEN
    WHEN( "beta values are not in increasing order" ){
      iRecordStream< char> iss( std::istringstream(" 2.0 1.0 3.0") );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( LEAPR::Card9( iss, nbeta ) );
      } // THEN
    } // WHEN
    WHEN( "too few beta values are provided" ){
      iRecordStream< char> iss( std::istringstream("1.0 2.0") );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( LEAPR::Card9( iss, nbeta ) );
      } // THEN
    } // WHEN
    WHEN( "too many beta values are provided" ){
      iRecordStream< char> iss( std::istringstream("1.0 2.0 3.0 4.0") );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( LEAPR::Card9( iss, nbeta ) );
      } // THEN
    } // WHEN
  } // GIVEN

  GIVEN( "a larger value for nbeta" ){
    Argument< LEAPR::Card7::Nbeta > nbeta;
    nbeta.value = 15;

    WHEN( "there are the correct number of betas and they are valid" ){
      iRecordStream< char> iss( std::istringstream(
      ".010 .015 .025 .035 .050 .075 .101 .150\n"
      "2.5e-1 3.3e-1  5.04e-1 7.56e-1 1.01e+0 1.26e+0 1.51e+0/"
      ) );

      THEN( "the beta values can be extracted correctly" ){
        std::vector< double > refBetas{.01, .015, .025, .035, .05,
          .075, .101, .150, .25, .33, .504, .756, 1.01, 1.26, 1.51};
        LEAPR::Card9 card9( iss, nbeta );
        REQUIRE( refBetas == card9.beta.value );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
