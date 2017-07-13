#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Dtemp input values",
  "[DTFT],[Card8],[Dtemp] "){
  GIVEN( "valid dtemp values" ){
    WHEN( "dtemp values provided" ){
      std::vector<double> validDtemp{ 0.0, 293.6, 500.0 };
      THEN( "the returned class has the correct value" ){
        for( auto dtemp : validDtemp ){
          iRecordStream<char> iss( std::istringstream( std::to_string(dtemp) ));
          REQUIRE( dtemp * dimwits::kelvin == 
          ( argument::extract< DTFR::Card8::Dtemp >( iss ) ).value );
        }
      } // THEN
    } // WHEN
    WHEN( "no dtemp values provided" ){
      THEN( "the default value is used" ){
        iRecordStream<char> iss( std::istringstream( " /" ) );
        REQUIRE( 300.0 * dimwits::kelvin == 
          ( argument::extract< DTFR::Card8::Dtemp > ( iss ) ).value );
      } // THEN
    } // WHEN
  } // GIVEN

  GIVEN( "invalid dtemp values" ){
    std::vector<double> invalidDtemp{ -0.1, -293.6, -500.0 };
    THEN( "an exception is thrown" ){
      for( auto dtemp : invalidDtemp ){
        iRecordStream<char> iss( std::istringstream( std::to_string(dtemp) ) );
	REQUIRE_THROWS( argument::extract< DTFR::Card8::Dtemp >(iss) );
      }
    } // THEN
  } // GIVEN
} // SCENARIO
