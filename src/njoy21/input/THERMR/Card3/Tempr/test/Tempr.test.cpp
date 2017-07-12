#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Tempr input values",
  "[Card3], [Tempr]" ){
  GIVEN( "a value for ntemp (number of temperatures)" ){
    Argument< THERMR::Card2::Ntemp > ntemp; ntemp.value = 3;
    WHEN( "there are the correct number of temperatures and they are valid" ){
      iRecordStream< char> iss( std::istringstream("1.0 2.0 3.0") );
      THEN( "the temperature values can be extracted correctly" ){
        auto temprs = argument::extract< 
                    THERMR::Card3::Tempr >(iss, ntemp);
        std::vector< dimwits::Quantity< dimwits::Kelvin > > refTemprs{
                      1.0*dimwits::kelvin, 
                      2.0*dimwits::kelvin, 
                      3.0*dimwits::kelvin};
        REQUIRE( refTemprs == temprs.value );
      } // THEN
    } // WHEN
    WHEN( "the temperature values are invalid" ){
      iRecordStream< char> iss( std::istringstream(" 1.0 -2.0 3.0") );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS(
            argument::extract< THERMR::Card3::Tempr >(iss, ntemp) );
      } // THEN
    } // WHEN
    WHEN( "the temperature values are not in increasing order" ){
      iRecordStream< char> iss( std::istringstream(" 1.0 2.0 1.5") );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS(
            argument::extract< THERMR::Card3::Tempr >(iss, ntemp) );
      } // THEN
    } // WHEN
    WHEN( "commas are used to separate values" ){
      iRecordStream< char> iss( std::istringstream(" 1.0, 2.0, 3.0") );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS(
            argument::extract< THERMR::Card3::Tempr >(iss, ntemp) );
      } // THEN
    } // WHEN
    WHEN( "there are not enough temperature values" ){
      iRecordStream< char> iss( std::istringstream(" 1.0 2.0") );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS(
            argument::extract< THERMR::Card3::Tempr >(iss, ntemp) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
