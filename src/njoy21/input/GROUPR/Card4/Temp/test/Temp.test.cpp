#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Temp input values",
         "[Card4], [Temp]" ){
  GIVEN( "a value for ntemp (number of temperatures)" ){
    Argument< GROUPR::Card2::Ntemp > ntemp;
    ntemp.value = 3;

    WHEN( "there are the correct number of temperatures and they are valid" ){
      iRecordStream< char> issValues( std::istringstream(" 1.0 2.0 3.0") );

      THEN( "the temperature values can be extracted correctly" ){
        auto temps = argument::extract< 
                    GROUPR::Card4::Temp >(issValues, ntemp);
        std::vector< dimwits::Quantity< dimwits::Kelvin > > refTemps{
                      1.0*dimwits::kelvin, 
                      2.0*dimwits::kelvin, 
                      3.0*dimwits::kelvin};
        REQUIRE( refTemps == temps.value );
      }
    }

    WHEN( "the temperature values are invalid" ){
      iRecordStream< char> issValues( std::istringstream(" 1.0 -2.0 3.0") );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS(
            argument::extract< GROUPR::Card4::Temp >(issValues, ntemp) );
      }
    }

    WHEN( "the temperature values are not in increasing order" ){
      std::string temps(" 1.0 2.0 1.5");
      iRecordStream< char> issValues( (std::istringstream(temps)) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS(
            argument::extract< GROUPR::Card4::Temp >(issValues, ntemp) );
      }
    }

    WHEN( "commas are used to separate values" ){
      iRecordStream< char> issValues( std::istringstream(" 1.0, 2.0, 3.0") );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS(
            argument::extract< GROUPR::Card4::Temp >(issValues, ntemp) );
      }
    }

    WHEN( "there are too many temperature values" ){
      iRecordStream< char> issValues( std::istringstream(" 1.0 2.0 3.0 4.0") );

      THEN( "an exception is thrown" ){
        REQUIRE_NOTHROW(
            argument::extract< GROUPR::Card4::Temp >(issValues, ntemp) );
      }
    }

    WHEN( "there are not enough temperature values" ){
      iRecordStream< char> issValues( std::istringstream(" 1.0 2.0") );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS(
            argument::extract< GROUPR::Card4::Temp >(issValues, ntemp) );
      }
    }
  }
} // SCENARIO
