#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "LEAPR Card10 temp input values",
  "[LEAPR], [Card10], [Temp] "){
  GIVEN( "valid temp values" ){
    WHEN( "temp values provided" ){
      std::vector<double> validTemp{ -293.0, 0.0, 293.6, 500.0 };
      THEN( "the returned class has the correct value" ){
        for( auto temp : validTemp ){
          iRecordStream<char> iss( std::istringstream( std::to_string(temp) ) );
          REQUIRE( temp * dimwits::kelvin == 
          ( argument::extract< LEAPR::Card10::Temp >( iss ) ).value );
        }
      } // THEN
    } // WHEN
    WHEN( "no temp values provided" ){
      THEN( "an exception is thrown" ){
        iRecordStream<char> iss( std::istringstream( " /" ) );
        REQUIRE_THROWS( argument::extract< LEAPR::Card10::Temp >(iss) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
