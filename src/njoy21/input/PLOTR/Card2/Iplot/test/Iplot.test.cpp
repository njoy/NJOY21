#define CATCH_CONFIG_MAIN

#include <numeric>

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Iplot output values", "[PLOTR],[Card2], [Iplot]"){

  GIVEN( "valid Iplot parameters" ){
    std::vector<int> validValues{-99,-8,-1,1,12,99};

    THEN( "the returned class has the correct value" ){
      for( auto iplot : validValues ){
        iRecordStream<char> issIplot( 
            std::istringstream( std::to_string( iplot ) ) );

        REQUIRE( iplot == argument::extract< PLOTR::Card2::Iplot >( 
                          issIplot ).value );
      }
    }
  } // GIVEN
  GIVEN( "no parameter provided" ){
    THEN( "the default value is used" ){
      iRecordStream<char> issIplot( std::istringstream( " /" ) );
      REQUIRE( 1 == argument::extract< PLOTR::Card2::Iplot>( issIplot ).value);
    }//THEN
  }//GIVEN
  GIVEN( "invalid Iplot parameters" ){
    std::vector<int> invalidValues{ 0, -100, 100};

    THEN( "the class throws an exception" ){
      for( auto iplot : invalidValues ){
        iRecordStream<char> issIplot( 
            std::istringstream( std::to_string( iplot ) ) );

        REQUIRE_THROWS( argument::extract< PLOTR::Card2::Iplot >( issIplot ) );
      }
    }
  } // GIVEN
} // SCENARIO
