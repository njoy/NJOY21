#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Verifying HEATR Card5 input", 
  "[HEATR], [Card5]" ){
  GIVEN( "a card2 nqa input value" ){
    Argument< HEATR::Card2::Nqa > nqa; nqa.value = 3;
    WHEN( "Card5 input is valid" ){
      iRecordStream<char> iss( std::istringstream( "-1.5e6 1.6e6 -98e6" ) );
      THEN( "the q values can be extracted correctly" ){
        std::vector<dimwits::Quantity<dimwits::ElectronVolts>> refQa{ 
          -1.5e6 * dimwits::electronVolts, 
          1.6e6  * dimwits::electronVolts, 
          -98e6  * dimwits::electronVolts };
	HEATR::Card5 card5( iss, nqa );
	REQUIRE( refQa == card5.qa.value );
      } // THEN
    } // WHEN
    WHEN( "a Card5 qa input value has large (>= 99 MeV) absolute value" ){
      iRecordStream<char> iss1( std::istringstream( "-1.5e6 -1.6e6 -10e7" ) );
      iRecordStream<char> iss2( std::istringstream( "1.5e6 1.6e6 99e6" ) );
      THEN( "an exception is thrown" ){
        REQUIRE_NOTHROW( HEATR::Card5( iss1, nqa ) );
        REQUIRE_NOTHROW( HEATR::Card5( iss2, nqa ) );
      } // THEN
    } // WHEN
    WHEN( "too few Card5 inputs are provided" ){
      iRecordStream<char> iss( std::istringstream( "1.5e6 1.6e6" ) );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( HEATR::Card5( iss, nqa ) );
      } // THEN
    } // WHEN
    WHEN( "too many Card5 inputs are provided" ){
      iRecordStream<char>iss( std::istringstream( "1.5e6 1.6e6 1.7e6 1.8e6" ) );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( HEATR::Card5( iss, nqa ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
