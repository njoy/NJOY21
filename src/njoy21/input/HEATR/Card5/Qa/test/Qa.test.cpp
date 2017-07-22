#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "HEATR qa values",
  "[HEATR], [Card5], [Qa]"){
  GIVEN( "a card2 nqa input value" ){
    Argument< HEATR::Card2::Nqa > nqa; nqa.value = 3;
    WHEN( "qa entries are valid" ){
      iRecordStream<char> iss( std::istringstream( "-1.5e6 1.6e6 -98e6" ) );
      THEN( "the q values can be extracted correctly" ){
        auto qas = argument::extract< HEATR::Card5::Qa >( iss, nqa );
        std::vector<dimwits::Quantity<dimwits::ElectronVolts>> refQa{ 
          -1.5e6 * dimwits::electronVolts, 
           1.6e6 * dimwits::electronVolts, 
          -98e6  * dimwits::electronVolts };
	REQUIRE( refQa == qas.value );
      } // THEN
    } // WHEN
    WHEN( "a qa entry has absolute value are greater than or equal to 99e6" ){
      iRecordStream<char> iss1( std::istringstream( "-1.5e6 -1.6e6 -99e6" ) );
      iRecordStream<char> iss2( std::istringstream( "1.5e6 1.6e6 10e7" ) );
      THEN( "no exception thrown" ){ 
        REQUIRE_NOTHROW( argument::extract< HEATR::Card5::Qa >( iss1, nqa ) );
        REQUIRE_NOTHROW( argument::extract< HEATR::Card5::Qa >( iss2, nqa ) );
      } // THEN
    } // WHEN
    WHEN( "commas are used to separate values" ){
      iRecordStream<char> iss( std::istringstream( "1.5e6, 1.6e6, 1.7e6" ) );
      THEN( "an exception is thrown" ){ 
        REQUIRE_THROWS( argument::extract< HEATR::Card5::Qa >( iss, nqa ) );
      } // THEN
    } // WHEN
    WHEN( "there are not enough q values" ){
      iRecordStream<char> iss( std::istringstream( "1.5e6 1.6e6" ) );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< HEATR::Card5::Qa >( iss, nqa ) );
      } // THEN
    } // WHEN
    WHEN( "there are too many q values" ){
      iRecordStream<char>iss( std::istringstream( "1.5e6 1.6e6 1.7e6 1.8e6" ) );
      THEN( "an exception is not thrown" ){
        REQUIRE_NOTHROW( argument::extract< HEATR::Card5::Qa >( iss, nqa ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
