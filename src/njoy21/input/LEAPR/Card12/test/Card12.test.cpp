#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;
SCENARIO( "LEAPR Card12 input values",
  "[LEAPR], [Card12]" ){
  GIVEN( "a small value for ni" ){
    Argument< LEAPR::Card11::Ni > ni;
    ni.value = 3;

    WHEN( "there are the correct number of card12 inputs and they are valid" ){
      iRecordStream< char> iss( std::istringstream(" 1.0 2.0 3.0") );

      THEN( "the card12 input values can be extracted correctly" ){
        std::vector< double > refRhos{ 1.0, 2.0, 3.0 };
        LEAPR::Card12 card12( iss, ni );
        REQUIRE( refRhos == card12.rho.value );
      } // THEN
    } // WHEN
    WHEN( "a card12 input value are out of range" ){
      iRecordStream< char> iss( std::istringstream("-1.0 2.0 3.0") );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( LEAPR::Card12( iss, ni ) );
      } // THEN
    } // WHEN
    WHEN( "too few card12 input values are provided" ){
      iRecordStream< char> iss( std::istringstream("1.0 2.0") );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( LEAPR::Card12( iss, ni ) );
      } // THEN
    } // WHEN
    WHEN( "too many card12 values are provided" ){
      iRecordStream< char> iss( std::istringstream("1.0 2.0 3.0 4.0") );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( LEAPR::Card12( iss, ni ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
