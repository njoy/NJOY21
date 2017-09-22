#define CATCH_CONFIG_MAIN

#include <numeric>

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Wr output values", "[PLOTR],[Card2], [Wr]"){

  GIVEN( "valid Wr parameters" ){
    std::vector<float> validValues{-90.0, -27.5, 0.0, 19.3, 182.9, 721.8};

    THEN( "the returned class has the correct value" ){
      for( auto wr : validValues ){
        iRecordStream<char> issWr( 
            std::istringstream( std::to_string( wr ) ) );

        REQUIRE( wr == argument::extract< PLOTR::Card2::Wr >( 
                          issWr ).value );
      }
    }
  } // GIVEN

  GIVEN( "no Wr parameter provided" ){
    THEN( "the default value is returned" ){
      iRecordStream<char> issWr( std::istringstream( " /" ) );
      REQUIRE( 0.0f == argument::extract< PLOTR::Card2::Wr >( 
                         issWr ).value );
    }
  } //GIVEN

  GIVEN( "invalid Wr parameters" ){
    std::vector<float> invalidValues{ -90.1 };

    THEN( "the returned class has the correct value" ){
      for( auto wr : invalidValues ){
        iRecordStream<char> issWr( 
            std::istringstream( std::to_string( wr ) ) );

        REQUIRE_THROWS( argument::extract< PLOTR::Card2::Wr >( issWr ) );
      }
    }
  } // GIVEN
} // SCENARIO
