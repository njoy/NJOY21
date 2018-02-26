#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;
SCENARIO( "LEAPR Card18 input values",
  "[LEAPR], [Card18]" ){
  GIVEN( "a value for nka" ){
    auto InvAng =  dimwits::pow( 1.0 * dimwits::angstrom, dimwits::Ratio<-1> );
    Argument< LEAPR::Card17::Nka > nka;
    nka.value = 3;

    WHEN( "there are the correct number of card18 inputs and they are valid" ){
      iRecordStream< char> iss( std::istringstream(" 1.0 2.0 3.0") );

      THEN( "the skappa values can be extracted correctly" ){
        std::vector< decltype(InvAng) > refSkappas{ 1.0 * InvAng, 
                                                    2.0 * InvAng, 
                                                    3.0 * InvAng };
        LEAPR::Card18 card18( iss, nka );
        REQUIRE( refSkappas == card18.skappa.value );
      } // THEN
    } // WHEN
    WHEN( "a card18 input value is out of range" ){
      iRecordStream< char> iss( std::istringstream("0.0 2.0 3.0") );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( LEAPR::Card18( iss, nka ) );
      } // THEN
    } // WHEN
//    WHEN( "the card18 input values are not in increasing order" ){
//      iRecordStream< char> iss( std::istringstream("1.0 3.0 2.0") );
//      THEN( "an exception is thrown" ){
//        REQUIRE_THROWS( LEAPR::Card18( iss, nka ) );
//      } // THEN
//    } // WHEN
    WHEN( "too few card18 input values are provided" ){
      iRecordStream< char> iss( std::istringstream("1.0 2.0") );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( LEAPR::Card18( iss, nka ) );
      } // THEN
    } // WHEN
    WHEN( "too many card18 input values are provided" ){
      iRecordStream< char> iss( std::istringstream("1.0 2.0 3.0 4.0") );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( LEAPR::Card18( iss, nka ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
