#define CATCH_CONFIG_MAIN

#include <numeric>

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Xstep output values", "[PLOTR],[Card5], [Xstep]"){

  GIVEN( "valid Xstep parameters" ){
    std::vector<double> validValues{0.1,0.5,0.8,1.0,2.0,80.0};

    THEN( "the returned class has the correct value" ){
      for( auto xstep : validValues ){
        iRecordStream<char> issXstep( 
            std::istringstream( std::to_string( xstep ) ) );

        REQUIRE( xstep == argument::extract< PLOTR::Card5::Xstep >( 
                          issXstep ).value );
      }
    }
  } // GIVEN

  GIVEN( "default value" ){
    iRecordStream<char> issXstep( std::istringstream( " /" ) );

    THEN( "default value is returned" ){
      REQUIRE( Approx( 1.0 ) == argument::extract< PLOTR::Card5::Xstep >(
                          issXstep ).value );
    }
  }//GIVEN

  GIVEN( "invalid Xstep parameters" ){
    std::vector<double> invalidValues{ -2.0, -1.1, 0.0 };

    THEN( "the class throws an exception" ){
      for( auto xstep : invalidValues ){
        iRecordStream<char> issXstep( 
            std::istringstream( std::to_string( xstep ) ) );

        REQUIRE_THROWS( argument::extract< PLOTR::Card5::Xstep >( issXstep ) );
      }
    }
  } // GIVEN
} // SCENARIO
