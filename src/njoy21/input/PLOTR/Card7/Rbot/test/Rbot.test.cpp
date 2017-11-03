#define CATCH_CONFIG_MAIN

#include <numeric>

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Rbot output values", "[PLOTR],[Card7], [Rbot]"){

  int jtype = 1;

  GIVEN( "valid entries" ){
  
    WHEN( "valid Rbot parameters are given" ){
      std::vector<double> validValues{-2.0,-1.0,0.0,0.1,0.5,0.8,1.0,2.0,80.0};
  
      THEN( "the returned class has the correct value" ){
        for( auto rbot : validValues ){
          iRecordStream<char> issRbot( 
              std::istringstream( std::to_string( rbot ) ) );
  
          REQUIRE( rbot == argument::extract< PLOTR::Card7::Rbot >( 
                            issRbot, jtype ).value );
        }
      }
    }
  
    WHEN( "default value is used" ){
      iRecordStream<char> issRbot( std::istringstream( " /" ) );
  
      THEN( "default value is returned" ){
        REQUIRE( Approx( 0.0 ) == argument::extract< PLOTR::Card7::Rbot >(
                            issRbot, jtype ).value );
      }
    }

    jtype = 2;
  
    WHEN( "valid Rbot parameters are given" ){
      std::vector<double> validValues{0.1,0.5,0.8,1.0,2.0,80.0};
  
      THEN( "the returned class has the correct value" ){
        for( auto rbot : validValues ){
          iRecordStream<char> issRbot( 
              std::istringstream( std::to_string( rbot ) ) );
  
          REQUIRE( rbot == argument::extract< PLOTR::Card7::Rbot >( 
                            issRbot, jtype ).value );
        }
      }
    }
  
    WHEN( "default value is used" ){
      iRecordStream<char> issRbot( std::istringstream( " /" ) );
  
      THEN( "default value is returned" ){
        REQUIRE( Approx( 1.0e-07 ) == argument::extract< PLOTR::Card7::Rbot >(
                            issRbot, jtype ).value );
      }
    }
  } // GIVEN

  GIVEN( "invalid entries" ){
    jtype = 2;
    std::vector<double> invalidValues{-10.0, -1.0, 0.0};
    WHEN( "values <= 0.0 are given for a log scale" ){
      for( auto rbot : invalidValues ){
        THEN( "an exception is thrown" ){
          iRecordStream<char> issRbot( std::istringstream(
                                       std::to_string( rbot ) ) );
          REQUIRE_THROWS( argument::extract< PLOTR::Card7::Rbot >(
                                             issRbot, jtype ) );
        }
      }
    }
  } // GIVEN
} // SCENARIO
