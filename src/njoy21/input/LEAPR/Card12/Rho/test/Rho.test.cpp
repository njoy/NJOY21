#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "LEAPR Card12 rho input values",
  "[LEAPR], [Card12], [Rho]" ){
  GIVEN( "a small value for ni" ){
    Argument< LEAPR::Card11::Ni > ni;
    ni.value = 3;

    WHEN( "there are the correct number of rhos and they are valid" ){
      iRecordStream< char> iss( std::istringstream(" 1.0 2.0 3.0") );

      THEN( "the rho values can be extracted correctly" ){
        auto rhos = argument::extract< 
          LEAPR::Card12::Rho >(iss, ni);
        std::vector< double > refRhos{ 1.0, 2.0, 3.0 };
        REQUIRE( refRhos == rhos.value );
      } // THEN
    } // WHEN
    WHEN( "the rho values are invalid" ){
      iRecordStream< char> iss( std::istringstream("-1.0 2.0 3.0") );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< 
          LEAPR::Card12::Rho >( iss, ni ) );
      } // THEN
    } // WHEN
    WHEN( "too few rho values are provided" ){
      iRecordStream< char> iss( std::istringstream("1.0 2.0") );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract<
          LEAPR::Card12::Rho >( iss, ni ) );
      } // THEN
    } // WHEN
    WHEN( "too many rho values are provided" ){
      iRecordStream< char> iss( std::istringstream("1.0 2.0 3.0 4.0") );
      THEN( "an exception is thrown" ){
        REQUIRE_NOTHROW( argument::extract<
          LEAPR::Card12::Rho >( iss, ni ) );
      } // THEN
    } // WHEN
  } // GIVEN

  GIVEN( "a larger value for ni" ){
    Argument< LEAPR::Card11::Ni > ni;
    ni.value = 7;

    WHEN( "there are the correct number of rhos and they are valid" ){
      iRecordStream< char> iss( std::istringstream(
      ".010 .015 .025 .035\n"
      "2.5e-1 3.3e-1  5.04e-1/"
      ) );

      THEN( "the rho values can be extracted correctly" ){
        auto rhos = argument::extract< 
          LEAPR::Card12::Rho >(iss, ni);
        std::vector< double > refRhos{ 
          .01, .015, .025, .035, .250, .330, .504 };
        REQUIRE( refRhos == rhos.value );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
