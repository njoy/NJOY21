#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Temp input values",
         "[Card3], [Temp]" ){
  GIVEN( "a value for ntemp (number of temperatures)" ){
    Argument< PURR::Card2::Ntemp > ntemp;
    ntemp.value = 3;

    WHEN( "there are the correct number of temperatures and they are valid" ){
      iRecordStream< char> issPoints( std::istringstream(" 1.0 2.0 3.0") );

      THEN( "the grid points can be extracted correctly" ){
        auto temps = argument::extract< 
                    PURR::Card3::Temp >(issPoints, ntemp);
        std::vector< dimwits::Quantity< dimwits::Kelvin > > refTemps{
                      1.0*dimwits::kelvin, 
                      2.0*dimwits::kelvin, 
                      3.0*dimwits::kelvin};
        REQUIRE( refTemps == temps.value );
      }
    }

    WHEN( "the grid points are invalid" ){
      iRecordStream< char> issPoints( std::istringstream(" 1.0 -2.0 3.0") );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS(
            argument::extract< PURR::Card3::Temp >(issPoints, ntemp) );
      }
    }

    WHEN( "commas are used to separate values" ){
      iRecordStream< char> issPoints( std::istringstream(" 1.0, 2.0, 3.0") );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS(
            argument::extract< PURR::Card3::Temp >(issPoints, ntemp) );
      }
    }

    WHEN( "there are too many grid points" ){
      iRecordStream< char> issPoints( std::istringstream(" 1.0 2.0 3.0 4.0") );

      THEN( "an exception is thrown" ){
        REQUIRE_NOTHROW(
            argument::extract< PURR::Card3::Temp >(issPoints, ntemp) );
      }
    }

    WHEN( "there are not enough grid points" ){
      iRecordStream< char> issPoints( std::istringstream(" 1.0 2.0") );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS(
            argument::extract< PURR::Card3::Temp >(issPoints, ntemp) );
      }
    }
  }
} // SCENARIO
