#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;
SCENARIO( "LEAPR Card10 input values",
  "[LEAPR], [Card10]" ){
  GIVEN( "valid card10 entry" ){
    std::vector<double> validValues{-293.5, 293.5};
    THEN( "the returned values are correct" ){
      for( auto& temp : validValues ){
        iRecordStream<char> iss(
          std::istringstream( std::to_string( temp ) ) );
        LEAPR::Card10 card10( iss );
        REQUIRE( card10.temp.value == temp * dimwits::kelvin );
      }
    } // THEN
  } // GIVEN

  GIVEN( "invalid card10 input" ){
    WHEN( "no card10 input is provided" ){
      iRecordStream<char> iss( std::istringstream( " / " ) );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( LEAPR::Card10( iss ) );
      } // THEN
    } // WHEN
    WHEN( "card10 input is out of range" ){
      iRecordStream<char> iss( std::istringstream( "0.0" ) );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( LEAPR::Card10( iss ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO

