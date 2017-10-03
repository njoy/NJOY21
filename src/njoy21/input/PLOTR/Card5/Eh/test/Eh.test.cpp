#define CATCH_CONFIG_MAIN

#include <numeric>

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Eh output values", "[PLOTR],[Card5], [Eh]"){

  Argument< PLOTR::Card5::El > el;
  el.value = 0.0;

  GIVEN( "valid Eh parameters" ){
    std::vector<float> validValues{0.01,0.1,0.5,0.8,1.0,2.0,80.0};

    THEN( "the returned class has the correct value" ){
      for( auto eh : validValues ){
        iRecordStream<char> issEh( 
            std::istringstream( std::to_string( eh ) ) );

        REQUIRE( eh == argument::extract< PLOTR::Card5::Eh >( 
                          issEh, el ).value );
      }
    }
  } // GIVEN

  GIVEN( "default value" ){
    iRecordStream<char> issEh( std::istringstream( " /" ) );
    
    THEN( "default value is returned" ){
      REQUIRE( APPROX( 1.0 ) == argument::extract< PLOTR::Card5::Eh >(
                          issEh, el ).value );
    }
  }//GIVEN

  GIVEN( "invalid Eh parameters" ){
    std::vector<float> invalidValues{ -2.0, -1.1 };

    THEN( "the class throws an exception" ){
      for( auto eh : invalidValues ){
        iRecordStream<char> issEh( 
            std::istringstream( std::to_string( eh ) ) );

        REQUIRE_THROWS( argument::extract< PLOTR::Card5::Eh >( issEh, el ) );
      }
    }
  } // GIVEN

  GIVEN( "Eh is less than El" ){
    iRecordStream<char> issEh( std::istringstream( " 10.0 / " ) );
    el.value = 20.0;

    REQUIRE_THROWS( argument::extract< PLOTR::Card5::Eh >( issEh, el ) );
  }//GIVEN
} // SCENARIO
