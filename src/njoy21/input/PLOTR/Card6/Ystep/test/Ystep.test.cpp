#define CATCH_CONFIG_MAIN

#include <numeric>

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Ystep output values", "[PLOTR],[Card6], [Ystep]"){

  GIVEN( "valid Ystep parameters" ){
    std::vector<double> validValues{0.1,0.5,0.8,1.0,2.0,80.0};

    THEN( "the returned class has the correct value" ){
      for( auto ystep : validValues ){
        iRecordStream<char> issYstep( 
            std::istringstream( std::to_string( ystep ) ) );

        REQUIRE( ystep == argument::extract< PLOTR::Card6::Ystep >( 
                          issYstep ).value );
      }
    }
  } // GIVEN

  GIVEN( "default value" ){
    iRecordStream<char> issYstep( std::istringstream( " /" ) );

    THEN( "default value is returned" ){
      REQUIRE( 1.0f == argument::extract< PLOTR::Card6::Ystep >(
                          issYstep ).value );
    }
  }//GIVEN

  GIVEN( "invalid Ystep parameters" ){
    std::vector<double> invalidValues{ -2.0, -1.1, 0.0 };

    THEN( "the class throws an exception" ){
      for( auto ystep : invalidValues ){
        iRecordStream<char> issYstep( 
            std::istringstream( std::to_string( ystep ) ) );

        REQUIRE_THROWS( argument::extract< PLOTR::Card6::Ystep >( issYstep ) );
      }
    }
  } // GIVEN
} // SCENARIO
