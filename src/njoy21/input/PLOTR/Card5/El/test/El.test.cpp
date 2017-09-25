#define CATCH_CONFIG_MAIN

#include <numeric>

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "El output values", "[PLOTR],[Card5], [El]"){

  GIVEN( "valid El parameters" ){
    std::vector<float> validValues{0.0,0.1,0.5,0.8,1.0,2.0,80.0};

    THEN( "the returned class has the correct value" ){
      for( auto el : validValues ){
        iRecordStream<char> issEl( 
            std::istringstream( std::to_string( el ) ) );

        REQUIRE( el == argument::extract< PLOTR::Card5::El >( 
                          issEl ).value );
      }
    }
  } // GIVEN

  GIVEN( "default value" ){
    iRecordStream<char> issEl( std::istringstream( " /" ) );

    THEN( "default value is returned" ){
      REQUIRE( 0.0f == argument::extract< PLOTR::Card5::El >(
                          issEl ).value );
    }
  }//GIVEN

  GIVEN( "invalid El parameters" ){
    std::vector<float> invalidValues{ -2.0, -1.1 };

    THEN( "the class throws an exception" ){
      for( auto el : invalidValues ){
        iRecordStream<char> issEl( 
            std::istringstream( std::to_string( el ) ) );

        REQUIRE_THROWS( argument::extract< PLOTR::Card5::El >( issEl ) );
      }
    }
  } // GIVEN
} // SCENARIO
