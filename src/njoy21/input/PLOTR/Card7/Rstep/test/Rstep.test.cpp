#define CATCH_CONFIG_MAIN

#include <numeric>

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Rstep output values", "[PLOTR],[Card7], [Rstep]"){

  GIVEN( "valid Rstep parameters" ){
    std::vector<double> validValues{0.1,0.5,0.8,1.0,2.0,80.0};

    THEN( "the returned class has the correct value" ){
      for( auto rstep : validValues ){
        iRecordStream<char> issRstep( 
            std::istringstream( std::to_string( rstep ) ) );

        REQUIRE( rstep == argument::extract< PLOTR::Card7::Rstep >( 
                          issRstep ).value );
      }
    }
  } // GIVEN

  GIVEN( "default value" ){
    iRecordStream<char> issRstep( std::istringstream( " /" ) );

    THEN( "default value is returned" ){
      REQUIRE( Approx( 1.0 ) == argument::extract< PLOTR::Card7::Rstep >(
                          issRstep ).value );
    }
  }//GIVEN

  GIVEN( "invalid Rstep parameters" ){
    std::vector<double> invalidValues{ -2.0, -1.1, 0.0 };

    THEN( "the class throws an exception" ){
      for( auto rstep : invalidValues ){
        iRecordStream<char> issRstep( 
            std::istringstream( std::to_string( rstep ) ) );

        REQUIRE_THROWS( argument::extract< PLOTR::Card7::Rstep >( issRstep ) );
      }
    }
  } // GIVEN
} // SCENARIO
