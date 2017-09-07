#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Egg input values", "[Card4], [Egg]" ){
  GIVEN( "a value for ngg (number of temperatures)" ){
    Argument< GAMINR::Card4::Ngg > ngg;
    ngg.value = 3;

    WHEN( "there are the correct number of temperatures and they are valid" ){
      iRecordStream< char> issPoints( std::istringstream(" 1.0 2.0 3.0 4.0 /") );

      THEN( "the energy boundaries can be extracted correctly" ){
        auto egg = argument::extract< GAMINR::Card4::Egg >(
            issPoints, ngg.value+1);
        std::vector< dimwits::Quantity< dimwits::ElectronVolt > > refEggs{
                      1.0*dimwits::electronVolt, 
                      2.0*dimwits::electronVolt, 
                      3.0*dimwits::electronVolt,
                      4.0*dimwits::electronVolt};
        REQUIRE( refEggs == egg.value );
      }
    }

    WHEN( "the energy boundaries are invalid" ){
      iRecordStream< char> issPoints( std::istringstream(" 1.0 -2.0 3.0 4.0") );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS(
            argument::extract< GAMINR::Card4::Egg >(issPoints, ngg.value+1) );
      }
    }

    WHEN( "the energy boundaries are not in increasing order" ){
      iRecordStream< char> issPoints( std::istringstream(" 1.0 2.2 2.0 4.0") );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS(
            argument::extract< GAMINR::Card4::Egg >(issPoints, ngg.value+1) );
      }
    }

    WHEN( "commas are used to separate values" ){
      iRecordStream< char> issPoints( std::istringstream(" 1.0, 2.0, 3.0, 4.0") );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS(
            argument::extract< GAMINR::Card4::Egg >(issPoints, ngg.value+1) );
      }
    }

    WHEN( "there are too many energy boundaries" ){
      iRecordStream< char> issPoints( 
          std::istringstream(" 1.0 2.0 3.0 4.0 5.0/") );

      THEN( "an exception is thrown" ){
        REQUIRE_NOTHROW(
            argument::extract< GAMINR::Card4::Egg >(issPoints, ngg.value+1) );
      }
    }

    WHEN( "there are not enough many energy boundaries" ){
      iRecordStream< char> issPoints( std::istringstream(" 1.0 2.0 3.0") );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS(
            argument::extract< GAMINR::Card4::Egg >(issPoints, ngg.value+1) );
      }
    }
  }
} // SCENARIO
