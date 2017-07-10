#define CATCH_CONFIG_MAIN

#include <numeric>

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Mtd output values", "[GROUPR],[Card9], [Mtd]"){
  GIVEN( "valid Mtd parameters" ){
    std::vector<int> validValues{ -999, -5, -4, -3, -2, -1, 1, 2, 3, 4, 5, 999};

    THEN( "the returned class has the correct value" ){
      for( auto mtd : validValues ){
        iRecordStream<char> issMtd( 
            std::istringstream( std::to_string( mtd ) ) );

        REQUIRE( mtd == argument::extract< GROUPR::Card9::Mtd >( 
                          issMtd ).value );
      }
    }
    WHEN( "no value is specified" ){
      THEN( "the default value is returned" ){
        iRecordStream<char> issMtd( std::istringstream( "/" ) );

        REQUIRE( 0 == argument::extract< GROUPR::Card9::Mtd >( issMtd ).value );
      }
    }
  } // GIVEN
  GIVEN( "invalid Mtd parameters" ){
    std::vector<int> invalidValues{ 1000 };

    THEN( "the returned class has the correct value" ){
      for( auto mtd : invalidValues ){
        iRecordStream<char> issMtd( 
            std::istringstream( std::to_string( mtd ) ) );

        REQUIRE_THROWS( argument::extract< GROUPR::Card9::Mtd >( issMtd ) );
      }
    }
  } // GIVEN
} // SCENARIO
