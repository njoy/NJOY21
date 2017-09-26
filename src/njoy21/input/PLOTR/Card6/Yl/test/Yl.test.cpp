#define CATCH_CONFIG_MAIN

#include <numeric>

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Yl output values", "[PLOTR],[Card6], [Yl]"){

  GIVEN( "valid Yl parameters" ){
    std::vector<float> validValues{0.0,0.1,0.5,0.8,1.0,2.0,80.0};

    THEN( "the returned class has the correct value" ){
      for( auto yl : validValues ){
        iRecordStream<char> issYl( 
            std::istringstream( std::to_string( yl ) ) );

        REQUIRE( yl == argument::extract< PLOTR::Card6::Yl >( 
                          issYl ).value );
      }
    }
  } // GIVEN

  GIVEN( "default value" ){
    iRecordStream<char> issYl( std::istringstream( " /" ) );

    THEN( "default value is returned" ){
      REQUIRE( 0.0f == argument::extract< PLOTR::Card6::Yl >(
                          issYl ).value );
    }
  }//GIVEN

  GIVEN( "invalid Yl parameters" ){
    std::vector<float> invalidValues{ -2.0, -1.1 };

    THEN( "the class throws an exception" ){
      for( auto yl : invalidValues ){
        iRecordStream<char> issYl( 
            std::istringstream( std::to_string( yl ) ) );

        REQUIRE_THROWS( argument::extract< PLOTR::Card6::Yl >( issYl ) );
      }
    }
  } // GIVEN
} // SCENARIO
