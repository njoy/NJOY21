#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "LEAPR Card8 alpha input values",
  "[LEAPR], [Card8], [Alpha]" ){
  GIVEN( "a small value for nalpha" ){
    Argument< LEAPR::Card7::Nalpha > nalpha;
    nalpha.value = 3;

    WHEN( "there are the correct number of alphas and they are valid" ){
      iRecordStream< char> iss( std::istringstream(" 1.0 2.0 3.0") );

      THEN( "the alpha values can be extracted correctly" ){
        auto alphas = argument::extract< 
          LEAPR::Card8::Alpha >(iss, nalpha);
        std::vector< double > refAlphas{ 1.0, 2.0, 3.0 };
        REQUIRE( refAlphas == alphas.value );
      } // THEN
    } // WHEN
    WHEN( "the alpha values are invalid" ){
      iRecordStream< char> iss( std::istringstream("-1.0 2.0 3.0") );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< 
          LEAPR::Card8::Alpha >( iss, nalpha ) );
      } // THEN
    } // WHEN
    WHEN( "alpha values are not in increasing order" ){
      iRecordStream< char> iss( std::istringstream(" 2.0 1.0 3.0") );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract<
          LEAPR::Card8::Alpha >( iss, nalpha ) );
      } // THEN
    } // WHEN
    WHEN( "too few alpha values are provided" ){
      iRecordStream< char> iss( std::istringstream("1.0 2.0") );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract<
          LEAPR::Card8::Alpha >( iss, nalpha ) );
      } // THEN
    } // WHEN
    WHEN( "too many alpha values are provided" ){
      iRecordStream< char> iss( std::istringstream("1.0 2.0 3.0 4.0") );
      THEN( "an exception is thrown" ){
        REQUIRE_NOTHROW( argument::extract<
          LEAPR::Card8::Alpha >( iss, nalpha ) );
      } // THEN
    } // WHEN
  } // GIVEN

  GIVEN( "a larger value for nalpha" ){
    Argument< LEAPR::Card7::Nalpha > nalpha;
    nalpha.value = 15;

    WHEN( "there are the correct number of alphas and they are valid" ){
      iRecordStream< char> iss( std::istringstream(
      ".010 .015 .025 .035 .050 .075 .101 .150\n"
      "2.5e-1 3.3e-1  5.04e-1 7.56e-1 1.01e+0 1.26e+0 1.51e+0/"
      ) );

      THEN( "the alpha values can be extracted correctly" ){
        auto alphas = argument::extract< 
          LEAPR::Card8::Alpha >(iss, nalpha);
        std::vector< double > refAlphas{.01, .015, .025, .035, .05,
          .075, .101, .150, .25, .33, .504, .756, 1.01, 1.26, 1.51};
        REQUIRE( refAlphas == alphas.value );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
