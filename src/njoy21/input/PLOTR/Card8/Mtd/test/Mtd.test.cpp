#define CATCH_CONFIG_MAIN

#include <numeric>

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Mtd output values", "[PLOTR],[Card8], [Mtd]"){
  int iverf = 2;
  GIVEN( "valid Mtd parameters" ){
    std::vector<int> validValues{ -999, -5, -4, -3, -2, -1, 1, 2, 3, 4, 5, 999};

    THEN( "the returned class has the correct value" ){
      for( auto mtd : validValues ){
        iRecordStream<char> issMtd( 
            std::istringstream( std::to_string( mtd ) ) );

        REQUIRE( mtd == argument::extract< PLOTR::Card8::Mtd >( 
                          issMtd, iverf ).value );
      }
    }
    WHEN( "no value is specified" ){
      THEN( "the default value is returned" ){
        iRecordStream<char> issMtd( std::istringstream( "/" ) );

        REQUIRE( 0 == argument::extract< PLOTR::Card8::Mtd >(
                                         issMtd, iverf ).value );
      }
    }
  } // GIVEN
  GIVEN( "invalid Mtd parameters" ){
    std::vector<int> invalidValues{ 1000 };

    THEN( "the returned class has the correct value" ){
      for( auto mtd : invalidValues ){
        iRecordStream<char> issMtd( 
            std::istringstream( std::to_string( mtd ) ) );

        REQUIRE_THROWS( argument::extract< PLOTR::Card8::Mtd >(
                                           issMtd, iverf ) );
      }
    }
  } // GIVEN
  GIVEN( "Iverf == 0" ){
    iverf = 0;
    std::vector<int> meaninglessMtd{ -1000, -999, -40, -2, 0, 2, 40, 999, 1000};
    THEN( "these values are ignored" ){
      for( auto mtd : meaninglessMtd ){
        iRecordStream<char> issMtd( std::istringstream(
                                    std::to_string( mtd ) ) );
        REQUIRE_NOTHROW( argument::extract< PLOTR::Card8::Mtd >(
                                            issMtd, iverf ) );
      }
    }
  }//GIVEN
} // SCENARIO
