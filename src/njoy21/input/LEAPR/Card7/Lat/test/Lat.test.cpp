#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "LEAPR lat values",
  "[LEAPR], [Card7], [Lat]"){

  GIVEN( "valid lat values" ){
    WHEN( "lat value is given" ){
      std::vector<int> validValues{0, 1};
      THEN( "the returned class has the correct value" ){
        for( int lat : validValues ){
          iRecordStream<char> iss( 
            std::istringstream( std::to_string( lat ) ) );
          REQUIRE( lat == argument::extract< 
            LEAPR::Card7::Lat >( iss ).value );
        }
      } // THEN
    } // WHEN
    WHEN( "no lat value is given" ){
      iRecordStream<char> iss(
        std::istringstream( " / " ) );
      THEN( "default value is used" ){
        REQUIRE( 0 == argument::extract<
          LEAPR::Card7::Lat >( iss ).value );
      } // THEN
    } // WHEN
  } // GIVEN

  GIVEN( "invalid lat values" ){
    std::vector<int> invalidValues{-1, 2};
    THEN( "an exception is thrown" ){
      for( int lat : invalidValues ){
        iRecordStream<char> iss( 
          std::istringstream( std::to_string( lat ) ) );
        REQUIRE_THROWS( argument::extract< 
          LEAPR::Card7::Lat >( iss ) );
      }
    } // THEN
  } // GIVEN
} // SCENARIO
